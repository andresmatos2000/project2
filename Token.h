#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    TYPE_EOF
};

class Token {
private:
    std::string _description;
    int line_number;
    TokenType tokenType;

public:
    Token(TokenType type, std::string description, int line);

    std::string tokenTypeToString(TokenType inputType);
    std::string getDescription();
    std::string To_String();
    TokenType getType();
};
#endif // TOKEN_H

