//
// Created by munch on 7/1/2021.
//

#ifndef PROJECT1_MULTIPLYAUTOMATON_H
#define PROJECT1_MULTIPLYAUTOMATON_H
#include "Automaton.h"
class MultiplyAutomaton : public Automaton
{
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};

void MultiplyAutomaton::S0(const std::string& input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_MULTIPLYAUTOMATON_H
