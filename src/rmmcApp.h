/***************************************************************
 * Name:      rmmcApp.h
 * Purpose:   Defines Application Class
 * Author:    Pt_Djefferson ()
 * Created:   2013-07-04
 * Copyright: Pt_Djefferson ()
 * License:
 **************************************************************/

#ifndef rmmcAPP_H
#define rmmcAPP_H

#include <wx/app.h>

class rmmcApp : public wxApp
{
    public:
        virtual bool OnInit();
        //virtual bool OnExceptionInMainLoop();
        //virtual void OnUnhandledException() {};
        //virtual void OnFatalException() {};
};

#endif // rmmcAPP_H
