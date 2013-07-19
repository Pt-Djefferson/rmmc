#ifndef TREECTRLWITHCHECKS_H
#define TREECTRLWITHCHECKS_H

#include <wx/treectrl.h>

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
    void (*OnStateChange)(wxTreeCtrl* tree_ctrl, const wxTreeItemId& item_id) = nullptr;

    void OnLeftClick(wxMouseEvent &event);
    //void OnBeginDrag(wxTreeEvent& event);

    wxDECLARE_NO_COPY_CLASS(TreeCtrlWithChecks);
    DECLARE_EVENT_TABLE()
};

#endif // TREECTRLWITHCHECKS_H
