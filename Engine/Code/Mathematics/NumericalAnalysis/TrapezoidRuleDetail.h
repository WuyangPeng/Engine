///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/30 10:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_DETAIL_H

#include "TrapezoidRule.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::TrapezoidRule<Real, UserDataType>::TrapezoidRule(int numSamples, Real begin, Real end, Function function, const UserDataType* userData)
    : m_NumSamples{ numSamples }, m_Begin{ begin }, m_End{ end }, m_Function{ function }, m_UserData{ userData }, m_Value{}
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::TrapezoidRule<Real, UserDataType>::Calculate()
{
    const auto numSamples = m_NumSamples - 1;
    auto difference = (m_End - m_Begin) / boost::numeric_cast<Real>(numSamples);
    m_Value = Math::GetRational(1, 2) * (m_Function(m_Begin, m_UserData) + m_Function(m_End, m_UserData));

    for (auto i = 1; i <= m_NumSamples - 2; ++i)
    {
        m_Value += m_Function(m_Begin + i * difference, m_UserData);
    }

    m_Value *= difference;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::TrapezoidRule<Real, UserDataType>::IsValid() const noexcept
{
    if (m_Function != nullptr && 2 <= m_NumSamples)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::TrapezoidRule<Real, UserDataType>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Value;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_DETAIL_H
