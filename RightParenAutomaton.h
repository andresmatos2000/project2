//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_RIGHTPARENAUTOMATON_H
#define PROJECT1_RIGHTPARENAUTOMATON_H
#include "Automaton.h"
class RightParenAutomaton : public Automaton
{
public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

void RightParenAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_RIGHTPARENAUTOMATON_H
