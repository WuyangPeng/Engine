///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 17:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ACHIEVE_H

#include "Bisect3.h"
#include "Detail/Bisect3Calculate.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3<Real>::Bisect3(Function function0, Function function1, Function function2, int maxLevel, Real tolerance) noexcept
    : m_Function0{ function0 }, m_Function1{ function1 }, m_Function2{ function2 }, m_MaxLevel{ maxLevel }, m_Tolerance{ tolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3<Real>::IsValid() const noexcept
{
    if (m_Function0 != nullptr && m_Function1 != nullptr && m_Function2 != nullptr && 0 < m_MaxLevel && Math::GetValue(0) <= m_Tolerance)
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
typename const Mathematics::Bisect3<Real>::Bisect3Root Mathematics::Bisect3<Real>::Bisect(Real beginPointX, Real beginPointY, Real beginPointZ, Real endPointX, Real endPointY, Real endPointZ) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Bisect3Calculate calculate{ *this, beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ };

    return calculate.GetRoot();
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetFunction0Value(Real x, Real y, Real z) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function0(x, y, z);
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetFunction1Value(Real x, Real y, Real z) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function1(x, y, z);
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetFunction2Value(Real x, Real y, Real z) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function2(x, y, z);
}

template <typename Real>
int Mathematics::Bisect3<Real>::GetMaxLevel() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxLevel;
}

template <typename Real>
Real Mathematics::Bisect3<Real>::GetTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Tolerance;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ACHIEVE_H
