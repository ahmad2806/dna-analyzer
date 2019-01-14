//
// Created by ahmad on 10/01/2019.
//

#ifndef PROJECT_DNA_ANALYZER_DNA_H
#define PROJECT_DNA_ANALYZER_DNA_H


#include "../Nucleotide/Nucleotide.h"
#include <tr1/memory>
#include <tr1/shared_ptr.h>

class IDna {

public:
    // if this is const ... we want to return a copy of that char (to not allow changes)
    virtual const Nucleotide operator[](int i) const = 0;

    virtual size_t size() const = 0;
    virtual Nucleotide *const &get_dna_sequence() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const IDna *squence);

    virtual ~IDna();
};


#endif //PROJECT_DNA_ANALYZER_DNA_H
