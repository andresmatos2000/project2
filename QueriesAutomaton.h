//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_QUERIESAUTOMATON_H
#define PROJECT1_QUERIESAUTOMATON_H
#include "Automaton.h"

class QueriesAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
    void S7(const std::string& input);

public:
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string& input);

};

void QueriesAutomaton::S0(const std::string& input) {
    if (input[index] == 'Q') {
        inputRead++;
        index++;
        S1(input);
    } else {
        Serr();
    }
}
void QueriesAutomaton::S1(const std::string& input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::S2(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::S3(const std::string& input) {
    if (input[index] == 'r') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::S4(const std::string& input) {
    if (input[index] == 'i') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::S5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}
void QueriesAutomaton::S6(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_QUERIESAUTOMATON_H
