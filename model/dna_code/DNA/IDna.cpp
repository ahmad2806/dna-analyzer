//
// Created by ahmad on 10/01/2019.
//

#include "IDna.h"

IDna::~IDna() {

}

std::ostream &operator<<(std::ostream &os, const IDna *squence) {
    size_t i;
    size_t len = squence->size();

    for (i = 0; i < len; ++i)
        os << squence->get_dna_sequence()[i];
    return os;
}

