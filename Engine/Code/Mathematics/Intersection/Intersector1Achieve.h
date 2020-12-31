///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 14:37)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_ACHIEVE_H

#include "Intersector1.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Intersector1<Real>::Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon) noexcept
    : m_U{ u0, u1 }, m_V{ v0, v1 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Intersector1<Real>::IsValid() const noexcept
{
    if (m_U.GetX() <= m_U.GetY() && m_V.GetX() <= m_V.GetY() && Math::GetValue(0) <= m_Epsilon)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Intersector1<Real>::GetU(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_U[index];
}

template <typename Real>
Real Mathematics::Intersector1<Real>::GetV(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_V[index];
}

template <typename Real>
Real Mathematics::Intersector1<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Epsilon;
}

template <typename Real>
void Mathematics::Intersector1<Real>::Swap(Intersector1& rhs) noexcept
{
    std::swap(m_U, rhs.m_U);
    std::swap(m_V, rhs.m_V);
    std::swap(m_Epsilon, rhs.m_Epsilon);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR1_ACHIEVE_H