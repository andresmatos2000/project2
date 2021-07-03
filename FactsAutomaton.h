//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_FACTSAUTOMATON_H
#define PROJECT1_FACTSAUTOMATON_H
#include "Automaton.h"

class FactsAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    FactsAutomaton() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);

};

void FactsAutomaton::S0(const std::string& input) {
    if (input[index] == 'F') {
        inputRead++;
        index++;
        S1(input);
    } else {
        Serr();
    }
}
void FactsAutomaton::S1(const std::string& input) {
    if (input[index] == 'a') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::S2(const std::string& input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::S3(const std::string& input) {
    if (input[index] == 't') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::S4(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}

#endif //PROJECT1_FACTSAUTOMATON_H
