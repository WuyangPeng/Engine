// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:34)

#include "Rendering/RenderingExport.h"

#include "TextureColourDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A1R5G5B5>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");
	    
	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A1R5G5B5>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A4R4G4B4>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

    RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A4R4G4B4>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A8R8G8B8>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8R8G8B8>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A8B8G8R8>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8B8G8R8>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A16B16G16R16>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");
    
	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A16B16G16R16F>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A16B16G16R16F>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A32B32G32R32F>
    ::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<TextureFormat::A32B32G32R32F>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A8>
    ::SetColour(BitType alpha)
{
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8>::RedType, Rendering::TrueType>::value, "RedType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8>::ColourTextureFormatTraitsAlpha] = alpha;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::L8>
    ::SetColour(BitType luminance)
{
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L8>::RedType, Rendering::TrueType>::value, "RedType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L8>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L8>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L8>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::L8>::LuminanceType, Rendering::TrueType>::value, "LuminanceType is TrueType!");

	RENDERING_CLASS_IS_VALID_4; 
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::L8>::ColourTextureFormatTraitsLuminance] = luminance;
    
	Standardization();
}


template <>
void Rendering::TextureColour<Rendering::TextureFormat::L16>
    ::SetColour(BitType luminance)
{    
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L16>::RedType, Rendering::TrueType>::value, "RedType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L16>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L16>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::L16>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::L16>::LuminanceType, Rendering::TrueType>::value, "LuminanceType is TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::L16>::ColourTextureFormatTraitsLuminance] = luminance;
    
	Standardization();
}


template <>
void Rendering::TextureColour<Rendering::TextureFormat::R16F>
    ::SetColour(BitType red)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::R16F>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R16F>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R16F>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R16F>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R16F>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::R16F>::ColourTextureFormatTraitsRed] = red;
    
	Standardization();
}


template <>
void Rendering::TextureColour<Rendering::TextureFormat::R32F>
    ::SetColour(BitType red)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::R32F>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R32F>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R32F>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R32F>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::R32F>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::R32F>::ColourTextureFormatTraitsRed] = red;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A8L8>
    ::SetColour(BitType alpha, BitType luminance)
{
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8L8>::RedType, Rendering::TrueType>::value, "RedType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8L8>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::A8L8>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8L8>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::A8L8>::LuminanceType, Rendering::TrueType>::value, "LuminanceType is TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::A8L8>::ColourTextureFormatTraitsAlpha] = alpha;
    m_Colour[ColourTextureFormatTraits<TextureFormat::A8L8>::ColourTextureFormatTraitsLuminance] = luminance;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::G16R16>
    ::SetColour(BitType green, BitType red)

{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::G16R16>::ColourTextureFormatTraitsGreen] = green;
    m_Colour[ColourTextureFormatTraits<TextureFormat::G16R16>::ColourTextureFormatTraitsRed] = red;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::G16R16F>
    ::SetColour(BitType green, BitType red)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16F>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16F>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16F>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16F>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G16R16F>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::G16R16F>::ColourTextureFormatTraitsGreen] = green;
    m_Colour[ColourTextureFormatTraits<TextureFormat::G16R16F>::ColourTextureFormatTraitsRed] = red;
    
	Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::G32R32F>
    ::SetColour(BitType green, BitType red)
{
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::G32R32F>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<TextureFormat::G32R32F>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G32R32F>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G32R32F>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<TextureFormat::G32R32F>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;
    
	m_Colour[ColourTextureFormatTraits<TextureFormat::G32R32F>::ColourTextureFormatTraitsGreen] = green;
    m_Colour[ColourTextureFormatTraits<TextureFormat::G32R32F>::ColourTextureFormatTraitsRed] = red;
    
	Standardization();
}