/***************************************************************
 * Name:      rmmcMain.h
 * Purpose:   Defines Application Frame
 * Author:    Pt_Djefferson ()
 * Created:   2013-07-04
 * Copyright: Pt_Djefferson ()
 * License:
 **************************************************************/

#ifndef rmmcMAIN_H
#define rmmcMAIN_H

//(*Headers(rmmcFrame)
#include <wx/treectrl.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/bmpcbox.h>
#include <wx/imaglist.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include "radialmenuconfig.h"
#include "treectrlwithchecks.h"
//#include <wx/event.h>


class rmmcFrame: public wxFrame {
public:

	rmmcFrame(wxWindow *parent,wxWindowID id = -1);
	virtual ~rmmcFrame();
	//RadialMenuConfig *config;
	wxXmlDocument* xml_config;

private:

	//(*Handlers(rmmcFrame)
	void OnQuit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnCommandsTreeCtrlBeginDrag(wxTreeEvent &event);
	void OnButton2Click(wxCommandEvent& event);
	void OnButton3Click(wxCommandEvent& event);
	//*)

	//(*Identifiers(rmmcFrame)
	static const long ID_TREECTRL1;
	static const long ID_BITMAPCOMBOBOX1;
	static const long ID_BUTTON1;
	static const long ID_TEXTCTRL1;
	static const long ID_BUTTON2;
	static const long ID_BUTTON3;
	static const long ID_BUTTON4;
	static const long ID_BUTTON5;
	static const long ID_BUTTON6;
	static const long ID_PANEL1;
	static const long ID_MENUITEM1;
	static const long idMenuAbout;
	static const long ID_STATUSBAR1;
	static const long ID_TOOLBAR1;
	//*)
	static const long ID_NEW;

	//(*Declarations(rmmcFrame)
	wxBitmapComboBox* BitmapComboBox1;
	wxButton* Button4;
	wxButton* Button1;
	wxImageList* ImageList2;
	TreeCtrlWithChecks* CommandsTreeCtrl;
	wxPanel* Panel1;
	wxButton* Button2;
	wxButton* Button6;
	wxButton* Button5;
	wxButton* Button3;
	wxStatusBar* StatusBar1;
	wxImageList* ItemStatesImageList;
	wxTextCtrl* TextCtrl1;
	wxToolBar* ToolBar;
	//*)

	DECLARE_EVENT_TABLE()
};

#endif // rmmcMAIN_H
