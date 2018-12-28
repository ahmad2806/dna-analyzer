//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDHANDLER_H
#define PROJECT_DNA_ANALYZER_COMMANDHANDLER_H


#include <string>
#include <vector>
#include "Command.h"

class CommandHandler {
public:
    std::string create_and_run_command(std::vector<std::string> &_vector);
    std::string run(Command *pCommand);

private:

    Command *command_factory(std::vector<std::string> &vector);
};


#endif //PROJECT_DNA_ANALYZER_COMMANDHANDLER_H
