//
// Created by matteo on 25/10/21.
//

#ifndef LABPROG_MAXFORMULA_H
#define LABPROG_MAXFORMULA_H

#include "Cell.h"

class MaxFormula : public Observer {
public:
    MaxFormula() = default;

    ~MaxFormula();

    void addCell(Cell *c);

    void removeCell(Cell *c);

    void update() override;



private:
    std::list<Cell *> cells;
};


#endif //LABPROG_MAXFORMULA_H
