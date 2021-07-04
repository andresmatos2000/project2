//
// Created by munch on 7/3/2021.
//

#ifndef PROJECT1_DATALOGPROGRAM_H
#define PROJECT1_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"
#include <vector>
class DatalogProgram{
private:

public:
    std::vector<Predicate*> Schemes;
    std::vector<Predicate*> Facts;
    std::vector<Rule*> Rules;
    std::vector<Predicate*> Queries;
    void addScheme(Predicate* schemes);
    void addFact(Predicate* facts);
    void addQuery(Predicate* queries);
    void addRule(Rule* rule);
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
#endif //PROJECT1_DATALOGPROGRAM_H
