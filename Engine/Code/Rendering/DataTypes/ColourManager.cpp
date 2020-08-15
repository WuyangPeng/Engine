// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:29)

#include "Rendering/RenderingExport.h"

#include "ColourManager.h"
#include "System/Helper/ConfigMacro.h"

#include<gsl/gsl_util>

 
void Rendering::ColourManager
	::ExtractR8G8B8 (unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue) noexcept
{
	unsigned char alpha{};

	return ExtractR8G8B8A8(color,red,green,blue,alpha);
}

void Rendering::ColourManager
	::ExtractR8G8B8A8 (unsigned int color, unsigned char& red, unsigned char& green, unsigned char& blue,  unsigned char& alpha) noexcept
{
#ifdef SYSTEM_BIG_ENDIAN
    red =  gsl::narrow_cast<unsigned char>((color & 0xFF000000) >> 24);
    green = gsl::narrow_cast<unsigned char>((color & 0x00FF0000) >> 16);
    blue = gsl::narrow_cast<unsigned char>((color & 0x0000FF00) >>  8);
    alpha = gsl::narrow_cast<unsigned char>((color & 0x000000FF));
#else // !SYSTEM_BIG_ENDIAN
    red = gsl::narrow_cast<unsigned char>((color & 0x000000FF));
    green = gsl::narrow_cast<unsigned char>((color & 0x0000FF00) >>  8);
    blue = gsl::narrow_cast<unsigned char>((color & 0x00FF0000) >> 16);
    alpha = gsl::narrow_cast<unsigned char>((color & 0xFF000000) >> 24);
#endif // SYSTEM_BIG_ENDIAN
}
