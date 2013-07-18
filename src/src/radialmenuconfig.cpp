#include "radialmenuconfig.h"

//djfXmlNodeTitles djfXmlNodeTitle;

void FillTreeCtrlWithData(wxTreeCtrl* tree_ctrl, wxXmlDocument* xml_doc) {
    if (tree_ctrl == nullptr || xml_doc == nullptr) return;

    wxString root_node_name = "RadialMenu.xml";
    //wxString root_section_name[10] = {"TankMenu", "lightTankMenu", "mediumTankMenu", "heavyTankMenu", "AT-SPGMenu", "SPGMenu", "TankSpecificCommands", "MapCommands", "HotkeyOnlyCommands", "GlobalProperties"};
    //wxString global_property_name[3] = {"MapMenuKey", "MenuReloadHotkey", "HotkeyCommandDelay"};

    //wxXmlNode* root_node = xml_doc->GetRoot();
    wxXmlNode* doc_node = xml_doc->GetDocumentNode();
    djfTreeItemNodeData* root_node_data = new djfTreeItemNodeData(doc_node, root_node_name);
    if (root_node_data->GetState() == djfItemNodeState::Deleted || root_node_data->GetState() == djfItemNodeState::Commented) {
        delete root_node_data;
        wxMessageBox(wxString::FromUTF8Unchecked(_("Ошибка анализа содержимого файла")), _("Welcome to..."));
        return;
    }
    tree_ctrl->DeleteAllItems();
    /*wxTreeItemId root_id =*/ tree_ctrl->AddRoot(root_node_data->GetTitle(), 0, 0, root_node_data);

#ifdef _comment_
    wxXmlNode* current_xml_node;
    for (unsigned int i = 0; i < 9/*10*/; ++i) {
        current_xml_node = FindXMLNode(root_xml_node, global_section[i]);
        djfTreeItemData* node_data = nullptr;
        if (current_xml_node != nullptr) {
            node_data = new djfTreeItemData(current_xml_node);
        }
        wxTreeItemId last_id = tree_ctrl->AppendItem(root_id, global_section_ru[i], -1, -1, node_data);
        FillTreeCtrlNodeWithXMLData(tree_ctrl, &last_id, current_xml_node, true);
    }

    wxTreeItemId global_properties_id = tree_ctrl->AppendItem(root_id, global_section_ru[9], -1, -1, nullptr);
    for (unsigned int i = 0; i < 3; ++i) {
        current_xml_node = FindXMLNode(root_xml_node, global_properties[i]);
        djfTreeItemData* node_data = nullptr;
        if (current_xml_node != nullptr) {
            node_data = new djfTreeItemData(current_xml_node);
        }
        wxTreeItemId last_id = tree_ctrl->AppendItem(global_properties_id, global_properties_ru[i], -1, -1, node_data);
        FillTreeCtrlNodeWithXMLData(tree_ctrl, &last_id, current_xml_node, true);
    }
#endif
};

void FillTreeCtrlNodeWithXMLData(wxTreeCtrl* tree_ctrl, wxTreeItemId* parent_id, wxXmlNode* parent_xml_node, const bool skip_parent) {
    if (tree_ctrl== nullptr || parent_xml_node == nullptr) return;
    wxTreeItemId last_id;
    if (!skip_parent) {
        djfTreeItemData* node_data = new djfTreeItemData(parent_xml_node);
        if (parent_id == nullptr) {
            last_id = tree_ctrl->AddRoot(node_data->GetItemTitle(), 0, 0, node_data);
        } else {
            last_id = tree_ctrl->AppendItem(*parent_id, node_data->GetItemTitle(), 0, 0, node_data);
        }
    } else {
        last_id = *parent_id;
    }
    //TODO: Сделать обработку закомментированных секций
    //tree_ctrl->SetItemState(last_id, !node_data->IsCommented());

    wxXmlNode* child = parent_xml_node->GetChildren();
    while (child) {
        FillTreeCtrlNodeWithXMLData(tree_ctrl, &last_id, child);
        child = child->GetNext();
    }
}

wxXmlNode* FindXMLNode(wxXmlNode* start_node, const wxString& node_name) {
    if (start_node == nullptr) return nullptr;
    wxXmlNode* child = start_node->GetChildren();
    while (child) {
        if (child->GetName() == node_name) return child;
        if (child->GetType() == wxXML_COMMENT_NODE) {
            wxLogNull SilenceExclamationmark;
            wxString content = child->GetContent();
            wxStringInputStream comment_stream(content);
            wxXmlDocument comment_doc;
            if (comment_doc.Load(comment_stream) && comment_doc.GetRoot()->GetName() == node_name) {
                return child;
            }
        }
        child = child->GetNext();
    }
    return nullptr;
}

void ParseXMLDataToTreeCtrl(wxTreeCtrl* tree_ctrl, wxXmlNode* root_xml_node) {
    if (tree_ctrl == nullptr || root_xml_node == nullptr) return;
    tree_ctrl->DeleteAllItems();
    djfTreeItemData* root_node_data = new djfTreeItemData(root_xml_node);
    wxTreeItemId root_id = tree_ctrl->AddRoot(root_node_data->GetItemTitle(), 0, 0, root_node_data);

    wxString global_section[10] = {"TankMenu", "lightTankMenu", "mediumTankMenu", "heavyTankMenu", "AT-SPGMenu", "SPGMenu", "TankSpecificCommands", "MapCommands", "HotkeyOnlyCommands", "GlobalProperties"};
    wxString global_section_ru[10] = {  wxString::FromUTF8Unchecked(_("Основные команды")),
                                        wxString::FromUTF8Unchecked(_("Команды для легких танков")),
                                        wxString::FromUTF8Unchecked(_("Команды для средних танков")),
                                        wxString::FromUTF8Unchecked(_("Команды для тяжелых танков")),
                                        wxString::FromUTF8Unchecked(_("Команды для ПТ-САУ")),
                                        wxString::FromUTF8Unchecked(_("Команды для САУ")),
                                        wxString::FromUTF8Unchecked(_("Команды для определенного танка")),
                                        wxString::FromUTF8Unchecked(_("Команды для карт")),
                                        wxString::FromUTF8Unchecked(_("Горячие клавиши")),
                                        wxString::FromUTF8Unchecked(_("Глобальные настройки"))};
    wxXmlNode* current_xml_node;
    for (unsigned int i = 0; i < 9/*10*/; ++i) {
        current_xml_node = FindXMLNode(root_xml_node, global_section[i]);
        djfTreeItemData* node_data = nullptr;
        if (current_xml_node != nullptr) {
            node_data = new djfTreeItemData(current_xml_node);
        }
        wxTreeItemId last_id = tree_ctrl->AppendItem(root_id, global_section_ru[i], -1, -1, node_data);
        FillTreeCtrlNodeWithXMLData(tree_ctrl, &last_id, current_xml_node, true);
    }

    wxString global_properties[] = {"MapMenuKey", "MenuReloadHotkey", "HotkeyCommandDelay"};
    wxString global_properties_ru[] = { wxString::FromUTF8Unchecked(_("Клавиша вызова меню карты")),
                                        wxString::FromUTF8Unchecked(_("Клавиша перезагрузки конфигурации мода")),
                                        wxString::FromUTF8Unchecked(_("Задержка между обработкой горячих клавиш"))};
    wxTreeItemId global_properties_id = tree_ctrl->AppendItem(root_id, global_section_ru[9], -1, -1, nullptr);
    for (unsigned int i = 0; i < 3; ++i) {
        current_xml_node = FindXMLNode(root_xml_node, global_properties[i]);
        djfTreeItemData* node_data = nullptr;
        if (current_xml_node != nullptr) {
            node_data = new djfTreeItemData(current_xml_node);
        }
        wxTreeItemId last_id = tree_ctrl->AppendItem(global_properties_id, global_properties_ru[i], -1, -1, node_data);
        FillTreeCtrlNodeWithXMLData(tree_ctrl, &last_id, current_xml_node, true);
    }
}
