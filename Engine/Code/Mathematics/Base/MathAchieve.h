///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/29 11:24)

#ifndef MATHEMATICS_BASE_MATH_ACHIEVE_H
#define MATHEMATICS_BASE_MATH_ACHIEVE_H

#include "Math.h"
#include "Mathematics/Rational/FloatingPointAnalysisDetail.h"

#include <algorithm>
#include <cmath>

template <typename Real>
Real Mathematics::Math<Real>::GetExponent() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto exponent = Log(maxReal);

    return exponent;
}

template <typename Real>
Real Mathematics::Math<Real>::GetLN2() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto ln2 = Log(GetValue(2));

    return ln2;
}

template <typename Real>
Real Mathematics::Math<Real>::GetLN10() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto ln10 = Log(GetValue(10));

    return ln10;
}

template <typename Real>
Real Mathematics::Math<Real>::GetInverseLN2() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto inverseLN2 = GetValue(1) / GetLN2();

    return inverseLN2;
}

template <typename Real>
Real Mathematics::Math<Real>::GetInverseLN10() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto inverseLN10 = GetValue(1) / GetLN10();

    return inverseLN10;
}

template <typename Real>
Real Mathematics::Math<Real>::GetSqrt2() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto sqrt2 = Sqrt(GetValue(2));

    return sqrt2;
}

template <typename Real>
Real Mathematics::Math<Real>::GetInverseSqrt2() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto inverseSqrt2 = GetValue(1) / GetSqrt2();

    return inverseSqrt2;
}

template <typename Real>
Real Mathematics::Math<Real>::GetSqrt3() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto sqrt3 = Sqrt(GetValue(3));

    return sqrt3;
}

template <typename Real>
Real Mathematics::Math<Real>::GetInverseSqrt3() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static const auto inverseSqrt3 = GetValue(1) / GetSqrt3();

    return inverseSqrt3;
}

template <typename Real>
Real Mathematics::Math<Real>::ACos(Real value) noexcept
{
    if (value <= GetValue(-1))
        return GetPI();
    else if (GetValue(1) <= value)
        return GetValue(0);
    else
        return acos(value);
}

template <typename Real>
Real Mathematics::Math<Real>::ASin(Real value) noexcept
{
    if (value <= GetValue(-1))
        return -GetHalfPI();
    else if (GetValue(1) <= value)
        return GetHalfPI();
    else
        return asin(value);
}

template <typename Real>
Real Mathematics::Math<Real>::ATan(Real value) noexcept
{
    return atan(value);
}

template <typename Real>
Real Mathematics::Math<Real>::ATan2(Real y, Real x) noexcept
{
    if (epsilon < FAbs(x) || epsilon < FAbs(y))
    {
        return atan2(y, x);
    }
    else
    {
        // 在数学上，ATan2(0,0)是不确定的，但是ANSI标准要求函数返回0。
        return GetValue(0);
    }
}

template <typename Real>
Real Mathematics::Math<Real>::Sin(Real value) noexcept
{
    return sin(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Cos(Real value) noexcept
{
    return cos(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Tan(Real value) noexcept
{
    return tan(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Ceil(Real value) noexcept
{
    return ceil(value);
}

template <typename Real>
Real Mathematics::Math<Real>::FAbs(Real value) noexcept
{
    return fabs(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Floor(Real value) noexcept
{
    return floor(value);
}

template <typename Real>
Real Mathematics::Math<Real>::FMod(Real x, Real y) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetZeroTolerance() < FAbs(y), "输入值为0！\n");

    return fmod(x, y);
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::Math<Real>::Sign(Real value) noexcept
{
    if (epsilon < value)
        return NumericalValueSymbol::Positive;
    else if (value < -epsilon)
        return NumericalValueSymbol::Negative;
    else
        return NumericalValueSymbol::Zero;
}

template <typename Real>
Real Mathematics::Math<Real>::Log(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) < value, "Log的输入值为非正数！\n");

    return log(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Log2(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) < value, "Log2的输入值为非正数！\n");

    return GetInverseLN2() * log(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Log10(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) < value, "Log10的输入值为非正数！\n");

    return GetInverseLN10() * log(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Exp(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(value <= GetExponent(), "输入值过大导致exp()计算溢出！\n");

    return exp(value);
}

template <typename Real>
Real Mathematics::Math<Real>::Pow(Real base, Real exponent) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) <= base, "Pow中base不允许为负数！\n");
    MATHEMATICS_ASSERTION_3(GetZeroTolerance() < FAbs(base) || GetZeroTolerance() < exponent, "0的非正数次方不存在！\n");

    return pow(base, exponent);
}

template <typename Real>
Real Mathematics::Math<Real>::Square(Real value) noexcept
{
    return value * value;
}

template <typename Real>
Real Mathematics::Math<Real>::Sqrt(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) <= value, "Sqrt的输入值不允许为负数！\n");

    return sqrt(value);
}

template <typename Real>
Real Mathematics::Math<Real>::InvSqrt(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) < value, "InvSqrt中除数必须大于0！\n");

    return GetValue(1) / Sqrt(value);
}

template <typename Real>
Real Mathematics::Math<Real>::CubeRoot(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    if (value < GetValue(0))
        return -Pow(-value, GetRational(1, 3));
    else
        return Pow(value, GetRational(1, 3));
}

template <typename Real>
Real Mathematics::Math<Real>::Clamp(Real value, Real minValue, Real maxValue) noexcept
{
    if (value <= minValue)
        return minValue;
    else if (maxValue <= value)
        return maxValue;
    else
        return value;
}

template <typename Real>
Real Mathematics::Math<Real>::Saturate(Real value) noexcept
{
    if (value <= GetValue(0))
        return GetValue(0);
    else if (GetValue(1) <= value)
        return GetValue(1);
    else
        return value;
}

template <typename Real>
bool Mathematics::Math<Real>::Approximate(Real lhs, Real rhs, const Real zeroTolerance) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(GetValue(0) <= zeroTolerance, "epsilon必须大于0！");

    if (FAbs(lhs - rhs) <= zeroTolerance)
        return true;
    else
        return false;
}

template <typename Real>
bool Mathematics::Math<Real>::FloatingPointEqual(Real lhs, Real rhs, int equalDigit) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(0 < equalDigit && equalDigit <= IntegerTraits<Real>::TraitsType::exponentShifting, "equalDigit必须大于0！");

    const FloatingPointAnalysis<Real> lhsAnalysis{ lhs };
    const FloatingPointAnalysis<Real> rhsAnalysis{ rhs };

    const auto shifting = IntegerTraits<Real>::TraitsType::exponentShifting - equalDigit;

    return (lhsAnalysis.GetSymbolValue() == rhsAnalysis.GetSymbolValue()) &&
           (lhsAnalysis.GetExponent() == rhsAnalysis.GetExponent()) &&
           ((lhsAnalysis.GetMantissa() >> shifting) == (rhsAnalysis.GetMantissa() >> shifting));
}

template <typename Real>
Real Mathematics::Math<Real>::GetNumericalRoundOffNonnegative(Real value) noexcept
{
    if (value < GetValue(0))
    {
        return GetValue(0);
    }

    return value;
}

template <typename Real>
Real Mathematics::Math<Real>::GetNumericalRoundOff(Real value, Real minValue, Real maxValue) noexcept
{
    if (value < minValue)
        return minValue;
    else if (maxValue < value)
        return maxValue;
    else
        return value;
}

#endif  // MATHEMATICS_BASE_MATH_ACHIEVE_H