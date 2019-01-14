//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_DATAHANDLER_H
#define PROJECT_DNA_ANALYZER_DATAHANDLER_H


#include <sstream>
#include <map>
#include "../DNA/DnaSequence/DnaSquence.h"
#include "../../../controller/sharedPtr/SharedPtr.h"

/******** singleton Handler ********/
class DataHandler {

public:

    static inline DataHandler *get_instance();

    static inline void reset_instance();

    static std::map<std::string, DnaSequence *> s_dataHolder;
    static std::map<std::string, std::string> s_key_name_value_id;
    static std::map<std::string, std::string> s_key_id_value_name;

    static const std::string DATA_EXISTS;
    static const std::string DATA_NOT_EXISTS;
    static const std::string DATA_WAS_ADD;

    std::string try_to_add_data(DnaSequence *_p_dna, std::string _name, std::string _id);

    std::pair<std::string, DnaSequence *> find_by_name(std::string name);

    std::pair<std::string, DnaSequence *> find_by_id(std::string basic_string);

private:


    DataHandler() {}

    static DataHandler *m_pInstace;

    void add_data(DnaSequence *pSequence, std::string _name, std::string id);

    bool check_if_data_exists(std::string name);

    std::pair<std::string, DnaSequence *> fetch_data_and_return(std::string id, std::string name);
};

DataHandler *DataHandler::get_instance() {
    if (!m_pInstace) {
        m_pInstace = new DataHandler();
    }

    return m_pInstace;
}

void DataHandler::reset_instance() {
    if (m_pInstace) {
        delete m_pInstace;
        m_pInstace = 0;
    }
}


#endif //PROJECT_DNA_ANALYZER_DATAHANDLER_H
