//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDHANDLER_H
#define PROJECT_DNA_ANALYZER_COMMANDHANDLER_H


#include <string>
#include <vector>
#include <stdexcept>

#include "../controller/sharedPtr/SharedPtr.h"

#include "Command.h"
#include "Commands/New/CommandNew.h"
#include "Commands/Exit/CommandExit.h"
#include "Commands/Print/CommandPrint.h"
#include "Commands/Save/CommandSave.h"
#include "Commands/Load/CommandLoad.h"



class CommandHandler {
public:
    std::string create_and_run_command(const std::vector<std::string> &_vector) const;

private:

    Command *command_factory(const std::string &_commandName)const;
};


#endif //PROJECT_DNA_ANALYZER_COMMANDHANDLER_H
