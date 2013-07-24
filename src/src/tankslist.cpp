#include "tankslist.h"

djfTanksList::djfTanksList() {
    m_names_hash.clear();
    wxXmlNode* root_node = new wxXmlNode(wxXML_ELEMENT_NODE, "list.xml");
    m_undecoded_xml.SetRoot(root_node);
};

djfTanksList::~djfTanksList() {
};

bool djfTanksList::Load(const wxString &file_name) {
	wxFileInputStream input_stream(file_name);
	wxDataInputStream data_stream(input_stream);

	if (!data_stream.IsOk()) return false;
	wxUint32 header = data_stream.Read32();
	if (header != 0x62a14e45) return false;
	data_stream.Read8();//#0

	//Формируем словарь тэгов
	if (!GetTagsArray(input_stream)) return false;

    wxFileName* full_path = new wxFileName(file_name);
    wxString country = (full_path->GetDirs())[full_path->GetDirCount() - 1];
    delete full_path;

    //wxXmlNode* xmlroot = new wxXmlNode(wxXML_ELEMENT_NODE, country);

    //PS.readElement(reader, xmlroot, xDoc, dictionary);
    //xDoc.AppendChild(xmlroot);
	/*
	    wxUint16 children_count = data_stream.Read16();

	    //---------------------------------------------
	    wxUint32 data = data_stream.Read32();
	    wxUint32 end = data & 0x0fffffff;
	    wxUint32 type = data >> 28;
	    wxUint32 address = input_stream.TellI();
	    DataDescriptor main_header_desc(end, type, address);
	    //---------------------------------------------

	    //---------------------------------------------
	    //TODO: Переделать в динамический массив
	    ElementDescriptor* children[100];
	    for (int i = 0; i < children_count; i++) {
	        wxUint16 name_index = data_stream.Read16();

	        wxUint32 data = data_stream.Read32();
	        wxUint32 end = data & 0x0fffffff;
	        wxUint32 type = data >> 28;
	        wxUint32 address = input_stream.TellI();
	        DataDescriptor data_descriptor(end, type, address);

	        children[i] = new ElementDescriptor(name_index, data_descriptor);
	    }
	    //---------------------------------------------

	    //int offset = readData(reader, dictionary, element, xDoc, 0, selfDataDescriptor);

	/*
	            int offset = readData(reader, dictionary, element, xDoc, 0, selfDataDescriptor);
	            long oldPos;

	            foreach (ElementDescriptor elementDescriptor in children)
	            {
	                XmlNode child = xDoc.CreateElement(dictionary[elementDescriptor.nameIndex]);
	                oldPos = reader.BaseStream.Position;
	                Debug.Write("reading >" + child.Name + "<, pisible length " + (elementDescriptor.dataDescriptor.end - offset).ToString() + ", offset " + offset.ToString() + ", dd.end " + elementDescriptor.dataDescriptor.end.ToString() + ", file position " + reader.BaseStream.Position.ToString());

	                offset = readData(reader, dictionary, child, xDoc, offset, elementDescriptor.dataDescriptor);

	                Debug.WriteLine("; i got >>>" + child.InnerXml + "<<<, new offset " + offset.ToString() + ", new file position " + reader.BaseStream.Position.ToString() + ", real length " + (reader.BaseStream.Position - oldPos).ToString());

	                element.AppendChild(child);
	            }
	*/




	/*
	    for (int i = 0; i < children_count; ++i)
	        if (children[i]) delete children[i];
	*/
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
