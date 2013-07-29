#ifndef SWF_H
#define SWF_H

struct swfRect {
    wxUint8 Bits;
    wxInt32 Xmin; //всегда 0
    wxInt32 Xmax;
    wxInt32 Ymin; //всегда 0
    wxInt32 Ymax;
};

struct swfHeader {
    wxUint8  CompressingType;
    wxUint16 Signature;
    wxUint8  Version;
    wxUint16 FileLength;
};

struct swfFrameHeader {
    swfRect  FrameSize;
    wxUint16 FrameRate;
    wxUint16 FrameCount;
};

class swf
{
    public:
        /** Default constructor */
        swf();
        /** Default destructor */
        virtual ~swf();
    protected:
    private:
};

#endif // SWF_H
