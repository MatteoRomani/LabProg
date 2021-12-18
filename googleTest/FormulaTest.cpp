//
// Created by matteo on 04/11/21.
//

#include "FormulaTest.h"

void FormulaTest::SetUp() {
    cells = new Cell[4];
    cells[0] = Cell(15.1);
    cells[1] = Cell(19.9);
    cells[2] = Cell(57.1);
    cells[3] = Cell(1.26);

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