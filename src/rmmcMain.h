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
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/imaglist.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include "radialmenuconfig.h"
#include "treectrlwithchecks.h"
#include <wx/artprov.h>
#include "version.h"
#include <wx/zipstrm.h>
#include "swf.h"

//#include <wx/event.h>


class rmmcFrame: public wxFrame {
public:

	rmmcFrame(wxWindow *parent,wxWindowID id = -1);
	virtual ~rmmcFrame();
	//RadialMenuConfig *config;
	wxXmlDocument *xml_config;

private:

	//(*Handlers(rmmcFrame)
	void OnQuit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnCommandsTreeCtrlBeginDrag(wxTreeEvent &event);
	void OnButton2Click(wxCommandEvent &event);
	void OnButton3Click(wxCommandEvent &event);
	void OnButton1Click(wxCommandEvent &event);
	void OnButton2Click1(wxCommandEvent& event);
	//*)

	//(*Identifiers(rmmcFrame)
	static const long ID_BITMAPBUTTON4;
	static const long ID_BITMAPBUTTON2;
	static const long ID_BITMAPBUTTON5;
	static const long ID_BITMAPBUTTON1;
	static const long ID_BITMAPBUTTON3;
	static const long ID_TREECTRL1;
	static const long ID_STATICTEXT1;
	static const long ID_TEXTCTRL1;
	static const long ID_BUTTON1;
	static const long ID_TEXTCTRL2;
	static const long ID_BUTTON2;
	static const long ID_BITMAPBUTTON6;
	static const long ID_STATICBITMAP1;
	static const long ID_STATICBITMAP2;
	static const long ID_STATICBITMAP3;
	static const long ID_STATICBITMAP4;
	static const long ID_STATICBITMAP5;
	static const long ID_STATICBITMAP6;
	static const long ID_STATICBITMAP7;
	static const long ID_STATICBITMAP8;
	static const long ID_PANEL2;
	static const long ID_STATICBITMAP9;
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
	wxStaticBitmap* StaticBitmap2;
	wxStaticBitmap* StaticBitmap8;
	wxStaticBitmap* StaticBitmap5;
	wxStaticBitmap* StaticBitmap7;
	wxBitmapButton* BitmapButton5;
	wxButton* Button1;
	wxStaticBitmap* StaticBitmap1;
	TreeCtrlWithChecks* CommandsTreeCtrl;
	wxImageList* ImageList1;
	wxStaticBitmap* StaticBitmap4;
	wxPanel* Panel1;
	wxBitmapButton* BitmapButton2;
	wxStaticText* StaticText1;
	wxBitmapButton* BitmapButton1;
	wxButton* Button2;
	wxImageList* ToolBarImageList;
	wxImageList* TreeCtrlImageList;
	wxStatusBar* StatusBar1;
	wxDirDialog* DirDialog1;
	wxBitmapButton* BitmapButton6;
	wxImageList* ItemStatesImageList;
	wxTextCtrl* TextCtrl2;
	wxBitmapButton* BitmapButton4;
	wxTextCtrl* TextCtrl1;
	wxStaticBitmap* StaticBitmap9;
	wxBitmapButton* BitmapButton3;
	wxPanel* Panel2;
	wxStaticBitmap* StaticBitmap6;
	wxToolBar* ToolBar;
	wxStaticBitmap* StaticBitmap3;
	//*)

	DECLARE_EVENT_TABLE()
};

#endif // rmmcMAIN_H
