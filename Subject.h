//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_SUBJECT_H
#define LABPROG_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    ~Subject() = default;

    virtual void addObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify() = 0;
};


#endif //LABPROG_SUBJECT_H
