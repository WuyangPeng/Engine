// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 13:45)

#ifndef RENDERING_SHADERS_ALPHA_STATE_FLAGS_H
#define RENDERING_SHADERS_ALPHA_STATE_FLAGS_H

namespace Rendering
{ 
	namespace AlphaStateFlags
	{
		enum class SourceBlendMode
		{
			Zero,
			One,
			DestinationColor,
			OneMinusDestinationColor,
			SourceAlpha,
			OneMinusSourceAlpha,
			DestinationAlpha,
			OneMinusDestinationAlpha,
			SourceAlphaSaturate,
			ConstantColor,
			OneMinusConstantColor,
			ConstantAlpha,
			OneMinusConstantAlpha,

			Quantity
		};

		enum class DestinationBlendMode
		{
			Zero,
			One,
			SourceColor,
			OneMinusSourceColor,
			SourceAlpha,
			OneMinusSourceAlpha,
			DestinationAlpha,
			OneMinusDestinationAlpha,
			ConstantColor,
			OneMinusConstantColor,
			ConstantAlpha,
			OneMinusConstantAlpha,

			Quantity
		};

		enum class CompareMode
		{
			Never,
			Less,
			Equal,
			LessEqual,
			Greater,
			NotEqual,
			GreaterEqual,
			Always,

			Quantity
		};
	}    
}

#endif // RENDERING_SHADERS_ALPHA_STATE_FLAGS_H
