#ifndef RADIALMENUCONFIG_H
#define RADIALMENUCONFIG_H

#include <wx/xml/xml.h>
#include <wx/sstream.h>
#include <wx/treectrl.h>
#include <wx/hashmap.h>

extern wxStringToStringHashMap Title;

enum class djfItemNodeState : int {
    Commented = 0,
    Normal,
    Properties,
    Deleted,
    Unknown
};

class djfTreeItemNodeData : public wxTreeItemData {
public:
    djfTreeItemNodeData(const wxXmlNode* parent_xml_node, const wxString& xml_node_name, wxColour colour = wxNullColour) : m_xml_node_name(xml_node_name), m_colour(colour) {
        m_node_state = GetNodeState(parent_xml_node);
        //m_inherited_state = djfItemNodeState::Unknown;
    };
    ~djfTreeItemNodeData() {};
    wxString GetTitle();/* {
        int i = Title.count(m_xml_node_name);
        if (Title.find(m_xml_node_name) == Title.end()) {
            return m_xml_node_name << i;
        } else {
            return Title[m_xml_node_name];
        }
    };*/
    djfItemNodeState GetState() { return m_node_state; };
    /*
    wxColour GetColour() {
        djfItemNodeState state = m_inherited_state;
        if (state == djfItemNodeState::Unknown) state = m_node_state;
        switch (state) {
            case djfItemNodeState::Commented:  return m_colour;// *wxYELLOW;
            case djfItemNodeState::Deleted:    return *wxLIGHT_GREY;
            //case djfItemNodeState::Normal:     return wxBLACK;
            case djfItemNodeState::Properties: return *wxBLUE;
            default: return *wxBLACK;
        }

    }
    */
    /*djfItemNodeState*/ void SetState(const djfItemNodeState state) { m_node_state = state; }
    wxXmlNode* GetXmlNode() { return m_xml_node; }
private:
    djfItemNodeState GetNodeState(const wxXmlNode* parent_xml_node) {
        m_xml_node = nullptr;
        if (m_xml_node_name == "GlobalProperties") return djfItemNodeState::Properties;
        wxXmlNode* child = parent_xml_node->GetChildren();
        //if (child == nullptr) return djfItemNodeState::Deleted;
        while (child) {
            if (child->GetName() == m_xml_node_name) {
                m_xml_node = child;
                return  djfItemNodeState::Normal;
            } else if (child->GetType() == wxXML_COMMENT_NODE) {
                //Маленький хак для подавления сообщения об ошибке
                wxLogNull SilenceExclamationmark;
                wxString content = child->GetContent();
                wxStringInputStream comment_stream(content);
                wxXmlDocument comment_doc;
                if (comment_doc.Load(comment_stream) && (comment_doc.GetRoot()->GetName() == m_xml_node_name)) {
                    m_xml_node = child;
                    return djfItemNodeState::Commented;
                }
            }
            child = child->GetNext();
        }
        return djfItemNodeState::Deleted;
    }
    djfItemNodeState m_node_state;
    //djfItemNodeState m_inherited_state;
    wxString m_xml_node_name;
    wxXmlNode* m_xml_node;
    wxColour m_colour;
};

void FillTreeCtrlWithData(wxTreeCtrl* tree_ctrl, wxXmlDocument* xml_doc, wxColour colour = wxNullColour);
void TreeItemStateChange(wxTreeCtrl* tree_ctrl, const wxTreeItemId& item_id);


void FillTreeCtrlNodeWithXMLData(wxTreeCtrl* tree_ctrl, wxTreeItemId* parent_id, wxXmlNode* parent_xml_node, const bool skip_parent = false);
void ParseXMLDataToTreeCtrl(wxTreeCtrl* tree_ctrl, wxXmlNode* root_xml_node);

enum class djfNodeType {
    djfRoot,
    djfProperty,
    djfSection,
    djfCommand,
    djfComment,
    djfUnknown
};

class djfTreeItemData : public wxTreeItemData {
public:
    djfTreeItemData(wxXmlNode* xml_node) : m_real_xml_node(xml_node) {};
    ~djfTreeItemData() {};

    wxString GetItemTitle() {
        wxString prefix = m_real_xml_node->GetName();
        return prefix;
    };
private:
    wxXmlNode* m_real_xml_node;
};

#ifdef _comment_
class djfTreeItemData : public wxTreeItemData {
public:
    djfTreeItemData(wxXmlNode* xml_node) : m_real_xml_node(xml_node) {
        //Первый парент корневого узла ссылается на XmlDoc
        if (m_real_xml_node->GetParent()->GetType() == wxXML_DOCUMENT_NODE) {
            m_node_type = djfNodeType::djfRoot;
        } else if (m_real_xml_node->GetType() == wxXML_COMMENT_NODE) {
            m_node_type = djfNodeType::djfComment;
            m_is_commented = true;

            //Маленький хак для подавления сообщения об ошибке
            wxLogNull SilenceExclamationmark;
            wxString content = m_real_xml_node->GetContent();
            wxStringInputStream comment_stream(content);
            wxXmlDocument comment_doc;
            m_skip_node = !comment_doc.Load(comment_stream);
            if (!m_skip_node) {
                wxXmlNode* uncommented_node = comment_doc.GetRoot();
                m_commented_title = uncommented_node->GetName();
            }
        } else if (m_real_xml_node->GetName() == "Command" && m_real_xml_node->GetNodeContent() == "") {
            m_node_type = djfNodeType::djfCommand;
        } else if (m_real_xml_node->GetChildren()) {
            if (m_real_xml_node->GetChildren()->GetType() == wxXML_TEXT_NODE) {
                m_node_type = djfNodeType::djfProperty;
            } else {
                m_node_type = djfNodeType::djfSection;
            }
        } else { m_node_type = djfNodeType::djfUnknown; }
    };
    ~djfTreeItemData() {
        //if (m_uncommented_node != nullptr) delete m_uncommented_node;
    };

    wxString GetItemTitle() {
        wxString prefix = m_real_xml_node->GetName();
        switch (m_node_type) {
        case djfNodeType::djfRoot:      prefix = "[R]" + prefix; break;
        case djfNodeType::djfProperty:  prefix = "[P]" + prefix + ": " + m_real_xml_node->GetNodeContent(); break;
        case djfNodeType::djfSection:   prefix = "[S]" + prefix; break;
        case djfNodeType::djfCommand:   prefix = "[Cmd]" + prefix; break;
        case djfNodeType::djfComment:   prefix = "[Cmt]" + m_commented_title; break;
        case djfNodeType::djfUnknown:   prefix = "[U]" + prefix; break;
        }
        return prefix;
    };
    djfNodeType GetItemType() { return m_node_type; };
    wxColour GetItemColour() {
        if (m_is_commented) {
            return *wxLIGHT_GREY;
        } else {
            return wxNullColour;
        }
    };
    bool NeedToProceedChilds() { return (m_node_type != djfNodeType::djfProperty && m_node_type != djfNodeType::djfComment); }
    bool IsCommented() { return m_is_commented; }
    bool SkipNode() { return m_skip_node; }
    void StateChanged() {
        /*
        if (m_is_commented) {
            //Если узел был закомментирован, то заменяем реальный узел
            //на его раскомментированную версию, раскомментированную версию удаляем.
            // *m_real_xml_node = *m_uncommented_node;
            //m_effective_node = m_real_xml_node;
            //delete m_uncommented_node;
        } else {
            //Если узел не был закомментирован, то сперва создаем его копию
            //как раскомментированную, затем получаем его текстовый вид,
            //через вспомогательный документ. Меняем тип реального узла и в
            //качестве контента вставляем туда текстовый вид. Раскомментированную версию
            //оставляем.
            //wxLogNull SilenceExclamationmark;
            wxXmlDocument comment_doc;
            wxStringOutputStream comment_stream;
            wxXmlNode uncommented_node = new wxXmlNode(*m_real_xml_node);
            comment_doc.SetRoot(m_uncommented_node);
            comment_doc.Save(comment_stream);
            m_real_xml_node->SetType(wxXML_COMMENT_NODE);
            wxString content = comment_stream.GetString();
            content.Replace("<?xml version=\"1.0\" encoding=\"UTF-8\"?>", "");
            //content.Replace("-->", "--&gt;");
            //content.Replace("<!--", "&lt;!--");
            m_real_xml_node->SetContent(content);
            comment_doc.DetachRoot();
            m_effective_node = m_uncommented_node;
        }
        */
        m_is_commented = !m_is_commented;
    };
private:
    wxXmlNode* m_real_xml_node;
    djfNodeType m_node_type;
    bool m_is_commented = false;
    wxString m_commented_title;
    bool m_skip_node = false;
};
#endif

/*
enum IconName {
    Blank,
    Attack,
    Yes,
    Helpme,
    Backtobase,
    No,
    Reload,
    Followme,
    Turnback,
    Helpmeex,
    Stop,
    Support,
    AttackSPG
};

enum CommandName {
    BLANK,
    ATTACK,
    ATTACKENEMY,
    BACKTOBASE,
    FOLLOWME,
    HELPME,
    HELPMEEX,
    NEGATIVE,
    POSITIVE,
    RELOADINGGUN,
    STOP,
    SUPPORTMEWITHFIRE,
    TURNBACK
};

enum ChatMode {
    Team, All
};
enum class MenuType {
    HotkeyOnlyCommands,
    TankMenu,
    lightTankMenu,
    mediumTankMenu,
    heavyTankMenu,
    AT_SPGMenu,
    SPGMenu,
    MapCommands,
    TankSpecificCommands
};
*/

#endif // RADIALMENUCONFIG_H

