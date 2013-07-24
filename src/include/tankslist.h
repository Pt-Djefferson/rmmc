#ifndef TANKSLIST_H
#define TANKSLIST_H

#include <wx/settings.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <wx/arrstr.h>
#include <wx/hashmap.h>
#include <wx/xml/xml.h>
#include <wx/filename.h>

#include <wx/tokenzr.h>

struct Descriptor {
    wxUint32 tag_index = -1;
    union {
        wxUint32 raw_info;
        struct /*info*/ {
            wxUint32 end  :28;
            wxUint32 type :4;
        };
    };
};

class djfTanksList {
public:
	djfTanksList();
	~djfTanksList();
	bool Load(const wxString &file_name);

	wxArrayString m_tags_dictionary;
	wxStringToNumHashMap m_names_hash;
	wxXmlDocument m_undecoded_xml;
protected:
private:
    bool GetTagsArray(wxFileInputStream& input_stream);
    wxString ReadNullTerminatedString(wxFileInputStream& input_stream);
	wxDECLARE_NO_COPY_CLASS(djfTanksList);
};

#endif // TANKSLIST_H
