///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 11:08)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_DETAIL_H

#include "TrapezoidRule.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::TrapezoidRule<Real, UserDataType>::TrapezoidRule(int numSamples, Real begin, Real end, Function function, const UserDataType* userData)
    : numSamples{ numSamples }, begin{ begin }, end{ end }, function{ function }, userData{ userData }, value{}
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::TrapezoidRule<Real, UserDataType>::Calculate()
{
    const auto numSamplesReduce1 = numSamples - 1;
    auto difference = (end - begin) / boost::numeric_cast<Real>(numSamplesReduce1);
    value = Math::GetRational(1, 2) * (function(begin, userData) + function(end, userData));

    for (auto i = 1; i <= numSamples - 2; ++i)
    {
        value += function(begin + i * difference, userData);
    }

    value *= difference;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::TrapezoidRule<Real, UserDataType>::IsValid() const noexcept
{
    if (function != nullptr && 2 <= numSamples)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::TrapezoidRule<Real, UserDataType>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return value;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_DETAIL_H
