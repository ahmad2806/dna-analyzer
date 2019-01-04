//
// Created by ahmad on 28/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDNEW_H
#define PROJECT_DNA_ANALYZER_COMMANDNEW_H

#include <iostream>
#include <sstream>

#include "../../dna_code/DataHandler/DataHandler.h"

#include "../../../controller/sharedPtr/SharedPtr.h"
#include "../DataAccessPermissionCommands.h"


class CommandNew : public DataAccessPermissionCommands {
private:

    static const std::string LENGTH_ERROR;
    static const std::string NAME_ERROR;
    static const std::string CREATE_DEFAULT_NAME;
    static const std::string PASS;
    static const std::string SEQUENCE_DEFAULT_NAME;

    static const int MAX_PARAMS = 3;
    static const int NAME_POSITION = 2;
    static const int SEQUENCE_TO_CREATE_POSITION = 1;
    static DataHandler * p_data_handler;

public:
    CommandNew();

    ~CommandNew();

    std::string run_command(const std::vector<std::string> &vector);
private:

    static inline std::string create_default_name();
    const inline std::string& validation(const std::vector<std::string> &vector);

    inline std::string fill_sequence_name(const std::string &_afterValidation, const std::vector<std::string> &vector);

    std::string try_to_create_sequence(const std::string &_name, const std::vector<std::string> &_vector);
};




const std::string &CommandNew::validation(const std::vector<std::string> &vector) {

    if ((vector.size() > MAX_PARAMS)
        || (vector.size()  <= 1))
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


std::string CommandNew::fill_sequence_name(const std::string &_afterValidation, const std::vector<std::string> &_vector) {
    std::string name;
    if (_afterValidation == CREATE_DEFAULT_NAME){
        name = create_default_name();
    } else {
        name = _vector.at(NAME_POSITION);
    }
    return name;
}

#endif //PROJECT_DNA_ANALYZER_COMMANDNEW_H
