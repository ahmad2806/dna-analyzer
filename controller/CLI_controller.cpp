//
// Created by ahmad on 28/12/2018.
//

#include "CLI_controller.h"

std::string CLI_controller::start_program() const{
    CommandHandler cmdHandler;

    std::string input;
    std::string result;

        bool b_isValidCommand = true;
        std::vector<std::string> v_convertMeToCommand;

        input = View::get_input_from_the_user();
        parse_input_to_vector(input, v_convertMeToCommand);

        try {
            result = cmdHandler.create_and_run_command(v_convertMeToCommand);
        } catch (std::invalid_argument &invalidCommand) {
            View::print_invalid_command(invalidCommand);
            b_isValidCommand = false;
        }

        if (result == "exit")
            View::say_bye();

        if (b_isValidCommand )
            View::print_result(result);
    return result;

}

void CLI_controller::parse_input_to_vector(const std::string &_input, std::vector<std::string> &myVec) const{
    std::stringstream local_stringStream(_input);
    std::string temp;
    while (local_stringStream >> temp)
        myVec.push_back(temp);
}

