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

    void addCell(Cell *c);

    void removeCell(Cell *c);

    void update() override;


private:
    std::list<Cell *> cells;
};


#endif //LABPROG_SUMFORMULA_H
