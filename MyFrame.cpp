//
// Created by matteo on 10/11/21.
//

#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_GRID_CELL_CHANGING(MyFrame::newCell)
wxEND_EVENT_TABLE()


MyFrame::MyFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 570)) {
    grid = new wxGrid(this, wxID_ANY,wxDefaultPosition, wxSize(483,570));

    minWriteText = new wxTextCtrl(this, wxID_ANY, "", wxPoint(575,70), wxSize(150,30),wxTE_READONLY);
    maxWriteText= new wxTextCtrl(this, wxID_ANY, "", wxPoint(575,130), wxSize(150,30),wxTE_READONLY);
    meanWriteText = new wxTextCtrl(this, wxID_ANY, "", wxPoint(575,190), wxSize(150,30),wxTE_READONLY);
    sumWriteText = new wxTextCtrl(this, wxID_ANY, "", wxPoint(575,250), wxSize(150,30),wxTE_READONLY);

    wxStaticText *minStatic = new wxStaticText(this, wxID_ANY, "Min:", wxPoint(540,75),wxSize(50,30));
    wxStaticText *maxStatic = new wxStaticText(this, wxID_ANY, "Max:", wxPoint(540,135),wxSize(50,30));
    wxStaticText *meanStatic = new wxStaticText(this, wxID_ANY, "Avg:", wxPoint(540,195),wxSize(50,30));
    wxStaticText *sumStatic = new wxStaticText(this, wxID_ANY, "Sum:", wxPoint(540,255),wxSize(50,30));
    grid->CreateGrid(20, 5);
    grid->SetGridLineColour(*wxLIGHT_GREY);

    sumFormula = new SumFormula();
    minFormula = new MinFormula();
    maxFormula = new MaxFormula();
    meanFormula = new MeanFormula();


}



void MyFrame::newCell(wxGridEvent &evt) {
    std::cout << "Vecchio valore: " << grid->GetCellValue(evt.GetRow(), evt.GetCol()) << std::endl;
    std::cout << "Valore corrente appena inserito: " << evt.GetString() << std::endl;

    if(grid->GetCellValue(evt.GetRow(),evt.GetCol()) != "") {
        std::cout << "Valore da cercare nelle celle usando *itr: "
                  << (float) wxAtof(grid->GetCellValue(evt.GetRow(), evt.GetCol())) << std::endl;
        for (auto itr = cells.begin(); itr != cells.end(); itr++) {
            if ((*itr)->getValue() == wxAtof(grid->GetCellValue(evt.GetRow(), evt.GetCol()))) {
                sumFormula->removeCell((*itr));
                minFormula->removeCell((*itr));
                maxFormula->removeCell((*itr));
                meanFormula->removeCell((*itr));

                cells.remove((*itr));
                break;
            }
        }
    }
    Cell *cell = new Cell(wxAtof(evt.GetString()));


    sumFormula->addCell(cell);
    minFormula->addCell(cell);
    maxFormula->addCell(cell);
    meanFormula->addCell(cell);

    cells.push_back(cell);

    float resSum = sumFormula->getResult();
    float resMin = minFormula->getResult();
    float resMax = maxFormula->getResult();
    float resMean = meanFormula->getResult();

    minWriteText->SetValue(wxString::Format(wxT("%f"), resMin));
    maxWriteText->SetValue(wxString::Format(wxT("%f"), resMax));
    sumWriteText->SetValue(wxString::Format(wxT("%f"), resSum));
    meanWriteText->SetValue(wxString::Format(wxT("%f"), resMean));

}

