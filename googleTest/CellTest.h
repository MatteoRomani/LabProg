//
// Created by matteo on 04/11/21.
//

#ifndef LABPROG_CELLTEST_H
#define LABPROG_CELLTEST_H

#include "gtest/gtest.h"
#include "../SumFormula.h"
#include "../MaxFormula.h"
#include "../MeanFormula.h"
#include "../MinFormula.h"
#include "../Cell.h"

class CellTest : public ::testing::Test {
protected:
    void SetUp() override;

    Cell *cells;

    SumFormula *sumFormula;
    MinFormula *minFormula;
    MaxFormula *maxFormula;
    MeanFormula *meanFormula;
};

TEST_F(CellTest, getSetCell) {
    ASSERT_EQ(0, cells[0].getValue());
    cells[0].setValue(12);
    ASSERT_EQ(12, cells[0].getValue());
}

TEST_F(CellTest, Notify) {
    cells[0].setValue(15.6);
    cells[1].setValue(6);
    cells[2].setValue(4);
    cells[3].setValue(2);
    ASSERT_FLOAT_EQ(27.6, sumFormula->getResult());
    ASSERT_FLOAT_EQ(2, minFormula->getResult());
    ASSERT_FLOAT_EQ(15.6, maxFormula->getResult());
    ASSERT_FLOAT_EQ(6.9, meanFormula->getResult());
}

TEST_F(CellTest, RemoveObsever) {
    sumFormula->removeCell(&cells[0]);

    cells[0].setValue(15.6);
    cells[1].setValue(6);
    cells[2].setValue(4);
    cells[3].setValue(2);
    ASSERT_FLOAT_EQ(12, sumFormula->getResult());
    ASSERT_FLOAT_EQ(2, minFormula->getResult());
    ASSERT_FLOAT_EQ(15.6, maxFormula->getResult());
    ASSERT_FLOAT_EQ(6.9, meanFormula->getResult());
}


#endif //LABPROG_CELLTEST_H
