//
// Created by munch on 7/3/2021.
//

#ifndef PROJECT1_RULE_H
#define PROJECT1_RULE_H
#include "Predicate.h"
#include <vector>
class Rule {
private:
    Predicate* headPredicate;
public:
    std::vector<Predicate*> predicateList;
    void setHeadPredicate(Predicate* headPredicate);
    std::string getHeadPredicate();
    std::string To_String();
    void addPredicate(Predicate* predicate);
    Rule(Predicate* headPredicate){
        this->headPredicate = headPredicate;
    }
};

void Rule::setHeadPredicate(Predicate* headPredicate) {
    this->headPredicate = headPredicate;
}

void Rule::addPredicate(Predicate* predicate) {
    predicateList.push_back(predicate);
}

std::string Rule::getHeadPredicate(){
    return this->headPredicate->To_String();
}
//std::string Rule::To_String(){
//    std::string fullString = this->getHeadPredicate();
//    for (unsigned int i = 0; i < predicateList.size(); ++i) {
//        return fullString += predicateList[i]->To_String()+  " ";
//    }
//}
#endif //PROJECT1_RULE_H
