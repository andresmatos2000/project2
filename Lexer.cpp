#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "QueriesAutomaton.h"
#include "CommentAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "PeriodAutomaton.h"
#include "CommaAutomaton.h"
#include "QMarkAutomaton.h"
#include "FactsAutomaton.h"
#include "SchemesAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "RulesAutomaton.h"
#include "Undefined.h"
#include <cctype>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for (auto p : automata){
        delete p;
    }
    automata.clear();
    for( auto p: tokens){
        delete p;
    } tokens.clear();
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new UndefinedAutomaton());

}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        maxRead = 0;
        Automaton* maxAutomaton = automata[0];
        bool whiteSpace = true;
        while(whiteSpace){
            char frontChar = input.front();
            if(isspace(frontChar)){
                if(frontChar == '\n'){
                    ++lineNumber;
                }
                whiteSpace = true;
                input.erase(0,1);
            }
            else{
                whiteSpace = false;
            }
        };
        if(input.empty()){
            break;
        }
        for(Automaton* automaton : automata) {
                inputRead = automaton->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automaton;
                };
        };

        // Here is the "Max" part of the algorithm
        if(maxRead > 0){
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead),lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                if(newToken->tokenTypeToString(newToken->getType()) != "COMMENT") //REMOVE ALL COMMENTS FROM TOKENS
                tokens.push_back(newToken);
        } else if( maxRead == -1){
            tokens.push_back(new Token(TokenType::UNDEFINED,input,lineNumber));
            maxRead = input.size();
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            maxRead = 1;
            tokens.push_back(new Token(TokenType::UNDEFINED,input.substr(0,maxRead),lineNumber));
        };
        input.erase(0,maxRead);
        // Update `input` by removing characters read to create Token
        //remove maxRead characters from input
    };
    tokens.push_back(new Token(TokenType::TYPE_EOF,input.substr(0,maxRead),lineNumber));
};

std::vector<Token*> Lexer::getTokens(){
    return tokens;
}