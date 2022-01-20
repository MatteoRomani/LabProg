//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_CELL_H
#define LABPROG_CELL_H


#include <list>
#include "Subject.h"
#include "Observer.h"

class Cell : public Subject {
public:
    explicit Cell(float value = 0) : value(value) {}

    ~Cell() = default;

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;


    float getValue() const;

    void setValue(float value);

private:
    float value;
    std::list<Observer*> observers;

};


#endif //LABPROG_CELL_H
