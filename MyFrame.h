//
// Created by matteo on 10/11/21.
//

#ifndef LABPROG_MYFRAME_H
#define LABPROG_MYFRAME_H


#include "wx/wx.h"
#include "wx/grid.h"
#include "Cell.h"
#include "SumFormula.h"
#include "MinFormula.h"
#include "MaxFormula.h"
#include "MeanFormula.h"
#include <list>

class MyFrame : public wxFrame{
public:
    MyFrame(const wxString& title);
private:
    void newCell(wxGridEvent &evt);

    std::list<Cell*> cells;

    MaxFormula *maxFormula;
    MinFormula *minFormula;
    MeanFormula *meanFormula;
    SumFormula *sumFormula;

    wxGrid *grid;

    wxTextCtrl *minWriteText;
    wxTextCtrl *maxWriteText;
    wxTextCtrl *meanWriteText;
    wxTextCtrl *sumWriteText;



    wxDECLARE_EVENT_TABLE();
};


#endif //LABPROG_MYFRAME_H
