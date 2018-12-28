//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDNEW_H
#define PROJECT_DNA_ANALYZER_COMMANDNEW_H

#include <iostream>

#include "../../Command.h"

class CommandNew : public Command{
public:
    CommandNew();
    std::string run_command();
};


#endif //PROJECT_DNA_ANALYZER_COMMANDNEW_H
