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
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/imaglist.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include "radialmenuconfig.h"
#include "treectrlwithchecks.h"
#include <wx/artprov.h>
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
	static const long ID_BITMAPBUTTON4;
	static const long ID_BITMAPBUTTON2;
	static const long ID_BITMAPBUTTON5;
	static const long ID_BITMAPBUTTON1;
	static const long ID_BITMAPBUTTON3;
	static const long ID_TREECTRL1;
	static const long ID_PANEL1;
	static const long ID_MENUITEM1;
	static const long idMenuAbout;
	static const long ID_STATUSBAR1;
	static const long ID_TOOLBAR1;
	//*)
	static const long ID_NEW;
	static const long ID_NEW_FROM_TEMPLATE;
	static const long ID_LOAD;
	static const long ID_SAVE;
	static const long ID_SAVE_AS;

	//(*Declarations(rmmcFrame)
	wxBitmapButton* BitmapButton5;
	TreeCtrlWithChecks* CommandsTreeCtrl;
	wxPanel* Panel1;
	wxBitmapButton* BitmapButton2;
	wxBitmapButton* BitmapButton1;
	wxImageList* ToolBarImageList;
	wxStatusBar* StatusBar1;
	wxImageList* ItemStatesImageList;
	wxBitmapButton* BitmapButton4;
	wxBitmapButton* BitmapButton3;
	wxToolBar* ToolBar;
	//*)

	DECLARE_EVENT_TABLE()
};

#endif // rmmcMAIN_H
