//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_RULESAUTOMATON_H
#define PROJECT1_RULESAUTOMATON_H
#include "Automaton.h"

class RulesAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string& input);

};

void RulesAutomaton::S0(const std::string& input) {
    if (input[index] == 'R') {
        inputRead++;
        index++;
        S1(input);
    } else {
        Serr();
    }
}
void RulesAutomaton::S1(const std::string& input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void RulesAutomaton::S2(const std::string& input) {
    if (input[index] == 'l') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void RulesAutomaton::S3(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void RulesAutomaton::S4(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_RULESAUTOMATON_H
