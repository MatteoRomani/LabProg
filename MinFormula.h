//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_MINFORMULA_H
#define LABPROG_MINFORMULA_H


#include <list>
#include "Observer.h"
#include "Cell.h"

class MinFormula : public Observer {
public:
    MinFormula() {}

    ~MinFormula();

    virtual void addCell(Cell *c);

    virtual void removeCell(Cell *c);

    virtual void update() override;

    virtual float formula() override;

private:
    std::list<Cell *> cells;
};


#endif //LABPROG_MINFORMULA_H
