//
// Created by ahmad on 01/11/2018.
//
#ifndef DNA_DNA_READER_WRITER_H
#define DNA_DNA_READER_WRITER_H

#include <fstream>
#include "../DNA/DnaSquence.h"

class Dna_reader_writer {
public:
    static std::vector<DnaSequence> read_from_file(const char *name);
    static void write_to_file(const DnaSequence& dna, const char *name);
    static void write_to_file(const std::vector<DnaSequence> dnas, const char *name);

        virtual ~Dna_reader_writer() = 0;
};


#endif //DNA_DNA_READER_WRITER_H
