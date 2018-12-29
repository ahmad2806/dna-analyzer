//
// Created by ahmad on 28/12/2018.
//

#include <iostream>
#include "CommandNew.h"

std::string CommandNew::run_command() {
    std::string s = "dad";
    return s;
}

CommandNew::CommandNew() {
    std::cout << "in command new\n";
}

CommandNew::~CommandNew() {

}
