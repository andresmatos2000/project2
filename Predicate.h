//
// Created by munch on 7/3/2021.
//
//Holds scheme, fact and query
#ifndef PROJECT1_PREDICATE_H
#define PROJECT1_PREDICATE_H
#include "Parameter.h"
#include <vector>
#include <set>
class Predicate {
private:
    std::vector<Parameter*> parameters;
    std::string name;
    std::string getName();


public:
    std::vector<Parameter*> getParameters();
    void addParameter(Parameter* parameter);
    Predicate(std::string name){
        this->name = name;
        this->parameters = std::vector<Parameter*>();
    };

    std::string To_String();
};

std::vector<Parameter*> Predicate::getParameters() {
    return parameters;
}

void Predicate::addParameter(Parameter* parameter){
    parameters.push_back(parameter);
}
std::string Predicate::getName() {
    return name;
}
std::string Predicate::To_String(){
    std::string fullString = "(";
    for(unsigned int i = 0; i < parameters.size(); i++){
        if(i == parameters.size()-1){
            fullString += parameters[i]->To_String();
        }else {
            fullString += parameters[i]->To_String() + ",";
        }
    }
    fullString += ")";
    return this->getName() + fullString;
}

#endif //PROJECT1_PREDICATE_H
