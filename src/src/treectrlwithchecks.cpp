#include "treectrlwithchecks.h"

BEGIN_EVENT_TABLE(TreeCtrlWithChecks, wxTreeCtrl)
    EVT_LEFT_DOWN(TreeCtrlWithChecks::OnLeftClick)
    //EVT_TREE_BEGIN_DRAG(1000, TreeCtrlWithChecks::OnBeginDrag)
    //EVT_TREE_BEGIN_RDRAG(1000, TreeCtrlWithChecks::OnBeginDrag)
END_EVENT_TABLE()

void TreeCtrlWithChecks::OnLeftClick(wxMouseEvent &event) {
   int flags;
   wxTreeItemId item_id = HitTest(event.GetPosition(), flags);
   if (item_id.IsOk() && flags & wxTREE_HITTEST_ONITEMSTATEICON/*wxTREE_HITTEST_ONITEMICON*/)
      {
          int item_state = this->GetItemState(item_id);
        if (item_state == 0 || item_state == 1) {
            this->SetItemState(item_id, !item_state);
        }
        //if (OnStateChange != nullptr) OnStateChange(this, item_id);
        event.Skip(false);  // stop the event, so no selection
      }
   else
      event.Skip(true);  // let normal selection processing happen
}

void TreeCtrlWithChecks::DoSetItemState(const wxTreeItemId& item, int state) {
    wxTreeCtrl::DoSetItemState(item, state);
    if (OnStateChange != nullptr) OnStateChange(this, item);
}

/*
void TreeCtrlWithChecks::OnBeginDrag(wxTreeEvent& event) {
    event.Allow();
}
*/
