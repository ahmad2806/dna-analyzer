//
// Created by ahmad on 14/01/2019.
//

#include "Pair.h"
#include "../../DnaSequence/DnaSquence.h"



Pair::Pair(std::tr1::shared_ptr<IDna> dna): m_dna(dna) {}

const Nucleotide Pair::operator[](int i) const {
    return (*m_dna)[i].pair();
}

size_t Pair::size() const {
    return m_dna->size();
}

Pair::~Pair() {}

