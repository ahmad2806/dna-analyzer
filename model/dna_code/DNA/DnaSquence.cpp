//
// Created by ahmad on 25/10/2018.
//

#include <iostream>
#include "DnaSquence.h"
#include <fstream>
#include <stdexcept>
#include <vector>


DnaSequence::DnaSequence(const char *p_dna) {
    check_and_allocate(p_dna);
//    dna_sequence = new Nucleotide[strlen(p_dna) + 1];
//    strcpy((char *) dna_sequence, p_dna);
}

DnaSequence::DnaSequence(const std::string &my_string) {
    const char *p_dna = my_string.c_str();
    check_and_allocate(p_dna);

//    dna_sequence = new Nucleotide[strlen(p_dna) + 1];
//    strcpy((char *) dna_sequence, p_dna);
}

DnaSequence::DnaSequence(const DnaSequence &other) {
    const char *p_dna;
    std::string s = other.convert_object_to_string();
    p_dna = s.c_str();
    check_and_allocate(p_dna);
}

//DnaSequence::DnaSequence(const DnaSequence &other) {
//    const char *p_dna = (char *) other.dna_sequence;
//    check_and_allocate(p_dna);
////
////    dna_sequence = new Nucleotide[strlen((char *) other.dna_sequence) + 1];
////    strcpy((char *) dna_sequence, (char *) other.dna_sequence);
//}


void DnaSequence::check_and_allocate(const char *p_dna) {
    size_t i;
    length = strlen(p_dna);
    try {
        dna_sequence = new Nucleotide[length];

        for (i = 0; i < length; ++i)
            dna_sequence[i] = p_dna[i];
    } catch (std::invalid_argument &msg) {
        delete[] dna_sequence;
        dna_sequence = 0;
        throw;
    } catch (std::bad_alloc &e) {
        throw;
    }

}

DnaSequence &DnaSequence::operator=(const DnaSequence &other) {
    if (this == &other)
        return *this;
    const char *p_dna;
    std::string s;
    s = other.convert_object_to_string();
    p_dna = s.c_str();
    check_and_allocate(p_dna);
    return *this;
}


DnaSequence &DnaSequence::operator=(const char *p_char) {
    check_and_allocate(p_char);
    return *this;
}

DnaSequence &DnaSequence::operator=(const std::string &s) {
    const char *p_dna = s.c_str();
    check_and_allocate(p_dna);
    return *this;
}

bool DnaSequence::operator==(const DnaSequence &rhs) const {
    size_t i = 0;
    if (this->getlength() == rhs.getlength()) {
        size_t len = length;
        for (; i < len; ++i) {
            if (dna_sequence[i] == rhs[i])
                continue;
            else
                break;
        }
    }
    return i == length;
}

bool DnaSequence::operator!=(const DnaSequence &rhs) const {
    return !(rhs == *this);
}
//DnaSequence &DnaSequence::do_assignment(const char *p_dna, size_t other_len) {
//    delete[] dna_sequence;
//    try {
//        dna_sequence = new Nucleotide[other_len];
//    } catch (std::bad_alloc &e) {
//        throw;
//    }
//    size_t i;
//    size_t len = other_len;
//    for (i = 0; i < len; ++i)
//        dna_sequence[i] = p_dna[i];
//    m_capacity = other_len;
//    return *this;
//}

DnaSequence::~DnaSequence() {
    delete[] dna_sequence;
}

std::ostream &operator<<(std::ostream &os, const DnaSequence &squence) {

    size_t i;
    size_t len = squence.getlength();

    os << "Dna Sequence is : ";
    for (i = 0; i < len; ++i)
        os << squence[i];
    return os;
}


const DnaSequence DnaSequence::slice_me(size_t from, size_t to) const {
    std::string str1;

    if (from > to || to > this->getlength() - 1 || to - from < 2)
        throw std::invalid_argument("invalid argu to slice");

    size_t i;
    for (i = from + 1; i < to; ++i)
        str1 += dna_sequence[i];
    DnaSequence d(str1);
    return d;

}

size_t DnaSequence::find_sub_string(const DnaSequence &sub_seq, size_t pos) const {
    if (length < sub_seq.length)
        throw std::invalid_argument("sub sequence was not found in the dna");
    size_t i = pos;
    size_t sub_at = 0;
    size_t j = 0;
    int entered = 0;
    for (; i < length; ++i) {
        if (dna_sequence[i] == sub_seq.dna_sequence[j]) {
            if (j == 0) {
                entered = 1;
                sub_at = i;
            }
            if (j == sub_seq.length - 1)
                return sub_at;
            ++j;
        } else {
            if (sub_at == i - 1 && entered) {
                entered = 0;
                i--;
            }
            j = 0;
        }
    }
    throw std::invalid_argument("sub sequence was not found in the dna");


//    std::string str1 = (char *) dna_sequence;
    // error ... when converting to string..
    // null terminator will be added causing invalid read of size 1
    // because in the new we didn't save a space for him

//    std::cout << *this<<"        "<<sub_seq<<std::endl;
//    size_t sub_at;
//    if (pos)
//        sub_at = str1.find((char *) sub_seq.dna_sequence, pos + sub_seq.getlength());
//
//    sub_at = str1.find((char *) sub_seq.dna_sequence);
//    if (sub_at == (size_t) -1)
//        throw std::invalid_argument("sub sequence was not found in the dna");
//    return sub_at;
}

const DnaSequence DnaSequence::pairing() {
    //do we change this? or return a new one !!?!
    // no const is needed...that's so we use the second [] operator
    std::string lets_pair;
    lets_pair = "";
    size_t i;
    size_t len = this->getlength();
    for (i = 0; i < len; ++i) {
        if (this->dna_sequence[i] == 'T') {
            //this->dna_sequence[i] = 'A';
            lets_pair += 'A';
        } else if (this->dna_sequence[i] == 'A') {
            //   this->dna_sequence[i] ='T';
            lets_pair += 'T';
        } else if (this->dna_sequence[i] == 'C') {
            //this->dna_sequence[i] == 'G';
            lets_pair += 'G';
        } else if (this->dna_sequence[i] == 'G') {
            //this->dna_sequence[i] == 'C';
            lets_pair += 'C';
        }
    }
    return DnaSequence(lets_pair);
}

size_t DnaSequence::count(const DnaSequence &sub_seq) const {
    size_t counter = 0;
    try {
        size_t pos = this->find_sub_string(sub_seq);

        while (pos >= 0) {

            ++counter;
            pos = this->find_sub_string(sub_seq, pos + sub_seq.getlength());
        }
    } catch (std::invalid_argument &msg) {/*do nothing*/}

    return counter;
}


std::vector<size_t> DnaSequence::find_all(const DnaSequence &sub_seq) const {
    std::vector<size_t> start_positions;
    size_t i = 0;
    while (i < length) {
        try {
            i = find_sub_string(sub_seq, i);
            start_positions.push_back(i);
            ++i;
        } catch (std::invalid_argument &msg) {/*do nothing*/ break; }
    }
    if (start_positions.size() == 0)
        throw std::invalid_argument("sub sequence was'nt found");
    return start_positions;
}

const std::string DnaSequence::convert_object_to_string() const {
    std::string str1;
    size_t i;
    for (i = 0; i < this->length; i++) {
        str1 += this->dna_sequence[i];
    }

    return str1;
}

Nucleotide *const &DnaSequence::get_dna_sequence() const {
    return dna_sequence;
}

std::vector<std::pair<size_t, size_t> > DnaSequence::find_consensus_sequence() const {
    std::vector<std::pair<size_t, size_t> > vec;
    size_t codon_size = 3;
    DnaSequence base_codon("ATG");
    DnaSequence tail_codon0("TAG");
    DnaSequence tail_codon1("TAA");
    DnaSequence tail_codon2("TGA");
    std::vector<size_t> base_codon_indexs = find_all(base_codon);
    size_t base_index_len = base_codon_indexs.size();
    size_t i, j;
    for (i = 0; i < base_index_len; i++) {
        for (j = base_codon_indexs[i] + codon_size;
             j < length - 2; j += codon_size) {
            std::string s;
            size_t index = j;
            s += dna_sequence[index++];
            s += dna_sequence[index++];
            s += dna_sequence[index];
            DnaSequence temp(s);
//            DnaSequence temp(this->slice_me(j, j+codon+1));//slice wont work because of the codons in the end of the seq
            if (temp == tail_codon0
                || temp == tail_codon1
                || temp == tail_codon2) {
                vec.push_back(std::make_pair(base_codon_indexs[i], j + codon_size));
            }
        }
    }
    return vec;
}
