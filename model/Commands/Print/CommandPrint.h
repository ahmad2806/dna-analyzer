//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDPRINT_H
#define PROJECT_DNA_ANALYZER_COMMANDPRINT_H


#include <iostream>

#include "../../Command.h"
#include "../DataAccessPermissionCommands.h"

class CommandPrint: public DataAccessPermissionCommands {
private:
    static const std::string INPUT_ERROR;
    static const std::string PASS;


public:
    CommandPrint();
    std::string run_command(const std::vector<std::string> &vector);

private:
    std::string validate_input(const std::vector<std::string> &vector);

    bool this_string_all_numbers(const std::string &_str);
};


#endif //PROJECT_DNA_ANALYZER_COMMANDPRINT_H
