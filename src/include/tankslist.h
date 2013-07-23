#ifndef TANKSLIST_H
#define TANKSLIST_H

#include <wx/settings.h>
#include <wx/wfstream.h>
#include <wx/datstrm.h>

class djfTanksList {
public:
	/** Default constructor */
	djfTanksList();
	/** Default destructor */
	virtual ~djfTanksList();
	bool Load(const wxString& file_name);
protected:
private:
    wxString m_file_name = "";
	wxDECLARE_NO_COPY_CLASS(djfTanksList);
};

#endif // TANKSLIST_H
