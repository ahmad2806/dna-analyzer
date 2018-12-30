//
// Created by ahmad on 30/12/2018.
//

#include "Command.h"

std::string Command::build_return_value(unsigned int _id, const std::string &_name, const DnaSequence* const _sequence) {
    std::ostringstream s;
    s << "[" << _id << "] "
      << _name << ": " << *_sequence;
    return s.str();
}

