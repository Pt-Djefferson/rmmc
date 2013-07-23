#include "tankslist.h"

djfTanksList::djfTanksList()
{
    //ctor
}

djfTanksList::~djfTanksList()
{
    //dtor
}

bool djfTanksList::Load(const wxString& file_name) {
    wxFileInputStream input(file_name);
    wxDataInputStream stream(input);

    if (stream.IsOk()) {
        wxUint32 header = 0;
        stream >> header;
        if (header == 0x62a14e45) {
            wxUint8 zero;
            stream >> zero;

            return true;
        }
    }
    return false;
}
