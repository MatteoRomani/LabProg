//
// Created by matteo on 10/11/21.
//

#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_GRID_CELL_CHANGING(MyFrame::newCell)
    EVT_BUTTON(1, MyFrame::clickButton)
wxEND_EVENT_TABLE()

// Tolta la possibilità di fare resize del frame perchè i posizionamenti sono relativi, non assoluti
MyFrame::MyFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 570)) {
    grid = new wxGrid(this, wxID_ANY,wxDefaultPosition, wxSize(483,570));
    wxButton *button = new wxButton(this, 1, "Calculate", wxPoint(575,460), wxSize(150,50));

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

void MyFrame::clickButton(wxCommandEvent &evt) {
    float resSum = sumFormula->getResult();
    float resMin = minFormula->getResult();
    float resMax = maxFormula->getResult();
    float resMean = meanFormula->getResult();

    minWriteText->SetValue(wxString::Format(wxT("%f"), resMin));
    maxWriteText->SetValue(wxString::Format(wxT("%f"), resMax));
    sumWriteText->SetValue(wxString::Format(wxT("%f"), resSum));
    meanWriteText->SetValue(wxString::Format(wxT("%f"), resMean));


}

void MyFrame::newCell(wxGridEvent &evt) {
    //se la cella selezionata ha gia un valore, allora non devo aggiungere una nuova cella
    //devo cercare la cella con il valore relativo e modificarlo
    std::cout << "Vecchio valore: " << grid->GetCellValue(evt.GetRow(), evt.GetCol()) << std::endl;
    std::cout << "Valore corrente appena inserito: " << evt.GetString() << std::endl;

    if(grid->GetCellValue(evt.GetRow(),evt.GetCol()) != "") {
        for(auto itr = cells.begin(); itr != cells.end(); itr++) {
            std::cout << "Valore da cercare nelle celle usando *itr: "
                      << (float) wxAtof(grid->GetCellValue(evt.GetRow(), evt.GetCol())) << std::endl;
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
    cell->addObserver(sumFormula);
    cell->addObserver(minFormula);
    cell->addObserver(maxFormula);
    cell->addObserver(meanFormula);

    sumFormula->addCell(cell);
    minFormula->addCell(cell);
    maxFormula->addCell(cell);
    meanFormula->addCell(cell);

    cells.push_back(cell);

}

