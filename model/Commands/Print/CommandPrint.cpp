//
// Created by ahmad on 28/12/2018.
//

#include "CommandPrint.h"


const std::string CommandPrint::INPUT_ERROR = "This command takes 2 arguments print @<name> | #<id>  [_accuracy] ";

const std::string CommandPrint::PASS = "PASS";

std::string CommandPrint::run_command(const std::vector<std::string> &vector) {
    std::string validation = validate_input(vector);
    if (validation != PASS)
        return validation;

    std::string answer = get_this_sequence(vector.at(1));

    return answer;
}

CommandPrint::CommandPrint()  {
    haveId = 0;
    haveName = 0;
    haveAccuracy = 0;
}