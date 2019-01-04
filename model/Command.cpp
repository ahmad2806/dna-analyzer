//
// Created by ahmad on 30/12/2018.
//

#include "Command.h"

DataHandler *Command::p_data_handler = DataHandler::get_instance();

std::string Command::build_return_value(std::string _id, std::string _name, const DnaSequence *const _sequence,
                                        unsigned int _accuracy) {
    std::ostringstream s;
    s << "[" << _id << "] ";

    _name.erase(0, 1); /* removing the @ */

    s << _name << ": ";

    unsigned int i;
    std::string str;

    /* if _accuracy is bigger than unsigned int, then we got error because it enters to the loop !! */
    if (_sequence->getlength() > DEFAULT_ACCURACY || _sequence->getlength() > _accuracy) {

        for (i = 0; i < _accuracy - DEFAULT_OFFSET; ++i) {

            str += _sequence->operator[](i);
        }

        unsigned int len = _sequence->getlength();
        s << str
          << "..."
          << _sequence->operator[](len - 3)
          << _sequence->operator[](len - 2)
          << _sequence->operator[](len - 1);

    } else
        s << *_sequence;


    return s.str();
}

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

