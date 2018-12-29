//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDNEW_H
#define PROJECT_DNA_ANALYZER_COMMANDNEW_H

#include <iostream>
#include <sstream>

#include "../../Command.h"
#include "../../dna_code/DNA/DnaSquence.h"

class CommandNew : public Command {
private:

    static const std::string LENGTH_ERROR;
    static const std::string NAME_ERROR;
    static const std::string CREATE_DEFAULT_NAME;
    static const std::string PASS;
    static const std::string SEQUENCE_DEFAULT_NAME;

    static const int MAX_PARAMS = 3;
    static const int NAME_POSITION = 2;
    static const int SEQUENCE_TO_CREATE_POSITION = 1;

public:
    CommandNew();

    ~CommandNew();

    std::string run_command(const std::vector<std::string> &vector);

private:

    static inline std::string create_default_name();
    const inline std::string& validation(const std::vector<std::string> &vector);

    inline std::string build_return_value(unsigned int _id, const std::string &_name, const DnaSequence* const_sequence);
    inline std::string fill_sequence_name(const std::string &_afterValidation, const std::vector<std::string> &vector);

    std::string try_to_create_sequence(const std::string &_name, const std::vector<std::string> &_vector);
};


/*******************  init static variables *********************/

const std::string CommandNew::LENGTH_ERROR = "This command takes at the most 3 commands <cmd> <seq> [@<name>]";

const std::string CommandNew::NAME_ERROR = "name of sequence should start with @<name> or you "
                                           "can remove it and we will set a default one for you";

const std::string CommandNew::CREATE_DEFAULT_NAME = "default name";
const std::string CommandNew::PASS = "pass";
const std::string CommandNew::SEQUENCE_DEFAULT_NAME = "seq";
/***************************************************************/


const std::string &CommandNew::validation(const std::vector<std::string> &vector) {
    if (vector.size() > MAX_PARAMS)
        return LENGTH_ERROR;
    /*name should start with @*/
    if (vector.size() == MAX_PARAMS) {
        if (vector.at(MAX_PARAMS - 1)[0] != '@')
            return NAME_ERROR;

        /* name starts with @ */
        if (vector.at(MAX_PARAMS - 1).length() > 1)
            return PASS;

        /* name only has @ without text name */
        return NAME_ERROR;
    }
    /* default name is needed because name was not given */

    return CREATE_DEFAULT_NAME;
}


std::string CommandNew::create_default_name() {
    static unsigned int defaultNumber = 0;
    std::ostringstream s;
    s << SEQUENCE_DEFAULT_NAME << defaultNumber;
    ++defaultNumber;
    return s.str();
}

std::string CommandNew::build_return_value(unsigned int _id, const std::string &_name, const DnaSequence* const _sequence) {
    std::ostringstream s;
    s << "[" << _id << "] "
      << _name << ": " << *_sequence;
    return s.str();
}

std::string CommandNew::fill_sequence_name(const std::string &_afterValidation, const std::vector<std::string> &_vector) {
    std::string name;
    if (_afterValidation == CREATE_DEFAULT_NAME){
        name = create_default_name();
    } else {
        name = _vector.at(NAME_POSITION);
        name.erase(0, 1); /* removing the @ */
    }
    return name;
}

#endif //PROJECT_DNA_ANALYZER_COMMANDNEW_H
