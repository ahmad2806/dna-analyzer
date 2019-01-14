//
// Created by ahmad on 14/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_PAIR_H
#define PROJECT_DNA_ANALYZER_PAIR_H

#include "../../IDna.h"
#include <tr1/memory>
#include <tr1/shared_ptr.h>

class Pair:public  IDna {
    std::tr1::shared_ptr<IDna> m_dna;
public:
    Pair(std::tr1::shared_ptr<IDna> dna);
    const Nucleotide operator[](int i) const;// if this is const ... we want to return a copy of that char (to not allow changes)
    size_t size() const ;
    ~Pair();
};


#endif //PROJECT_DNA_ANALYZER_PAIR_H
