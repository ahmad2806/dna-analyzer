//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDEXIT_H
#define PROJECT_DNA_ANALYZER_COMMANDEXIT_H


#include "../../Command.h"

class CommandExit : public Command{
public:
    std::string run_command();
};


#endif //PROJECT_DNA_ANALYZER_COMMANDEXIT_H
