//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDPRINT_H
#define PROJECT_DNA_ANALYZER_COMMANDPRINT_H


#include <iostream>
#include <cstdlib>

#include "../../Command.h"
#include "../DataAccessPermissionCommands.h"

class CommandPrint: public DataAccessPermissionCommands {

private:

    static const std::string INPUT_ERROR;
    static const std::string PASS;

public:
    CommandPrint();
    std::string run_command(const std::vector<std::string> &vector);

private:
    inline std::string validate_input(const std::vector<std::string> &vector);
    inline bool this_string_all_numbers(const std::string &_str);
};

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

#endif //PROJECT_DNA_ANALYZER_COMMANDPRINT_H
