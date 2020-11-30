///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/30 10:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H

#include "RombergIntegral.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

template <typename Real, typename UserDataType>
Mathematics::RombergIntegral<Real, UserDataType>::RombergIntegral(int order, Real begin, Real end, Function function, const UserDataType* userData)
    : m_Order{ order }, m_Begin{ begin }, m_End{ end }, m_Function{ function }, m_UserData{ userData }, m_Value{}, m_Rom{}
{
    m_Rom.fill(Container(m_Order));

    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::RombergIntegral<Real, UserDataType>::Calculate() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto difference = m_End - m_Begin;

    m_Rom[0][0] = Math::GetRational(1, 2) * difference * (m_Function(m_Begin, m_UserData) + m_Function(m_End, m_UserData));

    auto p0 = 1;
    for (auto orderIndex = 2; orderIndex <= m_Order; ++orderIndex)
    {
        // 通过梯形规则逼近。
        auto sum = Math::GetValue(0);

        for (auto i = 1; i <= p0; ++i)
        {
            sum += m_Function(m_Begin + difference * (i - (Math::GetRational(1, 2))), m_UserData);
        }

        // Richardson 外推法。
        m_Rom[1][0] = (Math::GetRational(1, 2) * (m_Rom[0][0] + difference * sum));

        auto p2 = 4;
        for (auto i = 1; i < orderIndex; ++i)
        {
            const auto next = i - 1;
            auto value1 = p2 * m_Rom[1][next];
            auto value2 = value1 - m_Rom[0][next];
            auto value3 = p2 - 1;
            m_Rom[1][i] = (value2) / (value3);

            p2 *= 4;
        }

        for (auto i = 0; i < orderIndex; ++i)
        {
            m_Rom[0][i] = m_Rom[1][i];
        }

        p0 *= 2;
        difference *= Math::GetRational(1, 2);
    }

    const auto orderMinus1 = m_Order - 1;

    m_Value = m_Rom[0][orderMinus1];

#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::RombergIntegral<Real, UserDataType>::IsValid() const noexcept
{
    if (m_Function != nullptr && 0 < m_Order)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::RombergIntegral<Real, UserDataType>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Value;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H
