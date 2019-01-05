//
// Created by ahmad on 28/12/2018.
//

#include <cstdlib>
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

std::string CommandPrint::validate_input(const std::vector<std::string> &vector) {

    if (vector.size() > 3 || vector.size() <= 1)
        return INPUT_ERROR;
    if (vector.size() == 3) {
        if (!this_string_all_numbers(vector.at(2))) {
            return INPUT_ERROR;
        }
        /* might have a problem if atoi cant handle unsigned int number !! */
        haveAccuracy = (unsigned int )atoi(vector.at(2).c_str());
    }
    if (!validate_name_or_id(vector[1][0]))
        return INPUT_ERROR;
    return PASS;

}

bool CommandPrint::this_string_all_numbers(const std::string &_str) {
    unsigned int i;
    for (i = 0;  i < _str.length() ; ++i) {
        int temp = isdigit(_str[i]);
        if (temp == 0) {
            if (_str[i] != '0')
                return false;
        }
    }
    return true;
}
