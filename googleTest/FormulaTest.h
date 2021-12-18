//
// Created by matteo on 04/11/21.
//

#ifndef LABPROG_FORMULATEST_H
#define LABPROG_FORMULATEST_H

#include "gtest/gtest.h"
#include "../MaxFormula.h"
#include "../MinFormula.h"
#include "../MeanFormula.h"
#include "../SumFormula.h"
#include "../Cell.h"


class FormulaTest : public ::testing::Test {
protected:
    void SetUp() override;

    Cell *cells;
    SumFormula *sumFormula;
    MaxFormula *maxFormula;
    MeanFormula *meanFormula;
    MinFormula *minFormula;

};

TEST_F(FormulaTest, SumFormula){
    sumFormula->update();
    ASSERT_FLOAT_EQ(93.36, sumFormula->getResult());
}
TEST_F(FormulaTest, MinFormula){
    minFormula->update();
    ASSERT_FLOAT_EQ(1.26, minFormula->getResult());
}
TEST_F(FormulaTest, MaxFormula){
    maxFormula->update();
    ASSERT_FLOAT_EQ(57.1, maxFormula->getResult());
}
TEST_F(FormulaTest, MeaneanFormula){
    meanFormula->update();
    float sum = 0;
    for(int i=0; i<4; i++)
        sum += cells[i].getValue();
    ASSERT_FLOAT_EQ(sum/4, meanFormula->getResult());
}

#endif //LABPROG_FORMULATEST_H
