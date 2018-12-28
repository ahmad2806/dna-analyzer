//
// Created by ahmad on 28/12/2018.
//

#include "CLI_controller.h"
void CLI_controller::start_program() {
    CommandHandler cmd_handler;

    int done = 0;
    std::string input;
    std::vector<std::string> v_convertMeToCommand;
    while (!done) {

        input = View::get_input_from_the_user();
        parse_input_to_vector(input, v_convertMeToCommand);

        std::string result =  cmd_handler.create_and_run_command(v_convertMeToCommand);
//        view.show(result);
//    }
    }
}


void CLI_controller::parse_input_to_vector(const std::string &_input, std::vector<std::string> &my_vec) {
    std::stringstream local_stringStream(_input);
    std::string temp;
    while (local_stringStream >> temp)
        my_vec.push_back(temp);
}

