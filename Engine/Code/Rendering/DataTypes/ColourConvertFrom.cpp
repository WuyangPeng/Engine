// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:10)

#include "Rendering/RenderingExport.h"

#include "ColourConvertFrom.h"
#include "ColourDetail.h"
#include "HalfFloat.h"
#include "ColourTextureFormatTraits.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26472)
void Rendering::ColourConvertFrom
    ::ConvertFromR5G6B5 (int numOutTexels, const char* inTexels,FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned short*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        target->SetRed(static_cast<float>((*source & 0xF800u) >> 11) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_RedMaxValue));
        target->SetGreen(static_cast<float>((*source & 0x07E0u) >>  5) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_GreenMaxValue));
        target->SetBlue(static_cast<float>((*source & 0x001Fu)) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::R5G6B5>::sm_BlueMaxValue));
        target->SetAlpha(0.0f);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA1R5G5B5 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned short*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        target->SetRed(static_cast<float>((*source & 0x7C00u) >> 10) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_RedMaxValue));
        target->SetGreen(static_cast<float>((*source & 0x03E0u) >> 5) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_GreenMaxValue));
        target->SetBlue(static_cast<float>((*source & 0x001Fu)) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_BlueMaxValue));
        target->SetAlpha(static_cast<float>((*source & 0x8000u) >> 15) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::sm_AlphaMaxValue));
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA4R4G4B4 (int numOutTexels, const char* inTexels,FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned short*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        target->SetRed(static_cast<float>((*source & 0x0F00u) >> 8) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_RedMaxValue));
        target->SetGreen(static_cast<float>((*source & 0x00F0u) >> 4) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_GreenMaxValue));
        target->SetBlue(static_cast<float>((*source & 0x000Fu)) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_BlueMaxValue));
        target->SetAlpha(static_cast<float>((*source & 0xF000u) >> 12) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::sm_AlphaMaxValue));
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA8 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned char*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto alpha = *source;
		const ByteColour colour{ 0,0,0,alpha };
        *target = colour;
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromL8 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned char*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto luminance = *source;
		const ByteColour colour{ luminance,luminance,luminance,static_cast<unsigned char>( ColourTextureFormatTraits<TextureFormat::L8>::sm_AlphaMaxValue) };
        *target = colour;
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA8L8 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned char*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto luminance = *source++;
		const auto alpha = *source++;
		const ByteColour colour{ luminance,luminance, luminance,alpha };
        *target = colour;
        
        ++target;
    }
}


void Rendering::ColourConvertFrom
    ::ConvertFromR8G8B8 (int numOutTexels, const char* inTexels,FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned char*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto blue = *source++;
		const auto green = *source++;
		const auto red = *source++;
		const ByteColour colour{ red,green,blue,0 };
        *target = colour;
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA8R8G8B8 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned char*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto blue = *source++;
		const auto green = *source++;
		const auto red = *source++;
		const auto alpha = *source++;
		const ByteColour colour{ red,green,blue,alpha };
        *target = colour;
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA8B8G8R8 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned char*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto red = *source++;
		const auto green = *source++;
		const auto blue = *source++;
		const auto alpha = *source++;
		const ByteColour colour{ red,green,blue,alpha };
        *target = colour;
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromL16 (int numOutTexels, const char* inTexels,FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned short*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto luminance = static_cast<float>(*source) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::L16>::sm_LuminanceMaxValue);
        
        target->SetRed(luminance);
        target->SetGreen(luminance);
        target->SetBlue(luminance);
        target->SetAlpha(1.0f);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromG16R16 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned short*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto red = static_cast<float>(*source++) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::G16R16>::sm_RedMaxValue);
		const auto green = static_cast<float>(*source++) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::G16R16>::sm_GreenMaxValue);
        
        target->SetRed(red);
        target->SetGreen(green);
        target->SetBlue(0.0f);
        target->SetAlpha(1.0f);
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA16B16G16R16 (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const unsigned short*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		const auto red = static_cast<float>(*source++) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_RedMaxValue);
		const auto green = static_cast<float>(*source++) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_GreenMaxValue);
		const auto blue = static_cast<float>(*source++) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_BlueMaxValue);
		const auto alpha = static_cast<float>(*source++) / static_cast<float>(ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::sm_AlphaMaxValue);
        
        target->SetRed(red);
        target->SetGreen(green);
        target->SetBlue(blue);
        target->SetAlpha(alpha);
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromR16F (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const HalfFloat::HalfFloatType*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        HalfFloat halfFloat;
		halfFloat.FromHalfFloatType(*source);
		const auto red = halfFloat.ToFloat();
        
        target->SetRed(red);
        target->SetGreen(0.0f);
        target->SetBlue(0.0f);
        target->SetAlpha(0.0f);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromG16R16F (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const HalfFloat::HalfFloatType*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		HalfFloat halfFloat;
		halfFloat.FromHalfFloatType(*source++);
		const auto red = halfFloat.ToFloat();

		halfFloat.FromHalfFloatType(*source++);
		const auto green = halfFloat.ToFloat();

        target->SetRed(red);
        target->SetGreen(green);
        target->SetBlue(0.0f);
        target->SetAlpha(0.0f);
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA16B16G16R16F (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const HalfFloat::HalfFloatType*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
		HalfFloat halfFloat;
		halfFloat.FromHalfFloatType(*source++);
		const auto red = halfFloat.ToFloat();

		halfFloat.FromHalfFloatType(*source++);
		const auto green = halfFloat.ToFloat();

		halfFloat.FromHalfFloatType(*source++);
		const auto blue = halfFloat.ToFloat();

		halfFloat.FromHalfFloatType(*source++);
		const auto alpha = halfFloat.ToFloat();

        target->SetRed(red);
        target->SetGreen(green);
        target->SetBlue(blue);
        target->SetAlpha(alpha);
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromR32F (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const float*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        target->SetRed(*source);
        target->SetGreen(0.0f);
        target->SetBlue(0.0f);
        target->SetAlpha(0.0f);
        
        ++source;
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromG32R32F (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const float*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        target->SetRed(*source++);
        target->SetGreen(*source++);
        target->SetBlue(0.0f);
        target->SetAlpha(0.0f);
        
        ++target;
    }
}

void Rendering::ColourConvertFrom
    ::ConvertFromA32B32G32R32F (int numOutTexels, const char* inTexels, FloatColour* outTexels)
{
	auto source = reinterpret_cast<const float*>(inTexels);
	auto target = outTexels;
    for (auto i = 0; i < numOutTexels; ++i)
    {
        target->SetRed(*source++);
        target->SetGreen(*source++);
        target->SetBlue(*source++);
        target->SetAlpha(*source++);
        
        ++target;
    }
}

Rendering::ColourConvertFrom::ConvertFromFunction
    Rendering::ColourConvertFrom::sm_FromFunction[ConvertFromQuantity]  
{
    nullptr,
    &ConvertFromR5G6B5,
    &ConvertFromA1R5G5B5,
    &ConvertFromA4R4G4B4,
    &ConvertFromA8,
    &ConvertFromL8,
    &ConvertFromA8L8,
    &ConvertFromR8G8B8,
    &ConvertFromA8R8G8B8,
    &ConvertFromA8B8G8R8,
    &ConvertFromL16,
    &ConvertFromG16R16,
    &ConvertFromA16B16G16R16,
    &ConvertFromR16F,
    &ConvertFromG16R16F,
    &ConvertFromA16B16G16R16F,
    &ConvertFromR32F,
    &ConvertFromG32R32F,
    &ConvertFromA32B32G32R32F,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};
#include STSTEM_WARNING_POP