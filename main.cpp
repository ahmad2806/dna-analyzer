#include <iostream>
#include "controller/CLI_controller.h"

int main() {
    CLI_controller cli;
    bool b_moreCommands = true;
    std::string result;
    while (b_moreCommands) {

        result = cli.start_program();
        if (result == "exit")
            b_moreCommands = false;
    }
    return 0;
}

