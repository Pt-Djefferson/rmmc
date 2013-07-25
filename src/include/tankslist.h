#ifndef TANKSLIST_H
#define TANKSLIST_H

#include <wx/settings.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <wx/arrstr.h>
//#include <wx/hashmap.h>
#include <wx/xml/xml.h>
#include <wx/filename.h>
#include <wx/dynarray.h>
#include <wx/dir.h>


#define djfELEMENT 0
#define djfSTRING  1
#define djfINTEGER 2
#define djfFLOAT   3
#define djfBOOLEAN 4
#define djfBASE64  5

struct Descriptor {
    wxUint16 tag_index = wxUINT16_MAX;
    union {
        wxUint32 raw_info;
        struct /*info*/ {
            wxUint32 end  :28;
            wxUint32 type :4;
        };
    };
};

WX_DECLARE_OBJARRAY(Descriptor, ArrayOfDescriptors);

class djfTanksList {
public:
	djfTanksList();
	~djfTanksList();
	bool Load(const wxString& game_dir);

	wxArrayString m_tags_dictionary;
	wxArrayString m_tanks;
	wxArrayString m_tanks_strings;
	wxArrayString m_tanks_names;
	//wxStringToNumHashMap m_names_hash;
	wxXmlDocument m_undecoded_xml;
protected:
private:
    bool UnpackXMLFile(const wxString& path, const wxString& nation, const wxString& file_name);
    bool GetTagsArray(wxFileInputStream& input_stream);
    void AddElement(wxXmlNode* node, wxFileInputStream& input_stream);
    void ReadElement(wxXmlNode* node, wxFileInputStream& input_stream, const Descriptor& descriptor, wxUint32& offset);
    wxString ReadNullTerminatedString(wxFileInputStream& input_stream);
    wxString ReadString(wxFileInputStream& input_stream, wxUint32 length);
    wxString ReadInteger(wxFileInputStream& input_stream, wxUint32 length);
    wxString ReadFloat(wxFileInputStream& input_stream, wxUint32 length);
    wxString ReadBoolean(wxFileInputStream& input_stream, wxUint32 length);
    wxString ReadBase64(wxFileInputStream& input_stream, wxUint32 length);
    void FillTanksArraysFromXML();
    bool LoadMOFile(const wxString& file_name);
	wxDECLARE_NO_COPY_CLASS(djfTanksList);
};

#endif // TANKSLIST_H
