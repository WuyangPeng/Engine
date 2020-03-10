// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:15)

#include "AssistTools/AssistToolsExport.h"

#include "ColorToGray.h"

AssistTools::ColorToGray
	::ColorToGray(int width, int height, unsigned char* data)
{
	unsigned char* color = data;
	for (int i = 0; i < width*height; ++i, color += 3)
	{
		float b = (float)color[0];
		float g = (float)color[1];
		float r = (float)color[2];
		unsigned char gray = (unsigned char)(0.30f*r + 0.59f*g + 0.11f*b);
		color[0] = gray;
		color[1] = gray;
		color[2] = gray;
	}
}



 
