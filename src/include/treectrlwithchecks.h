#ifndef TREECTRLWITHCHECKS_H
#define TREECTRLWITHCHECKS_H

#include <wx/treectrl.h>
#include <wx/colour.h>
#include <wx/settings.h>


enum class ItemState : int {
    NoState = -1,
    Commented = 0,
    Normal,
    Properties,
    Deleted,
    Command,
    Unknown
};

class TreeCtrlWithChecks : public wxTreeCtrl
{
public:
    TreeCtrlWithChecks(wxWindow *parent, wxWindowID id = wxID_ANY,
           const wxPoint& pos = wxDefaultPosition,
           const wxSize& size = wxDefaultSize,
           long style = wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT,
           const wxValidator& validator = wxDefaultValidator,
           const wxString& name = wxTreeCtrlNameStr) : wxTreeCtrl(parent, id, pos, size, style, validator, name) {};

    virtual ~TreeCtrlWithChecks(){};

    virtual void DoSetItemState(const wxTreeItemId& item, int state);

    virtual void SetItemStrike(const wxTreeItemId& item, bool strike = true) {
        if(!item.IsOk() || item == this->GetRootItem()) return;

        wxFont item_font = this->GetItemFont(item);
        if (item_font == wxNullFont) {
            item_font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
        }
        item_font.SetStrikethrough(strike);
        this->SetItemFont(item, item_font);
    }


    void (*OnStateChange)(wxTreeCtrl* tree_ctrl, const wxTreeItemId& item_id) = nullptr;

    void OnLeftClick(wxMouseEvent &event);
    //void OnBeginDrag(wxTreeEvent& event);
    //wxColour m_state_colour[5] = { wxTheColourDatabase->Find("GREY"), wxNullColour, *wxBLUE, *wxLIGHT_GREY, *wxRED };
    wxColour m_state_colour[5] = { wxTheColourDatabase->Find(/*"CADET BLUE"*/"LIGHT BLUE"), wxTheColourDatabase->Find("BLUE"), wxTheColourDatabase->Find("BROWN"), wxTheColourDatabase->Find("LIGHT GREY"), *wxRED };

    wxDECLARE_NO_COPY_CLASS(TreeCtrlWithChecks);
    DECLARE_EVENT_TABLE()
};

#endif // TREECTRLWITHCHECKS_H
