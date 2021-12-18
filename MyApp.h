//
// Created by matteo on 08/11/21.
//

#ifndef LABPROG_MYAPP_H
#define LABPROG_MYAPP_H

#include <wx/wx.h>
#include "MyFrame.h"

class MyApp : public wxApp {
public:
    bool OnInit()override;
private:
    MyFrame *frame = nullptr;
};


#endif //LABPROG_MYAPP_H
