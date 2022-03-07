///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/09 19:04)

#ifndef MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H

#include "Box2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iostream>

template <typename Real>
Mathematics::Box2<Real>::Box2(const Vector2& center, const Vector2& axis0, const Vector2& axis1, const Real extent0, const Real extent1, const Real epsilon) noexcept
    : center{ center }, axis{ axis0, axis1 }, extent{ extent0, extent1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Box2<Real>::Box2() noexcept
    : center{}, axis{}, extent{}, epsilon{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Box2<Real>::IsValid() const noexcept
{
    try
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (axis[0].IsNormalize(epsilon) &&
            axis[1].IsNormalize(epsilon) &&
            -epsilon <= extent[0] &&
            -epsilon <= extent[1])

    #include STSTEM_WARNING_POP
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Box2<Real>::VerticesType Mathematics::Box2<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto extAxis0 = GetAxis0() * GetExtent0();
    const auto extAxis1 = GetAxis1() * GetExtent1();

    VerticesType vertex{ center - extAxis0 - extAxis1,
                         center + extAxis0 - extAxis1,
                         center + extAxis0 + extAxis1,
                         center - extAxis0 + extAxis1 };

    return vertex;
}

template <typename Real>
typename Mathematics::Box2<Real>::Vector2 Mathematics::Box2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
typename Mathematics::Box2<Real>::Vector2 Mathematics::Box2<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[0];

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Box2<Real>::Vector2 Mathematics::Box2<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[1];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box2<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[0];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box2<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[1];

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Box2<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::Box2<Real>::GetMove(Real t, const Vector2& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Box2{ GetCenter() * t + velocity, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), GetEpsilon() };
}

template <typename Real>
bool Mathematics::Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    return Vector2Tools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Box2<Real>& box)
{
    outFile << "center="
            << box.GetCenter()
            << ",axis0="
            << box.GetAxis0()
            << ",axis1="
            << box.GetAxis1()
            << "extent0="
            << box.GetExtent0()
            << "extent1="
            << box.GetExtent1();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H
