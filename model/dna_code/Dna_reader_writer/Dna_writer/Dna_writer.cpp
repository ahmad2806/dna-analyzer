//
// Created by ahmad on 05/01/2019.
//

#include "Dna_writer.h"
const std::string Dna_writer::FILE_EXISTS = "file is already exists and has data, wont overwrite it\n\tSORRY !";
void Dna_writer::write_to_file(std::vector<std::tr1::shared_ptr<IDna> > dnas, const char *name) {
    size_t i, len = dnas.size();
    for (i = 0; i < len ; ++i)
        write_to_file(dnas[i], name);
}

std::string Dna_writer::write_to_file(std::tr1::shared_ptr<IDna> dna_seq, const char *name) {
    std::ofstream my_file;
    std::ifstream f(name);

    if (f.good())
        return FILE_EXISTS;
    my_file.open(name, std::fstream::app);
    if (my_file.is_open()) {
        size_t i;
        size_t len = dna_seq.get()->size();
        Nucleotide * seq = dna_seq.get()->get_dna_sequence();
        for (i = 0; i < len; ++i)
            my_file << seq[i];
        my_file << "\n";
        my_file.close();
    } else
        return "error while opening file\n";
    return "IDna was added to file successfully";

}
