//
// Created by ahmad on 29/12/2018.
//
#include "CommandHandler.h"

std::string CommandHandler::create_and_run_command(std::vector<std::string> &_vector) {
    Command *local_cmd = command_factory(_vector);
    std::string run_result;
    if (!local_cmd)
        throw std::invalid_argument("no such command please try again");

    run_result = local_cmd->run_command();

    delete local_cmd;
    return run_result;
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
