//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_MEANFORMULA_H
#define LABPROG_MEANFORMULA_H

#include "Cell.h"

class MeanFormula : public Observer {
public:
    MeanFormula() {}

    ~MeanFormula();

    void addCell(Cell *c);

    void removeCell(Cell *c);

    void update() override;

private:
    std::list<Cell *> cells;
};


#endif //LABPROG_MEANFORMULA_H
