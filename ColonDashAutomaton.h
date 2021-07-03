#ifndef COLONDASHAUTOMATON_H
#define COLONDASHAUTOMATON_H

#include "Automaton.h"

class ColonDashAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    ColonDashAutomaton() : Automaton(TokenType::COLON_DASH) {}  // Call the base constructor

    void S0(const std::string& input);
};

void ColonDashAutomaton::S0(const std::string& input) {
    if (input[index] == ':') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void ColonDashAutomaton::S1(const std::string& input) {
    if (input[index] == '-') {
        inputRead++;
    }
    else {
        Serr();
    }
}

#endif // COLONDASHAUTOMATON_H

