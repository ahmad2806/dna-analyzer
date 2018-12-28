//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_CLI_CONTROLLER_H
#define PROJECT_DNA_ANALYZER_CLI_CONTROLLER_H

#include <iostream>
#include <vector>

#include <iterator>
#include <sstream>

#include "../view/View.h"

#include "../model/Command.h"
#include "../model/Commands/New/CommandNew.h"
#include "../model/Commands/Print/CommandPrint.h"
#include "../model/Commands/Exit/CommandExit.h"


class CLI_controller {

public:
    void start_program();
private:
    Command* parse_input_to_command(const std::string &_input);


    void split_input(const std::string &_input, std::vector<std::string> &my_vec);
};


#endif //PROJECT_DNA_ANALYZER_CLI_CONTROLLER_H
