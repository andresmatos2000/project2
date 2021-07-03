//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_EOFAUTOMATON_H
#define PROJECT1_EOFAUTOMATON_H
#include "Automaton.h"
class EOFAutomaton : public Automaton
{
public:
    EOFAutomaton() : Automaton(TokenType::TYPE_EOF) {}  // Call the base constructor

    void S0(const std::string& input);
};

void EOFAutomaton::S0(const std::string& input) {
    if(inputRead == input.size()){
        inputRead++;
    }
}
#endif //PROJECT1_EOFAUTOMATON_H
