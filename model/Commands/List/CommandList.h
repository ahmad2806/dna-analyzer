//
// Created by ahmad on 04/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_LIST_H
#define PROJECT_DNA_ANALYZER_LIST_H


#include "../../Command.h"

class CommandList : public Command {
public:
    std::string run_command(const std::vector<std::string> &vector);

    inline std::string validate_input(const std::vector<std::string> &vector);

    static const std::string INVALID_INPUT;
    static const std::string PASS;
    static const std::string LIST_IS_EMPTY;
private:

    inline std::string get_dna_details_as_string(std::string _id, std::tr1::shared_ptr<IDna> _p_dna);
};

std::string CommandList::validate_input(const std::vector<std::string> &vector) {
    if (vector.size() != 1)
        return INVALID_INPUT;
    return PASS;
}


std::string CommandList::get_dna_details_as_string(std::string _id, std::tr1::shared_ptr<IDna> _p_dna) {

    return build_return_value(_id, p_data_handler->s_key_id_value_name[_id], _p_dna, DEFAULT_ACCURACY);
}

#endif //PROJECT_DNA_ANALYZER_LIST_H
