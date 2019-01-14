//
// Created by ahmad on 05/01/2019.
//

#include "Dna_writer.h"

std::string Dna_writer::write_to_file(const DnaSequence& dna_seq, const char *name) {
    std::ofstream my_file;
    my_file.open(name, std::fstream::app);
    if (my_file.is_open()) {
        size_t i;
        size_t len = dna_seq.size();
        Nucleotide * seq = dna_seq.get_dna_sequence();
        for (i = 0; i < len; ++i)
            my_file << seq[i];
        my_file << "\n";
        my_file.close();
    } else
        return "error while opening file\n";
    return "IDna was added to file successfully";
}

void Dna_writer::write_to_file(const std::vector<DnaSequence > dnas, const char *name) {
    size_t i, len = dnas.size();
    for (i = 0; i < len ; ++i)
        write_to_file(dnas[i], name);
}
