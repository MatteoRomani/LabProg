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
    cells.push_back(c);
}

void SumFormula::removeCell(Cell *c) {
    cells.remove(c);
}

void SumFormula::update() {
    formula();
}

float SumFormula::formula() {
    float sum = 0;
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        sum += (*itr)->getValue();
    }
    result = sum;
    return sum;
}