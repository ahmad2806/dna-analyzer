//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDEXIT_H
#define PROJECT_DNA_ANALYZER_COMMANDEXIT_H


#include "../../Command.h"

class CommandExit : public Command{
public:
    CommandExit();
    bool is_valid(const std::vector<std::string> &vector);

    std::string run_command(const std::vector<std::string> &vector);
};


#endif //PROJECT_DNA_ANALYZER_COMMANDEXIT_H
