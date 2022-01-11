//
// Created by matteo on 25/10/21.
//

#include "MinFormula.h"


MinFormula::~MinFormula() {
    for (auto itr = cells.begin(); itr != cells.end(); itr++)
        (*itr)->removeObserver(this);
}

void MinFormula::addCell(Cell *c) {
    c->addObserver(this);
    cells.push_back(c);
    update();
}

void MinFormula::removeCell(Cell *c) {
    c->removeObserver(this);
    cells.remove(c);
}

void MinFormula::update() {
    if (cells.size() == 0)
        return;
    auto min = cells.begin();
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        if ((*min)->getValue() > (*itr)->getValue())
            min = itr;
    }
    result = (*min)->getValue();
}

