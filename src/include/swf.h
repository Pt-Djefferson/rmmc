#ifndef SWF_H
#define SWF_H

#include <wx/wfstream.h>
#include <wx/datstrm.h>
#include <wx/zstream.h>
#include <wx/image.h>
#include <wx/zipstrm.h>

struct swfRect {
    wxUint8 Bits;
    wxInt32 Xmin; //всегда 0
    wxInt32 Xmax;
    wxInt32 Ymin; //всегда 0
    wxInt32 Ymax;
};

struct swfHeader {
    wxUint8  CompressingType;
    wxUint16 Signature; //всегда "WS"
    wxUint8  Version;
    wxUint32 FileLength;
};

struct swfFrameHeader {
    swfRect  FrameSize;
    wxUint16 FrameRate;
    wxUint16 FrameCount;
};

struct RGBData {
    wxUint8 Red;
    wxUint8 Green;
    wxUint8 Blue;
};

bool LoadImageFromSwfInPKG(const wxString& full_pkg_name, const wxString& relative_file_name, const wxUint16 tag_id, wxImage& image);

#endif // SWF_H
