// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/17 18:18)

#ifndef RENDERING_DATA_TYPES_FWD_H
#define RENDERING_DATA_TYPES_FWD_H

#include "Flags/TextureFormat.h"

namespace Rendering
{
	class HalfFloat;

	template <typename T,typename Enable>
	struct ColourDefaultTraits;

	template <typename T>
	class Colour;

	template <TextureFormat T>
	struct ColourTextureFormatTraits;

	template <TextureFormat Format>
	class TextureColour;

	class ColourManager;
	class ColourConvertFrom;
	class ColourConvertTo;
	class Utility;
	class Transform;
	class Bound;

	enum class TextureFormat;
}

#endif // RENDERING_DATA_TYPES_FWD_H