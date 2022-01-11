//
// Created by matteo on 25/10/21.
//

#include <iostream>
#include "SumFormula.h"

SumFormula::~SumFormula() {
    for (auto itr = cells.begin(); itr != cells.end(); itr++)
        (*itr)->removeObserver(this);
}

void SumFormula::addCell(Cell *c) {
    c->addObserver(this);
    cells.push_back(c);
    update();
}

void SumFormula::removeCell(Cell *c) {
    c->removeObserver(this);
    cells.remove(c);
}

void SumFormula::update() {
    float sum = 0;
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        sum += (*itr)->getValue();
    }
    result = sum;
}
