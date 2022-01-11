//
// Created by matteo on 25/10/21.
//

#include "MaxFormula.h"

MaxFormula::~MaxFormula(){
    for(auto & cell : cells){
        cell->removeObserver(this);
    }
}
void MaxFormula::addCell(Cell *c) {
    cells.push_back(c);
    update();
}
void MaxFormula::removeCell(Cell *c) {
    c->removeObserver(this);
    cells.remove(c);
}
void MaxFormula::update(){
    if (cells.empty())
        return;
    auto max = cells.begin();
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        if((*max)->getValue() < (*itr)->getValue())
            max = itr;
    }
    result = (*max)->getValue();
}
