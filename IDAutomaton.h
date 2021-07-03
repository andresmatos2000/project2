//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_IDAUTOMATON_H
#define PROJECT1_IDAUTOMATON_H
#include "Automaton.h"
#include <cctype>
class IDAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
};


void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    } else {
        Serr();
    }
}
void IDAutomaton::S1(const std::string& input) {
    while(isalpha(input[index]) || isdigit(input[index])){
        inputRead++;
        index++;
    };
}
#endif //PROJECT1_IDAUTOMATON_H
