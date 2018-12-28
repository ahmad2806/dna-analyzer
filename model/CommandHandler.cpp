//
// Created by ahmad on 29/12/2018.
//

#include <stdexcept>
#include "CommandHandler.h"
#include "Commands/CommandFactory.h"
#include "Commands/New/CommandNew.h"
#include "Commands/Exit/CommandExit.h"
#include "Commands/Print/CommandPrint.h"

std::string CommandHandler::run(Command *pCommand) {

    return std::string();
}

std::string CommandHandler::create_and_run_command(std::vector<std::string> &_vector) {
    Command* local_cmd = command_factory(_vector);
    if (!local_cmd)
        throw std::invalid_argument("no such command please try again");

    return local_cmd->run_command();
}

Command *CommandHandler::command_factory(std::vector<std::string> &vector) {
    std::string firstElement = vector.front();

    if (firstElement == "new") {
        return new CommandNew();
    }
    if (firstElement == "print") {
        return new CommandPrint();
    }
    if (firstElement == "exit") {
        return new CommandExit();
    }
    return 0;
}
