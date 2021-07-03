//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_SCHEMESAUTOMATON_H
#define PROJECT1_SCHEMESAUTOMATON_H
#include "Automaton.h"
class SchemesAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);

public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input);

};

void SchemesAutomaton::S0(const std::string& input) {
    if (input[index] == 'S') {
        inputRead++;
        index++;
        S1(input);
    } else {
        Serr();
    }
}
void SchemesAutomaton::S1(const std::string& input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S2(const std::string& input) {
    if (input[index] == 'h') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S3(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S4(const std::string& input) {
    if (input[index] == 'm') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}
void SchemesAutomaton::S6(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}
#endif //PROJECT1_SCHEMESAUTOMATON_H
