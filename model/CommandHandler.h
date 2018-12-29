//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDHANDLER_H
#define PROJECT_DNA_ANALYZER_COMMANDHANDLER_H


#include <string>
#include <vector>
#include <stdexcept>

#include "Command.h"
#include "Commands/New/CommandNew.h"
#include "Commands/Exit/CommandExit.h"
#include "Commands/Print/CommandPrint.h"



class CommandHandler {
public:
    std::string create_and_run_command(std::vector<std::string> &_vector);

private:

    Command *command_factory(std::vector<std::string> &vector);
};


#endif //PROJECT_DNA_ANALYZER_COMMANDHANDLER_H
