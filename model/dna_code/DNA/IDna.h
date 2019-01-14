//
// Created by ahmad on 10/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_DNA_H
#define PROJECT_DNA_ANALYZER_DNA_H


#include "../Nucleotide/Nucleotide.h"

class IDna {

public:
    // if this is const ... we want to return a copy of that char (to not allow changes)
    virtual const Nucleotide operator[](int i) const = 0;

    virtual size_t size() const = 0;

    virtual ~IDna();
};


#endif //PROJECT_DNA_ANALYZER_DNA_H
