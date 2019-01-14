//
// Created by ahmad on 05/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_DNA_WRITER_H
#define PROJECT_DNA_ANALYZER_DNA_WRITER_H


#include "../../DNA/DnaSequence/DnaSquence.h"
#include <fstream>

class Dna_writer {
    static const std::string FILE_EXISTS;
public:
    static std::string write_to_file(std::tr1::shared_ptr<IDna> dna, const char *name);

    static void write_to_file(std::vector<std::tr1::shared_ptr<IDna> >  dnas, const char *name);

};


#endif //PROJECT_DNA_ANALYZER_DNA_WRITER_H
