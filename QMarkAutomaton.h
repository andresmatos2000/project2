//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_QMARKAUTOMATON_H
#define PROJECT1_QMARKAUTOMATON_H
#include "Automaton.h"
class QMarkAutomaton : public Automaton
{
public:
    QMarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};

void QMarkAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_QMARKAUTOMATON_H
