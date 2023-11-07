///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:24)

#ifndef MATHEMATICS_OBJECTS_3D_RECTANGLE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_RECTANGLE3_DETAIL_H

#include "Rectangle3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Rectangle3<Real>::Rectangle3(const Vector3& center, const Vector3& axis0, const Vector3& axis1, Real extent0, Real extent1, Real epsilon) noexcept
    : center{ center }, axis{ axis0, axis1 }, extent{ extent0, extent1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Rectangle3<Real>::IsValid() const noexcept
{
    try
    {
    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)

        if (axis[0].IsNormalize(epsilon) &&
            axis[1].IsNormalize(epsilon) &&
            -epsilon < extent[0] &&
            -epsilon < extent[1])

    #include SYSTEM_WARNING_POP
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
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return axis[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis.at(index);
}

template <typename Real>
Real Mathematics::Rectangle3<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent.at(index);
}

template <typename Real>
Real Mathematics::Rectangle3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Rectangle3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return extent[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Rectangle3<Real>::VerticesType Mathematics::Rectangle3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto extAxis0 = GetAxis0() * GetExtent0();
    const auto extAxis1 = GetAxis1() * GetExtent1();

    VerticesType vertex{ center - extAxis0 - extAxis1, center + extAxis0 - extAxis1, center + extAxis0 + extAxis1, center - extAxis0 + extAxis1 };

    MATHEMATICS_ASSERTION_1(vertex.size() == 4, "返回的数组大小错误！");

    return vertex;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetPPCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center + GetExtent0() * GetAxis0() + GetExtent1() * GetAxis1();
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetPMCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center + GetExtent0() * GetAxis0() - GetExtent1() * GetAxis1();
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetMPCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center - GetExtent0() * GetAxis0() + GetExtent1() * GetAxis1();
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Rectangle3<Real>::GetMMCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center - GetExtent0() * GetAxis0() - GetExtent1() * GetAxis1();
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::Rectangle3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Rectangle3{ GetCenter() + t * velocity, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), epsilon };
}

#endif  // MATHEMATICS_OBJECTS_3D_RECTANGLE3_DETAIL_H
