// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/17 14:25)

#ifndef RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H
#define RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H

#include "Flags/TextureFormat.h"
#include "HalfFloat.h"

namespace Rendering
{
	struct TrueType
	{
        
	};
    
	struct FalseType
	{
        
	};
	
	template <TextureFormat T>
	struct ColourTextureFormatTraits; 

	template <>
	struct ColourTextureFormatTraits<TextureFormat::R5G6B5>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0x1F;
		static constexpr auto sm_GreenMaxValue = 0x3F;
		static constexpr auto sm_BlueMaxValue = 0x1F;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 3;

		using BitType= uint8_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 0,
		    ColourTextureFormatTraitsGreen = 1,
		    ColourTextureFormatTraitsBlue = 2,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::A1R5G5B5>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0x1F;
		static constexpr auto sm_GreenMaxValue = 0x1F;
		static constexpr auto sm_BlueMaxValue = 0x1F;
		static constexpr auto sm_AlphaMaxValue = 0x01;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 4;

		using BitType = uint8_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 1,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 3,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::A4R4G4B4>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0x0F;
		static constexpr auto sm_GreenMaxValue = 0x0F;
		static constexpr auto sm_BlueMaxValue = 0x0F;
		static constexpr auto sm_AlphaMaxValue = 0x0F;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 4;

		using BitType = uint8_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 1,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 3,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::A8>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0;
		static constexpr auto sm_GreenMaxValue = 0;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0xFF;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 1;

		using BitType = uint8_t;
		using RedType = FalseType;
		using GreenType = FalseType;
		using BlueType = FalseType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = -1,
		    ColourTextureFormatTraitsGreen = -1,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::L8>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0;
		static constexpr auto sm_GreenMaxValue = 0;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0xFF;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 1;

		using BitType = uint8_t;
		using RedType = FalseType;
		using GreenType = FalseType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = TrueType;

		enum
		{
		    ColourTextureFormatTraitsRed = -1,
		    ColourTextureFormatTraitsGreen = -1,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = 0,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::A8L8>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0;
		static constexpr auto sm_GreenMaxValue = 0;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0xFF;
		static constexpr auto sm_LuminanceMaxValue = 0xFF;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 2;

		using BitType = uint8_t;
		using RedType = FalseType;
		using GreenType = FalseType;
		using BlueType = FalseType;
		using AlphaType = TrueType;
		using LuminanceType = TrueType;

		enum
		{
		    ColourTextureFormatTraitsRed = -1,
		    ColourTextureFormatTraitsGreen = -1,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = 1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::R8G8B8>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0xFF;
		static constexpr auto sm_GreenMaxValue = 0xFF;
		static constexpr auto sm_BlueMaxValue = 0xFF;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 3;

		using BitType = uint8_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 0,
		    ColourTextureFormatTraitsGreen = 1,
		    ColourTextureFormatTraitsBlue = 2,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = 1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::A8R8G8B8>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0xFF;
		static constexpr auto sm_GreenMaxValue = 0xFF;
		static constexpr auto sm_BlueMaxValue = 0xFF;
		static constexpr auto sm_AlphaMaxValue = 0xFF;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 4;

		using BitType = uint8_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 1,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 3,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

	template <>
	struct ColourTextureFormatTraits<TextureFormat::A8B8G8R8>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0xFF;
		static constexpr auto sm_GreenMaxValue = 0xFF;
		static constexpr auto sm_BlueMaxValue = 0xFF;
		static constexpr auto sm_AlphaMaxValue = 0xFF;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 4;

		using BitType = uint8_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 3,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 1,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};
 
 	template <>
	struct ColourTextureFormatTraits<TextureFormat::L16>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0;
		static constexpr auto sm_GreenMaxValue = 0;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0xFFFF;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 1;

		using BitType = uint16_t;
		using RedType = FalseType;
		using GreenType = FalseType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = TrueType;

		enum
		{
		    ColourTextureFormatTraitsRed = -1,
		    ColourTextureFormatTraitsGreen = -1,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = 0,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::G16R16>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0xFFFF;
		static constexpr auto sm_GreenMaxValue = 0xFFFF;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 2;

		using BitType = uint16_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 1,
		    ColourTextureFormatTraitsGreen = 0,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::A16B16G16R16>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 0xFFFF;
		static constexpr auto sm_GreenMaxValue = 0xFFFF;
		static constexpr auto sm_BlueMaxValue = 0xFFFF;
		static constexpr auto sm_AlphaMaxValue = 0xFFFF;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = false;
		static constexpr auto sm_ArraySize = 4;

		using BitType = uint16_t;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 3,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 1,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 
 	template <>
	struct ColourTextureFormatTraits<TextureFormat::R16F>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 1;
		static constexpr auto sm_GreenMaxValue = 0;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = true;
		static constexpr auto sm_ArraySize = 1;

		using BitType = HalfFloat;
		using RedType = TrueType;
		using GreenType = FalseType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 0,
		    ColourTextureFormatTraitsGreen = -1,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::G16R16F>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 1;
		static constexpr auto sm_GreenMaxValue = 1;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = true;
		static constexpr auto sm_ArraySize = 2;

		using BitType = HalfFloat;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 1,
		    ColourTextureFormatTraitsGreen = 0,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 1;
		static constexpr auto sm_GreenMaxValue = 1;
		static constexpr auto sm_BlueMaxValue = 1;
		static constexpr auto sm_AlphaMaxValue = 1;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = true;
		static constexpr auto sm_ArraySize = 4;

		using BitType = HalfFloat;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 3,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 1,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::R32F>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 1;
		static constexpr auto sm_GreenMaxValue = 0;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = true;
		static constexpr auto sm_ArraySize = 1;

		using BitType = float;
		using RedType = TrueType;
		using GreenType = FalseType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 0,
		    ColourTextureFormatTraitsGreen = -1,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::G32R32F>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 1;
		static constexpr auto sm_GreenMaxValue = 1;
		static constexpr auto sm_BlueMaxValue = 0;
		static constexpr auto sm_AlphaMaxValue = 0;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = true;
		static constexpr auto sm_ArraySize = 2;

		using BitType = float;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = FalseType;
		using AlphaType = FalseType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 1,
		    ColourTextureFormatTraitsGreen = 0,
		    ColourTextureFormatTraitsBlue = -1,
		    ColourTextureFormatTraitsAlpha = -1,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};

 	template <>
	struct ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_RedMaxValue = 1;
		static constexpr auto sm_GreenMaxValue = 1;
		static constexpr auto sm_BlueMaxValue = 1;
		static constexpr auto sm_AlphaMaxValue = 1;
		static constexpr auto sm_LuminanceMaxValue = 0;
		static constexpr auto sm_IsFloatingPoint = true;
		static constexpr auto sm_ArraySize = 4;

		using BitType = float;
		using RedType = TrueType;
		using GreenType = TrueType;
		using BlueType = TrueType;
		using AlphaType = TrueType;
		using LuminanceType = FalseType;

		enum
		{
		    ColourTextureFormatTraitsRed = 3,
		    ColourTextureFormatTraitsGreen = 2,
		    ColourTextureFormatTraitsBlue = 1,
		    ColourTextureFormatTraitsAlpha = 0,
		    ColourTextureFormatTraitsLuminance = -1,
		};
	};
}

#endif // RENDERING_DATA_TYPES_COLOUR_TEXTURE_FORMAT_TRAITS_H
