//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_LEFTPARENAUTOMATON_H
#define PROJECT1_LEFTPARENAUTOMATON_H

#include "Automaton.h"
class LeftParenAutomaton : public Automaton
{
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

void LeftParenAutomaton::S0(const std::string& input) {
    if (input[index] == '(') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_LEFTPARENAUTOMATON_H
