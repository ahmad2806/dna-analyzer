//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMAND_H
#define PROJECT_DNA_ANALYZER_COMMAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include "dna_code/DNA/DnaSequence/DnaSquence.h"
#include "../controller/sharedPtr/SharedPtr.h"
#include "dna_code/DataHandler/DataHandler.h"

class Command{

protected:

    static const unsigned int DEFAULT_ACCURACY = 40;
    static const unsigned int DEFAULT_OFFSET = 8;

    char haveId; /* i have id */
    unsigned int haveAccuracy; /* i have accuracy */
    char haveName; /* i have name */

public:
    static DataHandler * p_data_handler;

    Command();
    std::string build_return_value (std::string _id, std::string _name, const DnaSequence*const _sequence, unsigned int _accuracy);

    virtual std::string run_command(const std::vector<std::string> &vector) = 0;
    virtual ~Command(){};

    inline std::string get_this_sequence(std::string find_by);
    inline bool validate_name_or_id(char s);
    inline std::vector<std::string> get_name_and_id_from(std::string);

private:
    inline std::string return_data_as_string_from(std::pair<std::string, DnaSequence*> );
};


std::string Command::get_this_sequence(std::string find_by) {
    std::pair<std::string, DnaSequence *> localPair;
    if (haveName) {
        try {
            localPair = p_data_handler->find_by_name(find_by);
        } catch (std::invalid_argument e) {
            return e.what();
        }
    } else {
        try {
            localPair = p_data_handler->find_by_id(find_by);
        } catch (std::invalid_argument e) {
            return e.what();
        }
    }
    return return_data_as_string_from(localPair);

}

std::string Command::return_data_as_string_from(std::pair<std::string, DnaSequence *> pair) {
    std::vector<std::string> idNameVec;
    idNameVec = get_name_and_id_from(pair.first);

    unsigned int  accuracy = haveAccuracy;
    if (accuracy == 0)
        accuracy = DEFAULT_ACCURACY;
    return build_return_value(idNameVec[0], idNameVec[1], pair.second, accuracy);
}

std::vector<std::string> Command::get_name_and_id_from(std::string _input) {
    std::vector<std::string> nameIdVec;
    std::stringstream local_stringStream(_input);
    std::string temp;
    while (local_stringStream >> temp)
        nameIdVec.push_back(temp);

    return nameIdVec;
}

bool Command::validate_name_or_id(char s) {

    if (s == '@')
        haveName = 1;
    else if (s == '#')
        haveId = 1;
    else
        return false;
    return true;
}

#endif //PROJECT_DNA_ANALYZER_COMMAND_H
