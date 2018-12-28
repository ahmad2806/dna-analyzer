//
// Created by ahmad on 28/12/2018.
//

#include "CLI_controller.h"

void CLI_controller::start_program() {
    int done  = 0;
    while (!done) {
        std::string input = View::get_input_from_the_user();
        Command *cmd = parse_input_to_command();
        if (cmd == "exit") {
            destroy_all_allocated_memo();
            break;
        }
        std::string result =  command_handler.run_command(cmd);
        view.show(result);
    }
}
