//
// Created by matteo on 04/11/21.
//

#include "CellTest.h"

void CellTest::SetUp() {
    cell = new Cell();

    sumFormula = new SumFormula();
    minFormula = new MinFormula();
    meanFormula = new MeanFormula();
    maxFormula = new MaxFormula();
}
