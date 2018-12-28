//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDPRINT_H
#define PROJECT_DNA_ANALYZER_COMMANDPRINT_H


#include <iostream>

#include "../../Command.h"

class CommandPrint: public Command {
public:
    CommandPrint();
    std::string run_command();
};


#endif //PROJECT_DNA_ANALYZER_COMMANDPRINT_H
