// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 13:44)

#ifndef ASSIST_TOOLS_BMP_COLOR_TO_GRAY_SAVE_BMP_H
#define ASSIST_TOOLS_BMP_COLOR_TO_GRAY_SAVE_BMP_H

#include "AssistTools/AssistToolsDll.h"

namespace AssistTools
{	
	class ASSIST_TOOLS_DEFAULT_DECLARE SaveBmp
	{
	public:
		SaveBmp (const char* name, int width, int height, unsigned char* data);
	};
}

#endif // ASSIST_TOOLS_BMP_COLOR_TO_GRAY_SAVE_BMP_H
