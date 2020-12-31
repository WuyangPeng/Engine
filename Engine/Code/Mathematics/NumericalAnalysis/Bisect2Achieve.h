///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:59)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ACHIEVE_H

#include "Bisect2.h"
#include "Detail/Bisect2CalculateDetail.h" 
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2<Real>::Bisect2(Function function0, Function function1, int maxLevel, Real tolerance) noexcept
    : m_Function0{ function0 }, m_Function1{ function1 }, m_MaxLevel{ maxLevel }, m_Tolerance{ tolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2<Real>::IsValid() const noexcept
{
    if (m_Function0 != nullptr && m_Function1 != nullptr && 0 < m_MaxLevel && Math::GetValue(0) <= m_Tolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Bisect2Root<Real> Mathematics::Bisect2<Real>::Bisect(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Bisect2Calculate calculate{ *this, beginPointX, beginPointY, endPointX, endPointY };

    return calculate.GetRoot();
}

template <typename Real>
Real Mathematics::Bisect2<Real>::GetFunction0Value(Real x, Real y) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function0(x, y);
}

template <typename Real>
Real Mathematics::Bisect2<Real>::GetFunction1Value(Real x, Real y) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function1(x, y);
}

template <typename Real>
int Mathematics::Bisect2<Real>::GetMaxLevel() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxLevel;
}

template <typename Real>
Real Mathematics::Bisect2<Real>::GetTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Tolerance;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ACHIEVE_H
