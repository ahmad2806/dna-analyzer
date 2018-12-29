//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_VIEW_H
#define PROJECT_DNA_ANALYZER_VIEW_H

#include <iostream>
#include <stdexcept>

class View {

public:
    static std::string get_input_from_the_user();
    static inline void say_bye();

    static inline void print_invalid_command(std::invalid_argument &argument);
};


void View::say_bye() {
    std::cout << "bye !" << std::endl;
}

void View::print_invalid_command(std::invalid_argument &argument) {
    std::cout << argument.what() <<std::endl;
}


#endif //PROJECT_DNA_ANALYZER_VIEW_H
