///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 13:50)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_ACHIEVE_H

#include "Intersector1.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Intersector1<Real>::Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon) noexcept
    : u{ u0, u1 }, v{ v0, v1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Intersector1<Real>::IsValid() const noexcept
{
    if (u.GetX() <= u.GetY() && v.GetX() <= v.GetY() && Math::GetValue(0) <= epsilon)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Intersector1<Real>::GetU(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return u[index];
}

template <typename Real>
Real Mathematics::Intersector1<Real>::GetV(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return v[index];
}

template <typename Real>
Real Mathematics::Intersector1<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename Real>
void Mathematics::Intersector1<Real>::Swap(Intersector1& rhs) noexcept
{
    std::swap(u, rhs.u);
    std::swap(v, rhs.v);
    std::swap(epsilon, rhs.epsilon);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR1_ACHIEVE_H