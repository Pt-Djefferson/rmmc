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
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
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
const long rmmcFrame::ID_BITMAPBUTTON4 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON2 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON5 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON1 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON3 = wxNewId();
const long rmmcFrame::ID_TREECTRL1 = wxNewId();
const long rmmcFrame::ID_PANEL1 = wxNewId();
const long rmmcFrame::ID_MENUITEM1 = wxNewId();
const long rmmcFrame::idMenuAbout = wxNewId();
const long rmmcFrame::ID_STATUSBAR1 = wxNewId();
const long rmmcFrame::ID_TOOLBAR1 = wxNewId();
//*)
const long rmmcFrame::ID_NEW = wxNewId();
const long rmmcFrame::ID_NEW_FROM_TEMPLATE = wxNewId();
const long rmmcFrame::ID_LOAD = wxNewId();
const long rmmcFrame::ID_SAVE = wxNewId();
const long rmmcFrame::ID_SAVE_AS = wxNewId();

BEGIN_EVENT_TABLE(rmmcFrame,wxFrame)
	//(*EventTable(rmmcFrame)
	//*)
END_EVENT_TABLE()

rmmcFrame::rmmcFrame(wxWindow *parent,wxWindowID id) {
	//(*Initialize(rmmcFrame)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer8;
	wxMenuItem* MenuItem2;
	wxMenuItem* MenuItem1;
	wxFlexGridSizer* FlexGridSizer2;
	wxBoxSizer* BoxSizer2;
	wxMenu* Menu1;
	wxBoxSizer* BoxSizer1;
	wxMenuBar* MenuBar1;
	wxFlexGridSizer* FlexGridSizer1;
	wxBoxSizer* BoxSizer3;
	wxMenu* Menu2;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1040,740));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(448,320), wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(2, 0, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableCol(1);
	FlexGridSizer2->AddGrowableRow(0);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	BitmapButton4 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON4, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_BUTTON), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
	BitmapButton4->SetDefault();
	BoxSizer6->Add(BitmapButton4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BitmapButton2 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("C:\\wx294\\art\\deffile.xpm"))), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	BitmapButton2->SetDefault();
	BoxSizer6->Add(BitmapButton2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BitmapButton5 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("C:\\wx294\\art\\deffile.xpm"))), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
	BitmapButton5->SetDefault();
	BoxSizer6->Add(BitmapButton5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer5->Add(BoxSizer6, 1, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\wx294\\art\\deffile.xpm"))), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	BoxSizer8->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BitmapButton3 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("C:\\wx294\\art\\deffile.xpm"))), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	BitmapButton3->SetDefault();
	BitmapButton3->SetFocus();
	BoxSizer8->Add(BitmapButton3, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer5->Add(BoxSizer8, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer2->Add(BoxSizer5, 0, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	CommandsTreeCtrl = new TreeCtrlWithChecks(Panel1, ID_TREECTRL1, wxDefaultPosition, wxDefaultSize, wxTR_HIDE_ROOT|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	BoxSizer2->Add(CommandsTreeCtrl, 1, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	FlexGridSizer2->Add(BoxSizer2, 1, wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3->Add(553,394,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(BoxSizer3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
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
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxST_SIZEGRIP, _T("ID_STATUSBAR1"));
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
	static const char *ToolBarImageList_0_XPM[] = {
	"16 16 30 1",
	"w c Black",
	"= c #97C4E7",
	"; c #72A8D2",
	"> c #FFFFFF",
	"0 c #839CB5",
	"o c #6B98B8",
	"X c #5A89A6",
	"# c #3A749C",
	"< c #D1E5F5",
	"q c #85A7BC",
	"$ c #C3DDF1",
	"9 c #749BB4",
	": c #5F9BC8",
	"+ c #538DB3",
	"- c #85BBE2",
	"4 c #EFF6FC",
	"O c #6591AE",
	"6 c #F7FBFD",
	"8 c #FAFCFE",
	"1 c #DAEAF7",
	"5 c #E9F3FA",
	"_ c None",
	"7 c #FDFDFE",
	"2 c #E2EFF8",
	". c #8EA9BC",
	"& c #B6D5EE",
	"* c #A5CCEA",
	", c #ACE95B",
	"3 c #F4F9FD",
	"@ c #4581AA",
	"___.XoOO+@#.____",
	"___.$$&*=-O;:___",
	"__@@@@$&*=O>=o__",
	"__@,,@$$&*O>>=o_",
	"@@@,,@@@$&OOoO+_",
	"@,,,,,,@<$&*=-+_",
	"@,,,,,,@1<$&*=+_",
	"@@@,,@@@21<$&*O_",
	"__@,,@34521<$&O_",
	"__@@@@634521<$o_",
	"___.>78634521<9_",
	"___.>>786345219_",
	"___.>>>78634520_",
	"___.>>>>786345q_",
	"___............_",
	"wwwwwwwwwwwwwwww"
	};
	ToolBarImageList = new wxImageList(16, 16, 2);
	ToolBarImageList->Add(wxBitmap(ToolBarImageList_0_XPM));

	Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&rmmcFrame::OnQuit);
	Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&rmmcFrame::OnAbout);
	//*)

	//config = new RadialMenuConfig();
	xml_config = new wxXmlDocument;
    CommandsTreeCtrl->SetStateImageList(ItemStatesImageList);
	CommandsTreeCtrl->OnStateChange = &TreeItemStateChange;

	Connect(ID_NEW,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click);

	ToolBar = CreateToolBar(/*wxBORDER_NONE|wxTB_HORIZONTAL*/wxTB_FLAT | wxTB_DOCKABLE/* | wxTB_TEXT*/, wxID_ANY);
	ToolBar->AddTool(ID_NEW, wxString::FromUTF8Unchecked(_("Новый")), wxArtProvider::GetBitmap(wxART_NEW, wxART_BUTTON, wxSize(24,24)));
	ToolBar->AddTool(ID_NEW_FROM_TEMPLATE, wxString::FromUTF8Unchecked(_("Из шаблона")), wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_BUTTON, wxSize(24,24)), (wxString)wxEmptyString, wxITEM_DROPDOWN);
    wxMenu* drop_menu = new wxMenu;
    drop_menu->Append(wxID_ANY, wxT("&First dummy item"));
    drop_menu->Append(wxID_ANY, wxT("&Second dummy item"));
    //drop_menu->AppendSeparator();
    //drop_menu->Append(wxID_EXIT, wxT("Exit"));
    ToolBar->SetDropdownMenu(ID_NEW_FROM_TEMPLATE, drop_menu);

	ToolBar->AddTool(ID_LOAD, wxString::FromUTF8Unchecked(_("Открыть")), wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_BUTTON, wxSize(24,24)));
	ToolBar->AddTool(ID_SAVE, wxString::FromUTF8Unchecked(_("Сохранить")), wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_BUTTON, wxSize(24,24)));
	ToolBar->AddTool(ID_SAVE_AS, wxString::FromUTF8Unchecked(_("Сохранить как")), wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS, wxART_BUTTON, wxSize(24,24)));
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
        //if (!xml_config->Load(wxString::FromUTF8Unchecked("resources/templates/Стандартный/RadialMenu.xml"))) {
        if (!xml_config->Load("resources/templates/Std/RadialMenu.xml")) {
            wxMessageBox(wxString::FromUTF8Unchecked(_("Ошибка чтения файла")), _("Welcome to..."));
            return;
        }
    }

    //CommandsTreeCtrl->DeleteAllItems();
    //FillTreeCtrlNodeWithXMLData(CommandsTreeCtrl, nullptr, xml_config->GetRoot());
    //ParseXMLDataToTreeCtrl(CommandsTreeCtrl, xml_config->GetRoot());
    FillTreeCtrlWithData(CommandsTreeCtrl, xml_config);
}

void rmmcFrame::OnButton3Click(wxCommandEvent& event)
{
    xml_config->Save("c:\\Projects\\RMConf\\resources\\templates\\new\\RadialMenu-unc.xml");
}
