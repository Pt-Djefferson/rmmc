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

//(*IdInit(rmmcFrame)
const long rmmcFrame::ID_BITMAPBUTTON4 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON2 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON5 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON1 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON3 = wxNewId();
const long rmmcFrame::ID_TREECTRL1 = wxNewId();
const long rmmcFrame::ID_STATICTEXT1 = wxNewId();
const long rmmcFrame::ID_TEXTCTRL1 = wxNewId();
const long rmmcFrame::ID_BUTTON1 = wxNewId();
const long rmmcFrame::ID_TEXTCTRL2 = wxNewId();
const long rmmcFrame::ID_BUTTON2 = wxNewId();
const long rmmcFrame::ID_BITMAPBUTTON6 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP1 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP2 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP3 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP4 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP5 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP6 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP7 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP8 = wxNewId();
const long rmmcFrame::ID_PANEL2 = wxNewId();
const long rmmcFrame::ID_STATICBITMAP9 = wxNewId();
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
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxMenuItem* MenuItem2;
	wxBoxSizer* BoxSizer13;
	wxMenuItem* MenuItem1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxMenu* Menu1;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxMenuBar* MenuBar1;
	wxBoxSizer* BoxSizer3;
	wxMenu* Menu2;

	Create(parent, wxID_ANY, _("Radial Menu Mod Configurator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1040,740));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(448,320), wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
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
	CommandsTreeCtrl = new TreeCtrlWithChecks(Panel1, ID_TREECTRL1, wxDefaultPosition, wxDefaultSize, wxTR_HIDE_ROOT|wxTR_MULTIPLE|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
	wxTreeItemId CommandsTreeCtrl_Item1 = CommandsTreeCtrl->AddRoot(_T("root"));
	wxTreeItemId CommandsTreeCtrl_Item2 = CommandsTreeCtrl->AppendItem(CommandsTreeCtrl_Item1, _T("Основные команды"));
	wxTreeItemId CommandsTreeCtrl_Item3 = CommandsTreeCtrl->AppendItem(CommandsTreeCtrl_Item1, _T("Команды для легких танков"));
	CommandsTreeCtrl->ScrollTo(CommandsTreeCtrl_Item2);
	BoxSizer2->Add(CommandsTreeCtrl, 1, wxTOP|wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer9->Add(BoxSizer2, 1, wxBOTTOM|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Папка с WoT:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer12->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _(".\\resources\\ingame"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer12->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer12->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer12, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer13 = new wxBoxSizer(wxVERTICAL);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer13->Add(TextCtrl2, 7, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer13->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer13, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BitmapButton6 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\Attack.png"))), wxPoint(32,32), wxSize(42,42), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
	BitmapButton6->SetDefault();
	StaticBitmap1 = new wxStaticBitmap(Panel2, ID_STATICBITMAP1, wxNullBitmap, wxPoint(80,32), wxSize(42,42), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	StaticBitmap2 = new wxStaticBitmap(Panel2, ID_STATICBITMAP2, wxNullBitmap, wxPoint(136,48), wxSize(16,16), wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
	StaticBitmap3 = new wxStaticBitmap(Panel2, ID_STATICBITMAP3, wxNullBitmap, wxPoint(160,48), wxSize(16,16), 0, _T("ID_STATICBITMAP3"));
	StaticBitmap4 = new wxStaticBitmap(Panel2, ID_STATICBITMAP4, wxNullBitmap, wxPoint(184,48), wxDefaultSize, 0, _T("ID_STATICBITMAP4"));
	StaticBitmap5 = new wxStaticBitmap(Panel2, ID_STATICBITMAP5, wxNullBitmap, wxPoint(208,48), wxDefaultSize, 0, _T("ID_STATICBITMAP5"));
	StaticBitmap6 = new wxStaticBitmap(Panel2, ID_STATICBITMAP6, wxNullBitmap, wxPoint(232,48), wxDefaultSize, 0, _T("ID_STATICBITMAP6"));
	StaticBitmap7 = new wxStaticBitmap(Panel2, ID_STATICBITMAP7, wxNullBitmap, wxPoint(256,48), wxDefaultSize, 0, _T("ID_STATICBITMAP7"));
	StaticBitmap8 = new wxStaticBitmap(Panel2, ID_STATICBITMAP8, wxBitmap(wxImage(_T("C:\\Projects\\git\\rmmc\\src\\icons\\ussr.png")).Rescale(wxSize(16,10).GetWidth(),wxSize(16,10).GetHeight())), wxPoint(136,72), wxSize(16,10), 0, _T("ID_STATICBITMAP8"));
	BoxSizer7->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap9 = new wxStaticBitmap(Panel1, ID_STATICBITMAP9, wxNullBitmap, wxDefaultPosition, wxSize(300,300), wxSIMPLE_BORDER, _T("ID_STATICBITMAP9"));
	BoxSizer11->Add(StaticBitmap9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(BoxSizer3, 3, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer9, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4->Add(-1,-1,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
	static const char *ItemStatesImageList_2_XPM[] = {
	"16 16 157 2",
	"E_ c #009AFE",
	"d. c #001547",
	"z_ c #013171",
	"B. c #005398",
	";_ c #055492",
	"l. c #0097FE",
	")_ c #032569",
	"/_ c #0091F2",
	"2_ c #03C4F9",
	"~_ c #40D5EE",
	"5. c #1388E4",
	"N_ c #19557C",
	"D_ c #008BED",
	"j. c #011640",
	"h_ c #2175C8",
	"x_ c #01040B",
	"+_ c #010103",
	"@_ c #010104",
	"K. c #01040F",
	"F. c #010105",
	"J. c #01071C",
	"2. c #0088FE",
	"#_ c #053F85",
	"=. c #2A8ABD",
	"i_ c #04173D",
	"v. c #00ABFE",
	"'_ c #0082F9",
	"8_ c #00D1FE",
	"p. c #0082FE",
	"8. c #00A8FE",
	"W_ c #0499F6",
	"}_ c #2D8293",
	"U_ c #002F75",
	"a. c #007CF6",
	"w_ c #1C65CC",
	"D. c #0067B2",
	"X_ c #020B1A",
	"y. c #007CFE",
	"x. c #00A2FE",
	"T_ c #015DE8",
	"$_ c #01A9E8",
	"]_ c #009FFE",
	"N. c #00297B",
	"R_ c #0076FE",
	"k. c #0090D4",
	"9. c #006AD8",
	"#. c #185384",
	"k_ c #2D8EE2",
	"q. c #013678",
	"(_ c #001A54",
	"[_ c #1089EB",
	"{_ c #0D2034",
	".. c #000E37",
	"L_ c #41C4F2",
	"4. c #098EFD",
	"3_ c #047BCA",
	"r_ c #1C82DD",
	"1. c #0096FE",
	"!_ c #03090A",
	";. c #0061D3",
	"H_ c #0D6ABC",
	"O. c #0093FE",
	"S_ c #030C1F",
	"n_ c #0F5BA1",
	"y_ c #0087D7",
	"6_ c #030F29",
	"*. c #10212C",
	",. c #0090FD",
	"@. c #0C8FF7",
	"+. c #0090FE",
	"p_ c #025BE4",
	"h. c #01183E",
	"d_ c #1B5AA7",
	"u_ c #011B4A",
	"6. c #0C8FFE",
	"<. c #008DFE",
	"B_ c #2F9FE0",
	"G_ c #00B3FE",
	"._ c #010307",
	"w. c #00B0FB",
	"5_ c #010613",
	"f. c #01030A",
	"J_ c #010001",
	"o_ c #010002",
	"s_ c #0A89E6",
	"Z. c #01061D",
	"3. c #0087FE",
	"H. c #003778",
	"t_ c #0F87DC",
	"<_ c #03AEEE",
	"u. c #0081FE",
	"V_ c #37A4ED",
	"-_ c #02132E",
	"o. c #0078EB",
	"_. c #0075E2",
	"m. c #001F49",
	"r. c #009EED",
	"l_ c #16A8F2",
	"X. c #02102F",
	"Y_ c #020A1C",
	"4_ c #020D29",
	"|_ c #2AB8FE",
	"j_ c #2779D1",
	"z. c #0078FE",
	"S. c #0092D6",
	"Z_ c #001C50",
	"0_ c #0F78DC",
	"f_ c #103860",
	">_ c #0283C8",
	":_ c #07529A",
	"^_ c #30C3FD",
	"P_ c #26BBFE",
	"F_ c #00BBFE",
	"n. c #001F7C",
	"M. c #0092F9",
	"7_ c #008FF5",
	"e. c #008CEC",
	"b_ c #00B8FD",
	"g. c #024597",
	"t. c #00B8FE",
	"*_ c #04275B",
	"__ c None",
	",_ c #00D8FE",
	"v_ c #0193E6",
	"O_ c #010206",
	"c_ c #0662B9",
	"q_ c #1B5FCB",
	"G. c #010514",
	"A_ c #01020A",
	"0. c #01020C",
	":. c #010516",
	"i. c #0086FE",
	"V. c #00D2F9",
	"`_ c #023FAE",
	"&_ c #033D73",
	"K_ c #206E87",
	"c. c #00CFFE",
	"1_ c #079BE6",
	"&. c #070D11",
	"M_ c #02060A",
	"C_ c #0F7AD2",
	"b. c #007AF9",
	"I_ c #00A0F6",
	"m_ c #020305",
	"$. c #0F2130",
	"Q_ c #0A203A",
	"=_ c #036FB9",
	">. c #033170",
	"a_ c #00C6FE",
	"s. c #0068CB",
	"7. c #0187FE",
	"9_ c #00C3F9",
	"C. c #0068D0",
	"g_ c #15477C",
	"A. c #001235",
	"e_ c #1F67D0",
	"-. c #0798FE",
	"________._X_o___O_______________",
	"____+_@_#_$_&_*_=_-_____________",
	"__O_;_:_>_,_<_1_2_3_4_5_o_______",
	"__6_7_8_9_0_q_w_e_r_t_y_u_______",
	"__i_p_a_s_d_f_g_h_j_k_l_z_______",
	"x_c_v_b_n_m_____M_N_B_V_C_Z_A___",
	"S_D_F_G_H_J_______J_K_L_P_I_U_J_",
	"Y_T_R_E_W_Q_________!_~_^_/_(___",
	"O_)_`_'_]_[_{_________}_|__...__",
	"____X.o.O.+.@.#.$.&.*.=.-.O.;.:.",
	"____>.,.<.1.2.3.4.5.6.7.3.8.9.0.",
	"____q.w.e.r.t.2.y.u.i.p.a.s.d.__",
	"____f.g.h.j.k.l.z.x.c.v.b.n.____",
	"______J_____m.G_M.N.B.V.C.Z.____",
	"____________A.S.D.F.G.H.J.______",
	"____________o_K.0.____J_________"
	};
	static const char *ItemStatesImageList_3_XPM[] = {
	"16 16 1 1",
	"_ c None",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________",
	"________________"
	};
	ItemStatesImageList = new wxImageList(16, 16, 5);
	ItemStatesImageList->Add(wxBitmap(ItemStatesImageList_0_XPM));
	ItemStatesImageList->Add(wxBitmap(ItemStatesImageList_1_XPM));
	ItemStatesImageList->Add(wxBitmap(ItemStatesImageList_2_XPM));
	ItemStatesImageList->Add(wxBitmap(ItemStatesImageList_3_XPM));
	ToolBarImageList = new wxImageList(16, 16, 1);
	DirDialog1 = new wxDirDialog(this, _("Select directory"), _("resources\\ingame"), wxDD_DEFAULT_STYLE|wxDD_DIR_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
	TreeCtrlImageList = new wxImageList(18, 18, 1);
	ImageList1 = new wxImageList(18, 18, 1);

	Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton3Click);
	// Set the images for CommandsTreeCtrl.
	CommandsTreeCtrl->SetImageList(TreeCtrlImageList);
	CommandsTreeCtrl->SetItemImage(CommandsTreeCtrl_Item2, 0, wxTreeItemIcon_Normal);
	CommandsTreeCtrl->SetItemImage(CommandsTreeCtrl_Item3, 1, wxTreeItemIcon_Normal);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_BEGIN_DRAG,(wxObjectEventFunction)&rmmcFrame::OnCommandsTreeCtrlBeginDrag);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_BEGIN_RDRAG,(wxObjectEventFunction)&rmmcFrame::OnCommandsTreeCtrlBeginDrag);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click1);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&rmmcFrame::OnQuit);
	Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&rmmcFrame::OnAbout);
	//*)

	this->SetTitle(this->GetTitle() + " ver.: " + AutoVersion::FULLVERSION_STRING);
	//config = new RadialMenuConfig();
	xml_config = new wxXmlDocument;
	CommandsTreeCtrl->SetStateImageList(ItemStatesImageList);
	CommandsTreeCtrl->OnStateChange = &TreeItemStateChange;

	Connect(ID_NEW,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click);

	ToolBar = CreateToolBar(/*wxBORDER_NONE|wxTB_HORIZONTAL*/wxTB_FLAT | wxTB_DOCKABLE/* | wxTB_TEXT*/, wxID_ANY);
	ToolBar->AddTool(ID_NEW, _("Новый"), wxArtProvider::GetBitmap(wxART_NEW, wxART_BUTTON, wxSize(24,24)));
	ToolBar->AddTool(ID_NEW_FROM_TEMPLATE, _("Из шаблона"), wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_BUTTON, wxSize(24,24)), (wxString)wxEmptyString, wxITEM_DROPDOWN);
	wxMenu *drop_menu = new wxMenu;
	drop_menu->Append(wxID_ANY, _("&First dummy item"));
	drop_menu->Append(wxID_ANY, _("&Second dummy item"));
	//drop_menu->AppendSeparator();
	//drop_menu->Append(wxID_EXIT, wxT("Exit"));
	ToolBar->SetDropdownMenu(ID_NEW_FROM_TEMPLATE, drop_menu);

	ToolBar->AddTool(ID_LOAD, _("Открыть"), wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_BUTTON, wxSize(24,24)));
	ToolBar->AddTool(ID_SAVE, _("Сохранить"), wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_BUTTON, wxSize(24,24)));
	ToolBar->AddTool(ID_SAVE_AS, _("Сохранить как"), wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS, wxART_BUTTON, wxSize(24,24)));
	ToolBar->Realize();
	//CommandsTreeCtrl->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(rmmcFrame::UpdateUi), NULL, this);

	//Yes = 40
	//Attack = 42
	//Reload = 44
	//No = 46
	//Backtobase = 48
	//Helpme = 50
	//Helpmeex = 52
	//Support = 54
	//AttackSPG = 56
	//Turnback = 58
	//Stop = 60
	//Followme = 62
    wxString ingame_path = "C:\\Projects\\git\\rmmc\\src\\resources\\ingame";
    wxImage img;
    for (wxUint16 i = 0; i < 12; ++i) {
        if (LoadImageFromSwfInPKG(ingame_path + "\\res\\packages\\gui.pkg", "gui\\flash\\RadialMenu.swf", 40 + i * 2, img)) {
            if (img.IsOk()) {
                img.Resize(wxSize(122,122), wxPoint(-40,-40));
                img.Resize(wxSize(42,42), wxPoint(0,0));
                TreeCtrlImageList->Add(wxBitmap(img.Scale(18, 18, wxIMAGE_QUALITY_HIGH)));
            }
        }
    }
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

void rmmcFrame::OnButton2Click(wxCommandEvent &event) {
	{
		//Маленький хак для подавления сообщения об ошибке
		wxLogNull SilenceExclamationmark;
		//if (!xml_config->Load(_("resources/templates/Стандартный/RadialMenu.xml"))) {
		if (!xml_config->Load("resources/templates/Std/RadialMenu.xml")) {
			wxMessageBox(_("Ошибка чтения файла"), _("Welcome to..."));
			return;
		}
	}

	//CommandsTreeCtrl->DeleteAllItems();
	//FillTreeCtrlNodeWithXMLData(CommandsTreeCtrl, nullptr, xml_config->GetRoot());
	//ParseXMLDataToTreeCtrl(CommandsTreeCtrl, xml_config->GetRoot());
	FillTreeCtrlWithData(CommandsTreeCtrl, xml_config);
}

void rmmcFrame::OnButton3Click(wxCommandEvent &event) {
	//xml_config->Save("c:\\Projects\\RMConf\\resources\\templates\\new\\RadialMenu-unc.xml");
	wxImage image("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\Attack.png");
	image.Resize(wxSize(122,122), wxPoint(-40,-40));
	image.Resize(wxSize(42,42), wxPoint(0,0));
	StaticBitmap1->SetBitmap(wxBitmap(image));
	StaticBitmap2->SetBitmap(wxBitmap(image.Scale(16, 16, wxIMAGE_QUALITY_HIGH)));

	wxImage image2("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\Reload.png");
	image2.Resize(wxSize(122,122), wxPoint(-40,-40));
	image2.Resize(wxSize(42,42), wxPoint(0,0));
	StaticBitmap3->SetBitmap(wxBitmap(image2.Scale(16, 16, wxIMAGE_QUALITY_HIGH )));
	wxImage image3("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\AttackSPG.png");
	image3.Resize(wxSize(122,122), wxPoint(-40,-40));
	image3.Resize(wxSize(42,42), wxPoint(0,0));
	StaticBitmap4->SetBitmap(wxBitmap(image3.Scale(16, 16, wxIMAGE_QUALITY_HIGH )));
	wxImage image4("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\Backtobase.png");
	image4.Resize(wxSize(122,122), wxPoint(-40,-40));
	image4.Resize(wxSize(42,42), wxPoint(0,0));
	StaticBitmap5->SetBitmap(wxBitmap(image4.Scale(16, 16, wxIMAGE_QUALITY_HIGH )));
	wxImage image5("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\Followme.png");
	image5.Resize(wxSize(122,122), wxPoint(-40,-40));
	image5.Resize(wxSize(42,42), wxPoint(0,0));
	StaticBitmap6->SetBitmap(wxBitmap(image5.Scale(16, 16, wxIMAGE_QUALITY_HIGH )));
	wxImage image6("C:\\Projects\\git\\rmmc\\src\\icons\\commands\\Helpme.png");
	image6.Resize(wxSize(122,122), wxPoint(-40,-40));
	image6.Resize(wxSize(42,42), wxPoint(0,0));
	StaticBitmap7->SetBitmap(wxBitmap(image6.Scale(16, 16, wxIMAGE_QUALITY_HIGH)));
	//ImageList1->Add(image);
	//CommandsTreeCtrl->GetItemImage(CommandsTreeCtrl_Item3);
	ImageList1->Add(wxBitmap(image.Scale(18, 18, wxIMAGE_QUALITY_HIGH)));
	ImageList1->Add(wxBitmap(image2.Scale(18, 18, wxIMAGE_QUALITY_HIGH)));

	wxFFileInputStream input_stream("C:\\Projects\\git\\rmmc\\src\\resources\\ingame\\res\\packages\\gui.pkg");
	wxZipInputStream zip_stream(input_stream);

    wxZipEntry* entry;
    entry = zip_stream.GetNextEntry();
    while (entry) {
        if (entry->GetName() == "gui\\maps\\icons\\map\\01_karelia.png") break;
        entry = zip_stream.GetNextEntry();
    }

    TextCtrl2->AppendText(entry->GetName());
    /*
    wxString name = wxZipEntry::GetInternalName("gui\\maps\\icons\\map\\01_karelia.png");
    wxZipEntry entry(name);
    //wxZipEntry entry("gui\\maps\\icons\\map\\01_karelia.png");
    if (zip_stream.OpenEntry(entry)) {
        */
        wxImage img(zip_stream, wxBITMAP_TYPE_PNG);
        StaticBitmap9->SetBitmap(wxBitmap(img));
    /*
    }
    */
}

void rmmcFrame::OnButton1Click(wxCommandEvent &event) {
	if (DirDialog1->ShowModal() == wxID_OK) {
		TextCtrl1->Clear();
		*TextCtrl1 << DirDialog1->GetPath();
	}
}

void rmmcFrame::OnButton2Click1(wxCommandEvent& event)
{
    wxLogNull SilenceExclamationmark;
    TextCtrl2->Clear();

    /*
    djfTanksList tank_list;
    tank_list.Load(TextCtrl1->GetLineText(0));

    for (auto it : tank_list.m_local_names) {
        *TextCtrl2 << it.first << " - " << it.second << "\r\n";
    }
    */

    wxImage img;
    if (LoadImageFromSwfInPKG("C:\\Projects\\git\\rmmc\\src\\resources\\ingame\\res\\packages\\gui.pkg", "gui\\flash\\RadialMenu.swf", 40, img)) {
        if (img.IsOk()) {
            img.SaveFile("test.png", wxBITMAP_TYPE_PNG);
        }
    }

}
