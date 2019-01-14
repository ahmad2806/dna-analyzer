//
// Created by ahmad on 01/11/2018.
//
#ifndef DNA_DNA_READER_WRITER_H
#define DNA_DNA_READER_WRITER_H

#include "../../DNA/DnaSequence/DnaSquence.h"
#include <fstream>
class Dna_reader {
public:
    static std::vector<std::string> read_from_file(const char *name);

};


#endif //DNA_DNA_READER_WRITER_H
