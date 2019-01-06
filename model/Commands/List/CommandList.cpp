//
// Created by ahmad on 04/01/2019.
//

#include "CommandList.h"

const std::string CommandList::INVALID_INPUT = "This command takes only one argument no more";
const std::string CommandList::LIST_IS_EMPTY = "list is empty try to create new one using command new or load new one using load";
const std::string CommandList::PASS = "PASS";

std::string CommandList::run_command(const std::vector<std::string> &vector) {
    std::string validation = validate_input(vector);

    std::map<std::string, DnaSequence*>::iterator it;

    std::stringstream answer;

    char is_empty = 1;
    for ( it = p_data_handler->s_dataHolder.begin(); it != p_data_handler->s_dataHolder.end(); it++ ) {
            is_empty = 0;
            answer  << get_dna_details_as_string(it->first, it->second) << "\n";
    }
    if (is_empty)
        return LIST_IS_EMPTY;

    return answer.str();
}


