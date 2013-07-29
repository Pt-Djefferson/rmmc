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
	static const char *TreeCtrlImageList_0_XPM[] = {
	"16 10 150 2",
	"1. c #540B0D",
	"t_ c #48090B",
	"$_ c #780E11",
	"1_ c #730A11",
	"C_ c #A30F14",
	"^_ c #5E100F",
	"T_ c #840D11",
	"v_ c #54080F",
	"M_ c #A57809",
	"W_ c #710D10",
	"Y_ c #650B0E",
	"/_ c #7C4808",
	"5. c #890E12",
	"U_ c #7D0C10",
	"P_ c #946F07",
	"k. c #6A0C0F",
	"N_ c #80130F",
	"g_ c #820D10",
	"X. c #6F0D11",
	"Z. c #57090C",
	"0. c #630B0F",
	"4. c #870E11",
	"z_ c #BC1A1E",
	"p. c #870E12",
	"[_ c #7B0C0F",
	",. c #B0181E",
	"S_ c #6F0A0E",
	":_ c #63080B",
	"i. c #680C0E",
	"c. c #5C0A0D",
	"#. c #800D0F",
	"i_ c #9B8A07",
	"e. c #610B0F",
	"C. c #660C0D",
	"D_ c #8F1015",
	"p_ c #952415",
	"4_ c #6C1A0B",
	"<_ c #830E12",
	":. c #8F0D11",
	"r. c #A01317",
	"8_ c #690D0E",
	"d. c #810E11",
	"v. c #560A0B",
	"f_ c #990F13",
	">. c #560A0E",
	"x. c #3E0609",
	"V. c #7A0D10",
	"!_ c #5B0B0E",
	"O. c #4F090C",
	"6_ c #920E13",
	"x_ c #9C1619",
	"a_ c #8E6308",
	"3. c #780D11",
	"-_ c #60090B",
	"O_ c #64230A",
	"__ c #4D090A",
	")_ c #77200E",
	"F_ c #951217",
	"}_ c #650A0E",
	"l. c #760D10",
	"m. c #6A0B0E",
	"u. c #4B090C",
	"0_ c #9F1418",
	"s. c #7B0E10",
	"q_ c #871014",
	"E_ c #6F0C0F",
	"Q_ c #740D10",
	"l_ c #C11D23",
	"#_ c #680B0E",
	"@. c #6A0511",
	"H_ c #5C090F",
	"&. c #740A0F",
	"A. c #610A0C",
	"=_ c #55080A",
	"]_ c #8C0B11",
	"c_ c #4E0A0C",
	"J_ c #802F0E",
	",_ c #42080B",
	"<. c #961318",
	"|_ c #720D11",
	"V_ c #8A0E11",
	"R_ c #961015",
	"e_ c #8A0E12",
	"`_ c #7B280D",
	".. c #831015",
	"z. c #390708",
	"{_ c #810D10",
	"@_ c #6E0D0E",
	"._ c #620B0E",
	"*. c #5D070E",
	"=. c #7A0C0E",
	"o. c #670C0E",
	"d_ c #9E0F13",
	"u_ c #9A410E",
	"9. c #7F0D0F",
	"t. c #971116",
	"_. c #AF151C",
	"r_ c #730B0D",
	"7_ c #7F0D10",
	"w. c #7F0D12",
	"L_ c #905C09",
	"*_ c #600B0D",
	"5_ c #970E14",
	"f. c #840E12",
	"+_ c #7A0610",
	"(_ c #931714",
	"6. c #7D0D10",
	";_ c #710B0E",
	"h_ c #65090C",
	"j_ c #65090D",
	"j. c #950E14",
	"2. c #570A0E",
	"M. c #7B0D10",
	"b. c #6F0B0E",
	"K_ c #A06C0A",
	"y_ c #6A0711",
	"q. c #9F1015",
	"Z_ c #930E13",
	"k_ c #A41418",
	"N. c #740C0E",
	"2_ c #94410D",
	"w_ c #8C0D11",
	"8. c #790D0F",
	"b_ c #972515",
	"a. c #790D10",
	">_ c #490507",
	"~_ c #4E090C",
	"I_ c #881610",
	"n_ c #751610",
	"B_ c #660A0E",
	"y. c #47080B",
	"g. c #770D0F",
	"9_ c #8F1115",
	"n. c #6B0B0F",
	"$. c #8F0E11",
	"+. c #5F090F",
	"h. c #700C0F",
	"&_ c #7C0E12",
	"X_ c #6B080E",
	"B. c #640A0E",
	"'_ c #832F0D",
	";. c #690B0E",
	"-. c #810C0F",
	"A_ c #56080B",
	"m_ c #8A4D0B",
	"o_ c #4D100B",
	"G_ c #4F0A0D",
	"3_ c #6E2F0A",
	"7. c #730D0F",
	"s_ c #62070E",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_z_x_",
	"c_v_b_n_m_M_N_B_V_C_Z_#_A_S_D_F_",
	"G_H_J_K_L_P_I_U_Y_#_T_R_E_W_Q_!_",
	"~_^_/_(_)_`_'_]_[_{_}_|__...X.o.",
	"O.+.@.#.$.&.*.=.-.;.:.#_>.,.<.1.",
	"~_2.3.E_4.5.6.7.8.9.0.q.w.e.r.t.",
	"y.u.Q_i.p.a.s.d.f.g.h.E_j.k.|_l.",
	"z.x.c.v.b.n.m.h.M.N.n.B.V.C.Z.A."
	};
	static const char *TreeCtrlImageList_1_XPM[] = {
	"16 10 158 2",
	"_. c #2D3032",
	"#. c #373B3F",
	"]_ c #0F0F0F",
	"i. c #5A6066",
	"3_ c #50555B",
	"z. c #764F52",
	"x_ c #801908",
	"__ c #570F04",
	"c. c #A41C12",
	"/_ c #3A424A",
	"v. c #8F251C",
	"n. c #48383C",
	"g_ c #516265",
	"{_ c #303134",
	"^_ c #6D1614",
	"x. c #911915",
	"G_ c #661205",
	"s_ c #4E4F58",
	"B. c #721715",
	"Y_ c #6C6D73",
	"8_ c #835555",
	"M. c #5F1104",
	".. c #4C5257",
	"k_ c #881806",
	"f. c #5A484A",
	"G. c #701405",
	"K_ c #56575D",
	"i_ c #4C4C53",
	"h_ c #A86561",
	"r. c #3B4348",
	")_ c #65666F",
	",. c #222629",
	"5. c #811407",
	"~_ c #822D26",
	"J_ c #181819",
	"D_ c #8D1305",
	"@_ c #363635",
	"O_ c #675454",
	"Z. c #313236",
	"V. c #473C41",
	"b_ c #686A70",
	"E_ c #545459",
	"m_ c #595B65",
	"5_ c #86888C",
	"R_ c #5E5F68",
	"D. c #8B5457",
	"q_ c #841808",
	"$_ c #47393E",
	"&. c #777984",
	"C_ c #817E80",
	"j. c #77767F",
	"[_ c #202023",
	"+_ c #616365",
	"2_ c #414E56",
	"8. c #575860",
	"0. c #75767D",
	"$. c #525159",
	"Z_ c #555E64",
	"J. c #761305",
	"Q_ c #875759",
	"C. c #2D2F32",
	"d. c #87190F",
	"3. c #1E1D20",
	"e_ c #A72810",
	":_ c #741606",
	"W_ c #816C6C",
	"T_ c #505157",
	"m. c #570E03",
	"f_ c #919191",
	":. c #6E6F78",
	"&_ c #6F0F05",
	"a_ c #7D7E86",
	"V_ c #6E6F7A",
	"=. c #0D0E0E",
	"v_ c #42525A",
	"A_ c #AA3227",
	"9_ c #7E1B13",
	"b. c #763F3F",
	"*_ c #771706",
	"h. c #71737D",
	"e. c #58565E",
	"}_ c #80828E",
	"t. c #7A5F65",
	"1. c #242224",
	"u. c #5B5D64",
	"*. c #6A6C73",
	"9. c #60616B",
	"d_ c #65656D",
	"X_ c #701006",
	"p_ c #7E7F89",
	"L. c #5D100B",
	"N. c #621105",
	"B_ c #686970",
	">_ c #5B1004",
	"0_ c #781505",
	"L_ c #868791",
	"._ c #6C1304",
	"a. c #601104",
	"2. c #1B1B1C",
	"H_ c #111012",
	"@. c #742A2B",
	"A. c #3E4046",
	"S. c #4D4F55",
	"'_ c #4D4F56",
	"u_ c #57575A",
	"t_ c #4E2A28",
	"k. c #6B6D75",
	"`_ c #57575D",
	"F. c #89150E",
	"g. c #3C4349",
	"1_ c #813938",
	"o. c #50565D",
	"<. c #19181A",
	"U_ c #232326",
	">. c #4B4C52",
	"!_ c #934F4C",
	"4_ c #696A72",
	"r_ c #8F200A",
	"#_ c #21262A",
	"4. c #6D1405",
	"S_ c #931105",
	"X. c #494F56",
	"F_ c #851505",
	"l_ c #7E1706",
	"K. c #740F05",
	";_ c #94210C",
	"y_ c #93494A",
	"|_ c #3F3E44",
	"-_ c #A32A10",
	"n_ c #62636C",
	"w. c #7B7D86",
	"6_ c #949495",
	"l. c #314247",
	",_ c #5F0F04",
	"7_ c #515458",
	"I_ c #242428",
	"-. c #565860",
	"o_ c #8E3635",
	"z_ c #7A1707",
	"y. c #716063",
	"P_ c #1D1D1F",
	"H. c #671405",
	"6. c #773F3D",
	"s. c #781705",
	"(_ c #48535A",
	"c_ c #2A3238",
	"O. c #4F4E56",
	"<_ c #901807",
	"q. c #81828B",
	"+. c #6A211F",
	"p. c #34373A",
	"N_ c #161616",
	"7. c #324048",
	"j_ c #901509",
	"w_ c #9D270E",
	"M_ c #5C5D65",
	";. c #5C5D66",
	"=_ c #91220B",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_z_x_",
	"c_v_b_n_m_M_N_B_V_C_Z_A_S_D_F_G_",
	"H_J_K_L_P_I_U_Y_T_R_E_W_Q_!_~_^_",
	"/_(_i_)_`_'_]_[_{_}_|__...X.o.O.",
	"+.@.#.$.&.*.=.-.;.:.>.,.<.1.2.3.",
	"4.5.6.7.8.9.0.q.w.e.r.t.y.u.i.p.",
	"a.s.d.f.g.)_h.j.k.l.z.x.c.v.b.n.",
	"m.M.N.B.V.C.Z.A.S.D.F.G.H.J.K.L."
	};
	static const char *TreeCtrlImageList_2_XPM[] = {
	"16 10 159 2",
	"z. c #852624",
	"T_ c #2D3649",
	"0. c #9E403E",
	"Z_ c #982320",
	"M_ c #19233E",
	"n_ c #2D364C",
	"v_ c #3C4863",
	"X. c #9F8E8D",
	"1. c #B13A34",
	"A. c #737780",
	"0_ c #801C1A",
	"q_ c #91221F",
	"E_ c #A3736D",
	"t. c #82838D",
	"I_ c #121C32",
	"2_ c #212E4C",
	"2. c #AF6F66",
	",_ c #21283E",
	"8_ c #6C3539",
	"&. c #8A8E9A",
	"w. c #846E73",
	"V. c #676368",
	"3_ c #1F2E51",
	"__ c #1A2132",
	"!_ c #771513",
	"j_ c #7B767E",
	"P. c #5F494B",
	"4. c #675D64",
	"<. c #88150E",
	"p. c #A82D2B",
	"D. c #5F464A",
	"6. c #811710",
	"h_ c #797983",
	"6_ c #27365A",
	"H_ c #1D253C",
	"5. c #69100B",
	"B. c #655A5E",
	"+. c #682F2F",
	"l. c #71211F",
	"=_ c #7F4F50",
	"B_ c #111A33",
	"V_ c #461D25",
	"g. c #784E50",
	"4_ c #1B223D",
	"}_ c #492D3F",
	"r_ c #722E2D",
	";_ c #848284",
	"U_ c #1E2940",
	"P_ c #141E34",
	"K. c #5C1E20",
	",. c #6A1411",
	"e. c #989599",
	"x. c #AA3E35",
	"_. c #7E6264",
	"m_ c #1E263C",
	"O. c #784548",
	"/_ c #32394B",
	"G_ c #878C90",
	"i. c #AD4B46",
	"$. c #82858D",
	"s. c #634B4F",
	"f. c #85575A",
	"-_ c #8B716F",
	"L_ c #1C263D",
	"k. c #8B3632",
	"K_ c #1C294B",
	"i_ c #212A43",
	"|_ c #6C3738",
	"G. c #922B29",
	"N_ c #334362",
	"J_ c #2E3C5B",
	"'_ c #1F273C",
	"p_ c #38445F",
	";. c #565F71",
	"W_ c #9D4640",
	")_ c #333D59",
	"r. c #A1A7AC",
	"a. c #881712",
	"C. c #65656D",
	"9. c #983C37",
	">_ c #59636B",
	"j. c #964543",
	"Q_ c #7F2222",
	"D_ c #807379",
	"+_ c #18233B",
	"@. c #6A666C",
	"^_ c #6A2B29",
	"y_ c #222E4C",
	"7_ c #36415A",
	"L. c #5C3233",
	"A_ c #7B3134",
	"g_ c #928C90",
	":_ c #72777F",
	"n. c #7C828C",
	"x_ c #731A17",
	"e_ c #8E2822",
	"m. c #80676A",
	"=. c #616B77",
	"#. c #86848B",
	"C_ c #A92D16",
	"`_ c #3E4960",
	"s_ c #252F48",
	"1_ c #1B243F",
	"3. c #8F7073",
	"9_ c #792825",
	"7. c #932019",
	"8. c #74211C",
	"F. c #86403E",
	"d. c #765357",
	"<_ c #28334D",
	"X_ c #19213A",
	"(_ c #414A61",
	"z_ c #904545",
	"$_ c #1E2234",
	"{_ c #26334B",
	"S_ c #745053",
	"*_ c #6E3336",
	"@_ c #26334E",
	"o_ c #353F52",
	"~_ c #6D1716",
	"M. c #574245",
	"w_ c #9B221C",
	".. c #A79492",
	"u. c #885D60",
	">. c #97312F",
	"Y_ c #1F2F50",
	"O_ c #1A253B",
	"q. c #763B3E",
	"R_ c #786A70",
	"J. c #66100D",
	"F_ c #999598",
	"N. c #645154",
	"*. c #888F96",
	"u_ c #1A2545",
	"Z. c #656A73",
	"k_ c #87767B",
	"[_ c #242A3F",
	"b. c #6C656D",
	"f_ c #475273",
	":. c #743B3F",
	"t_ c #182541",
	"._ c #222A3C",
	"a_ c #2C3B5E",
	"H. c #81120C",
	"h. c #7C4647",
	"y. c #6F636A",
	"d_ c #2F3F5D",
	"5_ c #34435E",
	"#_ c #111B33",
	"l_ c #A27272",
	"-. c #525B6B",
	"]_ c #1B2338",
	"c_ c #202A44",
	"o. c #856A70",
	"b_ c #252E49",
	"&_ c #5E1C1C",
	"S. c #666871",
	"c. c #955150",
	"v. c #7B595E",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_z_x_",
	"c_v_b_n_m_M_N_B_V_C_Z_A_S_D_F_G_",
	"H_J_K_L_P_I_U_Y_T_R_E_W_Q_!_~_^_",
	"/_(_)_`_'_]_[_{_}_|__...X.o.O.+.",
	"@.#.$.&.*.=.-.;.:.>.,.<.1.2.3.4.",
	"5.6.7.8.9.0.q.w.e.r.t.y.u.i.p.a.",
	"s.d.f.g.h.j.k.l.z.x.c.v.b.n.#.m.",
	"M.N.B.V.C.Z.A.S.D.F.G.H.J.K.L.P."
	};
	static const char *TreeCtrlImageList_3_XPM[] = {
	"16 10 158 2",
	"X_ c #11215E",
	"f. c #575C77",
	"$. c #3E4568",
	"F_ c #74170C",
	"Z. c #6E7077",
	"&. c #82838A",
	"H_ c #0F1B4B",
	"M. c #0F1B4D",
	":_ c #6D160A",
	"+. c #0F1B4E",
	"Z_ c #7D7C86",
	"Q_ c #791509",
	"v_ c #142568",
	"3_ c #2D3C7A",
	"^_ c #5A1309",
	".. c #961A0F",
	"S_ c #7E160A",
	"B_ c #676973",
	"V_ c #8A8B8F",
	"-. c #6C6D76",
	"C. c #717178",
	"U_ c #6C6D77",
	"f_ c #A8A9AB",
	"!_ c #83170B",
	"6_ c #9E9EA2",
	"l_ c #8D1F0F",
	"x. c #77150E",
	"(_ c #122263",
	":. c #7D6D73",
	"i. c #701409",
	"N. c #101F56",
	"}_ c #74757E",
	"=. c #74757F",
	"1_ c #15266B",
	"5. c #15266C",
	"L_ c #10226D",
	"K. c #671308",
	"S. c #6D6E75",
	"4_ c #7C7D83",
	"@_ c #6D6E76",
	"5_ c #9F9FA1",
	"4. c #132364",
	"L. c #541007",
	"K_ c #132365",
	">_ c #591107",
	"r. c #821812",
	"1. c #87190B",
	"B. c #0C1952",
	"q_ c #9D2311",
	"p_ c #3E4A7B",
	"n. c #6A1108",
	"j_ c #6D211D",
	"u_ c #1B3186",
	"|_ c #6E727D",
	"m. c #0A1338",
	"8. c #6E6F75",
	"#_ c #696B74",
	"7_ c #878990",
	"w_ c #9B2311",
	"h. c #73737C",
	"g_ c #878994",
	"0. c #8C8D96",
	"._ c #0F1D56",
	"G_ c #611309",
	"b_ c #192E7E",
	"J. c #72160A",
	"x_ c #72160B",
	"F. c #6D4D4E",
	"i_ c #0F1D65",
	"W_ c #7E1814",
	"A_ c #7C211D",
	"$_ c #71737A",
	";. c #7B7E88",
	",_ c #0D1741",
	"]_ c #85868D",
	"Y_ c #80828D",
	"D_ c #70160B",
	"`_ c #0D1755",
	"__ c #0B143A",
	"I_ c #60616A",
	"A. c #6F7078",
	"s_ c #6F7079",
	"V. c #56596B",
	"y. c #861A0D",
	"R_ c #83838A",
	"m_ c #2E365D",
	"=_ c #834540",
	"2. c #621409",
	">. c #7A1812",
	",. c #8B1B0D",
	"O_ c #243476",
	"G. c #6E1309",
	"~_ c #73170A",
	"g. c #77787E",
	";_ c #78180B",
	"a_ c #86878D",
	"2_ c #132876",
	")_ c #132263",
	"l. c #7A7C86",
	"j. c #70717A",
	"+_ c #7F8087",
	"h_ c #70717B",
	"N_ c #8E8F96",
	"3. c #111C50",
	"P_ c #2F3A6D",
	"n_ c #11226F",
	"*_ c #8C8F91",
	"9_ c #6E7178",
	"-_ c #7B130A",
	"6. c #111F6B",
	"[_ c #696A74",
	"/_ c #0F1C4E",
	"9. c #787982",
	"c_ c #0F1946",
	"<. c #911A0D",
	"@. c #14266A",
	"o_ c #14266D",
	"a. c #142364",
	"s. c #142365",
	"b. c #7E170C",
	"#. c #0F1C60",
	"w. c #767984",
	"y_ c #172A74",
	"t. c #7C170C",
	"u. c #8D1A0B",
	"X. c #8D1A0D",
	"e. c #7D686C",
	"e_ c #861C0E",
	"T_ c #6A6B75",
	"*. c #83858F",
	"d_ c #9C9C9F",
	"C_ c #97989F",
	"q. c #888993",
	"z_ c #8B1D0F",
	"'_ c #474F78",
	"<_ c #15276E",
	"_. c #785B5E",
	"r_ c #671409",
	"E_ c #8F7B80",
	"M_ c #727379",
	"k. c #72737B",
	"8_ c #6D6F7A",
	"&_ c #868689",
	"p. c #0E1A4A",
	"t_ c #0E1744",
	"J_ c #132465",
	"7. c #4A5072",
	"O. c #7D180A",
	"c. c #7D180B",
	"v. c #7D180C",
	"k_ c #71160B",
	"d. c #0E1D62",
	"o. c #89170A",
	"D. c #6B6F77",
	"z. c #745E61",
	"H. c #6A150A",
	"{_ c #6B6C76",
	"0_ c #832F26",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_z_x_",
	"c_v_b_n_m_M_N_B_V_C_Z_A_S_D_F_G_",
	"H_J_K_L_P_I_U_Y_T_R_E_W_Q_!_~_^_",
	"/_(_)_`_'_]_[_{_}_|__...X.o.O.^_",
	"+.@.v_#.$.&.*.=.-.;.:.>.,.<.1.2.",
	"3.4.5.6.7.8.9.0.q.w.e.r.t.y.u.i.",
	"p.a.s.d.f.g.h.j.k.l.z.x.c.v.b.n.",
	"m.M.N.B.V.C.Z.A.S.D.F.G.H.J.K.L."
	};
	static const char *TreeCtrlImageList_4_XPM[] = {
	"16 10 160 2",
	"e_ c #635865",
	"$. c #69727F",
	"J_ c #821612",
	"3. c #7D0C03",
	"&. c #68565E",
	"m. c #685660",
	"f_ c #93160C",
	"A_ c #722322",
	"9. c #68535C",
	"g_ c #59444F",
	"r_ c #6A4749",
	"=. c #623335",
	"(_ c #524958",
	"n. c #535F6E",
	"d_ c #961D10",
	"L_ c #7B0C04",
	"h. c #121933",
	"5. c #676C78",
	"3_ c #786F72",
	"-. c #581F21",
	"w_ c #3A425F",
	"l. c #661513",
	"q_ c #171D3B",
	"1_ c #4D3640",
	"S. c #451F23",
	"C_ c #968A8D",
	"<_ c #293655",
	"L. c #4D3037",
	"[_ c #77120A",
	"7. c #732728",
	"2_ c #54282A",
	"@_ c #2E3752",
	"F_ c #656975",
	"A. c #060B27",
	"v_ c #850801",
	"K. c #5E2D30",
	"s_ c #65636B",
	"z_ c #731E1B",
	":. c #6C201D",
	"z. c #5B555F",
	"g. c #3B4358",
	"E_ c #8F4545",
	"!_ c #6A646D",
	"8_ c #766367",
	"*_ c #222942",
	"U_ c #8D1005",
	"o. c #7A1616",
	"._ c #632B2D",
	"x. c #3B3D50",
	"2. c #971507",
	"a. c #750902",
	"P. c #111A31",
	"R_ c #761F1B",
	"u. c #754142",
	"w. c #620905",
	"l_ c #852E2F",
	"=_ c #070C27",
	"O_ c #2F3243",
	"N. c #473036",
	":_ c #0C1333",
	"@. c #070921",
	"D_ c #79646C",
	"O. c #6D2423",
	";. c #710C03",
	"/_ c #484350",
	"+. c #5D3133",
	"`_ c #5E4A50",
	"~_ c #4B5060",
	"M. c #6C4043",
	".. c #820F05",
	"5_ c #646A7C",
	"<. c #650702",
	"p_ c #63484D",
	"r. c #717982",
	"H_ c #6D1513",
	"J. c #585C65",
	",_ c #121830",
	"a_ c #85898E",
	"F. c #3F424F",
	"e. c #77585C",
	"Q_ c #66525A",
	"__ c #353746",
	"i_ c #523C44",
	"K_ c #6D0F0B",
	"D. c #581B1A",
	"&_ c #815A59",
	"b. c #684046",
	"0_ c #0B143A",
	"j_ c #474A60",
	"s. c #6A2E2F",
	"x_ c #572E32",
	"Y_ c #690C03",
	"y_ c #7B6975",
	"4_ c #404355",
	"m_ c #601A1A",
	"Z_ c #78565B",
	"$_ c #700704",
	"I_ c #5D0701",
	"|_ c #510501",
	"T_ c #560903",
	"k_ c #715860",
	"V_ c #891B10",
	"B. c #2A303F",
	"c_ c #690601",
	"6_ c #96332A",
	"k. c #4B2024",
	"b_ c #7F0D03",
	";_ c #070E2F",
	"'_ c #624045",
	"c. c #75757F",
	")_ c #594B55",
	"f. c #6A515A",
	"v. c #6C4549",
	"N_ c #7F3F3B",
	"t. c #615C66",
	"q. c #491D20",
	"7_ c #780908",
	"o_ c #696A6D",
	"j. c #050B29",
	"p. c #931711",
	"8. c #813334",
	"+_ c #0A1238",
	"H. c #323242",
	"X_ c #51282A",
	"h_ c #1C253D",
	"V. c #0D1631",
	"0. c #30384C",
	"4. c #6A0703",
	"^_ c #212940",
	"M_ c #702424",
	"Z. c #080F2A",
	"1. c #870C04",
	"t_ c #614D54",
	"9_ c #172144",
	"S_ c #752528",
	"*. c #5D2124",
	"n_ c #7E1108",
	"G_ c #424854",
	"P_ c #6D0801",
	"B_ c #5A0B06",
	"_. c #6D0802",
	"-_ c #0B1331",
	"C. c #060C27",
	"y. c #614147",
	">. c #652C2F",
	"W_ c #77484C",
	",. c #580E0C",
	"I. c #181F2F",
	"6. c #6C595F",
	"{_ c #861307",
	"d. c #6F2B2B",
	"X. c #810F0A",
	"}_ c #620A02",
	">_ c #1B2335",
	"#_ c #682726",
	"]_ c #552A2D",
	"i. c #9D2D28",
	"#. c #34374C",
	"G. c #02031B",
	"u_ c #6D6370",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_z_x_",
	"c_v_b_n_m_M_N_B_V_C_Z_A_S_D_F_G_",
	"H_J_K_L_P_I_U_Y_T_R_E_W_Q_!_~_^_",
	"/_(_)_`_'_]_[_{_}_|__...X.o.O.+.",
	"@.#.$.&.*.=.-.;.:.>.,.<.1.2.3.4.",
	"5.6.7.8.9.0.q.w.e.r.t.y.u.i.p.a.",
	"s.d.f.g.h.j.k.l.z.x.c.v.b.n.m.M.",
	"N.B.V.C.Z.A.S.D.F.G.H.J.K.L.P.I."
	};
	static const char *TreeCtrlImageList_5_XPM[] = {
	"16 10 153 2",
	"b_ c #865912",
	"9. c #7D1517",
	"*. c #651114",
	"O_ c #590F12",
	";_ c #821619",
	"u. c #6A1215",
	"t. c #330C0C",
	"_. c #8E151B",
	"v. c #4B0D0F",
	"1. c #501114",
	"!_ c #380D0E",
	"F_ c #440F12",
	"7_ c #732A13",
	"*_ c #8C181C",
	"U_ c #40180C",
	"Y_ c #8A1E22",
	"p. c #491013",
	"a. c #8C151B",
	"n. c #550F10",
	"m_ c #791216",
	"x_ c #420F12",
	"d. c #661214",
	"C. c #4E0E10",
	"[_ c #360A0B",
	"o. c #531215",
	"Z_ c #5A0D0F",
	"I_ c #652210",
	"5. c #771217",
	"=. c #88181B",
	"5_ c #7E1019",
	"3. c #511214",
	"~_ c #451012",
	"c_ c #541C15",
	"g_ c #753B11",
	"S. c #701115",
	"]_ c #773514",
	"o_ c #510F11",
	"0. c #8D1619",
	"h. c #811418",
	"-. c #3E0C0C",
	"K_ c #541613",
	",. c #6E1114",
	"r_ c #7A1317",
	"Q_ c #560D0F",
	"4_ c #81111B",
	"#_ c #761F17",
	"m. c #4F0F10",
	"x. c #2B090A",
	"N. c #7F1417",
	"J_ c #7D4013",
	".. c #671012",
	"i_ c #A07F11",
	"G_ c #5F2814",
	"^_ c #541015",
	"3_ c #821B18",
	"g. c #591113",
	"e_ c #95181D",
	"=_ c #89161A",
	"X_ c #460E10",
	"._ c #3A0C0E",
	"$. c #683D10",
	"S_ c #571112",
	",_ c #330B0C",
	"2. c #7B1417",
	"V. c #570E10",
	"}_ c #A41E23",
	"6. c #681115",
	"p_ c #8C6012",
	"C_ c #741013",
	"-_ c #85161A",
	">. c #7E1518",
	"k. c #5A0F10",
	"q. c #4E0D0F",
	"b. c #3B0D0E",
	"d_ c #800C19",
	"M_ c #660E13",
	"#. c #621A14",
	"6_ c #985915",
	"j. c #771115",
	";. c #580F10",
	"8. c #701318",
	"4. c #881418",
	"t_ c #390D0E",
	"f_ c #95261D",
	"7. c #561214",
	"D_ c #4A0D0E",
	"8_ c #690F16",
	"D. c #4A0D0F",
	"y. c #430F0F",
	"O. c #5B1315",
	"l. c #4F0E0E",
	"/_ c #731418",
	"h_ c #4F0E12",
	"<_ c #481011",
	":. c #9C1B22",
	"T_ c #A62329",
	"$_ c #821A18",
	"B_ c #9F4B27",
	"j_ c #591013",
	"a_ c #953D18",
	"X. c #461012",
	"q_ c #95171C",
	"@. c #7D1317",
	"l_ c #821719",
	"V_ c #9A1B21",
	"z_ c #82171B",
	"F. c #3A0B0B",
	")_ c #520F12",
	"y_ c #3F0F12",
	"`_ c #6A1014",
	"'_ c #803D12",
	"R_ c #9F191D",
	"w_ c #93171B",
	"0_ c #93171C",
	"A. c #6F1114",
	"u_ c #8E5C15",
	"W_ c #681012",
	"A_ c #551010",
	"&. c #6F0E18",
	"k_ c #6D1417",
	"2_ c #773F13",
	"+_ c #6D1114",
	"s_ c #80111A",
	"e. c #8A191D",
	"Z. c #4E0F11",
	"c. c #360B0D",
	"__ c #2A090A",
	"(_ c #851218",
	"B. c #661013",
	"L_ c #6B1114",
	"f. c #581112",
	"+. c #88161A",
	"v_ c #AF9512",
	"@_ c #701216",
	"z. c #75161A",
	"M. c #450E11",
	"E_ c #811517",
	"P_ c #700F14",
	"{_ c #6E1517",
	"&_ c #86161A",
	"9_ c #7A1418",
	"r. c #7A1419",
	"1_ c #651A16",
	"n_ c #5D0C16",
	"<. c #370C0E",
	"|_ c #97191E",
	">_ c #731316",
	"s. c #731317",
	"w. c #4F0D0E",
	"H_ c #821F1A",
	":_ c #84161A",
	"i. c #6C1215",
	"N_ c #681E13",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_&_z_",
	"t_x_c_v_b_n_m_M_N_B_V_C_Z_A_S_D_",
	"t_F_G_H_J_K_L_P_I_U_Y_T_R_E_W_Q_",
	"!_~_^_/_(_j_)_`_'_]_[_{_}_|__...",
	"!_X.o.O.+.@.#.$.&.*.=.-.;.:.>.,.",
	"<.~_1.2.3.4.5.6.7.8.9.0.q.w.e.r.",
	"t.y.X.u.i.p.a.s.d.f.g.h.j.k.l.z.",
	"x.c.v.b.n.m.M.N.B.V.C.Z.A.S.D.F."
	};
	static const char *TreeCtrlImageList_6_XPM[] = {
	"16 10 155 2",
	"#_ c #6D6067",
	"{_ c #5E1316",
	"<. c #5F616A",
	"3. c #7D7F88",
	"6_ c #962629",
	"@_ c #6E6D76",
	">. c #805158",
	"z. c #53565D",
	"4. c #80868F",
	"__ c #4E4F55",
	"u. c #4E4F56",
	"-_ c #76787C",
	"v. c #585A63",
	"=_ c #7B7C7F",
	"c. c #676974",
	"X. c #6C6D75",
	"a_ c #7E191A",
	"e. c #6C6D76",
	"e_ c #7B7C83",
	"9_ c #7C5A61",
	"-. c #5F1417",
	"5_ c #953638",
	"M. c #606269",
	"$_ c #71686D",
	";. c #641516",
	"=. c #70171B",
	"z_ c #65666E",
	"X_ c #74757D",
	"S. c #54575F",
	"0. c #6E1719",
	"T_ c #7A191C",
	"*. c #7A191D",
	"x_ c #5E5F65",
	"O_ c #6D6E74",
	"o_ c #6D6E75",
	"a. c #777982",
	"7. c #73181A",
	"1_ c #7C7D85",
	"8. c #73181C",
	"N_ c #78191C",
	">_ c #525459",
	"Q_ c #612B2F",
	"O. c #575860",
	"3_ c #7A7D85",
	"S_ c #867C82",
	"<_ c #75767E",
	"j. c #711515",
	"k. c #682327",
	"^_ c #6B6B74",
	"E_ c #6A1417",
	"i_ c #828890",
	"k_ c #878C94",
	"L_ c #83666E",
	"G. c #505159",
	"q_ c #787A80",
	"u_ c #878991",
	"4_ c #7C5F62",
	"h. c #791718",
	"7_ c #94282C",
	"f_ c #72191B",
	"V. c #5F545B",
	"s. c #71737C",
	"v_ c #808289",
	"i. c #676871",
	"+. c #76777F",
	"Z. c #593438",
	"}_ c #831C1E",
	"`_ c #721315",
	"Y_ c #6B1517",
	"F. c #4C4E54",
	"m_ c #7C1B1D",
	"h_ c #A02126",
	",. c #747A85",
	"H_ c #5B5D64",
	"c_ c #5B5D65",
	"&_ c #7E7F80",
	";_ c #6F7075",
	":_ c #6F7076",
	"y_ c #797B83",
	"~_ c #797881",
	"R_ c #751719",
	".. c #636B75",
	"p_ c #86555B",
	"A_ c #731D1E",
	"q. c #691214",
	"H. c #45474F",
	"C_ c #5D1012",
	"n_ c #837D85",
	"w_ c #7C7F84",
	"g. c #7A1518",
	"#. c #837A83",
	"r. c #686974",
	"0_ c #7C7C83",
	"d_ c #671517",
	"w. c #6A2225",
	"B_ c #6C1617",
	"_. c #68282C",
	"l. c #595159",
	"n. c #52535A",
	"._ c #616269",
	"2. c #57575F",
	"U_ c #651516",
	"D_ c #989A9F",
	"!_ c #70717B",
	"J_ c #7F8089",
	"8_ c #8A3136",
	"P_ c #711415",
	"&. c #76181B",
	"f. c #6F1718",
	"t. c #5F626B",
	"[_ c #631516",
	"N. c #64666D",
	"x. c #64666E",
	"G_ c #5A5B62",
	"5. c #824C51",
	"C. c #5B393F",
	"d. c #6C3F44",
	"@. c #82848C",
	")_ c #866970",
	",_ c #5D5F66",
	"'_ c #72181A",
	"I_ c #72181B",
	"l_ c #71727C",
	"9. c #77191D",
	"B. c #656A71",
	"|_ c #771618",
	"j_ c #97666E",
	"*_ c #7E8184",
	"/_ c #5B5C63",
	"m. c #5B5C64",
	"D. c #515159",
	"A. c #5A4349",
	"W_ c #5F0F11",
	"2_ c #888991",
	"M_ c #75191B",
	"g_ c #922124",
	"]_ c #6E181A",
	"r_ c #686B71",
	"s_ c #621315",
	"t_ c #63646C",
	"K_ c #868992",
	"o. c #686871",
	"b_ c #81828B",
	":. c #731315",
	"b. c #3E3F45",
	"+_ c #6B6F76",
	"6. c #781416",
	"1. c #5C5D65",
	"p. c #75777F",
	"y. c #5C5D66",
	"Z_ c #601012",
	"F_ c #84868E",
	"V_ c #711618",
	"$. c #761A1A",
	"(_ c #7A7B84",
	"__._X_o_O_+_@_#_$_&_*_=_-_;_:_>_",
	",_<_1_2_3_4_5_6_7_8_9_0_q_w_e_r_",
	"t_y_u_i_p_a_s_d_f_g_h_j_k_l_z_x_",
	"c_v_b_n_m_M_N_B_V_C_Z_A_S_D_F_G_",
	"H_J_K_L_P_I_U_Y_T_R_E_W_Q_!_~_^_",
	"/_(_K_)_`_'_]_[_{_f_}_|__...X.o.",
	"O.+.@.#.$.&.*.=.-.;.{_:.>.,.<.1.",
	"2.X_3.4.5.6.7.8.9.0.q.w.e.r.t.y.",
	"u.i.p.a.s.d.f.g.h.j.k.l.z.x.c.v.",
	"b.n.m.M.N.B.V.C.Z.A.m.S.D.F.G.H."
	};
	TreeCtrlImageList = new wxImageList(16, 10, 8);
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_0_XPM));
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_1_XPM));
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_2_XPM));
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_3_XPM));
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_4_XPM));
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_5_XPM));
	TreeCtrlImageList->Add(wxBitmap(TreeCtrlImageList_6_XPM));
	ImageList1 = new wxImageList(18, 18, 1);

	Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton2Click);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&rmmcFrame::OnButton3Click);
	// Set the images for CommandsTreeCtrl.
	CommandsTreeCtrl->SetImageList(ImageList1);
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

    djfTanksList tank_list;
    tank_list.Load(TextCtrl1->GetLineText(0));

    //for (auto it : tank_list.m_tags_dictionary) {
    //    *TextCtrl2 << it << "\r\n";
    //}

    //wxString xml_str = "";
    //wxStringOutputStream out_stream(&xml_str);
    //tank_list.m_undecoded_xml.Save(out_stream);
    //TextCtrl2->AppendText(xml_str);

    //for (wxUint32 i = 0; i < tank_list.m_tanks.GetCount(); ++i) {
    //    *TextCtrl2 << tank_list.m_tanks[i] + " = " + tank_list.m_tanks_strings[i] + "\r\n";
    //}
    //m_local_names
    for (auto it : tank_list.m_local_names) {
        *TextCtrl2 << it.first << " - " << it.second << "\r\n";
    }

    //*TextCtrl2 << tank_list.test << "\r\n";

    /*
    djfTanksList tank_list;
    if (!tank_list.Load()) {
        *TextCtrl2 << "File Error.";
    }
    */
}
