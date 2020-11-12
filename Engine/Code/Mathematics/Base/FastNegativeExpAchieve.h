///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 14:44)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_ACHIEVE_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_ACHIEVE_H

#include "FastNegativeExp.h"
#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpMoreRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

    auto result = static_cast<Real>(0.0038278);

    result *= value;
    result += static_cast<Real>(0.0292732);
    result *= value;
    result += static_cast<Real>(0.2507213);
    result *= value;
    result += Math::GetValue(1);
    result *= result;
    result *= result;
    result = Math::GetValue(1) / result;

    return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

    auto result = static_cast<Real>(0.00026695);

    result *= value;
    result += static_cast<Real>(0.00227723);
    result *= value;
    result += static_cast<Real>(0.03158565);
    result *= value;
    result += static_cast<Real>(0.24991035);
    result *= value;
    result += Math::GetValue(1);
    result *= result;
    result *= result;
    result = Math::GetValue(1) / result;

    return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

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
    result += Math::GetValue(1);
    result *= result;
    result *= result;

    result = Math::GetValue(1) / result;

    return result;
}

template <typename Real>
Real Mathematics::FastNegativeExp<Real>::FastNegativeExpMorePreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= value, "输入值必须在范围[0,无穷大)！\n");

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
    result += Math::GetValue(1);
    result *= result;
    result *= result;
    result = Math::GetValue(1) / result;

    return result;
}

#endif  // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_ACHIEVE_H