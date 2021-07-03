//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_STRINGAUTOMATON_H
#define PROJECT1_STRINGAUTOMATON_H
#include "Automaton.h"
class StringAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
};


void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    } else {
        Serr();
    }
}
void StringAutomaton::S1(const std::string& input) {
    if(input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S1(input);
    } else if(input[index] == '\''){
            inputRead++;
            index++;
            S2(input);
    } else if(unsigned(inputRead) > input.size()){
        type = TokenType::UNDEFINED;
        //std::cout << "ERR";
    } else {
        inputRead++;
        index++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string& input) {
    if(input[index] == '\''){
        index++;
        inputRead++;
        S1(input);
    }
}

#endif //PROJECT1_STRINGAUTOMATON_H
