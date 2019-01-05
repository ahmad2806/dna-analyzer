//
// Created by ahmad on 01/11/2018.
//

#include "dna_read.h"


std::vector<std::string> Dna_reader::read_from_file(const char *name) {
    std::vector<std::string> vec;
    std::ifstream my_file(name);
    std::string line;
    if (my_file.is_open()) {
        while (std::getline(my_file, line))
            vec.push_back(line);
        my_file.close();
    } else std::cout << "Unable to open file\n";

    return vec;
}

