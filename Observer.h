//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_OBSERVER_H
#define LABPROG_OBSERVER_H

class Observer {
public:
    ~Observer() = default;

    virtual void update() = 0;

    float getResult() const;

protected:
    float result = 0;
};

#endif //LABPROG_OBSERVER_H
