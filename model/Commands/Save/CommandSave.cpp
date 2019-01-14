//
// Created by ahmad on 04/01/2019.
//

#include "CommandSave.h"

DataHandler *CommandSave::p_data_handler = DataHandler::get_instance();
Dna_writer *CommandSave::p_dna_writer;

const std::string CommandSave::FILE_SUFFIX = ".rawdna";
const std::string CommandSave::INVALID_INPUT = "This command takes 2 arguments save <@seqNum> | <#seqNumber> [<filename>]";
const std::string CommandSave::PASS = "PASS";

CommandSave::CommandSave() {
    haveName = 0;
    haveId = 0;
}

std::string CommandSave::run_command(const std::vector<std::string> &vector) {
    std::string validation = validate_input(vector);
    if (validation == INVALID_INPUT)
        return validation;
    return try_to_get_sequence_and_save(vector);

}



std::string CommandSave::try_to_get_sequence_and_save(const std::vector<std::string> &vector) {

    std::pair<std::string, std::tr1::shared_ptr<IDna> > answer;
    if (haveName)
        answer = p_data_handler->find_by_name(vector[1]);
    else if (haveId)
        answer = p_data_handler->find_by_id(vector[1]);
    else
        return INVALID_INPUT;

    return try_to_save(answer, vector);
}

std::string
CommandSave::try_to_save(std::pair<std::string, std::tr1::shared_ptr<IDna> > pair, const std::vector<std::string> &vector) {
    std::string seqName = get_name_and_id_from(pair.first)[1];
    std::string fileName;
    if (vector.size() == 2) {
        seqName.erase(0, 1);
        fileName = seqName;
    } else {
        fileName = vector[2];
    }
    std::stringstream s;
    s << fileName << FILE_SUFFIX;
    return p_dna_writer->write_to_file(pair.second, s.str().c_str());
}
