//
// Created by munch on 6/30/2021.
//

#ifndef PROJECT1_COMMENTAUTOMATON_H
#define PROJECT1_COMMENTAUTOMATON_H
#include "Automaton.h"
class CommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string& input);
};


void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        index++;
        inputRead++;
        S1(input);
    } else {
        Serr();
    }
}
void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        //block
        index++;
        inputRead++;
        S2(input);
    } else {
        //line comment
        S3(input);
    }
}
void CommentAutomaton::S2(const std::string& input) {
    while(input[index] != '|'){
        if(input[index] == '\n'){
            newLines++;
        }
        index++;
        inputRead++;
        if(unsigned(inputRead) > input.size()){
            newLines++;
            type = TokenType::UNDEFINED;
            //std::cout << "ERR";
            break;
        }

    }
    if(input[index] == '|') {
        index++;
        inputRead++;
        S4(input);
    }
}
void CommentAutomaton::S3(const std::string& input) {
    while(input[index] != '\n'){
        index++;
        inputRead++;
    }
}
void CommentAutomaton::S4(const std::string& input) {
    if(input[index] == '#'){
        inputRead++;
    } else {
        inputRead++;
        index++;
        //std::cout << input;
        S2(input);
    }
}
#endif //PROJECT1_COMMENTAUTOMATON_H
