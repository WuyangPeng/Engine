// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:20)

#include "Rendering/RenderingExport.h"

#include "ColourConvertTo.h"
#include "ColourDetail.h"
#include "HalfFloat.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/DataTypes/ColourTextureFormatTraits.h"

void Rendering::ColourConvertTo
    ::ConvertToR5G6B5 (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
    auto source = inTexels;
	auto target = reinterpret_cast<unsigned short*>(outTexels);
    for (int i = 0; i < numInTexels; ++i)
    {
		auto red = static_cast<unsigned short>(source->GetRed() * ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_RedMaxValue + 0.5f);        
		auto green = static_cast<unsigned short>(source->GetGreen() * ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_GreenMaxValue + 0.5f);        
		auto blue = static_cast<unsigned short>(source->GetBlue() * ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_BlueMaxValue + 0.5f);

        *target = blue | (green << 5) | (red << 11);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA1R5G5B5 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned short*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		auto red = static_cast<unsigned short>(source->GetRed() * ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_RedMaxValue + 0.5f);        
		auto green = static_cast<unsigned short>(source->GetGreen() * ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_GreenMaxValue + 0.5f);        
		auto blue = static_cast<unsigned short>(source->GetBlue() * ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_BlueMaxValue + 0.5f);        
		auto alpha = static_cast<unsigned short>(source->GetAlpha() * ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_AlphaMaxValue + 0.5f);
        
        *target = blue | (green << 5) | (red << 10) | (alpha << 15);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA4R4G4B4 (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned short*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		auto red = static_cast<unsigned short>(source->GetRed() * ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_RedMaxValue + 0.5f);        
		auto green = static_cast<unsigned short>(source->GetGreen() * ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_GreenMaxValue +  0.5f);        
		auto blue = static_cast<unsigned short>(source->GetBlue() * ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_BlueMaxValue + 0.5f);        
		auto alpha = static_cast<unsigned short>(source->GetAlpha() * ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_AlphaMaxValue + 0.5f);
        
        *target = blue | (green << 4) | (red << 8) | (alpha << 12);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA8 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned char*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		ByteColour colour{ *source };
        
        *target = colour.GetAlpha();
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToL8 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned char*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		ByteColour colour{ *source };
        
        *target = colour.GetRed();
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA8L8 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned char*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		ByteColour colour{ *source };
        
        *target++ = colour.GetRed();
        *target++ = colour.GetAlpha();
        
        ++source;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToR8G8B8 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned char*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		ByteColour colour{ *source };
        
        *target++ = colour.GetBlue();
        *target++ = colour.GetGreen();
        *target++ = colour.GetRed();
        
        ++source;
    }
}

void Rendering::ColourConvertTo
   ::ConvertToA8R8G8B8 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned char*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		ByteColour colour{ *source };
        
        *target++ = colour.GetBlue();
        *target++ = colour.GetGreen();
        *target++ = colour.GetRed();
        *target++ = colour.GetAlpha();
        
        ++source;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA8B8G8R8 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned char*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		ByteColour colour{ *source };
        
        *target++ = colour.GetRed();
        *target++ = colour.GetGreen();
        *target++ = colour.GetBlue();
        *target++ = colour.GetAlpha();
        
        ++source;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToL16 (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned short*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		auto red = static_cast<unsigned short>(source->GetRed() *  ColourTextureFormatTraits<TextureFormat::L16>::sm_LuminanceMaxValue + 0.5f);
        
        *target = red;
        
        ++source;
        ++target;
    }
}


void Rendering::ColourConvertTo
    ::ConvertToG16R16 (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned short*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		auto red = static_cast<unsigned short>(source->GetRed() * ColourTextureFormatTraits<TextureFormat::G16R16>::sm_RedMaxValue + 0.5f);
        
        *target++ = red;
        
		auto green = static_cast<unsigned short>(source->GetGreen() *  ColourTextureFormatTraits<TextureFormat::G16R16>::sm_GreenMaxValue + 0.5f);
        
        *target++ = green;
        
        ++source;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA16B16G16R16 (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<unsigned short*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		auto red = static_cast<unsigned short>(source->GetRed() * ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_RedMaxValue + 0.5f);
        
        *target++ = red;
        
		auto green = static_cast<unsigned short>(source->GetGreen() * ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_GreenMaxValue + 0.5f);
        
        *target++ = green;
        
		auto blue = static_cast<unsigned short>(source->GetBlue() * ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_BlueMaxValue + 0.5f);
        
        *target++ = blue;
        
		auto alpha = static_cast<unsigned short>(source->GetAlpha() * ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_AlphaMaxValue + 0.5f);
        
        *target++ = alpha;
        
        ++source;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToR16F (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<HalfFloat::HalfFloatType*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		*target = HalfFloat{ source->GetRed() }.ToHalfFloat();
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToG16R16F (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<HalfFloat::HalfFloatType*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
		*target++ = HalfFloat{ source->GetRed() }.ToHalfFloat();
		*target++ = HalfFloat{ source->GetGreen() }.ToHalfFloat();
        
        ++source;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToA16B16G16R16F (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<HalfFloat::HalfFloatType*>(outTexels);
    for (int i = 0; i < numInTexels; ++i)
    {
		*target++ = HalfFloat{ source->GetRed() }.ToHalfFloat();
		*target++ = HalfFloat{ source->GetGreen() }.ToHalfFloat();
		*target++ = HalfFloat{ source->GetBlue() }.ToHalfFloat();
		*target++ = HalfFloat{ source->GetAlpha() }.ToHalfFloat();
        
        ++source;
    }
}


void Rendering::ColourConvertTo
    ::ConvertToR32F (int numInTexels, const FloatColour* inTexels,char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<float*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
        *target = source->GetRed();
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertTo
    ::ConvertToG32R32F (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<float*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
        *target++ = source->GetRed();
        *target++ = source->GetGreen();
        
        ++source;
    }
}


void Rendering::ColourConvertTo
    ::ConvertToA32B32G32R32F (int numInTexels, const FloatColour* inTexels, char* outTexels)
{
	auto source = inTexels;
	auto target = reinterpret_cast<float*>(outTexels);
    for (auto i = 0; i < numInTexels; ++i)
    {
        *target++ = source->GetRed();
        *target++ = source->GetGreen();
        *target++ = source->GetBlue();
        *target++ = source->GetAlpha();
        
        ++source;
    }
}

Rendering::ColourConvertTo::ConvertToFunction
    Rendering::ColourConvertTo::sm_ToFunction[ConvertToQuantity]  
{
    nullptr,
    &ConvertToR5G6B5,
    &ConvertToA1R5G5B5,
    &ConvertToA4R4G4B4,
    &ConvertToA8,
    &ConvertToL8,
    &ConvertToA8L8,
    &ConvertToR8G8B8,
    &ConvertToA8R8G8B8,
    &ConvertToA8B8G8R8,
    &ConvertToL16,
    &ConvertToG16R16,
    &ConvertToA16B16G16R16,
    &ConvertToR16F,
    &ConvertToG16R16F,
    &ConvertToA16B16G16R16F,
    &ConvertToR32F,
    &ConvertToG32R32F,
    &ConvertToA32B32G32R32F,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};
