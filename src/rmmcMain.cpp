/***************************************************************
 * Name:      rmmcMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Pt_Djefferson ()
 * Created:   2013-07-04
 * Copyright: Pt_Djefferson ()
 * License:
 **************************************************************/
//TODO: Перед релизом подогнать статическую линковку под non-monolithic библиотеки wxWidgets и убрать лишнее
//TODO: wxWidgets пересобрать без поддержки TIFF и возможно JPEG, ZLIB


#include "wx_pch.h"
#include "rmmcMain.h"
#include <wx/msgdlg.h>
#include <wx/xml/xml.h>

//(*InternalHeaders(rmmcFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format) {
	wxString wxbuild(wxVERSION_STRING);

	if (format == long_f ) {
#if defined(__WXMSW__)
		wxbuild << _T("-Windows");
#elif defined(__UNIX__)
		wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
		wxbuild << _T("-Unicode build");
#else
		wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
	}

	return wxbuild;
}

void TreeItemStateChange(TreeCtrlWithChecks* tree_ctrl, const wxTreeItemId& item_id) {
    djfTreeItemData *item_data = (djfTreeItemData *)tree_ctrl->GetItemData(item_id);
    if (item_data) {
        //item_data->StateChanged();
        //tree_ctrl->SetItemTextColour(item_id, item_data->GetItemColour());
    }
}

//(*IdInit(rmmcFrame)
const long rmmcFrame::ID_TREECTRL1 = wxNewId();
const long rmmcFrame::ID_BITMAPCOMBOBOX1 = wxNewId();
const long rmmcFrame::ID_BUTTON1 = wxNewId();
const long rmmcFrame::ID_TEXTCTRL1 = wxNewId();
const long rmmcFrame::ID_BUTTON2 = wxNewId();
const long rmmcFrame::ID_BUTTON3 = wxNewId();
const long rmmcFrame::ID_BUTTON4 = wxNewId();
const long rmmcFrame::ID_BUTTON5 = wxNewId();
const long rmmcFrame::ID_BUTTON6 = wxNewId();
const long rmmcFrame::ID_PANEL1 = wxNewId();
const long rmmcFrame::ID_MENUITEM1 = wxNewId();
const long rmmcFrame::idMenuAbout = wxNewId();
const long rmmcFrame::ID_STATUSBAR1 = wxNewId();
const long rmmcFrame::ID_TOOLBAR1 = wxNewId();
//*)
const long rmmcFrame::ID_NEW = wxNewId();

BEGIN_EVENT_TABLE(rmmcFrame,wxFrame)
	//(*EventTable(rmmcFrame)
	//*)
END_EVENT_TABLE()

rmmcFrame::rmmcFrame(wxWindow *parent,wxWindowID id) {
	//(*Initialize(rmmcFrame)
	wxMenuItem* MenuItem2;
	wxMenuItem* MenuItem1;
	wxMenu* Menu1;
	wxMenuBar* MenuBar1;
	wxMenu* Menu2;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1040,740));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(448,320), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	CommandsTreeCtrl = new TreeCtrlWithChecks(Panel1, ID_TREECTRL1, wxPoint(8,64), wxSize(320,440), wxTR_HIDE_ROOT|wxTR_MULTIPLE|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	CommandsTreeCtrl->ExpandAll();
	BitmapComboBox1 = new wxBitmapComboBox(Panel1, ID_BITMAPCOMBOBOX1, wxEmptyString, wxPoint(896,24), wxDefaultSize, 0, NULL, 0, wxDefaultValidator, _T("ID_BITMAPCOMBOBOX1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxPoint(872,432), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(760,64), wxSize(264,352), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxPoint(8,504), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Label"), wxPoint(120,504), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(Panel1, ID_BUTTON4, _("Label"), wxPoint(8,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button5 = new wxButton(Panel1, ID_BUTTON5, _("Label"), wxPoint(88,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	Button6 = new wxButton(Panel1, ID_BUTTON6, _("Label"), wxPoint(256,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar1->Append(Menu1, _("&File"));
	Menu2 = new wxMenu();
	MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar1->Append(Menu2, _("Help"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -1 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	static const char *ItemStatesImageList_0_XPM[] = {
	"16 16 6 1",
	"+ c #FFFFFF",
	"o c #DADADA",
	"O c #F4F4F4",
	"_ c None",
	"X c #E0E0E0",
	". c #9D9D9D",
	"________________",
	"________________",
	"___...........__",
	"__.XXXXXXXXXXo._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.XOOOOOOOOO+._",
	"__.o++++++++++._",
	"___...........__",
	"________________"
	};
	static const char *ItemStatesImageList_1_XPM[] = {
	"16 16 25 1",
	"= c Black",
	"1 c #1E1E1E",
	"@ c #FFFFFF",
	"5 c #444444",
	"o c #DADADA",
	"# c #818181",
	": c #909090",
	"+ c #DBDBDB",
	"& c #737373",
	"2 c #BEBEBE",
	"4 c #121212",
	"; c #6C6C6C",
	"7 c #8A8A8A",
	"6 c #DDDDDD",
	"O c #F4F4F4",
	", c #7D7D7D",
	"> c #C8C8C8",
	"3 c #676767",
	"- c #B2B2B2",
	"_ c None",
	"* c #C1C1C1",
	"$ c #424242",
	"< c #A4A4A4",
	"X c #E0E0E0",
	". c #9D9D9D",
	"________________",
	"________________",
	"___...........__",
	"__.XXXXXXXXXXo._",
	"__.XOOOOOOOO+@._",
	"__.XOOOOOOO#$@._",
	"__.XOOOOOO&$*@._",
	"__.XOOOOO&=-O@._",
	"__.XO;:O>=&OO@._",
	"__.X,==<$12OO@._",
	"__.XO34==5OOO@._",
	"__.XO6<4=7OOO@._",
	"__.XOOO:$oOOO@._",
	"__.o@@@@@@@@@@._",
	"___...........__",
	"________________"
	};
	ItemStatesImageList = new wxImageList(16, 16, 3);
	ItemStatesImageList->Add(wxBitmap(ItemStatesImageList_0_XPM));
	ItemStatesImageList->Add(wxBitmap(ItemStatesImageList_1_XPM));
	ImageList2 = new wxImageList(16, 16, 1);

	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_BEGIN_DRAG,(wxObjectEventFunction)&rmmcFrame::OnCommandsTreeCtrlBeginDrag);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_BEGIN_RDRAG,(wxObjectEventFunction)&rmmcFrame::OnCommandsTreeCtrlBeginDrag);

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton3Click);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&rmmcFrame::OnQuit);
	Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&rmmcFrame::OnAbout);
	//*)

	//config = new RadialMenuConfig();
	xml_config = new wxXmlDocument;
    CommandsTreeCtrl->SetStateImageList(ItemStatesImageList);
	CommandsTreeCtrl->OnStateChange = &TreeItemStateChange;

	ToolBar = CreateToolBar(wxBORDER_NONE|wxTB_HORIZONTAL, wxID_ANY);
	ToolBar->AddTool(ID_NEW, "New", wxBitmap(ItemStatesImageList_0_XPM));
	ToolBar->Realize();
	//CommandsTreeCtrl->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(rmmcFrame::UpdateUi), NULL, this);
}

rmmcFrame::~rmmcFrame() {
	//(*Destroy(rmmcFrame)
	//*)
	//delete config;
	delete xml_config;
}

void rmmcFrame::OnQuit(wxCommandEvent &event) {
	Close();
}

void rmmcFrame::OnAbout(wxCommandEvent &event) {
	wxString msg = wxbuildinfo(long_f);
	wxMessageBox(msg, _("Welcome to..."));
}

void rmmcFrame::OnCommandsTreeCtrlBeginDrag(wxTreeEvent &event) {
	event.Allow();
}

void rmmcFrame::OnButton2Click(wxCommandEvent& event)
{
    {
        //Маленький хак для подавления сообщения об ошибке
        wxLogNull SilenceExclamationmark;
        if (!xml_config->Load("c:\\Projects\\RMConf\\resources\\templates\\new\\RadialMenu.xml")) {
            wxMessageBox(_("Ошибка"), _("Welcome to..."));
            return;
        }
    }

    //CommandsTreeCtrl->DeleteAllItems();
    //FillTreeCtrlNodeWithXMLData(CommandsTreeCtrl, nullptr, xml_config->GetRoot());
    ParseXMLDataToTreeCtrl(CommandsTreeCtrl, xml_config->GetRoot());
}

void rmmcFrame::OnButton3Click(wxCommandEvent& event)
{
    xml_config->Save("c:\\Projects\\RMConf\\resources\\templates\\new\\RadialMenu-unc.xml");
}
