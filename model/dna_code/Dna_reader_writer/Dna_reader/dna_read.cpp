//
// Created by ahmad on 01/11/2018.
//

#include "dna_read.h"
Dna_reader::~Dna_reader_writer() {}



std::vector<DnaSequence> Dna_reader::read_from_file(const char *name) {
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

