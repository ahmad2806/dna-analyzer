//
// Created by ahmad on 28/12/2018.
//

#include "CommandNew.h"


CommandNew::CommandNew() {}

CommandNew::~CommandNew() {}

std::string CommandNew::run_command(const std::vector<std::string> &vector) {

    std::string afterValidation = validation(vector);

    std::string name;
    std::string answer;

    /* checking for errors*/
    if (afterValidation == LENGTH_ERROR
        || afterValidation == NAME_ERROR) {
        return afterValidation;
    }

    /* getting the name of the sequence */
    name = fill_sequence_name(afterValidation, vector);

    /* lets create our sequence*/
    answer = try_to_create_sequence(name, vector);

    return answer;
}

std::string CommandNew::try_to_create_sequence(const std::string &_name, const std::vector<std::string> &_vector) {
    std::string answer ;
    try {
        DnaSequence* p_newDna = new DnaSequence (_vector.at(SEQUENCE_TO_CREATE_POSITION));
        static unsigned int dnaId = 1;
        answer = build_return_value(dnaId, _name, p_newDna);
        ++dnaId;

        /* add new seq with name to list
         * add(newDna, name);
         * TODO
         * */

    } catch (std::invalid_argument &msg) {
        return msg.what();
    } catch (std::bad_alloc &e) {
        throw;
    }
    return answer;

}

/*
int main (){
    CommandNew c;
    std::vector<std::string> x ;
    x.push_back("new");
    x.push_back("AGTC");
    x.push_back("@nameHHHH");
    std::cout << c.run_command(x) << std::endl;

    std::vector<std::string> y ;
    y.push_back("new");
    y.push_back("AGTC");
    std::cout << c.run_command(y) << std::endl;


    std::vector<std::string> n ;
    n.push_back("new");
    n.push_back("AGTCs");
    std::cout << c.run_command(n) << std::endl;


    return 0;
}
*/

/*
g++ -g -ansi -pedantic -std=c++98 -Wall model/dna_code/DNA/DnaSquence.cpp
 model/dna_code/Nucleotide/Nucleotide.cpp model/Commands/New/CommandNew.cpp -o a
 */