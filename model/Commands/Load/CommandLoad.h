//
// Created by ahmad on 05/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_COMMANDLOAD_H
#define PROJECT_DNA_ANALYZER_COMMANDLOAD_H


#include "../../Command.h"
#include "../../dna_code/Dna_reader_writer/Dna_reader/dna_read.h"
#include "../New/CommandNew.h"

class CommandLoad : public Command {

public:

    CommandLoad();
    std::string run_command(const std::vector<std::string> &vector);

    static const std::string INVALID_INPUT;
    static const std::string PASS;

private:

    static const std::string FILE_SUFFIX;
    static Dna_reader* p_dna_reader;

    char haveNoName;

    inline std::string validate_input(const std::vector<std::string> &vector);
    inline bool name_is_legal(const std::string &basic_string);
    inline std::string get_name_from(const std::string &_oldName);

    std::string try_to_load_sequence(const std::vector<std::string> &vector);
    std::string add_sequence_to_data(std::vector<std::string> _dnaVector, const std::vector<std::string> &_inputVector);

};


std::string CommandLoad::validate_input(const std::vector<std::string> &vector) {
    if (vector.size() > 3 || vector.size() < 2)
        return INVALID_INPUT;

    if (vector.size() == 3) {
        if (name_is_legal(vector[2])) {
            haveNoName = 0;
        } else {
            return INVALID_INPUT;
        }
    }
    return PASS;

}
bool CommandLoad::name_is_legal(const std::string &name) {
    return name[0] == '@';
}
std::string CommandLoad::get_name_from(const std::string &_oldName) {
    std::stringstream s;
    s << '@' << _oldName.substr(0, _oldName.find(FILE_SUFFIX));
    return s.str();
}

#endif //PROJECT_DNA_ANALYZER_COMMANDLOAD_H
