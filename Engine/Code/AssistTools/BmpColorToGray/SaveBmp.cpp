// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:15)

#include "AssistTools/AssistToolsExport.h"

#include "SaveBmp.h"
#include "System/Helper/PragmaWarning/Disable4996.h"

#include <windows.h>
#include <cassert>
#include <cstdio>

AssistTools::SaveBmp
	::SaveBmp (const char* name, int width, int height, unsigned char* data)
{
    assert((width % 4) == 0);
    int quantity = width*height;
    int numBytes = 3*quantity;

    BITMAPFILEHEADER fileHeader;
    fileHeader.bfType = 0x4d42;  // "BM"
    fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) +  numBytes;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    BITMAPINFOHEADER infoHeader;
    infoHeader.biSize = sizeof(BITMAPINFOHEADER);
    infoHeader.biWidth = width;
    infoHeader.biHeight = height;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24;
    infoHeader.biCompression = BI_RGB;
    infoHeader.biSizeImage = 0;
    infoHeader.biXPelsPerMeter = 0;
    infoHeader.biYPelsPerMeter = 0;
    infoHeader.biClrUsed = 0;
    infoHeader.biClrImportant = 0;

    FILE* outFile = fopen(name, "wb");
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outFile);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outFile);
    fwrite(data, sizeof(unsigned char), numBytes, outFile);
    fclose(outFile);
} 