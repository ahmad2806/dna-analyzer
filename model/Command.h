//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMAND_H
#define PROJECT_DNA_ANALYZER_COMMAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include "dna_code/DNA/DnaSquence.h"

class Command{
public:
    std::string build_return_value (unsigned int _id, const std::string &_name, const DnaSequence* const _sequence);
    virtual std::string run_command(const std::vector<std::string> &vector) = 0;
    virtual ~Command(){};
};
#endif //PROJECT_DNA_ANALYZER_COMMAND_H
