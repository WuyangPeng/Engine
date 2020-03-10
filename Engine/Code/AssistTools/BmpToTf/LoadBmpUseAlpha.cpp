// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:15)

#include "AssistTools/AssistToolsExport.h"

#include "LoadBmpUseAlpha.h"
#include "CoreTools/Helper/MemoryMacro.h"

#include <windows.h>
#include <cassert>

AssistTools::LoadBmpUseAlpha
	::LoadBmpUseAlpha(const System::TChar* name, unsigned char alpha, int& width, int& height, unsigned char*& texels)
{
	HBITMAP hImage = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, 0, 0,
		                                LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (!hImage)
	{
		assert(hImage);
		width = 0;
		height = 0;
		texels = 0;
		return;
	}

	DIBSECTION dibSection;
	GetObject(hImage, sizeof(DIBSECTION), &dibSection);

	width = dibSection.dsBm.bmWidth;
	height = dibSection.dsBm.bmHeight;

	if (dibSection.dsBm.bmBitsPixel == 24)
	{
		// Pad with an alpha channel.
		int numBytes = 4 * width*height;
		texels = NEW1<unsigned char>(numBytes);
		unsigned char* src = (unsigned char*)dibSection.dsBm.bmBits;
		unsigned char* trg = texels;
		for (int i = 0; i < numBytes; ++i)
		{
			if ((i % 4) == 3)
			{
				*trg++ = alpha;
			}
			else
			{
				*trg++ = *src++;
			}
		}
	}
	else if (dibSection.dsBm.bmBitsPixel == 32)
	{
		texels = NEW1<unsigned char>(4 * width*height);
		memcpy(texels, dibSection.dsBm.bmBits, 4 * width*height);
	}
	else
	{
		assert(false);
		texels = 0;
		DeleteObject(hImage);
		return;
	}

	DeleteObject(hImage); 
}

 