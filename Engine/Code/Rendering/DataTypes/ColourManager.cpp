// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/18 15:29)

#include "Rendering/RenderingExport.h"

#include "ColourManager.h"
#include "System/Helper/ConfigMacro.h"

unsigned int Rendering::ColourManager
	::MakeR8G8B8 (unsigned char red, unsigned char green, unsigned char blue)
{
	return MakeR8G8B8A8(red,green,blue,255);
}

unsigned int Rendering::ColourManager
	::MakeR8G8B8A8 (unsigned char red,unsigned char green, unsigned char blue, unsigned char alpha)
{
#ifdef SYSTEM_BIG_ENDIAN
    return (alpha | (blue << 8) | (green << 16) | (red << 24));
#else // !SYSTEM_BIG_ENDIAN
    return (red | (green << 8) | (blue << 16) | (alpha << 24));
#endif // SYSTEM_BIG_ENDIAN
}

void Rendering::ColourManager
	::ExtractR8G8B8 (unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue)
{
	unsigned char alpha{};

	return ExtractR8G8B8A8(color,red,green,blue,alpha);
}

void Rendering::ColourManager
	::ExtractR8G8B8A8 (unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue,  unsigned char& alpha)
{
#ifdef SYSTEM_BIG_ENDIAN
    red =  static_cast<unsigned char>((color & 0xFF000000) >> 24);
    green = static_cast<unsigned char>((color & 0x00FF0000) >> 16);
    blue = static_cast<unsigned char>((color & 0x0000FF00) >>  8);
    alpha = static_cast<unsigned char>((color & 0x000000FF));
#else // !SYSTEM_BIG_ENDIAN
    red = static_cast<unsigned char>((color & 0x000000FF));
    green = static_cast<unsigned char>((color & 0x0000FF00) >>  8);
    blue = static_cast<unsigned char>((color & 0x00FF0000) >> 16);
    alpha = static_cast<unsigned char>((color & 0xFF000000) >> 24);
#endif // SYSTEM_BIG_ENDIAN
}
