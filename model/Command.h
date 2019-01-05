//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMAND_H
#define PROJECT_DNA_ANALYZER_COMMAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include "dna_code/DNA/DnaSquence.h"
#include "../controller/sharedPtr/SharedPtr.h"
#include "dna_code/DataHandler/DataHandler.h"

class Command{
protected:
    static const unsigned int DEFAULT_ACCURACY = 40;
    static const unsigned int DEFAULT_OFFSET = 8;
    char haveId; /* i have id */
    unsigned int haveAccuracy; /* i have id */
    char haveName; /* i have name */

public:
    Command();
    static DataHandler * p_data_handler;
    std::string build_return_value (std::string _id, std::string _name, const DnaSequence*const _sequence, unsigned int _accuracy);
    virtual std::string run_command(const std::vector<std::string> &vector) = 0;
    virtual ~Command(){};
    std::string get_this_sequence(std::string find_by);
    bool validate_name_or_id(char s);
    std::vector<std::string> get_name_and_id_from(std::string);
private:
    std::string return_data_as_string_from(std::pair<std::string, DnaSequence*> );
};
#endif //PROJECT_DNA_ANALYZER_COMMAND_H
