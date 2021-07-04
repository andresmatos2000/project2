//
// Created by munch on 7/3/2021.
//

#ifndef PROJECT1_PARAMETER_H
#define PROJECT1_PARAMETER_H
#include "Token.h"

class Parameter {
private:
        std::string value;
        TokenType tokenType;
        TokenType getToken();


public:
    std::string getValue();
    std::string To_String();
    Parameter(TokenType tokenType, std::string value){
        this->value = value;
        this->tokenType = tokenType;
    }


};

TokenType Parameter::getToken() {
    return tokenType;
}
std::string Parameter::getValue() {
    return value;
}

std::string Parameter::To_String(){
    return getValue();
}
#endif //PROJECT1_PARAMETER_H
