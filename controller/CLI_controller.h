//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_CLI_CONTROLLER_H
#define PROJECT_DNA_ANALYZER_CLI_CONTROLLER_H

#include <iostream>
#include <vector>

#include <sstream>

#include "../view/View.h"

#include "../model/CommandHandler.h"


class CLI_controller {

public:
    void start_program() const;
private:
    void parse_input_to_vector(const std::string &_input, std::vector<std::string> &my_vec) const;
};


#endif //PROJECT_DNA_ANALYZER_CLI_CONTROLLER_H
