#include "tankslist.h"

#include <wx/arrimpl.cpp> // This is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(ArrayOfDescriptors);

djfTanksList::djfTanksList() {
	//m_names_hash.clear();
};

djfTanksList::~djfTanksList() {
};

bool djfTanksList::Load(const wxString &game_dir) {
    m_tanks.Empty();
	m_tanks_strings.Empty();
	m_tanks_names.Empty();

	wxXmlNode *root_node = new wxXmlNode(wxXML_ELEMENT_NODE, "list.xml");
	m_undecoded_xml.SetRoot(root_node);

    //========= XML ===========
    wxString xml_dir_path = game_dir + "/res/scripts/item_defs/vehicles/";
    wxDir xml_res_dir(xml_dir_path);
    if (!xml_res_dir.IsOpened()) {
        return false;
    }
    wxString nation_dir_name;
    bool cont = xml_res_dir.GetFirst(&nation_dir_name, wxEmptyString, wxDIR_DIRS);
    while (cont) {
        if (wxFileName::FileExists(xml_dir_path + nation_dir_name + "\\list.xml")) {
            if (!UnpackXMLFile(xml_dir_path, nation_dir_name, "\\list.xml")) {
                return false;
            }
        }
        cont = xml_res_dir.GetNext(&nation_dir_name);
    }

    FillTanksArraysFromXML();

    //========= MO ===========
    wxString mo_dir_path = game_dir + "/res/text/LC_MESSAGES/";
    wxDir mo_res_dir(mo_dir_path);
    if (!mo_res_dir.IsOpened()) {
        return false;
    }
    wxString mo_file_name;
    wxString mo_full_file_name;
    cont = mo_res_dir.GetFirst(&mo_file_name, "*_vehicles.mo", wxDIR_FILES);
    while (cont) {
        mo_full_file_name = mo_dir_path + mo_file_name;
        if (!LoadMOFile(mo_full_file_name)) {
            return false;
        }
        cont = mo_res_dir.GetNext(&mo_file_name);
    }

	return true;
}
void djfTanksList::FillTanksArraysFromXML() {
	wxXmlNode* nation_node = m_undecoded_xml.GetRoot()->GetChildren();
	while (nation_node) {
        m_tanks.Add("----" + nation_node->GetName() + "----");
        m_tanks_strings.Add("----");
        wxXmlNode* tank_node = nation_node->GetChildren();
        while (tank_node) {
            wxXmlNode* tank_string_node = tank_node->GetChildren();
            while (tank_string_node) {
                if (tank_string_node->GetName() == "userString") {
                    m_tanks.Add(tank_node->GetName());
                    m_tanks_strings.Add(tank_string_node->GetNodeContent());
                    break;
                }
                tank_string_node= tank_string_node->GetNext();
            }
            tank_node = tank_node->GetNext();
        }
        nation_node = nation_node->GetNext();
	}
}

bool djfTanksList::UnpackXMLFile(const wxString& path, const wxString& nation, const wxString& file_name) {
	wxFileInputStream input_stream(path + nation + file_name);
	wxDataInputStream data_stream(input_stream);

	if (!data_stream.IsOk()) return false;
	wxUint32 header = data_stream.Read32();
	if (header != 0x62a14e45) return false;
	data_stream.Read8();//#0

	//Формируем словарь тэгов
	if (!GetTagsArray(input_stream)) return false;

	wxXmlNode *node = new wxXmlNode(wxXML_ELEMENT_NODE, nation);
	m_undecoded_xml.GetRoot()->AddChild(node);
	AddElement(node, input_stream);
	return true;
}

//Формируем словарь тэгов
bool djfTanksList::GetTagsArray(wxFileInputStream &input_stream) {
	m_tags_dictionary.Empty();
	wxString tag = ReadNullTerminatedString(input_stream);
	while (tag.Length() != 0) {
		m_tags_dictionary.Add(tag);
		tag = ReadNullTerminatedString(input_stream);
	}
	if (m_tags_dictionary.GetCount() == 0) return false;
	return true;
}

wxString djfTanksList::ReadNullTerminatedString(wxFileInputStream &input_stream) {
	wxDataInputStream data_stream(input_stream);
	wxString result = "";
	while (!input_stream.Eof()) {
		wxUint8 character = data_stream.Read8();
		if (character == 0) break;
		result += wxChar(character);
	}
	return result;
}

void djfTanksList::AddElement(wxXmlNode *node, wxFileInputStream &input_stream) {
	wxDataInputStream data_stream(input_stream);
	wxUint16 children_count = data_stream.Read16();

	Descriptor self;
	self.raw_info = data_stream.Read32();

	ArrayOfDescriptors children;
	for (wxUint16 i = 0; i < children_count; ++i) {
		Descriptor child;
		child.tag_index = data_stream.Read16();
		child.raw_info  = data_stream.Read32();
		children.Add(child);
	}

	wxUint32 offset = 0;
	ReadElement(node, input_stream, self, offset);

    for (wxUint16 i = 0; i < children_count; ++i) {
        wxXmlNode *child = new wxXmlNode(wxXML_ELEMENT_NODE, m_tags_dictionary[children[i].tag_index]);
        node->AddChild(child);
        ReadElement(child, input_stream, children[i], offset);
    }
}

void djfTanksList::ReadElement(wxXmlNode *node, wxFileInputStream &input_stream, const Descriptor &descriptor, wxUint32 &offset) {
	wxUint32 length = descriptor.end - offset;
	switch (descriptor.type) {
	case djfELEMENT:
		AddElement(node, input_stream);
		break;
	case djfSTRING:
		//node->SetContent(ReadString(input_stream, length));
		node->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", ReadString(input_stream, length)));
		break;
	case djfINTEGER:
	    node->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", ReadInteger(input_stream, length)));
		break;
	case djfFLOAT:
	    node->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", ReadFloat(input_stream, length)));
		break;
	case djfBOOLEAN:
	    node->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", ReadBoolean(input_stream, length)));
		break;
	case djfBASE64:
	    node->AddChild(new wxXmlNode(wxXML_TEXT_NODE, "", ReadBase64(input_stream, length)));
		break;
	default:
		break;
	}

	offset = descriptor.end;
}

wxString djfTanksList::ReadString(wxFileInputStream &input_stream, wxUint32 length) {
	wxDataInputStream data_stream(input_stream);
	wxString result = "";
	while (!input_stream.Eof() && length > 0) {
		result += wxChar(data_stream.Read8());
		--length;
	}
	return result;
}

wxString djfTanksList::ReadInteger(wxFileInputStream &input_stream, wxUint32 length) {
	wxDataInputStream data_stream(input_stream);
	wxString result = "";
	switch (length) {
	case 1:
		result = wxString::Format(wxT("%i"),data_stream.Read8());
		break;
	case 2:
		result = wxString::Format(wxT("%i"),data_stream.Read16());
		break;
	case 4:
		result = wxString::Format(wxT("%i"),data_stream.Read32());
		break;
	case 8:
		result = wxString::Format(wxT("%i"),data_stream.Read64());
		break;
	default:
		result = "0";
		break;
	}
	return result;
}

wxString djfTanksList::ReadFloat(wxFileInputStream& input_stream, wxUint32 length) {
    union {
        wxUint32 raw_int;
        wxFloat32 res_float;
    };
	wxDataInputStream data_stream(input_stream);
	wxString result = "";
	wxUint16 cnt = length / 4;
	for (wxUint16 i = 0; i < cnt; ++i) {
        if (i != 0) result += " ";
        raw_int = data_stream.Read32();
        result += wxString::Format(wxT("%.6f"),res_float);
	}
	return result;
}

wxString djfTanksList::ReadBoolean(wxFileInputStream& input_stream, wxUint32 length) {
	wxDataInputStream data_stream(input_stream);
	if (length == 1) data_stream.Read8();
	wxString result = (length == 1 ? "true" : "false");
	return result;
}

wxString djfTanksList::ReadBase64(wxFileInputStream& input_stream, wxUint32 length) {
   	wxDataInputStream data_stream(input_stream);
   	while (length > 0) {
        data_stream.Read8();
        --length;
   	}
	wxString result = "Base64 content";
	return result;
}

bool djfTanksList::LoadMOFile(const wxString& file_name) {
	wxFileInputStream input_stream(file_name);
	wxDataInputStream data_stream(input_stream);

	if (!data_stream.IsOk()) return false;
	wxUint32 header = data_stream.Read32();
	if (header != 0x950412de) return false;
	//Пропускаем номер ревизии формата файла
	data_stream.Read32();
	wxUint32 number_of_strings = data_stream.Read32();
	wxUint32 original_strings_offset    = data_stream.Read32();
	wxUint32 translation_strings_offset = data_stream.Read32();
	wxUint32 hashing_table_size   = data_stream.Read32();
	wxUint32 hashing_table_offset = data_stream.Read32();

	return true;
}
