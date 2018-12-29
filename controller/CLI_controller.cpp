//
// Created by ahmad on 28/12/2018.
//

#include <stdexcept>
#include "CLI_controller.h"

void CLI_controller::start_program() {
    CommandHandler cmdHandler;

    int moreCommands = 1;
    std::string input;
    std::string result;

    while (moreCommands) {
        std::vector<std::string> v_convertMeToCommand;
        input = View::get_input_from_the_user();
        parse_input_to_vector(input, v_convertMeToCommand);

        try {
            result = cmdHandler.create_and_run_command(v_convertMeToCommand);
        } catch (std::invalid_argument &invalidCommand) {
            View::print_invalid_command(invalidCommand);
        }

        if (result == "exit"){
            View::say_bye();
            break;
        }

//        view.show(result);
//    }
    }
}


void CLI_controller::parse_input_to_vector(const std::string &_input, std::vector<std::string> &myVec) {
    std::stringstream local_stringStream(_input);
    std::string temp;
    while (local_stringStream >> temp)
        myVec.push_back(temp);
}

