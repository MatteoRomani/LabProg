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

    Cell *cell;
    SumFormula *sumFormula;
    MinFormula *minFormula;
    MaxFormula *maxFormula;
    MeanFormula *meanFormula;
};

TEST_F(CellTest, getSetCell) {
    ASSERT_EQ(0, cell->getValue());
    cell->setValue(12);
    ASSERT_EQ(12, cell->getValue());
}

TEST_F(CellTest, AddObserver){
    cell->addObserver(sumFormula);
    cell->addObserver(minFormula);
    cell->addObserver(meanFormula);
    cell->addObserver(maxFormula);

    sumFormula->addCell(cell);
    minFormula->addCell(cell);
    maxFormula->addCell(cell);
    meanFormula->addCell(cell);

    EXPECT_EQ(4, cell->observersSize()) << "non sono stati aggiunti correttamente gli osservatori oppure il numero è sfalsato";
    ASSERT_TRUE(cell->isObserver(sumFormula)) << "sumFormula non è stata aggiunta correttamente agli osservatori";
    ASSERT_TRUE(cell->isObserver(maxFormula)) << "maxFormula non è stata aggiunta correttamente agli osservatori";
    ASSERT_TRUE(cell->isObserver(minFormula)) << "minFormula non è stata aggiunta correttamente agli osservatori";
    ASSERT_TRUE(cell->isObserver(meanFormula)) << "meanFormula non è stata aggiunta correttamente agli osservatori";
}

TEST_F(CellTest, RemoveObsever){
    cell->addObserver(sumFormula);
    cell->addObserver(minFormula);
    cell->addObserver(meanFormula);
    cell->addObserver(maxFormula);

    cell->removeObserver(sumFormula);
    ASSERT_FALSE(cell->isObserver(sumFormula));
    ASSERT_EQ(3, cell->observersSize());
    cell->removeObserver(minFormula);
    ASSERT_FALSE(cell->isObserver(minFormula));
    ASSERT_EQ(2, cell->observersSize());
    cell->removeObserver(meanFormula);
    ASSERT_FALSE(cell->isObserver(meanFormula));
    ASSERT_EQ(1, cell->observersSize());
    cell->removeObserver(maxFormula);
    ASSERT_FALSE(cell->isObserver(maxFormula));
    ASSERT_EQ(0, cell->observersSize());
}

TEST_F(CellTest, Notify){
    cell->addObserver(sumFormula);
    cell->addObserver(minFormula);
    cell->addObserver(maxFormula);
    cell->addObserver(meanFormula);

    sumFormula->addCell(cell);
    minFormula->addCell(cell);
    maxFormula->addCell(cell);
    meanFormula->addCell(cell);

    cell->setValue(12);

    ASSERT_EQ(12, sumFormula->getResult())<<"valore non aggiornato correttamente";
    ASSERT_EQ(12, minFormula->getResult());
    ASSERT_EQ(12, maxFormula->getResult());
    ASSERT_EQ(12, meanFormula->getResult());
}

TEST_F(CellTest, DuplicateFormule){
    cell->addObserver(sumFormula);
    cell->addObserver(minFormula);
    cell->addObserver(maxFormula);
    cell->addObserver(meanFormula);

    cell->addObserver(sumFormula);
    cell->addObserver(minFormula);
    cell->addObserver(maxFormula);
    cell->addObserver(meanFormula);

    ASSERT_EQ(4, cell->observersSize()) << "Gli stessi osservatori vengono aggiunti più volte";
}


#endif //LABPROG_CELLTEST_H
