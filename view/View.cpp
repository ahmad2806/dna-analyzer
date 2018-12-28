//
// Created by ahmad on 28/12/2018.
//

#include "View.h"
// we can move it as inline __ later __
std::string View::get_input_from_the_user() {
    std::string input;
    std::cout << "> cmd >>>";
    std::getline(std::cin, input);
    return input;
}
