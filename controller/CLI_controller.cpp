//
// Created by ahmad on 28/12/2018.
//

#include "CLI_controller.h"
void CLI_controller::start_program() {
    int done = 0;
    while (!done) {
        std::string input = View::get_input_from_the_user();
        Command *cmd = parse_input_to_command(input);

//        std::string result =  command_handler.run_command(cmd);
//        view.show(result);
//    }
    }
}

//Command Factory
Command *CLI_controller::parse_input_to_command(const std::string &_input) {

    std::vector<std::string> v_inputAfterSplit;

    split_input(_input, v_inputAfterSplit);
    const std::string firstElement = v_inputAfterSplit.front();

    if (firstElement == "new") {
        return new CommandNew();
    }
    if (firstElement == "print") {
        return new CommandPrint();
    }
    if (firstElement == "exit") {
        return new CommandExit();
    }


    return 0;
}

void CLI_controller::split_input(const std::string &_input, std::vector<std::string> &my_vec) {
    std::stringstream local_stringStream(_input);
    std::string temp;
    while (local_stringStream >> temp)
        my_vec.push_back(temp);

}

