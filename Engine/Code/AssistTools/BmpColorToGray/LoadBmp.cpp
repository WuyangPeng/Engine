// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:15)

#include "AssistTools/AssistToolsExport.h"

#include "LoadBmp.h"

#include <windows.h>
#include <cassert>
#include <cstdio>

AssistTools::LoadBmp
	::LoadBmp (const System::TChar* name, int& width, int& height, unsigned char*& data)
{
    HBITMAP hImage = (HBITMAP) LoadImage(NULL, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    assert(hImage);

    DIBSECTION dibSection;
    GetObject(hImage, sizeof(DIBSECTION), &dibSection);

    width = dibSection.dsBm.bmWidth;
    height = dibSection.dsBm.bmHeight;
    assert(dibSection.dsBm.bmBitsPixel == 24);
    data = new unsigned char[3*width*height];
    memcpy(data, dibSection.dsBm.bmBits, 3*width*height);

    DeleteObject(hImage);
} 