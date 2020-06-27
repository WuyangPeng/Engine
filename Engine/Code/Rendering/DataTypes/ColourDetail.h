// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/18 11:22)

#ifndef RENDERING_DATA_TYPES_COLOUR_DETAIL_H
#define RENDERING_DATA_TYPES_COLOUR_DETAIL_H

#include "Colour.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <type_traits> 
#include "CoreTools/ClassInvariant/Noexcept.h"

template <typename T>
Rendering::Colour<T>
	::Colour(T red,T green,T blue,T alpha)
	:m_Colour{ red,green,blue,alpha }
{ 
	Standardization();

	RENDERING_SELF_CLASS_IS_VALID_4;
}

// private
template <typename T>
void Rendering::Colour<T>
	::InitColour(T red,T green,T blue,T alpha) noexcept
{
	m_Colour.at(Red) = red;
	m_Colour.at(Green) = green;
	m_Colour.at(Blue) = blue;
	m_Colour.at(Alpha) = alpha;
}

// private
template <typename T>
void Rendering::Colour<T>
	::Standardization()
{
	StandardizationRed();
	StandardizationGreen();
	StandardizationBlue();
	StandardizationAlpha();
}

// private
template <typename T>
void Rendering::Colour<T>
	::StandardizationRed() 
{
	m_Colour.at(Red) = Clamp(m_Colour.at(Red));

	CoreTools::DoNothing();
}

// private
template <typename T>
void Rendering::Colour<T>
	::StandardizationGreen()
{
	m_Colour.at(Green) = Clamp(m_Colour.at(Green));

	CoreTools::DoNothing();
}

// private
template <typename T>
void Rendering::Colour<T>
	::StandardizationBlue()
{
	m_Colour.at(Blue) = Clamp(m_Colour.at(Blue));

	CoreTools::DoNothing();
}

// private
template <typename T>
void Rendering::Colour<T>
	::StandardizationAlpha()
{
	m_Colour.at(Alpha) = Clamp(m_Colour.at(Alpha));

	CoreTools::DoNothing();
}

// static 
// private
template <typename T>
T Rendering::Colour<T>
	::Clamp(T colour) noexcept
{
	if(colour < sm_MinValue)
		return sm_MinValue;
	else if(sm_MaxValue < colour)
		return sm_MaxValue;
	else 
		return colour;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>
	::Colour(const Colour<RhsType>& colour)
	:m_Colour{}
{
	try
	{
		ConvertingColourFormat(colour,std::is_floating_point<T>(),std::is_floating_point<RhsType>());
	}
	catch(boost::bad_numeric_cast&)
	{
		using namespace std::literals;
        THROW_EXCEPTION(SYSTEM_TEXT("ÑÕÉ«Êý¾Ý×ª»»Ê§°Ü¡£"s));
	}

	SELF_CLASS_IS_VALID_4;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>
	::operator= (const Colour<RhsType>& colour)
{
	CLASS_IS_VALID_4;

	try
	{
		ConvertingColourFormat(colour,std::is_floating_point<T>(),std::is_floating_point<RhsType>());
	}
	catch(boost::bad_numeric_cast&)
	{
        THROW_EXCEPTION(SYSTEM_TEXT("ÑÕÉ«Êý¾Ý×ª»»Ê§°Ü¡£"));
	}

    return *this;
}

// private
template <typename T>
template <typename RhsType,bool TIsFloatingPoint,bool RhsIsFloatingPoint>
void Rendering::Colour<T>
	::ConvertingColourFormat(const Colour<RhsType>& colour,const std::integral_constant<bool,TIsFloatingPoint>&,const std::integral_constant<bool,RhsIsFloatingPoint>&)
{
	InitColour(boost::numeric_cast<T>(colour.GetRed()),boost::numeric_cast<T>(colour.GetGreen()),boost::numeric_cast<T>(colour.GetBlue()),boost::numeric_cast<T>(colour.GetAlpha()));
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>
	::ConvertingColourFormat(const Colour<RhsType>& colour,const std::true_type&,const std::false_type&)
{
	static_assert(std::is_floating_point<T>::value,"T isn't floating point!");
	static_assert(std::is_integral<RhsType>::value, "RhsType isn't integral!");

	auto red = ConvertingIntegralToFloatingPoint(colour.GetRed());
	auto green = ConvertingIntegralToFloatingPoint(colour.GetGreen());
	auto blue = ConvertingIntegralToFloatingPoint(colour.GetBlue());
	auto alpha = ConvertingIntegralToFloatingPoint(colour.GetAlpha());

	InitColour(red,green,blue,alpha);
}

// static
// private
template <typename T>
template <typename RhsType>
T Rendering::Colour<T>
	::ConvertingIntegralToFloatingPoint(RhsType rhs)
{
	static_assert(std::is_floating_point<T>::value, "T isn't floating point!");
	static_assert(std::is_integral<RhsType>::value, "RhsType isn't integral!");

	constexpr auto rhsTypeDistance = ColourDefaultTraits<RhsType>::sm_MaxValue - ColourDefaultTraits<RhsType>::sm_MinValue;
	constexpr auto lhsTypeDistance = sm_MaxValue - sm_MinValue;

	return (boost::numeric_cast<T>(rhs) - ColourDefaultTraits<RhsType>::sm_MinValue)  * lhsTypeDistance / rhsTypeDistance + sm_MinValue;
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>
	::ConvertingColourFormat(const Colour<RhsType>& colour,const std::false_type&,const std::true_type&)
{
	static_assert(std::is_integral<T>::value, "T isn't integral!");
	static_assert(std::is_floating_point<RhsType>::value, "RhsType isn't floating point!");

	auto red = ConvertingFloatingPointToIntegral(colour.GetRed());
	auto green = ConvertingFloatingPointToIntegral(colour.GetGreen());
	auto blue = ConvertingFloatingPointToIntegral(colour.GetBlue());
	auto alpha = ConvertingFloatingPointToIntegral(colour.GetAlpha());

	InitColour(red,green,blue,alpha);
}

// static
// private
template <typename T>
template <typename RhsType>
T Rendering::Colour<T>
	::ConvertingFloatingPointToIntegral(RhsType rhs)
{
	static_assert(std::is_integral<T>::value, "T isn't integral!");
	static_assert(std::is_floating_point<RhsType>::value, "RhsType isn't floating point!");

	constexpr auto rhsTypeDistance = ColourDefaultTraits<RhsType>::sm_MaxValue - ColourDefaultTraits<RhsType>::sm_MinValue;
	constexpr auto lhsTypeDistance = sm_MaxValue - sm_MinValue;

	return boost::numeric_cast<T>((rhs - ColourDefaultTraits<RhsType>::sm_MinValue) * lhsTypeDistance / rhsTypeDistance + sm_MinValue + static_cast<RhsType>(0.5f));
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Rendering::Colour<T>
	::IsValid() const noexcept
{
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26482)   
#include SYSTEM_WARNING_DISABLE(26446) 
	for(int i = Red;i < ColourSize;++i)
	{
		if (m_Colour[i] < sm_MinValue || sm_MaxValue < m_Colour[i])
		{
			return false;
		}		   
	}

	return true;
#include STSTEM_WARNING_POP
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
T Rendering::Colour<T>
	::GetRed() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour.at(Red);
}

template <typename T>
T Rendering::Colour<T>
	::GetGreen() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour.at(Green);  
}

template <typename T>
T Rendering::Colour<T>
	::GetBlue() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour.at(Blue);
}

template <typename T>
T Rendering::Colour<T>
	::GetAlpha() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour.at(Alpha);
}

template <typename T>
const T* Rendering::Colour<T>
	::GetPoint() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_4;

	return m_Colour.data();
}

template <typename T>
void Rendering::Colour<T>
	::SetColour(T red,T green,T blue,T alpha)
{
	RENDERING_CLASS_IS_VALID_4;

	SetRed(red);
	SetGreen(green);
	SetBlue(blue);
	SetAlpha(alpha);

	Standardization();
}

template <typename T>
void Rendering::Colour<T>
	::SetRed(T red)
{
	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Red] = red;

	StandardizationRed();
}

template <typename T>
void Rendering::Colour<T>
	::SetGreen(T green)
{
	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Green] = green;

	StandardizationGreen();
}

template <typename T>
void Rendering::Colour<T>
	::SetBlue(T blue)
{
	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Blue] = blue;

	StandardizationBlue();
}

template <typename T>
void Rendering::Colour<T>
	::SetAlpha(T alpha)
{
	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Alpha] = alpha;

	StandardizationAlpha();
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>
	::operator+= (const Colour& rhs)
{
	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Red] += rhs.m_Colour[Red];
	m_Colour[Green] += rhs.m_Colour[Green];
	m_Colour[Blue] += rhs.m_Colour[Blue];
	m_Colour[Alpha] += rhs.m_Colour[Alpha];

	Standardization();

	return *this;
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>
	::operator-= (const Colour& rhs) 
{
	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Red] -= rhs.m_Colour[Red];
	m_Colour[Green] -= rhs.m_Colour[Green];
	m_Colour[Blue] -= rhs.m_Colour[Blue];
	m_Colour[Alpha] -= rhs.m_Colour[Alpha];

	Standardization();

	return *this;
}

template <typename T>
Rendering::Colour<T>& Rendering::Colour<T>
	::operator*= (const Colour& rhs) 
{
	static_assert(sm_MaxValue != 0,"sm_MaxValue != 0");

	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Red] *= rhs.m_Colour[Red];
	m_Colour[Green] *= rhs.m_Colour[Green];
	m_Colour[Blue] *= rhs.m_Colour[Blue];
	m_Colour[Alpha] *= rhs.m_Colour[Alpha];	

	m_Colour[Red] /= sm_MaxValue;
	m_Colour[Green] /= sm_MaxValue;
	m_Colour[Blue] /= sm_MaxValue;
	m_Colour[Alpha] /= sm_MaxValue;	

	Standardization();

	return *this;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>
	::operator*= (RhsType rhs)
{
	static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

	RENDERING_CLASS_IS_VALID_4;

	m_Colour[Red] *= rhs;
	m_Colour[Green] *= rhs;
	m_Colour[Blue] *= rhs;
	m_Colour[Alpha] *= rhs;

	Standardization();

	return *this;
}

template <typename T>
template <typename RhsType>
Rendering::Colour<T>& Rendering::Colour<T>
	::operator/= (RhsType rhs)
{
	static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

	RENDERING_CLASS_IS_VALID_4;

	Divide(rhs,std::is_floating_point<RhsType>());

	return *this;
}

// private
template <typename T>
template <typename RhsType,bool RhsIsFloatingPoint>
void Rendering::Colour<T>
    ::Divide(RhsType rhs,const std::integral_constant<bool,RhsIsFloatingPoint>&)
{
    if(Mathematics::Math<RhsType>::FAbs(rhs) <= Mathematics::Math<RhsType>::sm_Epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("³ýÁã´íÎó£¡"));
    }
    
	m_Colour[Red] /= rhs;
	m_Colour[Green] /= rhs;
	m_Colour[Blue] /= rhs;
	m_Colour[Alpha] /= rhs;
    
	Standardization();
}

// private
template <typename T>
template <typename RhsType>
void Rendering::Colour<T>
     ::Divide(RhsType rhs,const std::false_type&)
{
    if(rhs <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("³ýÁã´íÎó£¡"));
    }
    
	m_Colour[Red] /= rhs;
	m_Colour[Green] /= rhs;
	m_Colour[Blue] /= rhs;
	m_Colour[Alpha] /= rhs;
    
	Standardization();
}

template <typename T>
bool Rendering
	::Approximate(const Colour<T>& lhs,const Colour<T>& rhs,T epsilon) noexcept
{
	static_assert(std::is_floating_point<T>::value, "T isn't floating point!");

	return Mathematics::Math<T>::FAbs(lhs.GetRed() - rhs.GetRed()) <= epsilon &&
		   Mathematics::Math<T>::FAbs(lhs.GetGreen() - rhs.GetGreen()) <= epsilon &&
		   Mathematics::Math<T>::FAbs(lhs.GetBlue() - rhs.GetBlue()) <= epsilon &&
		   Mathematics::Math<T>::FAbs(lhs.GetAlpha() - rhs.GetAlpha()) <= epsilon;
}

template <typename T>
bool Rendering
	::operator== (const Rendering::Colour<T>& lhs,const Rendering::Colour<T>& rhs) noexcept
{
	static_assert(std::is_integral<T>::value, "T isn't integral!"); 

	return lhs.GetRed() == rhs.GetRed() && lhs.GetGreen() == rhs.GetGreen() &&
		   lhs.GetBlue() == rhs.GetBlue() && lhs.GetAlpha() == rhs.GetAlpha();
}

template <typename LhsType,typename RhsType>
const Rendering::Colour<LhsType> Rendering
	::operator* (const Colour<LhsType>& lhs,RhsType rhs)
{	
	static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

	return Colour<LhsType>(lhs) *= rhs;
}

template <typename LhsType,typename RhsType>
const Rendering::Colour<RhsType> Rendering
	::operator* (LhsType lhs,const Colour<RhsType>& rhs)
{
	static_assert(std::is_arithmetic<LhsType>::value, "LhsType isn't arithmetic!"); 

	return Colour<RhsType>(rhs) *= lhs;
}

template <typename LhsType,typename RhsType>
const Rendering::Colour<LhsType> Rendering
	::operator/ (const Colour<LhsType>& lhs,RhsType rhs)
{
	static_assert(std::is_arithmetic<RhsType>::value, "RhsType isn't arithmetic!");

	return Colour<LhsType>(lhs) /= rhs;
}

template <typename T>
std::ostream& Rendering
	::operator<<( std::ostream& os,const Colour<T>& colour )
{
	static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

	os << "red = " << colour.GetRed() << " green = " << colour.GetGreen()
	   << " blue = " << colour.GetBlue() << " alpha = " << colour.GetAlpha();

	return os;
}

#endif // RENDERING_DATA_TYPES_COLOUR_DETAIL_H