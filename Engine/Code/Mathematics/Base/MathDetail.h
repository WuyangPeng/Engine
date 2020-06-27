// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:16)

#ifndef MATHEMATICS_BASE_MATH_DETAIL_H
#define MATHEMATICS_BASE_MATH_DETAIL_H

#include "Math.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATH_DETAIL)

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"

#include <algorithm>

// Math<float>公用常数特化。
template<>
const float Mathematics::Math<float>
	::sm_Epsilon{ FLT_EPSILON };
template<>
const float Mathematics::Math<float>
	::sm_ZeroTolerance{ 1e-06f };
template<>
const float Mathematics::Math<float>
	::sm_MaxReal{ FLT_MAX };
template<>
const float Mathematics::Math<float>
	::sm_Exponent{ Math<float>::Log(sm_MaxReal) };
template<>
const float Mathematics::Math<float>
	::sm_PI{ 4.0f * Math<float>::ATan(1.0f) };
template<>
const float Mathematics::Math<float>
	::sm_TwoPI{ 2.0f * Math<float>::sm_PI };
template<>
const float Mathematics::Math<float>
	::sm_HalfPI{ 0.5f * Math<float>::sm_PI };
template<>
const float Mathematics::Math<float>
	::sm_QuarterPI{ 0.25f * Math<float>::sm_PI };
template<>
const float Mathematics::Math<float>
	::sm_InversePI{ 1.0f / Math<float>::sm_PI };
template<>
const float Mathematics::Math<float>
	::sm_InverseTwoPI{ 1.0f / Math<float>::sm_TwoPI };
template<>
const float Mathematics::Math<float>
	::sm_DegToRad{ Math<float>::sm_PI / 180.0f };
template<>
const float Mathematics::Math<float>
	::sm_RadToDeg{ 180.0f / Math<float>::sm_PI };
template<>
const float Mathematics::Math<float>
	::sm_LN2{ Math<float>::Log(2.0f) };
template<>
const float Mathematics::Math<float>
	::sm_LN10{ Math<float>::Log(10.0f) };
template<>
const float Mathematics::Math<float>
	::sm_InverseLN2{ 1.0f / Math<float>::sm_LN2 };
template<>
const float Mathematics::Math<float>
	::sm_InverseLN10{ 1.0f / Math<float>::sm_LN10 };
template<>
const float Mathematics::Math<float>
	::sm_Sqrt2{ Math<float>::Sqrt(2.0f) };
template<>
const float Mathematics::Math<float>
	::sm_InverseSqrt2{ 1.0f / Math<float>::sm_Sqrt2 };
template<>
const float Mathematics::Math<float>
	::sm_Sqrt3{ Math<float>::Sqrt(3.0f) };
template<>
const float Mathematics::Math<float>
	::sm_InverseSqrt3{ 1.0f / Math<float>::sm_Sqrt3 };

template<>
const float Mathematics::Math<float>
	::sm_Zero{ 0.0f };
template<>
const float Mathematics::Math<float>
	::sm_One{ 1.0f };
template<>
const float Mathematics::Math<float>
	::sm_Two{ 2.0f };
template<>
const float Mathematics::Math<float>
	::sm_Three{ 3.0f };
template<>
const float Mathematics::Math<float>
	::sm_NegativeOne{ -sm_One };
template<>
const float Mathematics::Math<float>
	::sm_OneHalf{ sm_One / sm_Two };
template<>
const float Mathematics::Math<float>
	::sm_OneThird{ sm_One / sm_Three };

// Math<double>公用常数特化。
template<>
const double Mathematics::Math<double>
	::sm_Epsilon{ DBL_EPSILON };
template<>
const double Mathematics::Math<double>
	::sm_ZeroTolerance{ 1e-08 };
template<>
const double Mathematics::Math<double>
	::sm_MaxReal{ DBL_MAX };
template<>
const double Mathematics::Math<double>
	::sm_Exponent{ Math<double>::Log(sm_MaxReal) };
template<>
const double Mathematics::Math<double>
	::sm_PI{ 4.0 * Math<double>::ATan(1.0) };
template<>
const double Mathematics::Math<double>
	::sm_TwoPI{ 2.0 * Math<double>::sm_PI };
template<>
const double Mathematics::Math<double>
	::sm_HalfPI{ 0.5 * Math<double>::sm_PI };
template<>
const double Mathematics::Math<double>
	::sm_QuarterPI{ 0.25 * Math<double>::sm_PI };
template<>
const double Mathematics::Math<double>
	::sm_InversePI{ 1.0 / Math<double>::sm_PI };
template<>
const double Mathematics::Math<double>
	::sm_InverseTwoPI{ 1.0 / Math<double>::sm_TwoPI };
template<>
const double Mathematics::Math<double>
	::sm_DegToRad{ Math<double>::sm_PI / 180.0 };
template<>
const double Mathematics::Math<double>
	::sm_RadToDeg{ 180.0 / Math<double>::sm_PI };
template<>
const double Mathematics::Math<double>
	::sm_LN2{ Math<double>::Log(2.0) };
template<>
const double Mathematics::Math<double>
	::sm_LN10{ Math<double>::Log(10.0) };
template<>
const double Mathematics::Math<double>
	::sm_InverseLN2{ 1.0 / Math<double>::sm_LN2 };
template<>
const double Mathematics::Math<double>
	::sm_InverseLN10{ 1.0 / Math<double>::sm_LN10 };
template<>
const double Mathematics::Math<double>
	::sm_Sqrt2{ Math<double>::Sqrt(2.0) };
template<>
const double Mathematics::Math<double>
	::sm_InverseSqrt2{ 1.0 / Math<double>::sm_Sqrt2 };
template<>
const double Mathematics::Math<double>
	::sm_Sqrt3{ Math<double>::Sqrt(3.0) };
template<>
const double Mathematics::Math<double>
	::sm_InverseSqrt3{ 1.0 / Math<double>::sm_Sqrt3 }; 

template<>
const double Mathematics::Math<double>
	::sm_Zero{ 0.0 };
template<>
const double Mathematics::Math<double>
	::sm_One{ 1.0 };
template<>
const double Mathematics::Math<double>
	::sm_Two{ 2.0 };
template<>
const double Mathematics::Math<double>
	::sm_Three{ 3.0 };
template<>
const double Mathematics::Math<double>
	::sm_NegativeOne{ -sm_One };
template<>
const double Mathematics::Math<double>
	::sm_OneHalf{ sm_One / sm_Two };
template<>
const double Mathematics::Math<double>
	::sm_OneThird{ sm_One / sm_Three };

template <typename Real>
Real Mathematics::Math<Real>
	::ACos(Real value) noexcept
{
	if (value < sm_NegativeOne)
		return sm_PI;
	else if (sm_One < value)
		return sm_Zero;
	else
		return acos(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::ASin(Real value) noexcept
{
	if (value < sm_NegativeOne)
		return -sm_HalfPI;
	else if (sm_One < value)
		return sm_HalfPI;
	else
		return asin(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::ATan(Real value) noexcept
{
	return atan(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::ATan2(Real y, Real x) noexcept
{
	if (sm_Epsilon < FAbs(x) || sm_Epsilon < FAbs(y))
	{
		return atan2(y, x);
	}
	else
	{
		// 在数学上，ATan2(0,0)是不确定的，但是ANSI标准要求函数返回0。
		return sm_Zero;
	}
}

template <typename Real>
Real Mathematics::Math<Real>
	::Sin(Real value) noexcept
{
	return sin(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Cos(Real value) noexcept
{
	return cos(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Tan(Real value) noexcept
{
	return tan(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Ceil(Real value) noexcept
{
	return ceil(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::FAbs(Real value) noexcept
{
	return fabs(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Floor(Real value) noexcept
{
	return floor(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::FMod(Real x, Real y)  
{
	MATHEMATICS_ASSERTION_3(sm_Epsilon < FAbs(y), "输入值为0！\n");

	return fmod(x, y);
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::Math<Real>
	::Sign(Real value) noexcept
{
	if (sm_Epsilon < value)
		return NumericalValueSymbol::Positive;
	else if (value < -sm_Epsilon)
		return NumericalValueSymbol::Negative;
	else
		return NumericalValueSymbol::Zero;
}

template <typename Real>
Real Mathematics::Math<Real>
	::Log(Real value)
{
	MATHEMATICS_ASSERTION_3(sm_Zero < value, "Log的输入值为非正数！\n");

	return log(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Log2(Real value)
{
	MATHEMATICS_ASSERTION_3(sm_Zero < value, "Log2的输入值为非正数！\n");

	return sm_InverseLN2 * log(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Log10(Real value)
{
	MATHEMATICS_ASSERTION_3(sm_Zero < value, "Log10的输入值为非正数！\n");

	return sm_InverseLN10 * log(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Exp(Real value)
{
	MATHEMATICS_ASSERTION_3(value <= sm_Exponent, "输入值过大导致exp()计算溢出！\n");

	return exp(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Pow(Real base, Real exponent)
{
	MATHEMATICS_ASSERTION_3(sm_Zero <= base, "Pow中base不允许为负数！\n");
	MATHEMATICS_ASSERTION_3(sm_Epsilon < FAbs(base) || sm_Epsilon < exponent, "0的非正数次方不存在！\n");

	return pow(base, exponent);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Square(Real value) noexcept
{
	return value * value;
}

template <typename Real>
Real Mathematics::Math<Real>
	::Sqrt(Real value)  
{	 
	MATHEMATICS_ASSERTION_3(sm_Zero <= value, "Sqrt的输入值不允许为负数！\n");	 

	return sqrt(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::InvSqrt(Real value)
{
	MATHEMATICS_ASSERTION_3(sm_Zero < value, "InvSqrt中除数必须大于0！\n");

	return sm_One / Sqrt(value);
}

template <typename Real>
Real Mathematics::Math<Real>
	::CubeRoot(Real value)
{
	if (value < sm_Zero)
		return -Pow(-value, sm_OneThird);
	else
		return Pow(value, sm_OneThird);
}

template <typename Real>
Real Mathematics::Math<Real>
	::Clamp(Real value, Real minValue, Real maxValue) noexcept
{
	if (value <= minValue)
		return minValue;
	else if (maxValue <= value)
		return maxValue;
	else
		return value;
}

template <typename Real>
Real Mathematics::Math<Real>
	::Saturate(Real value) noexcept
{
	if (value <= sm_Zero)
		return sm_Zero;
	else if (sm_One <= value)
		return sm_One;
	else
		return value;
}

template <typename Real>
bool Mathematics::Math<Real>
	::Approximate(Real lhs, Real rhs, const Real epsilon)  
{
	MATHEMATICS_ASSERTION_3(sm_Zero <= epsilon, "epsilon必须大于0！");

	if (FAbs(lhs - rhs) <= epsilon)
		return true;
	else
		return false;
}

template <typename Real>
bool Mathematics::Math<Real>
	::FloatingPointEqual(Real lhs, Real rhs, int equalDigit)
{
	MATHEMATICS_ASSERTION_3(0 < equalDigit && equalDigit <= IntegerTraits<Real>::TraitsType::g_ExponentShifting, "equalDigit必须大于0！");

	FloatingPointAnalysis<Real> lhsAnalysis{ lhs };
	FloatingPointAnalysis<Real> rhsAnalysis{ rhs };

	return (lhsAnalysis.GetSymbolValue() == rhsAnalysis.GetSymbolValue()) &&
		   (lhsAnalysis.GetExponent() == rhsAnalysis.GetExponent()) &&
		   ((lhsAnalysis.GetMantissa() >> (IntegerTraits<Real>::TraitsType::g_ExponentShifting - equalDigit)) == (rhsAnalysis.GetMantissa() >> (IntegerTraits<Real>::TraitsType::g_ExponentShifting - equalDigit)));
}

template <typename Real>
Real Mathematics::Math<Real>
	::GetNumericalRoundOffNonnegative(Real value) noexcept
{
	if (value < sm_Zero)
	{
		return sm_Zero;
	}

	return value;
}

template <typename Real>
Real Mathematics::Math<Real>
	::GetNumericalRoundOff(Real value, Real minValue, Real maxValue) noexcept
{
	if (value < minValue)
		return minValue;
	else if (maxValue < value)
		return maxValue;
	else
		return value;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATH_DETAIL)

#endif // MATHEMATICS_BASE_MATH_DETAIL_H