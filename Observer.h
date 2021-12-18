//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_OBSERVER_H
#define LABPROG_OBSERVER_H

class Observer {
public:

    virtual void update() = 0;

    float getResult();

    virtual float formula() = 0;

protected:
    float result = 0;
};

#endif //LABPROG_OBSERVER_H
