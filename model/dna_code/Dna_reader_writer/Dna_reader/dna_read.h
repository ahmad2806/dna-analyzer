//
// Created by ahmad on 01/11/2018.
//
#ifndef DNA_DNA_READER_WRITER_H
#define DNA_DNA_READER_WRITER_H

#include "../../DNA/DnaSquence.h"

class Dna_reader {
public:
    static std::vector<DnaSequence> read_from_file(const char *name);


    virtual ~Dna_reader_writer() = 0;
};


#endif //DNA_DNA_READER_WRITER_H
