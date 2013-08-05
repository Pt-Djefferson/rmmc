#include "swf.h"

bool LoadImageFromSwfInPKG(const wxString& full_pkg_name, const wxString& relative_file_name, const wxUint16 tag_id, wxImage& image) {
	wxFFileInputStream pkg_input_stream(full_pkg_name);
	if (!pkg_input_stream.IsOk()) return false;
	wxZipInputStream pkg_zip_stream(pkg_input_stream);

    wxZipEntry* entry;
    entry = pkg_zip_stream.GetNextEntry();
    while (entry) {
        if (entry->GetName() == relative_file_name) break;
        entry = pkg_zip_stream.GetNextEntry();
    }

	wxDataInputStream* header_data_stream = new wxDataInputStream(pkg_zip_stream);
	swfHeader swf_header;
	swf_header.CompressingType = header_data_stream->Read8();
	swf_header.Signature = header_data_stream->Read16();
	swf_header.Version = header_data_stream->Read8();
	swf_header.FileLength = header_data_stream->Read32();
	delete header_data_stream;

    wxInputStream* input_stream = nullptr;
	if (swf_header.CompressingType == 0x43) {
        input_stream = new wxZlibInputStream(pkg_zip_stream);
	} else {
	    input_stream = &pkg_zip_stream;
	}
	wxDataInputStream data_stream(*input_stream);

    wxUint8 frame_bits = data_stream.Read8();
    wxUint8 frame_length_in_bits = (frame_bits >> 3) * 4 - 3;
    wxUint8 frame_length_in_bytes = frame_length_in_bits / 8 + (frame_length_in_bits % 8 > 0) + 4;
    input_stream->SeekI(frame_length_in_bytes, wxFromCurrent);

    while (!input_stream->Eof()) {
        wxUint16 tag_type_and_length = data_stream.Read16();
        wxUint16 tag_type = tag_type_and_length >> 6;
        wxUint32 tag_length = tag_type_and_length & 0x3f;
        if (tag_length == 0x3f)
            tag_length = data_stream.Read32();

        if (tag_type == 0) break;

        if (/*tag_type == 20 || */tag_type == 36) {
            wxUint16 char_id = data_stream.Read16();
            wxUint8 bitmap_format = data_stream.Read8();
            wxUint16 bitmap_width = data_stream.Read16();
            wxUint16 bitmap_height = data_stream.Read16();
            //wxUint8 bitmap_color_table_size = 0;
            if (bitmap_format == 3) {
                    /*bitmap_color_table_size = */data_stream.Read8();
                    --tag_length;
            }
            tag_length -= 7;
            if (char_id != tag_id) {
                input_stream->SeekI(tag_length, wxFromCurrent);
            } else {
                wxUint32 bitmap_size = bitmap_width * bitmap_height;

                wxZlibInputStream argb_zlib_stream(*input_stream);
                wxDataInputStream argb_zlib_data_stream(argb_zlib_stream);

                wxUint8* alpha_buffer;
                RGBData*   data_buffer;
                alpha_buffer = (wxUint8*) malloc (bitmap_size);
                data_buffer = (RGBData*) malloc (bitmap_size * 3);
                for (wxUint32 i = 0; i < bitmap_size; ++i) {
                    alpha_buffer[i] = argb_zlib_data_stream.Read8();
                    data_buffer[i].Red = argb_zlib_data_stream.Read8();
                    data_buffer[i].Green = argb_zlib_data_stream.Read8();
                    data_buffer[i].Blue = argb_zlib_data_stream.Read8();
                }
                image.SetData((unsigned char*) data_buffer, bitmap_width, bitmap_height);

                if (image.HasAlpha()) image.ClearAlpha();
                image.InitAlpha();
                image.SetAlpha((unsigned char*) alpha_buffer);
                break;
            }
        } else {
            input_stream->SeekI(tag_length, wxFromCurrent);
        }
    }
	if (swf_header.CompressingType == 0x43) {
        delete input_stream;
	}

    return true;
}
