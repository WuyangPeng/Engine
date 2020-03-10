// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:15)

#ifndef ASSIST_TOOLS_BMP_TO_WMTF_LOAD_BMP_USE_ALPHA_H
#define ASSIST_TOOLS_BMP_TO_WMTF_LOAD_BMP_USE_ALPHA_H
 
#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{	
	class ASSIST_TOOLS_DEFAULT_DECLARE LoadBmpUseAlpha
	{
	public:
		LoadBmpUseAlpha(const System::TChar* name, unsigned char alpha, int& width, int& height, unsigned char*& texels);
	};
}


#endif // ASSIST_TOOLS_BMP_TO_WMTF_LOAD_BMP_USE_ALPHA_H
