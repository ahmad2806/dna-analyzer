//
// Created by ahmad on 29/12/2018.
//

#include "CommandExit.h"



std::string CommandExit::run_command(const std::vector<std::string> &vector) {
    std::string s = "exit";


    return s;

}

CommandExit::CommandExit() {
    std::cout << "in Command Exit\n";
}

bool CommandExit::is_valid(const std::vector<std::string> &vector) {
    return false;
}
