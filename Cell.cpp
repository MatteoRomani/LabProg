//
// Created by matteo on 25/10/21.
//

#include "Cell.h"

void Cell::addObserver(Observer *o) {
    if(!isObserver(o))
        observers.push_back(o);
}
void Cell::removeObserver(Observer *o) {
    observers.remove(o);
}
void Cell::notify() {
    for(auto itr=observers.begin(); itr != observers.end(); itr++)
        (*itr)->update();
}

bool Cell::isObserver(Observer *o) {
    for(auto itr = observers.begin(); itr != observers.end(); itr++){
        if((*itr) == o){
            return true;
        }
    }
    return false;
}

float Cell::getValue() const {
    return value;
}

void Cell::setValue(float value) {
    Cell::value = value;
    notify();
}

int Cell::observersSize() const {
    return observers.size();
}