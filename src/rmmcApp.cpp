/***************************************************************
 * Name:      rmmcApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Pt_Djefferson ()
 * Created:   2013-07-04
 * Copyright: Pt_Djefferson ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "rmmcApp.h"

//(*AppHeaders
#include "rmmcMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(rmmcApp);

bool rmmcApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	rmmcFrame* Frame = new rmmcFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
/*
bool rmmcApp::OnExceptionInMainLoop() {
    try
    {
        throw;
    }
    catch ( std::exception& e )
    {
        wxLogWarning(wxT("Caught MyException(%s) in MyApp."), e.what());
        wxMessageBox(e.what(), _("Welcome to..."));
    }
    catch ( ... )
    {
        wxMessageBox(_("Ошибка"), _("Welcome to..."));
        //throw;
    }

    return true;
}
*/
