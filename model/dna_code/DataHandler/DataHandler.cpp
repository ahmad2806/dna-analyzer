//
// Created by ahmad on 29/12/2018.
//

#include "DataHandler.h"

DataHandler *DataHandler::m_pInstace = 0;
std::map<std::string, std::tr1::shared_ptr<IDna> > DataHandler::s_dataHolder;

std::map<std::string, std::string> DataHandler::s_key_name_value_id;
std::map<std::string, std::string> DataHandler::s_key_id_value_name;

const std::string DataHandler::DATA_EXISTS = "this sequence is already exists, for your safety wont and it again";
const std::string DataHandler::DATA_NOT_EXISTS = "data does not exists please try again";
const std::string DataHandler::DATA_WAS_ADD = "data was added successfully boss";

std::string DataHandler::try_to_add_data(std::tr1::shared_ptr<IDna> _p_dna, std::string _name, std::string _id) {
    bool exists = check_if_data_exists(_name);
    if (exists)
        return DATA_EXISTS;
    add_data(_p_dna, _name, _id);
    return DATA_WAS_ADD;
}

bool DataHandler::check_if_data_exists(std::string name) {

    return !(s_key_name_value_id.find(name) == s_key_name_value_id.end());
}


void DataHandler::add_data(std::tr1::shared_ptr<IDna> shared_seq, std::string _name, std::string _id) {
    s_dataHolder.insert(std::make_pair(_id, shared_seq));
//    s_dataHolder[string_id.str()] = pSequence;
    s_key_id_value_name[_id] = _name;
    s_key_name_value_id[_name] = _id;
    std::cout << s_dataHolder.size() << std::endl;
//    std::cout << *s_dataHolder[string_id.str()] << "\n" << s_key_id_value_name[string_id.str()] << "\n" << s_key_name_value_id[_name] << "\n";

}

std::pair<std::string, std::tr1::shared_ptr<IDna> > DataHandler::find_by_name(std::string name) {

    if (s_key_name_value_id.find(name) == s_key_name_value_id.end())
        throw std::invalid_argument(DATA_NOT_EXISTS);

    std::string id = s_key_name_value_id[name];

    return fetch_data_and_return(id, name);

}

std::pair<std::string, std::tr1::shared_ptr<IDna> > DataHandler::find_by_id(std::string id) {
    /*remove # from the id*/
    id.erase(0, 1);
    if (s_key_id_value_name.find(id) == s_key_id_value_name.end())
        throw std::invalid_argument(DATA_NOT_EXISTS);

    std::string name = s_key_id_value_name[id];

    return fetch_data_and_return(id, name);

}

std::pair<std::string, std::tr1::shared_ptr<IDna> > DataHandler::fetch_data_and_return(std::string id, std::string name) {

    std::stringstream s;
    s << id << " " << name;
    std::pair<std::string, std::tr1::shared_ptr<IDna> > m(std::make_pair(s.str(), s_dataHolder[id])) ;

    return m;
}

/*
 * g++ -Wall -ansi -pedantic -std=c++98 model/dna_code/DataHandler/DataHandler.cpp
 * model/dna_code/DNA/DnaSquence.cpp model/dna_code/Nucleotide/Nucleotide.cpp -o a

 * */