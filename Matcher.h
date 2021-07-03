//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_MATCHER_H
#define PROJECT1_MATCHER_H

#include "Automaton.h"

class Matcher : public Automaton
{
private:
    std::string toMatch;

public:
    Matcher(std::string toMatch, TokenType tokenType);
    int Start(const std::string& input) {
        bool isMatch = true;
        inputRead = 0; // member variable inherited from Automaton class
        for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
            if (input[i] != toMatch[i]) {
                isMatch = false;
            }
        }
        if (isMatch) {
            inputRead = toMatch.size();
        }
        return inputRead;
    };
    void S0(const std::string& input);
};

Matcher::Matcher(std::string toMatch, TokenType tokenType) {
    type = tokenType;
    this->toMatch = toMatch;
}
#endif //PROJECT1_MATCHER_H
