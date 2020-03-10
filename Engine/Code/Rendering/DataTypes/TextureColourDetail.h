// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 11:33)

#ifndef RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H
#define RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H

#include "TextureColour.h"
#include "Mathematics/Base/MathDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <type_traits> 

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::sm_MinValue{ static_cast<BitType>(ColourTextureFormatTraits<Format>::sm_MinValue) };

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::sm_RedMaxValue{ static_cast<BitType>(ColourTextureFormatTraits<Format>::sm_RedMaxValue) };

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::sm_GreenMaxValue{ static_cast<BitType>(ColourTextureFormatTraits<Format>::sm_GreenMaxValue) };

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::sm_BlueMaxValue{ static_cast<BitType>(ColourTextureFormatTraits<Format>::sm_BlueMaxValue) };

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::sm_AlphaMaxValue{ static_cast<BitType>(ColourTextureFormatTraits<Format>::sm_AlphaMaxValue) };

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::sm_LuminanceMaxValue{ static_cast<BitType>(ColourTextureFormatTraits<Format>::sm_LuminanceMaxValue) };

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>
	::TextureColour()
	:m_Colour{}
{
	for(int i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] = sm_MinValue;
	}

	RENDERING_SELF_CLASS_IS_VALID_4;
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>
	::TextureColour(BitType red, BitType green, BitType blue, BitType alpha)
{	
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType,Rendering::TrueType>::value,"RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType,Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType,Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::AlphaType,Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::LuminanceType,Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] = sm_MinValue;
	}

	SetColour(red,green,blue,alpha); 

	RENDERING_SELF_CLASS_IS_VALID_4;
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>
	::TextureColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!"); 
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] = sm_MinValue;
	}

	SetColour(red,green,blue); 

	RENDERING_SELF_CLASS_IS_VALID_4;
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>
	::TextureColour(BitType value)
{ 
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::GreenType, Rendering::TrueType>::value, "GreenType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::BlueType, Rendering::TrueType>::value, "BlueType isn't TrueType!");

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] = sm_MinValue;
	}
	
	SetColour(value); 

	RENDERING_SELF_CLASS_IS_VALID_4;
}
 
template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>
	::TextureColour(BitType firstValue, BitType secondValue)
{		
	static_assert((std::is_same<ColourTextureFormatTraits<Format>::RedType,Rendering::TrueType>::value &&
				   std::is_same<ColourTextureFormatTraits<Format>::GreenType,Rendering::TrueType>::value &&
	 	 	 	   !std::is_same<ColourTextureFormatTraits<Format>::BlueType,Rendering::TrueType>::value &&
	 	 	 	   !std::is_same<ColourTextureFormatTraits<Format>::LuminanceType,Rendering::TrueType>::value &&
	 	 	 	   !std::is_same<ColourTextureFormatTraits<Format>::AlphaType,Rendering::TrueType>::value) ||
	 	 	 	  (!std::is_same<ColourTextureFormatTraits<Format>::RedType,Rendering::TrueType>::value &&
	 	 	 	   !std::is_same<ColourTextureFormatTraits<Format>::GreenType,Rendering::TrueType>::value &&
	 	 	 	   !std::is_same<ColourTextureFormatTraits<Format>::BlueType,Rendering::TrueType>::value &&
				   std::is_same<ColourTextureFormatTraits<Format>::LuminanceType,Rendering::TrueType>::value &&
				   std::is_same<ColourTextureFormatTraits<Format>::AlphaType, Rendering::TrueType>::value),"Format type is error!");

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] = sm_MinValue;
	}

	SetColour(firstValue, secondValue); 

	RENDERING_SELF_CLASS_IS_VALID_4;
} 

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>
	::SetColour(BitType red, BitType green, BitType blue, BitType alpha)
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!");

	RENDERING_CLASS_IS_VALID_4;

	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsBlue] = blue;
	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsAlpha] = alpha;

	Standardization();
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>
	::SetColour(BitType red, BitType green, BitType blue)
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType, Rendering::TrueType>::value, "RedType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::AlphaType, Rendering::TrueType>::value, "AlphaType isn't TrueType!");
	static_assert(!std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, Rendering::TrueType>::value, "LuminanceType isn't TrueType!"); 

	RENDERING_CLASS_IS_VALID_4;

	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsRed] = red;
	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsGreen] = green;
	m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsBlue] = blue;

	Standardization();
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A1R5G5B5>
	::SetColour(BitType red, BitType green, BitType blue);
template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A4R4G4B4>
	::SetColour(BitType red, BitType green, BitType blue);
template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A8R8G8B8>
	::SetColour(BitType red, BitType green, BitType blue);
template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A8B8G8R8>
	::SetColour(BitType red, BitType green, BitType blue);
template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A16B16G16R16>
	::SetColour(BitType red, BitType green, BitType blue);
template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A16B16G16R16F>
	::SetColour(BitType red, BitType green, BitType blue);
template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A32B32G32R32F>
	::SetColour(BitType red, BitType green, BitType blue);

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>
	::SetColour(BitType value)
{
	static_assert(false,"TextureFormat is error!");

	RENDERING_CLASS_IS_VALID_4;

	m_Colour[0] = value; 
}  

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A8>
	::SetColour(BitType alpha);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::L8>
	::SetColour(BitType luminance);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::L16>
	::SetColour(BitType luminance);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::R16F>
	::SetColour(BitType red);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::R32F>
	::SetColour(BitType red);
 
template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>
	::SetColour(BitType firstValue, BitType secondValue)
{
	static_assert(false, "TextureFormat is error!");

	RENDERING_CLASS_IS_VALID_4;

	m_Colour[0] = firstValue;  
	m_Colour[1] = secondValue; 
} 

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::A8L8>
	::SetColour(BitType alpha, BitType luminance);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::G16R16>
	::SetColour(BitType green, BitType red);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::G16R16F>
	::SetColour(BitType green, BitType red);

template <>
RENDERING_DEFAULT_DECLARE void Rendering::TextureColour<Rendering::TextureFormat::G32R32F>
	::SetColour(BitType green, BitType red); 
 
// static 
// private
template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::Clamp(BitType colour, BitType maxValue)
{
	if(colour < sm_MinValue)
		return sm_MinValue;
	else if(maxValue < colour)
		return maxValue;
	else 
		return colour;
}

template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
Rendering::TextureColour<Format>
	::TextureColour(const TextureColour<RhsFormat>& colour)
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType, ColourTextureFormatTraits<RhsFormat>::RedType>::value, "RedType isn't same!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType, ColourTextureFormatTraits<RhsFormat>::GreenType>::value, "GreenType isn't same!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType, ColourTextureFormatTraits<RhsFormat>::BlueType>::value, "BlueType isn't same!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, ColourTextureFormatTraits<RhsFormat>::LuminanceType>::value, "LuminanceType isn't same!");
	 
	ConvertingColourFormat(colour); 

	RENDERING_SELF_CLASS_IS_VALID_4;
}

template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>
	::operator= (const TextureColour<RhsFormat>& colour)
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType, ColourTextureFormatTraits<RhsFormat>::RedType>::value, "RedType isn't same!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType, ColourTextureFormatTraits<RhsFormat>::GreenType>::value, "GreenType isn't same!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType, ColourTextureFormatTraits<RhsFormat>::BlueType>::value, "BlueType isn't same!");
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, ColourTextureFormatTraits<RhsFormat>::LuminanceType>::value, "LuminanceType isn't same!");

	RENDERING_CLASS_IS_VALID_4;

	ConvertingColourFormat(colour);	

    return *this;
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>
	::ConvertingColourFormat(const TextureColour<RhsFormat>& colour)
{
	using RhsBitType = typename ColourTextureFormatTraits<RhsFormat>::BitType;

	auto rhsRedMaxValue = boost::numeric_cast<RhsBitType>(ColourTextureFormatTraits<RhsFormat>::sm_RedMaxValue);
	auto rhsGreenMaxValue = boost::numeric_cast<RhsBitType>(ColourTextureFormatTraits<RhsFormat>::sm_GreenMaxValue);
	auto rhsBlueMaxValue = boost::numeric_cast<RhsBitType>(ColourTextureFormatTraits<RhsFormat>::sm_BlueMaxValue);
	auto rhsLuminanceMaxValue = boost::numeric_cast<RhsBitType>(ColourTextureFormatTraits<RhsFormat>::sm_LuminanceMaxValue);

	Converting<RhsFormat,ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsRed,
			   ColourTextureFormatTraits<RhsFormat>::ColourTextureFormatTraitsRed>(colour,sm_RedMaxValue,rhsRedMaxValue,std::is_same<ColourTextureFormatTraits<Format>::RedType,TrueType>());
	Converting<RhsFormat,ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsGreen,
			   ColourTextureFormatTraits<RhsFormat>::ColourTextureFormatTraitsGreen>(colour,sm_GreenMaxValue,rhsGreenMaxValue,std::is_same<ColourTextureFormatTraits<Format>::GreenType,TrueType>());
	Converting<RhsFormat,ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsBlue,
			   ColourTextureFormatTraits<RhsFormat>::ColourTextureFormatTraitsBlue>(colour,sm_BlueMaxValue,rhsBlueMaxValue,std::is_same<ColourTextureFormatTraits<Format>::BlueType,TrueType>());
	ConvertingAlpha(colour,std::is_same<ColourTextureFormatTraits<Format>::AlphaType,TrueType>(), std::is_same<ColourTextureFormatTraits<RhsFormat>::AlphaType,TrueType>());
	Converting<RhsFormat, ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsLuminance,
			   ColourTextureFormatTraits<RhsFormat>::ColourTextureFormatTraitsLuminance> (colour,sm_LuminanceMaxValue,rhsLuminanceMaxValue,std::is_same<ColourTextureFormatTraits<Format>::LuminanceType,TrueType>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat,int Index,int RhsIndex,bool IsFloatingPoint, bool RhsIsFloatingPoint>
void Rendering::TextureColour<Format>
   ::ConvertingBit( const TextureColour<RhsFormat>& colour,BitType maxValue,typename TextureColour<RhsFormat>::BitType rhsMinValue,
					typename TextureColour<RhsFormat>::BitType rhsMaxValue,const std::integral_constant<bool,IsFloatingPoint>&,
				    const std::integral_constant<bool,RhsIsFloatingPoint>&)
{
	using RhsBitType = typename TextureColour<RhsFormat>::BitType;

	const auto rhsFormatDistance = boost::numeric_cast<RhsBitType>(rhsMaxValue - rhsMinValue);
	const auto lhsFormatDistance = boost::numeric_cast<BitType>(maxValue - sm_MinValue);
	const auto value = boost::numeric_cast<RhsBitType>(colour[RhsIndex] - rhsMinValue);

	m_Colour[Index] = boost::numeric_cast<BitType>(value * lhsFormatDistance / rhsFormatDistance) + sm_MinValue;
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat,int Index,int RhsIndex>
void Rendering::TextureColour<Format>
	::ConvertingBit( const TextureColour<RhsFormat>& colour,BitType maxValue,typename TextureColour<RhsFormat>::BitType rhsMinValue,
					 typename TextureColour<RhsFormat>::BitType rhsMaxValue,const std::false_type&,const std::true_type&)
{
	using RhsBitType = typename TextureColour<RhsFormat>::BitType;

	const auto rhsFormatDistance = boost::numeric_cast<RhsBitType>(rhsMaxValue - rhsMinValue);
	const auto lhsFormatDistance = boost::numeric_cast<BitType>(maxValue - sm_MinValue);
	const auto value = boost::numeric_cast<RhsBitType>(colour[RhsIndex] - rhsMinValue);

	m_Colour[Index] = boost::numeric_cast<BitType>(value * lhsFormatDistance / rhsFormatDistance + 0.5f) + sm_MinValue;
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat,int Index,int RhsIndex,bool HaveBit>
void Rendering::TextureColour<Format>
	::Converting( const TextureColour<RhsFormat>& colour,BitType maxValue,typename TextureColour<RhsFormat>::BitType rhsMaxValue,const std::integral_constant<bool,HaveBit>& )
{
	using RhsBitType = typename TextureColour<RhsFormat>::BitType;

	auto rhsMinValue = boost::numeric_cast<RhsBitType>(ColourTextureFormatTraits<RhsFormat>::sm_MinValue);

	ConvertingBit<RhsFormat,Index,RhsIndex>(colour,maxValue,rhsMinValue,rhsMaxValue, std::integral_constant<bool,sm_IsFloatingPoint>(),
										    std::integral_constant<bool,ColourTextureFormatTraits<RhsFormat>::sm_IsFloatingPoint>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat,int Index,int RhsIndex>
void Rendering::TextureColour<Format>
    ::Converting( const TextureColour<RhsFormat>& colour, BitType maxValue, typename TextureColour<RhsFormat>::BitType rhsMaxValue,const std::false_type& )
{
	SYSTEM_UNUSED_ARG(colour);
	SYSTEM_UNUSED_ARG(maxValue);
	SYSTEM_UNUSED_ARG(rhsMaxValue);
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat,bool HaveAlpha,bool RhsHaveAlpha>
void Rendering::TextureColour<Format>
	::ConvertingAlpha(const TextureColour<RhsFormat>& colour,const std::integral_constant<bool, HaveAlpha>&,const std::integral_constant<bool, RhsHaveAlpha>&)
{
     SYSTEM_UNUSED_ARG(colour);
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>
	::ConvertingAlpha(const TextureColour<RhsFormat>& colour,const std::true_type&,const std::true_type&)
{
	using RhsBitType = typename ColourTextureFormatTraits<RhsFormat>::BitType;

	auto rhsAlphaMaxValue = boost::numeric_cast<RhsBitType>(ColourTextureFormatTraits<RhsFormat>::sm_AlphaMaxValue);

	Converting<RhsFormat,ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsAlpha,
		       ColourTextureFormatTraits<RhsFormat>::ColourTextureFormatTraitsAlpha>(colour,sm_AlphaMaxValue,rhsAlphaMaxValue,std::is_same<ColourTextureFormatTraits<Format>::AlphaType,TrueType>());
}

// private
template <Rendering::TextureFormat Format>
template <Rendering::TextureFormat RhsFormat>
void Rendering::TextureColour<Format>
	::ConvertingAlpha(const TextureColour<RhsFormat>& colour,const std::true_type&,const std::false_type&)
{
	 m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsAlpha] = sm_AlphaMaxValue;

     SYSTEM_UNUSED_ARG(colour);
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::TextureFormat Format>
bool Rendering::TextureColour<Format>
	::IsValid() const noexcept
{
	for(auto i = 0;i < sm_ArraySize;++i)
	{
		if (m_Colour[i] < sm_MinValue)
		{
			return false;
		}		   
	}

	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::GetRed() const
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::RedType, Rendering::TrueType>::value, "RedType is TrueType!"); 

	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsRed];
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::GetGreen() const
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::GreenType, Rendering::TrueType>::value, "GreenType is TrueType!");

	RENDERING_CLASS_IS_VALID_CONST_4;  

	return m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsGreen];
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::GetBlue() const
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::BlueType, Rendering::TrueType>::value, "BlueType is TrueType!");

	RENDERING_CLASS_IS_VALID_CONST_4; 

	return m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsBlue];
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::GetAlpha() const
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::AlphaType, Rendering::TrueType>::value, "AlphaType is TrueType!");

	RENDERING_CLASS_IS_VALID_CONST_4; 

	return m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsAlpha];
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::GetLuminance() const
{
	static_assert(std::is_same<ColourTextureFormatTraits<Format>::LuminanceType, Rendering::TrueType>::value, "LuminanceType is TrueType!");

	RENDERING_CLASS_IS_VALID_CONST_4; 

	return m_Colour[ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsLuminance];
}

template <Rendering::TextureFormat Format>
const typename Rendering::TextureColour<Format>::BitType* Rendering::TextureColour<Format>
	::GetPoint() const
{
	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour.data();
}

template <Rendering::TextureFormat Format>
typename Rendering::TextureColour<Format>::BitType Rendering::TextureColour<Format>
	::operator[]( int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_4;
	RENDERING_ASSERTION_1(0 <= index && index < sm_ArraySize,"À˜“˝¥ÌŒÛ£°");

	return m_Colour[index];
}
 
template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>
	::operator+= (const TextureColour& rhs)
{
	RENDERING_CLASS_IS_VALID_4;

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] += rhs.m_Colour[i];
	}

	Standardization();

	return *this;
}

template <Rendering::TextureFormat Format>
void Rendering::TextureColour<Format>
	::Standardization()
{
    Standardization<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsRed>(std::is_same<ColourTextureFormatTraits<Format>::RedType,TrueType>(),sm_RedMaxValue);
	Standardization<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsGreen>(std::is_same<ColourTextureFormatTraits<Format>::GreenType,TrueType>(), sm_GreenMaxValue);
	Standardization<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsBlue>(std::is_same<ColourTextureFormatTraits<Format>::BlueType,TrueType>(),sm_BlueMaxValue);
	Standardization<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsAlpha>(std::is_same<ColourTextureFormatTraits<Format>::AlphaType,TrueType>(),sm_AlphaMaxValue);
	Standardization<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsLuminance>(std::is_same<ColourTextureFormatTraits<Format>::LuminanceType,TrueType>(),sm_LuminanceMaxValue);
}

template <Rendering::TextureFormat Format>
template <int Index>
void Rendering::TextureColour<Format>
	::Standardization(const std::false_type&,BitType maxValue)
{
	SYSTEM_UNUSED_ARG(maxValue);
}

template <Rendering::TextureFormat Format>
template <int Index>
void Rendering::TextureColour<Format>
	::Standardization(const std::true_type&,BitType maxValue)
{
	static_assert(0 <= Index && Index < sm_ArraySize,"index is crossing!");

	m_Colour[Index] = Clamp(m_Colour[Index],maxValue);
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>
	::operator-= (const TextureColour& rhs) 
{
	RENDERING_CLASS_IS_VALID_4;

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] -= rhs.m_Colour[i];
	}

	Standardization();

	return *this;
}

template <Rendering::TextureFormat Format>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>
	::operator*= (const TextureColour& rhs) 
{
	RENDERING_CLASS_IS_VALID_4;

 	Multiply<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsRed>(std::is_same<ColourTextureFormatTraits<Format>::RedType,TrueType>(),sm_RedMaxValue,rhs);
	Multiply<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsGreen>(std::is_same<ColourTextureFormatTraits<Format>::GreenType,TrueType>(),sm_GreenMaxValue,rhs);
	Multiply<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsBlue>(std::is_same<ColourTextureFormatTraits<Format>::BlueType,TrueType>(),sm_BlueMaxValue,rhs);
	Multiply<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsAlpha>(std::is_same<ColourTextureFormatTraits<Format>::AlphaType,TrueType>(),sm_AlphaMaxValue,rhs);
	Multiply<ColourTextureFormatTraits<Format>::ColourTextureFormatTraitsLuminance>(std::is_same<ColourTextureFormatTraits<Format>::LuminanceType,TrueType>(),sm_LuminanceMaxValue,rhs);

	Standardization();
	
	return *this;
}

template <Rendering::TextureFormat Format>
template <int Index,bool HaveBit>
void Rendering::TextureColour<Format>
	::Multiply(const std::integral_constant<bool,HaveBit>&,BitType maxValue,const TextureColour& colour)
{
	static_assert(0 <= Index && Index < sm_ArraySize, "index is crossing!"); 

	m_Colour[Index] = BitType(m_Colour[Index] * colour[Index] / maxValue); 
}

template <Rendering::TextureFormat Format>
template <int Index>
void Rendering::TextureColour<Format>
	::Multiply(const std::false_type&,BitType maxValue,const TextureColour& colour)
{
	SYSTEM_UNUSED_ARG(maxValue);
	SYSTEM_UNUSED_ARG(colour);
} 

template <Rendering::TextureFormat Format>
template <typename RhsType>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>
	::operator*= (RhsType rhs)
{
	static_assert(std::is_arithmetic<RhsType>::value,"RhsType is arithmetic!");

	RENDERING_CLASS_IS_VALID_4;

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] *= rhs;
	}

	Standardization();

	return *this;
}

template <Rendering::TextureFormat Format>
template <typename RhsType>
Rendering::TextureColour<Format>& Rendering::TextureColour<Format>
	::operator/= (RhsType rhs)
{
	static_assert(boost::is_arithmetic<RhsType>::value, "RhsType is arithmetic!");

	RENDERING_CLASS_IS_VALID_4;

	Divide(rhs,std::is_floating_point<RhsType>());

	return *this;
}

// private
template <Rendering::TextureFormat Format>
template <typename RhsType,bool RhsIsFloatingPoint>
void Rendering::TextureColour <Format>
    ::Divide(RhsType rhs,const std::integral_constant<bool,RhsIsFloatingPoint>&)
{
    if(Mathematics::Math<RhsType>::FAbs(rhs) <= Mathematics::Math<RhsType>::sm_Epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("≥˝¡„¥ÌŒÛ£°"));
    }

	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] /= rhs;
	}

	Standardization();
}

// private
template <Rendering::TextureFormat Format>
template <typename RhsType>
void Rendering::TextureColour <Format>
    ::Divide(RhsType rhs,const std::false_type&)
{
    if(rhs == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("≥˝¡„¥ÌŒÛ£°"));
    }
    
	for(auto i = 0;i < sm_ArraySize;++i)
	{
		m_Colour[i] /= rhs;
	}
    
	Standardization();
}
 
template <Rendering::TextureFormat Format>
bool Rendering
	::Approximate(const TextureColour<Format>& lhs,const TextureColour<Format>& rhs,typename TextureColour<Format>::BitType epsilon)
{
	static_assert(ColourTextureFormatTraits<Format>::sm_IsFloatingPoint,"Format is Floating Point!");

	using BitType = typename ColourTextureFormatTraits<Format>::BitType;

	for(auto i = 0;i < ColourTextureFormatTraits<Format>::sm_ArraySize;++i)
	{
		if (epsilon < Mathematics::Math<BitType>::FAbs(lhs[i] - rhs[i]))
		{
			return false;
		}              
	}

	return true;
}

template <Rendering::TextureFormat Format>
bool Rendering
	::operator== (const TextureColour<Format>& lhs,const TextureColour<Format>& rhs)
{
	static_assert(!ColourTextureFormatTraits<Format>::sm_IsFloatingPoint, "Format isn't Floating Point!");

	for(auto i = 0;i < ColourTextureFormatTraits<Format>::sm_ArraySize;++i)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}              
	}

	return true;
}

template <Rendering::TextureFormat LhsFormat,typename RhsType>
const Rendering::TextureColour<LhsFormat> Rendering
	::operator* (const TextureColour<LhsFormat>& lhs, RhsType rhs)
{
	static_assert(std::is_arithmetic<RhsType>::value, "RhsType is arithmetic!");

	return TextureColour<LhsFormat>(lhs) *= rhs;
}

template <typename LhsType, Rendering::TextureFormat RhsFormat>
const Rendering::TextureColour<RhsFormat> Rendering
	::operator* (LhsType lhs, const TextureColour<RhsFormat>& rhs)
{
	static_assert(std::is_arithmetic<LhsType>::value, "LhsType is arithmetic!"); 

	return TextureColour<RhsFormat>(rhs) *= lhs;
}

template <Rendering::TextureFormat LhsFormat,typename RhsType>
const Rendering::TextureColour<LhsFormat> Rendering
	::operator/ (const TextureColour<LhsFormat>& lhs, RhsType rhs) 
{
	static_assert(std::is_arithmetic<RhsType>::value, "RhsType is arithmetic!");

	return TextureColour<LhsFormat>(lhs) /= rhs;
}

#endif // RENDERING_DATA_TYPES_TEXTURE_COLOUR_DETAIL_H