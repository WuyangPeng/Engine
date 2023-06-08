///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H

#include "RombergIntegral.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real, typename UserDataType>
Mathematics::RombergIntegral<Real, UserDataType>::RombergIntegral(int order, Real begin, Real end, Function function, const UserDataType* userData)
    : order{ order }, begin{ begin }, end{ end }, function{ function }, userData{ userData }, value{}, rom{}
{
    rom.fill(Container(order));

    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
void Mathematics::RombergIntegral<Real, UserDataType>::Calculate()
{
    CoreTools::DisableNoexcept();

    auto difference = end - begin;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    rom[0][0] = Math::GetRational(1, 2) * difference * (function(begin, userData) + function(end, userData));

    auto p0 = 1;
    for (auto orderIndex = 2; orderIndex <= order; ++orderIndex)
    {
        // 通过梯形规则逼近。
        auto sum = Math::GetValue(0);

        for (auto i = 1; i <= p0; ++i)
        {
            sum += function(begin + difference * (i - (Math::GetRational(1, 2))), userData);
        }

        // Richardson 外推法。
        rom[1][0] = (Math::GetRational(1, 2) * (rom[0][0] + difference * sum));

        auto p2 = 4;
        for (auto i = 1; i < orderIndex; ++i)
        {
            const auto next = i - 1;
            auto value1 = p2 * rom[1][next];
            auto value2 = value1 - rom[0][next];
            auto value3 = p2 - 1;
            rom[1][i] = (value2) / (value3);

            p2 *= 4;
        }

        for (auto i = 0; i < orderIndex; ++i)
        {
            rom[0][i] = rom[1][i];
        }

        p0 *= 2;
        difference *= Math::GetRational(1, 2);
    }

    const auto orderMinus1 = order - 1;

    value = rom[0][orderMinus1];

#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::RombergIntegral<Real, UserDataType>::IsValid() const noexcept
{
    if (function != nullptr && 0 < order)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::RombergIntegral<Real, UserDataType>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return value;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H
