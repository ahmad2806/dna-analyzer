//
// Created by ahmad on 29/12/2018.
//
#include "CommandHandler.h"

std::string CommandHandler::create_and_run_command(const std::vector<std::string> &_vector) const {
    Command *local_cmd = 0;

    /* making sure that we don't get an empty vector */
    try {
        local_cmd = command_factory(_vector.at(0));
    } catch (std::exception e) {
        throw std::invalid_argument("no such command please try again");
    }

    std::string run_result;
    if (!local_cmd)
        throw std::invalid_argument("no such command please try again");
    SharedPtr<Command> m_command(local_cmd);

    run_result = m_command.get()->run_command(_vector);


    return run_result;
}


Command *CommandHandler::command_factory(const std::string &_commandName) const {


    if (_commandName == "new") {
        return new CommandNew();
    }
    if (_commandName == "print") {
        return new CommandPrint();
    }
    if (_commandName == "exit") {
        return new CommandExit();
    }
    if (_commandName == "save") {
        return new CommandSave();
    }
    if (_commandName == "load") {
        return new CommandLoad();
    }
    if (_commandName == "list") {
        return new CommandList();
    }
    return 0;
}

