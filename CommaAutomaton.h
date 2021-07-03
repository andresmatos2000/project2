//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_COMMAAUTOMATON_H
#define PROJECT1_COMMAAUTOMATON_H
#include "Automaton.h"
class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};

void CommaAutomaton::S0(const std::string& input) {
    if (input[index] == ',') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_COMMAAUTOMATON_H
