/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:37)

#ifndef MATHEMATICS_OBJECTS_3D_RECTANGLE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_RECTANGLE3_DETAIL_H

#include "Rectangle3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Rectangle3<Real>::Rectangle3() noexcept
    : center{}, axis{ Vector3Type::GetUnitX(), Vector3Type::GetUnitY() }, extent{ MathType::GetValue(1), MathType::GetValue(1) }, epsilon{ MathType::GetZeroTolerance() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Rectangle3<Real>::Rectangle3(const Vector3Type& center, const Vector3Type& axis0, const Vector3Type& axis1, Real extent0, Real extent1, Real epsilon) noexcept
    : center{ center }, axis{ axis0, axis1 }, extent{ extent0, extent1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Rectangle3<Real>::Rectangle3(const AlgebraRectangle3& rectangle3, Real epsilon)
    : center{ Vector3Type{ rectangle3.GetCenter() } }, axis{ Vector3Type{ rectangle3.GetAxis(0) }, Vector3Type{ rectangle3.GetAxis(1) } }, extent{ rectangle3.GetExtent(0), rectangle3.GetExtent(1) }, epsilon{ epsilon }
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
Mathematics::Rectangle3<Real> Mathematics::Rectangle3<Real>::GetMove(Real t, const Vector3Type& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Rectangle3{ GetCenter() + t * velocity, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), epsilon };
}

template <typename Real>
typename Mathematics::Rectangle3<Real>::AlgebraRectangle3 Mathematics::Rectangle3<Real>::GetAlgebraRectangle3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return AlgebraRectangle3{ center.GetVector(), { GetAxis0().GetVector(), GetAxis1().GetVector() }, { GetExtent0(), GetExtent1() } };
}

template <int N, typename Real>
bool Mathematics::operator==(const Rectangle3<Real>& lhs, const Rectangle3<Real>& rhs)
{
    if (lhs.GetCenter() != rhs.GetCenter())
    {
        return false;
    }

    for (auto i = 0; i < 2; ++i)
    {
        if (lhs.GetAxis(i) != rhs.GetAxis(i))
        {
            return false;
        }
    }

    for (auto i = 0; i < 2; ++i)
    {
        if (lhs.GetExtent(i) != rhs.GetExtent(i))
        {
            return false;
        }
    }

    return true;
}

template <int N, typename Real>
bool Mathematics::operator!=(const Rectangle3<Real>& lhs, const Rectangle3<Real>& rhs)
{
    return !(lhs < rhs);
}

template <int N, typename Real>
bool Mathematics::operator<(const Rectangle3<Real>& lhs, const Rectangle3<Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetAxis() < rhs.GetAxis())
    {
        return true;
    }

    if (rhs.GetAxis() < lhs.GetAxis())
    {
        return false;
    }

    return lhs.GetExtent() < rhs.GetExtent();
}

template <int N, typename Real>
bool Mathematics::operator<=(const Rectangle3<Real>& lhs, const Rectangle3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
bool Mathematics::operator>(const Rectangle3<Real>& lhs, const Rectangle3<Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
bool Mathematics::operator>=(const Rectangle3<Real>& lhs, const Rectangle3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_RECTANGLE3_DETAIL_H
