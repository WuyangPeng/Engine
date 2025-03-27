///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:55)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_ACHIEVE_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_ACHIEVE_H

#include "FastNegativeExp.h"
#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpMoreRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

    auto result = static_cast<Real>(0.0038278);

    result *= value;
    result += static_cast<Real>(0.0292732);
    result *= value;
    result += static_cast<Real>(0.2507213);
    result *= value;
    result += static_cast<Real>(1.0);
    result *= result;
    result *= result;
    result = static_cast<Real>(1.0) / result;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

    auto result = static_cast<Real>(0.00026695);

    result *= value;
    result += static_cast<Real>(0.00227723);
    result *= value;
    result += static_cast<Real>(0.03158565);
    result *= value;
    result += static_cast<Real>(0.24991035);
    result *= value;
    result += static_cast<Real>(1.0);
    result *= result;
    result *= result;
    result = static_cast<Real>(1.0) / result;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

    auto result = static_cast<Real>(0.000014876);

    result *= value;
    result += static_cast<Real>(0.000127992);
    result *= value;
    result += static_cast<Real>(0.002673255);
    result *= value;
    result += static_cast<Real>(0.031198056);
    result *= value;
    result += static_cast<Real>(0.250010936);
    result *= value;
    result += static_cast<Real>(1.0);
    result *= result;
    result *= result;

    result = static_cast<Real>(1.0) / result;

    return result;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpMorePreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

    auto result = static_cast<Real>(0.0000006906);

    result *= value;
    result += static_cast<Real>(0.0000054302);
    result *= value;
    result += static_cast<Real>(0.0001715620);
    result *= value;
    result += static_cast<Real>(0.0025913712);
    result *= value;
    result += static_cast<Real>(0.0312575832);
    result *= value;
    result += static_cast<Real>(0.2499986842);
    result *= value;
    result += static_cast<Real>(1.0);
    result *= result;
    result *= result;
    result = static_cast<Real>(1.0) / result;

    return result;
}

#endif  // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_ACHIEVE_H