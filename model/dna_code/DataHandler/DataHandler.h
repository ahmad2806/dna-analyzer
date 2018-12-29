//
// Created by ahmad on 29/12/2018.
//

#ifndef PROJECT_DNA_ANALYZER_DATAHANDLER_H
#define PROJECT_DNA_ANALYZER_DATAHANDLER_H


#include <sstream>
#include <map>
#include "../../dna_code/DNA/DnaSquence.h"

/******** singleton Handler ********/
class DataHandler {
public:
    static inline DataHandler* get_instance();
    static inline void reset_instance();


    std::string try_to_add_data(DnaSequence* _p_dna, std::string _name, unsigned int _id);


private:
    DataHandler() { }
    static DataHandler* m_pInstace;
    static std::map<std::string, DnaSequence*> s_dataHolder;

    static const std::string DATA_EXISTS;
    static const std::string DATA_WAS_ADD;

    void add_data(DnaSequence * pSequence, std::string _name, unsigned int id);

    bool check_if_data_exists(DnaSequence *pSequence, std::string _name, unsigned int id);
};
DataHandler* DataHandler::get_instance()
{
    if (!m_pInstace)
    {
        m_pInstace = new DataHandler();
    }

    return m_pInstace;
}

void DataHandler::reset_instance()     {
    if (m_pInstace)
    {
        delete m_pInstace;
        m_pInstace = 0;
    }
}



#endif //PROJECT_DNA_ANALYZER_DATAHANDLER_H
