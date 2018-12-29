//
// Created by ahmad on 28/10/2018.
//

#include <stdexcept>
#include "Nucleotide.h"

Nucleotide::Nucleotide() {}

Nucleotide::Nucleotide(char nucle) {
    *this = nucle;
}

Nucleotide &Nucleotide::operator=(const Nucleotide &other) {
    m_nucleotide = other.m_nucleotide;
    return *this;

}
//return char & so we can create a chain n1 = n2 = 'G'

Nucleotide &Nucleotide::operator=(const char my_char) {
    try {
        check_validate(my_char);

    } catch (std::invalid_argument &msg) {
//        std::cout << msg.what() << std::endl;
        throw;
    }
    m_nucleotide = my_char;
    return *this;
}

bool Nucleotide::check_validate(const char c) {
    if (c == 'A' ||
        c == 'G' ||
        c == 'C' ||
        c == 'T'
            )
        return true;
    throw std::invalid_argument("invalid Nucleotide please try again");
}

std::string &operator+=(std::string &my_str, const Nucleotide &nuc) {
    return my_str += nuc.get_nucleotide();
}