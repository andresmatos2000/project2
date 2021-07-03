#include "Token.h"
#include <iostream>

Token::Token(TokenType type, std::string description, int line) {
    tokenType = type;
    _description = description;
    line_number = line;
}

std::string Token::tokenTypeToString(TokenType inputType) {
    switch (inputType) {
        case TokenType::COLON:
            return "COLON";
            break;
        case TokenType::COLON_DASH:
            return "COLON_DASH";
            break;
        case TokenType::QUERIES:
            return "QUERIES";
            break;
        case TokenType::COMMA:
            return "COMMA";
            break;
        case TokenType::Q_MARK:
            return "Q_MARK";
            break;
        case TokenType::PERIOD:
            return "PERIOD";
            break;
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            return "MULTIPLY";
            break;
        case TokenType::ADD:
            return "ADD";
            break;
        case TokenType::COMMENT:
            return "COMMENT";
            break;
        case TokenType::FACTS:
            return "FACTS";
            break;
        case TokenType::RULES:
            return "RULES";
            break;
        case TokenType::SCHEMES:
            return "SCHEMES";
            break;
        case TokenType::ID:
            return "ID";
            break;
        case TokenType::STRING:
            return "STRING";
            break;
        case TokenType::UNDEFINED:
            return "UNDEFINED";
            break;
        case TokenType::TYPE_EOF:
            return "EOF";
            break;
        default:
            return "UNDEFINED";
            break;
    }
}

std::string Token::To_String() {
    return "(" + tokenTypeToString(tokenType) + ",\"" + _description + "\"," + std::to_string(line_number) + ")";
}
