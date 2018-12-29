//
// Created by ahmad on 01/11/2018.
//

#include "dna_read_writer.h"
Dna_reader_writer::~Dna_reader_writer() {}



std::vector<DnaSequence> Dna_reader_writer::read_from_file(const char *name) {
    std::vector<DnaSequence> vec;
    std::ifstream my_file(name);
    std::string line;
    if (my_file.is_open()) {
        while (std::getline(my_file, line))
            vec.push_back(DnaSequence(line));
        my_file.close();
    } else std::cout << "Unable to open file\n";

    return vec;
}


void Dna_reader_writer::write_to_file(const DnaSequence& dna_seq, const char *name) {
    std::ofstream my_file;
    my_file.open(name, std::fstream::app);
    if (my_file.is_open()) {
        size_t i;
        size_t len = dna_seq.getlength();
        Nucleotide * seq = dna_seq.get_dna_sequence();
        for (i = 0; i < len; ++i)
            my_file << seq[i];
        my_file << "\n";
        my_file.close();
    } else std::cout << "error while opening file\n";
}

void Dna_reader_writer::write_to_file(const std::vector<DnaSequence > dnas, const char *name) {
    size_t i, len = dnas.size();
    for (i = 0; i < len ; ++i)
        write_to_file(dnas[i], name);
}
