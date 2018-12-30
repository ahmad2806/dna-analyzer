//
// Created by ahmad on 29/12/2018.
//
#include "CommandHandler.h"
#include "../controller/sharedPtr/SharedPtr.h"

std::string CommandHandler::create_and_run_command(const std::vector<std::string> &_vector) const{
    Command *local_cmd = command_factory(_vector.at(0));
    SharedPtr<Command> m_command(local_cmd);

    std::string run_result;
    if (!local_cmd)
        throw std::invalid_argument("no such command please try again");

    run_result = m_command.get()->run_command(_vector);


    return run_result;
}

Command *CommandHandler::command_factory(const std::string & _commandName) const{


    if (_commandName == "new") {
        return new CommandNew();
    }
    if (_commandName== "print") {
        return new CommandPrint();
    }
    if (_commandName== "exit") {
        return new CommandExit();
    }
    return 0;
}
