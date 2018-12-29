//
// Created by ahmad on 29/12/2018.
//

#include "DataHandler.h"

DataHandler* DataHandler::m_pInstace = 0;
std::map<std::string,DnaSequence *> DataHandler::s_dataHolder;

const std::string DataHandler::DATA_EXISTS = "this sequence is already exists, for your safety wont and it again";
const std::string DataHandler::DATA_WAS_ADD = "data was added successfully boss";

std::string DataHandler::try_to_add_data( DnaSequence * _p_dna, std::string _name, unsigned int _id) {
    bool exists = check_if_data_exists(_p_dna, _name, _id);
    if (exists)
        return DATA_EXISTS;
    add_data(_p_dna, _name, _id);
    return DATA_WAS_ADD;
}

bool DataHandler::check_if_data_exists(DnaSequence *pSequence, std::string _name, unsigned int id) {
    if (s_dataHolder.find(_name) == s_dataHolder.end()) {
        std::stringstream s;
        s << id;
        if (s_dataHolder.find(s.str()) == s_dataHolder.end()){
            return false;
        }
    }
    return true;
}
void DataHandler::add_data(DnaSequence * pSequence, std::string _name, unsigned int _id) {
    std::ostringstream s;
    s << _id;
    s_dataHolder[_name] = pSequence;
    s_dataHolder[s.str()] = pSequence;
}

/*
 * g++ -Wall -ansi -pedantic -std=c++98 model/dna_code/DataHandler/DataHandler.cpp
 * model/dna_code/DNA/DnaSquence.cpp model/dna_code/Nucleotide/Nucleotide.cpp -o a

 * */