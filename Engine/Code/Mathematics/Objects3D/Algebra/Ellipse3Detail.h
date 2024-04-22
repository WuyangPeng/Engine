///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/24 20:24)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_ELLIPSE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_ELLIPSE3_DETAIL_H

#include "Ellipse3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Ellipse3<Real>::Ellipse3() noexcept
    : center{},
      normal{ Real{}, Real{}, Math::GetValue(1) },
      axis{ Vector3{ Math::GetValue(1), Real{}, Real{} },
            Vector3{ Real{}, Math::GetValue(1), Real{} } },
      extent{ Math::GetValue(1), Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::Ellipse3<Real>::Ellipse3(const Vector3& center, const Vector3& normal, const AxisType& axis, const Vector2& extent) noexcept
    : center{ center },
      normal{ normal },
      axis{ axis },
      extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Ellipse3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Ellipse3<Real>::Vector3 Mathematics::Algebra::Ellipse3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Ellipse3<Real>::Vector3 Mathematics::Algebra::Ellipse3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Ellipse3<Real>::AxisType Mathematics::Algebra::Ellipse3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Ellipse3<Real>::Vector3 Mathematics::Algebra::Ellipse3<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis.at(index);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Ellipse3<Real>::Vector2 Mathematics::Algebra::Ellipse3<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Ellipse3<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent[index];
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Ellipse3<Real>::SetCenter(const Vector3& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Ellipse3<Real>::SetNormal(const Vector3& aNormal) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    normal = aNormal;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Ellipse3<Real>::SetAxis(const AxisType& aAxis) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis = aAxis;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Ellipse3<Real>::SetExtent(const Vector2& aExtent) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    extent = aExtent;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Ellipse3<Real>::SetAxis(int index, const Vector3& aAxis)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis.at(index) = aAxis;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator==(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() &&
           lhs.GetNormal() == rhs.GetNormal() &&
           lhs.GetAxis(0) == rhs.GetAxis(0) &&
           lhs.GetAxis(1) == rhs.GetAxis(1) &&
           lhs.GetExtent() == rhs.GetExtent();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator!=(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetNormal() < rhs.GetNormal())
    {
        return true;
    }

    if (rhs.GetNormal() < lhs.GetNormal())
    {
        return false;
    }

    if (lhs.GetAxis(0) < rhs.GetAxis(0))
    {
        return true;
    }

    if (rhs.GetAxis(0) < lhs.GetAxis(0))
    {
        return false;
    }

    if (lhs.GetAxis(1) < rhs.GetAxis(1))
    {
        return true;
    }

    if (rhs.GetAxis(1) < lhs.GetAxis(1))
    {
        return false;
    }

    return lhs.GetExtent() < rhs.GetExtent();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<=(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>=(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_ELLIPSE3_DETAIL_H
