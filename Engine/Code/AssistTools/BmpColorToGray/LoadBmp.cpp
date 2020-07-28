// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:15)

#include "AssistTools/AssistToolsExport.h"

#include "LoadBmp.h"

#include <windows.h>
#include <cassert>
#include <cstdio>

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26451)
AssistTools::LoadBmp
	::LoadBmp (const System::TChar* name, int& width, int& height, unsigned char*& data)
{
    HBITMAP hImage = static_cast<HBITMAP>( LoadImage(NULL, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
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
#include STSTEM_WARNING_POP