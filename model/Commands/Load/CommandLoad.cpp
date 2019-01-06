//
// Created by ahmad on 05/01/2019.
//

#include "CommandLoad.h"

const std::string CommandLoad::INVALID_INPUT = "This command takes 2 arguments load <file_name> [@<sequence_name>]";
const std::string CommandLoad::PASS = "PASS";
const std::string CommandLoad::FILE_SUFFIX = ".rawdna";

Dna_reader *CommandLoad::p_dna_reader;

CommandLoad::CommandLoad() : haveNoName(1) {}

std::string CommandLoad::run_command(const std::vector<std::string> &vector) {
    std::string validation = validate_input(vector);
    if (validation == INVALID_INPUT)
        return validation;
    return try_to_load_sequence(vector);

}




std::string CommandLoad::try_to_load_sequence(const std::vector<std::string> &vector) {
    std::vector<std::string> my_seq = p_dna_reader->read_from_file(vector[1].c_str());
    if (my_seq.empty())
        return INVALID_INPUT;
    return add_sequence_to_data(my_seq, vector);
}

std::string
CommandLoad::add_sequence_to_data(std::vector<std::string> _dnaVector, const std::vector<std::string> &_inputVector) {
    std::string name;
    if (haveNoName) {
        name = get_name_from(_inputVector[1]);
    } else {
        name = _inputVector[2];
    }

    CommandNew createNew;
    return createNew.try_to_create_sequence(name, _dnaVector[0]);
}




