//
// Created by ahmad on 05/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_DNA_WRITER_H
#define PROJECT_DNA_ANALYZER_DNA_WRITER_H


#include "../../DNA/DnaSquence.h"
#include <fstream>

class Dna_writer {
public:
    static std::string write_to_file(const DnaSequence &dna, const char *name);

    static void write_to_file(const std::vector<DnaSequence> dnas, const char *name);

};


#endif //PROJECT_DNA_ANALYZER_DNA_WRITER_H
