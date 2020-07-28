// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:15)

#include "AssistTools/AssistToolsExport.h"

#include "ColorToGray.h"
#include "System/Helper/PragmaWarning.h"

AssistTools::ColorToGray
	::ColorToGray(int width, int height, unsigned char* data) noexcept
{

#include STSTEM_WARNING_PUSH
	 #include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26489)
	unsigned char* color = data;
	if(color != nullptr)
	{
		for(int i = 0; i < width * height; ++i, color += 3)
		{
			const float b = static_cast<float>(color[0]);
			const float g = static_cast<float>(color[1]);
			const float r = static_cast<float>(color[2]);
			const unsigned char gray = static_cast<unsigned char>(0.30f * r + 0.59f * g + 0.11f * b);
			color[0] = gray;
			color[1] = gray;
			color[2] = gray;
		}
	}
#include STSTEM_WARNING_POP
}



 
