//
// Created by munch on 7/3/2021.
//

#ifndef PROJECT1_DATALOGPROGRAM_H
#define PROJECT1_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"
#include <vector>
#include <set>
class DatalogProgram{
private:

public:
    std::vector<Predicate*> Schemes;
    std::vector<Predicate*> Facts;
    std::vector<Rule*> Rules;
    std::vector<Predicate*> Queries;
    std::set<std::string> Domain;
    void addScheme(Predicate* schemes);
    void addFact(Predicate* facts);
    void addQuery(Predicate* queries);
    void addRule(Rule* rule);
    std::string To_String();
    void parseDomain(std::vector<Parameter*>domain);
    void parseHelper();
    DatalogProgram(){
        std::vector<Predicate*> Schemes;
        std::vector<Predicate*> Facts;
        std::vector<Rule*> Rules;
        std::vector<Predicate*> Queries;
    };
    ~DatalogProgram(){
        for (auto p : Schemes){
            delete p;
        }
        Schemes.clear();
        for( auto p: Facts){
            delete p;
        } Facts.clear();
        for( auto p: Rules){
            delete p;
        } Rules.clear();
        for( auto p: Queries){
            delete p;
        } Queries.clear();
    }
};
void DatalogProgram::addScheme(Predicate* schemes) {
    Schemes.push_back(schemes);
}
void DatalogProgram::addFact(Predicate* facts) {
    Facts.push_back(facts);
}
void DatalogProgram::addQuery(Predicate* queries) {
    Queries.push_back(queries);
}
void DatalogProgram::addRule(Rule* rule){
    Rules.push_back(rule);
}
void DatalogProgram::parseHelper(){
    for (unsigned int i = 0; i < Facts.size(); ++i) {
        parseDomain(Facts[i]->getParameters());
    }
};
void DatalogProgram::parseDomain(std::vector<Parameter*>domain){
    for (int i = 0; i < domain.size(); ++i) {
        Domain.insert(domain[i]->getValue());
    }
};

std::string DatalogProgram::To_String(){
    std::string fullString;
    if(!Schemes.empty()){
        fullString += "Schemes(" + std::to_string(Schemes.size()) + ")"+":\n";
        for (unsigned int i = 0; i < Schemes.size(); ++i) {
            fullString += "  " + Schemes[i]->To_String() + "\n";
        }
    }
    if(!Facts.empty()){
        fullString += "Facts(" + std::to_string(Facts.size()) + ")"+":\n";
        for (unsigned int i = 0; i < Facts.size(); ++i) {
            fullString += "  " + Facts[i]->To_String() + ".\n";
        }
    }
    if(!Rules.empty()){
        fullString += "Rules(" + std::to_string(Rules.size()) + ")"+":\n";
        for (unsigned int i = 0; i < Rules.size(); ++i) {
            fullString += "  " + Rules[i]->To_String() + ".\n";
        }
    }
    if(!Queries.empty()){
        fullString += "Queries(" + std::to_string(Queries.size()) + ")"+":\n";
        for (unsigned int i = 0; i < Queries.size(); ++i) {
            fullString += "  " + Queries[i]->To_String() + "?\n";
        }
    }
    if(!Domain.empty()){
        fullString += "Domain(" + std::to_string(Domain.size()) + ")"+":\n";
        for(auto f : Domain){
            fullString += "  " + f + "\n";
        }
    }

    return fullString;
}
#endif //PROJECT1_DATALOGPROGRAM_H
