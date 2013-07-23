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
        if (item_state == (int)ItemState::Commented || item_state == (int)ItemState::Normal) {
            this->SetItemState(item_id, !item_state);
        }
        //if (OnStateChange != nullptr) OnStateChange(this, item_id);
        event.Skip(false);  // stop the event, so no selection
      }
   else
      event.Skip(true);  // let normal selection processing happen
}

void TreeCtrlWithChecks::DoSetItemState(const wxTreeItemId& item, int state) {
    wxTreeItemId root_id = this->GetRootItem();

    bool was_deleted = false;
    if (item != root_id) {
        was_deleted = this->GetItemState(item) == (int)ItemState::Deleted;
    }

    //wxTreeCtrl::DoSetItemState(item, state);

    int parent_state = (int)ItemState::Normal;
    wxTreeItemId parent_id = this->GetItemParent(item);
    while (parent_id.IsOk() && parent_id != root_id) {
        if (this->GetItemState(parent_id) != (int)ItemState::Normal
            && this->GetItemState(parent_id) != (int)ItemState::NoState
            && this->GetItemState(parent_id) != (int)ItemState::Properties) parent_state = this->GetItemState(parent_id);
        parent_id = this->GetItemParent(parent_id);
    }
    //this->SetItemTextColour(item, m_state_colour[effective_state]);

    if (parent_state == (int)ItemState::Normal) {
        wxTreeCtrl::DoSetItemState(item, state);

        this->SetItemTextColour(item, m_state_colour[state]);

        if (was_deleted && state != (int)ItemState::Deleted) {
            SetItemStrike(item, false);
        } else if (!was_deleted && state == (int)ItemState::Deleted) {
            SetItemStrike(item, true);
        }


        wxTreeItemIdValue cookie;
        wxTreeItemId child_id = this->GetFirstChild(item, cookie);
        while (child_id.IsOk()) {
            if (state == (int)ItemState::Normal) {
                this->SetItemTextColour(child_id, m_state_colour[this->GetItemState(child_id)]);
            } else {
                this->SetItemTextColour(child_id, m_state_colour[state]);
            }
            child_id = this->GetNextChild(item, cookie);
        }
    }
    //if (OnStateChange != nullptr) OnStateChange(this, item);
}

/*
void TreeCtrlWithChecks::OnBeginDrag(wxTreeEvent& event) {
    event.Allow();
}
*/
