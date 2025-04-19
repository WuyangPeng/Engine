///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:55)

#ifndef MATHEMATICS_BASE_FAST_TRIGONOMETRIC_ACHIEVE_H
#define MATHEMATICS_BASE_FAST_TRIGONOMETRIC_ACHIEVE_H

#include "FastTrigonometric.h"
#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastSinRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "输入值必须在范围[0,pi/2]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = static_cast<Real>(7.61e-03);
    result *= angleSquare;
    result -= static_cast<Real>(1.6605e-01);
    result *= angleSquare;
    result += static_cast<Real>(1.0);
    result *= angle;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastSinPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "输入值必须在范围[0,pi/2]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = static_cast<Real>(-2.39e-08);
    result *= angleSquare;
    result += static_cast<Real>(2.7526e-06);
    result *= angleSquare;
    result -= static_cast<Real>(1.98409e-04);
    result *= angleSquare;
    result += static_cast<Real>(8.3333315e-03);
    result *= angleSquare;
    result -= static_cast<Real>(1.666666664e-01);
    result *= angleSquare;
    result += static_cast<Real>(1.0);
    result *= angle;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastSinMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "输入值必须在范围[0,pi/2]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = angleSquare / static_cast<Real>(20.0) / static_cast<Real>(21.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(18.0) / static_cast<Real>(19.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(16.0) / static_cast<Real>(17.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(14.0) / static_cast<Real>(15.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(12.0) / static_cast<Real>(13.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(10.0) / static_cast<Real>(11.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(8.0) / static_cast<Real>(9.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(6.0) / static_cast<Real>(7.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(4.0) / static_cast<Real>(5.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(2.0) / static_cast<Real>(3.0);
    result = static_cast<Real>(1.0) - result;
    result *= angle;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastCosRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "输入值必须在范围[0,pi/2]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = static_cast<Real>(3.705e-02);
    result *= angleSquare;
    result -= static_cast<Real>(4.967e-01);
    result *= angleSquare;
    result += static_cast<Real>(1.0);

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastCosPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "输入值必须在范围[0,pi/2]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = -static_cast<Real>(2.605e-07);
    result *= angleSquare;
    result += static_cast<Real>(2.47609e-05);
    result *= angleSquare;
    result -= static_cast<Real>(1.3888397e-03);
    result *= angleSquare;
    result += static_cast<Real>(4.16666418e-02);
    result *= angleSquare;
    result -= static_cast<Real>(4.999999963e-01);
    result *= angleSquare;
    result += static_cast<Real>(1.0);

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastCosMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "输入值必须在范围[0,pi/2]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = angleSquare / static_cast<Real>(21.0) / static_cast<Real>(22.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(19.0) / static_cast<Real>(20.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(17.0) / static_cast<Real>(18.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(15.0) / static_cast<Real>(16.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(13.0) / static_cast<Real>(14.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(11.0) / static_cast<Real>(12.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(9.0) / static_cast<Real>(10.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(7.0) / static_cast<Real>(8.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(5.0) / static_cast<Real>(6.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(3.0) / static_cast<Real>(4.0);
    result = static_cast<Real>(1.0) - result;
    result *= angleSquare / static_cast<Real>(2.0);
    result = static_cast<Real>(1.0) - result;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastTanRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetQuarterPI(), "输入值必须在范围[0,pi/4]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = static_cast<Real>(2.033e-01);
    result *= angleSquare;
    result += static_cast<Real>(3.1755e-01);
    result *= angleSquare;
    result += static_cast<Real>(1.0);
    result *= angle;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastTanPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetQuarterPI(), "输入值必须在范围[0,pi/4]！\n");

    const auto angleSquare = MathType::Square(angle);

    auto result = static_cast<Real>(9.5168091e-03);
    result *= angleSquare;
    result += static_cast<Real>(2.900525e-03);
    result *= angleSquare;
    result += static_cast<Real>(2.45650893e-02);
    result *= angleSquare;
    result += static_cast<Real>(5.33740603e-02);
    result *= angleSquare;
    result += static_cast<Real>(1.333923995e-01);
    result *= angleSquare;
    result += static_cast<Real>(3.333314036e-01);
    result *= angleSquare;
    result += static_cast<Real>(1.0);
    result *= angle;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastTanMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= angle && angle <= MathType::GetQuarterPI(), "输入值必须在范围[0,pi/4]！\n");

    return FastSinMorePreciseCalculation(angle) / FastCosMorePreciseCalculation(angle);
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastInvSinRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value && value <= MathType::GetValue(1), "输入值必须在范围[0,1]！\n");

    const auto root = MathType::Sqrt(MathType::GetValue(1) - value);

    auto result = static_cast<Real>(-0.0187293);
    result *= value;
    result += static_cast<Real>(0.0742610);
    result *= value;
    result -= static_cast<Real>(0.2121144);
    result *= value;
    result += static_cast<Real>(1.5707288);

    result = MathType::GetHalfPI() - root * result;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastInvSinPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value && value <= MathType::GetValue(1), "输入值必须在范围[0,1]！\n");

    const auto root = MathType::Sqrt(MathType::GetValue(1) - value);

    auto result = static_cast<Real>(-0.0012624911);
    result *= value;
    result += static_cast<Real>(0.0066700901);
    result *= value;
    result -= static_cast<Real>(0.0170881256);
    result *= value;
    result += static_cast<Real>(0.0308918810);
    result *= value;
    result -= static_cast<Real>(0.0501743046);
    result *= value;
    result += static_cast<Real>(0.0889789874);
    result *= value;
    result -= static_cast<Real>(0.2145988016);
    result *= value;
    result += static_cast<Real>(1.5707963050);

    result = MathType::GetHalfPI() - root * result;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastInvCosRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value && value <= MathType::GetValue(1), "输入值必须在范围[0,1]！\n");

    const auto root = MathType::Sqrt(MathType::GetValue(1) - value);

    auto result = static_cast<Real>(-0.0187293);
    result *= value;
    result += static_cast<Real>(0.0742610);
    result *= value;
    result -= static_cast<Real>(0.2121144);
    result *= value;
    result += static_cast<Real>(1.5707288);
    result *= root;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastInvCosPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value && value <= MathType::GetValue(1), "输入值必须在范围[0,1]！\n");

    const auto root = MathType::Sqrt(MathType::GetValue(1) - value);

    auto result = static_cast<Real>(-0.0012624911);
    result *= value;
    result += static_cast<Real>(0.0066700901);
    result *= value;
    result -= static_cast<Real>(0.0170881256);
    result *= value;
    result += static_cast<Real>(0.0308918810);
    result *= value;
    result -= static_cast<Real>(0.0501743046);
    result *= value;
    result += static_cast<Real>(0.0889789874);
    result *= value;
    result -= static_cast<Real>(0.2145988016);
    result *= value;
    result += static_cast<Real>(1.5707963050);
    result *= root;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastInvTanRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(-1) <= value && value <= MathType::GetValue(1), "输入值必须在范围[-1,1]！\n");

    const auto valueSquare = MathType::Square(value);

    auto result = static_cast<Real>(0.0208351);
    result *= valueSquare;
    result -= static_cast<Real>(0.085133);
    result *= valueSquare;
    result += static_cast<Real>(0.180141);
    result *= valueSquare;
    result -= static_cast<Real>(0.3302995);
    result *= valueSquare;
    result += static_cast<Real>(0.999866);
    result *= value;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastTrigonometric<Real>::FastInvTanPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(-1) <= value && value <= MathType::GetValue(1), "输入值必须在范围[-1,1]！\n");

    const auto valueSquare = MathType::Square(value);

    auto result = static_cast<Real>(0.0028662257);
    result *= valueSquare;
    result -= static_cast<Real>(0.0161657367);
    result *= valueSquare;
    result += static_cast<Real>(0.0429096138);
    result *= valueSquare;
    result -= static_cast<Real>(0.0752896400);
    result *= valueSquare;
    result += static_cast<Real>(0.1065626393);
    result *= valueSquare;
    result -= static_cast<Real>(0.1420889944);
    result *= valueSquare;
    result += static_cast<Real>(0.1999355085);
    result *= valueSquare;
    result -= static_cast<Real>(0.3333314528);
    result *= valueSquare;
    result += static_cast<Real>(1.0);
    result *= value;

    return result;
}

#endif  // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_ACHIEVE_H