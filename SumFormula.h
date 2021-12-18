//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_SUMFORMULA_H
#define LABPROG_SUMFORMULA_H


#include <list>
#include "Observer.h"
#include "Cell.h"

class SumFormula : public Observer {
public:
    SumFormula() {}

    ~SumFormula();

    virtual void addCell(Cell *c);

    virtual void removeCell(Cell *c);

    virtual void update() override;

    virtual float formula() override;

private:
    std::list<Cell *> cells;
};


#endif //LABPROG_SUMFORMULA_H
