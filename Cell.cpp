//
// Created by matteo on 25/10/21.
//

#include "Cell.h"

void Cell::addObserver(Observer *o) {
    observers.push_back(o);
}

void Cell::removeObserver(Observer *o) {
    observers.remove(o);
}

void Cell::notify() const {
    for (auto itr = observers.begin(); itr != observers.end(); itr++)
        (*itr)->update();
}

float Cell::getValue() const {
    return value;
}

void Cell::setValue(float value) {
    Cell::value = value;
    notify();
}

