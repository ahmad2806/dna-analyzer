//
// Created by ahmad on 28/10/2018.
//

#ifndef DNA_NUCLEOTIDE_H
#define DNA_NUCLEOTIDE_H


#include <iostream>

class Nucleotide {
public:

    Nucleotide(char nucle);

    Nucleotide();

    Nucleotide &operator=(const Nucleotide &other);

    Nucleotide &operator=(const char my_char);

    inline const Nucleotide pair() const;


    bool operator==(const Nucleotide &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Nucleotide &squence);

    static bool check_validate(const char c);

    const char get_nucleotide() const {
        return m_nucleotide;
    }

private:
    char m_nucleotide;

};

std::string &operator+=(std::string &my_str, const Nucleotide &nuc);


inline std::ostream &operator<<(std::ostream &os, const Nucleotide &squence) {
    return os << squence.m_nucleotide;
}

inline bool Nucleotide::operator==(const Nucleotide &other) const {
    return this->m_nucleotide == other.m_nucleotide;
}

const Nucleotide Nucleotide::pair() const{
    std::string lets_pair;
    lets_pair = "";

    if (m_nucleotide == 'T')
        return Nucleotide('A');

    if (m_nucleotide == 'A')
        return Nucleotide('T');

    if (m_nucleotide == 'C')
        return Nucleotide('G');

    return Nucleotide('C');
}


#endif //DNA_NUCLEOTIDE_H
