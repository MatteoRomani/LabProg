//
// Created by matteo on 08/11/21.
//

#include "MyApp.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    frame = new MyFrame("ProvaGrid");
    frame->SetSizeHints(800, 570,800, 570);
    frame->Show();
    return true;
}