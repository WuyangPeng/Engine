// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 10:58)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_BIT_MAPFONT_H
#define RENDERING_OPENGL_RENDERER_OPENGL_BIT_MAPFONT_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
	class BitmapFontChar
	{
	public:
		BitmapFontChar(int xOrigin, int yOrigin, int xSize, int ySize,const unsigned char* bitmap)
		{
			mXOrigin = xOrigin;
			mYOrigin = yOrigin;
			mXSize = xSize;
			mYSize = ySize;
			mBitmap = bitmap;
		}

		int mXOrigin, mYOrigin, mXSize, mYSize;
		const unsigned char* mBitmap;
	};

	class BitmapFont
	{
	public:
		BitmapFont(const char* name, int numCharacters,const BitmapFontChar* const* characters)
		{
			mName = name;
			mNumCharacters = numCharacters;
			mCharacters = characters;
		}

		const char* mName;
		int mNumCharacters;
		const BitmapFontChar* const* mCharacters;
	};

	extern const BitmapFont gVerdanaS16B0I0;
}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_BIT_MAPFONT_H
