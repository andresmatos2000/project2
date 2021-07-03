//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_PERIODAUTOMATON_H
#define PROJECT1_PERIODAUTOMATON_H
#include "Automaton.h"
class PeriodAutomaton : public Automaton
{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};

void PeriodAutomaton::S0(const std::string& input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_PERIODAUTOMATON_H
