//
// Created by matteo on 04/11/21.
//

#include "CellTest.h"

void CellTest::SetUp() {
    cells = new Cell[4];
    cells[0] = Cell();
    cells[1] = Cell();
    cells[2] = Cell();
    cells[3] = Cell();

    sumFormula = new SumFormula();
    minFormula = new MinFormula();
    meanFormula = new MeanFormula();
    maxFormula = new MaxFormula();

    for (int i = 0; i < 4; i++) {
        cells[i].addObserver(sumFormula);
        cells[i].addObserver(maxFormula);
        cells[i].addObserver(minFormula);
        cells[i].addObserver(meanFormula);

        sumFormula->addCell(&cells[i]);
        minFormula->addCell(&cells[i]);
        maxFormula->addCell(&cells[i]);
        meanFormula->addCell(&cells[i]);
    }
}
