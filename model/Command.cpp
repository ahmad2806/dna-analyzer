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
    if (_sequence->size() > DEFAULT_ACCURACY || _sequence->size() > _accuracy) {

        for (i = 0; i < _accuracy - DEFAULT_OFFSET; ++i) {

            str += _sequence->operator[](i);
        }

        unsigned int len = _sequence->size();
        s << str
          << "..."
          << _sequence->operator[](len - 3)
          << _sequence->operator[](len - 2)
          << _sequence->operator[](len - 1);

    } else
        s << *_sequence;


    return s.str();
}

Command::Command() :haveAccuracy(0){

}

