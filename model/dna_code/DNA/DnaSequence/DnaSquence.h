//
// Created by ahmad on 25/10/2018.
//

#ifndef DNA_DNASQUENCE_H
#define DNA_DNASQUENCE_H


#include <ostream>
#include <iostream>

#include <cstring>
#include <stdexcept>
#include <vector>
#include "../../Nucleotide/Nucleotide.h"

class DnaSequence {


public:

    explicit DnaSequence(const char *p_dna);

    explicit DnaSequence(const std::string &s_dna);

    DnaSequence(const DnaSequence &other);

    virtual ~DnaSequence();

    DnaSequence &operator=(const char *other);

    DnaSequence &operator=(const std::string &other);

    DnaSequence &operator=(const DnaSequence &other);

    bool operator==(const DnaSequence &rhs) const;

    bool operator!=(const DnaSequence &rhs) const;

    const Nucleotide operator[](int i) const; // if this is const ... we want to return a copy of that char (to not allow changes)
    Nucleotide &operator[](int i); // if non const object was passed .. we return the reference to that char

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &squence);


    size_t getlength() const;

    Nucleotide *const &get_dna_sequence() const;




    size_t find_sub_string(const DnaSequence &sub_seq, size_t pos = 0) const;

    std::vector<size_t> find_all(const DnaSequence &sub_seq) const;

    const DnaSequence slice_me(size_t from, size_t to) const;

    const DnaSequence pairing();

    size_t count(const DnaSequence &sub_seq) const;

    std::vector<std::pair<size_t, size_t> > find_consensus_sequence() const;



private:
    Nucleotide *dna_sequence;
    size_t length;

    const std::string convert_object_to_string() const;

    void check_and_allocate(const char *p_dna);

    //DnaSequence &do_assignment(const char *p_dna, const size_t other_len);

};


inline const Nucleotide DnaSequence::operator[](int i) const {
    //we return const char so we protect the user
    // from changing it and rely on that changes !!!!
    // so when ever he want to change it ...
    // we have compilation error
    return dna_sequence[i];
}

inline Nucleotide &DnaSequence::operator[](int i) {
    return dna_sequence[i];

}

inline size_t DnaSequence::getlength() const {
    return length;
}


#endif //DNA_DNASQUENCE_H
