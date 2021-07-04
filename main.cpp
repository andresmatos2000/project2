#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <fstream>

using namespace std;
std::string readCodeIn(char** argv){
    //cout << argv[1];
    ifstream in;
    in.open(argv[1]);
    std::string fullString;
    std::string line;
    while(getline(in,line)) {
        fullString += line + "\n";
    }
    in.close();
    return fullString;
}

int main(int argc, char** argv) {

    std::string fullString = readCodeIn(argv);
    Lexer* lexer = new Lexer();
    lexer->Run(fullString);
    std::vector<Token*> tokenList = lexer->getTokens();
    for(unsigned int i = 0; i < tokenList.size(); i++){
        //cout << tokenList[i]->To_String() << endl;
    }
    //cout << "Total Tokens = " + to_string(tokenList.size());
    Parser* parser = new Parser(tokenList);
    delete parser;
    delete lexer;

    return 0;
}

