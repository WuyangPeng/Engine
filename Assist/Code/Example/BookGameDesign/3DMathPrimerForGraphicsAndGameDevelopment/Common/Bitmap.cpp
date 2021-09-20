/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// Bitmap.cpp - Simple bitmap loader
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Bitmap.h"
#include "CommonStuff.h"
#include "Renderer.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4996)
#include SYSTEM_WARNING_DISABLE(26408)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)

/////////////////////////////////////////////////////////////////////////////
//
// Local stuff
//
/////////////////////////////////////////////////////////////////////////////

// File header for .TGA file
namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
#pragma pack(1)

    struct TGAHeader
    {
        unsigned char imageIDLength;
        unsigned char colorMapType;
        unsigned char imageType;
        unsigned short colorMapFirstIndex;
        unsigned short colorMapLength;
        unsigned char colorMapBitsPerEntry;
        unsigned short xOrigin, yOrigin;
        unsigned short width, height;
        unsigned char bitsPerPixel;
        unsigned char imageDescriptor;
    };

#pragma pack()

    /////////////////////////////////////////////////////////////////////////////
    //
    // class Bitmap member functions
    //
    /////////////////////////////////////////////////////////////////////////////

    //---------------------------------------------------------------------------
    // Bitmap::Bitmap
    //
    // Constructor - reset interval variables to default, empty state

    Bitmap::Bitmap() noexcept
    {
        sizeX = 0;
        sizeY = 0;
        fmt = eFormat_None;
        data = nullptr;
    }

    //---------------------------------------------------------------------------
    // Bitmap::~Bitmap
    //
    // Destructor - make sure resources are freed

    Bitmap::~Bitmap() noexcept
    {
        freeMemory();
    }

    //---------------------------------------------------------------------------
    // Bitmap::allocateMemory
    //
    // Allocate a bitmap in the specified format

    void Bitmap::allocateMemory(int xs, int ys, EFormat format) noexcept
    {
        // Sanity check

        assert(xs > 0);
        assert(ys > 0);

        // First, free up anything already allocated

        freeMemory();

        // Figure out how big one row is, in bytes

        int rowBytes = 0;
        switch (format)
        {
            case eFormat_8888:
                rowBytes = xs * 4;
                break;

            default:
                assert(false);  // bogus pixel format
        }

        // Allocate memory
        const auto mallocSize = ys * rowBytes;
        data = malloc(mallocSize);
        if (data == nullptr)
        {
            ABORT("Out of memory for bitmap");
        }

        // Remember dimensions

        sizeX = xs;
        sizeY = ys;
        fmt = format;
    }

    //---------------------------------------------------------------------------
    // Bitmap::freeMemory
    //
    // Allocate a bitmap in the specified format

    void Bitmap::freeMemory() noexcept
    {
        // Free memory, if some was allocated

        if (data != nullptr)
        {
            free(data);
            data = nullptr;
        }

        // Reset

        sizeX = 0;
        sizeY = 0;
        fmt = eFormat_None;
    }

    //---------------------------------------------------------------------------
    // Bitmap::getPix
    //
    // Fetch a pixel at the given coordinates.  The pixel is always returned in
    // 32-bit 0xAARRGGBB format, the same as used by the Renderer class
    // and MAKE_ARGB macro.

    unsigned Bitmap::getPix(int x, int y) const noexcept
    {
        // Safety check

        if ((x < 0) || (y < 0) || (x >= sizeX) || (y >= sizeY) || (data == nullptr))
        {
            assert(false);
            return 0;
        }

        // Check format

        unsigned result = 0;
        switch (fmt)
        {
            case eFormat_8888:
                result = static_cast<unsigned*>(data)[y * sizeX + x];
                break;

            default:
                assert(false);
                result = 0;
                break;
        }

        // Return it

        return result;
    }

    //---------------------------------------------------------------------------
    // Bitmap::setPix
    //
    // Set a pixel at the given coordinates.  The pixel is specified in
    // 32-bit 0xAARRGGBB format, the same as used by the Renderer class
    // and MAKE_ARGB macro.

    void Bitmap::setPix(int x, int y, unsigned argb) noexcept
    {
        // Safety check

        if ((x < 0) || (y < 0) || (x >= sizeX) || (y >= sizeY) || (data == nullptr))
        {
            assert(false);
            return;
        }

        // Check format

        switch (fmt)
        {
            case eFormat_8888:
                static_cast<unsigned*>(data)[y * sizeX + x] = argb;
                break;

            default:
                assert(false);
                break;
        }
    }

    //---------------------------------------------------------------------------
    // Bitmap::load
    //
    // Load a bitmap from an image file.  Uses the extension to
    // figure out how to load.

    bool Bitmap::load(const char* filename, char* returnErrMsg) noexcept
    {
        // Free up anything already allocated

        freeMemory();

        // Fetch extension.  I wish I could use the _splitpath function,
        // but it's not cross-platform.  I'll parse the thing myself.

        const char* ext = strchr(filename, '.');
        if (ext == nullptr)
        {
            strcpy(returnErrMsg, "Filename has no extension");
            return false;
        }
        for (;;)
        {
            const char* dot = strchr(ext + 1, '.');
            if (dot == nullptr)
            {
                break;
            }
            ext = dot;
        }

        // Check for known extensions

        if (stricmp(ext, ".tga") == 0)
        {
            return loadTGA(filename, returnErrMsg);
        }
        if (stricmp(ext, ".bmp") == 0)
        {
            return loadBMP(filename, returnErrMsg);
        }

        // Unknown extension

        sprintf(returnErrMsg, "Unknown/unsupported file extension '%s'", ext);
        return false;
    }

    //---------------------------------------------------------------------------
    // Bitmap::loadTGA
    //
    // Load image in .TGA format.

    bool Bitmap::loadTGA(const char* filename, char* returnErrMsg) noexcept
    {
        // Open the file

        FILE* f = fopen(filename, "rb");
        if (f == nullptr)
        {
            strcpy(returnErrMsg, "Can't open file.");

            return Cleanup(f);
        }

        // Read TGA header

        TGAHeader head;
        if (fread(&head, sizeof(head), 1, f) != 1)
        {
            return IOError(returnErrMsg, f);
        }

        // Check format

        if (head.imageType == 2)
        {  // UNCOMPRESSED_TRUECOLOR
            if ((head.bitsPerPixel != 24) && (head.bitsPerPixel != 32))
            {
                sprintf(returnErrMsg, "%d-bit truecolor image not supported", static_cast<int>(head.bitsPerPixel));
                return Cleanup(f);
            }
            if (head.colorMapType != 0)
            {
                strcpy(returnErrMsg, "Truecolor image with colormap not supported");
                return Cleanup(f);
            }
            //} else if (head.imageType == 1) { // UNCOMPRESSED_COLORMAPPED
            //	if (
            //		(head.colorMapType != 1) ||
            //		(head.bitsPerPixel != 8) ||
            //		(head.colorMapFirstIndex != 0) ||
            //		(head.colorMapLength != 256) ||
            //		(head.colorMapBitsPerEntry != 24)
            //	) {
            //		strcpy(returnErrMsg, "Invalid colormapped image file format");
            //		return 0;
            //	}
        }
        else
        {
            sprintf(returnErrMsg, ".TGA image type %d not supported", static_cast<int>(head.imageType));
            return Cleanup(f);
        }

        // Check origin

        assert(!(head.imageDescriptor & 0x10));  // x origin at the right not supported

        // Allocate image of the correct size

        allocateMemory(head.width, head.height, eFormat_8888);

        // Read the image data, in file order

        // int	rowSz = head.bitsPerPixel / 8 * sizeX;
        for (int y = 0; y < sizeY; ++y)
        {
            // Figure out which row this is in the image.
            // TGA's can be stored "upside down"

            int dy = 0;
            if (head.imageDescriptor & 0x20)
            {
                dy = y;
            }
            else
            {
                dy = sizeY - y - 1;
            }

            // Get shortcut pointer to first pixel in the row

            auto step = dy * sizeX;
            unsigned* destPtr = static_cast<unsigned*>(data) + step;

            // Read in the data for this row

            for (int x = 0; x < sizeX; ++x)
            {
                int b = fgetc(f);
                int g = fgetc(f);
                int r = fgetc(f);
                int a = 0;
                if (head.bitsPerPixel == 24)
                {
                    a = 255;
                }
                else
                {
                    a = fgetc(f);
                }
                if (b < 0 || g < 0 || r < 0 || a < 0)
                {
                    return IOError(returnErrMsg, f);
                }
                *destPtr = MAKE_ARGB(a, r, g, b);
                ++destPtr;
            }
        }

        // OK

        fclose(f);
        return true;
    }

    bool Bitmap::IOError(char* returnErrMsg, FILE* f) noexcept
    {
        strcpy(returnErrMsg, "I/O error, or file is corrupt.");
        return Cleanup(f);
    }

    //---------------------------------------------------------------------------
    // Bitmap::loadBMP
    //
    // Load image in .BMP format.

    bool Bitmap::loadBMP([[maybe_unused]] const char* filename, char* returnErrMsg) noexcept
    {
        // Free up anything already allocated

        freeMemory();

        // !FIXME!

        assert(false);
        strcpy(returnErrMsg, "BMP support not implemented yet");
        return false;
    }

    bool Bitmap::Cleanup(FILE* f) noexcept
    {
        // Cleanup

        freeMemory();
        if (f != nullptr)
        {
            fclose(f);
        }

        // Report failure

        return false;
    }

}
#include STSTEM_WARNING_POP