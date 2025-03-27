/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/22 16:38)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_DETAIL_H

#include "Circle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Algebra::Circle3<Real>::Circle3() noexcept
    : center{},
      normal{ MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(1) },
      radius{ MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Algebra::Circle3<Real>::Circle3(const Vector3Type& inCenter, const Vector3Type& inNormal, Real inRadius) noexcept
    : center{ inCenter },
      normal{ inNormal },
      radius{ inRadius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::Circle3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Algebra::Circle3<Real>::Vector3Type Mathematics::Algebra::Circle3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Algebra::Circle3<Real>::Vector3Type Mathematics::Algebra::Circle3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Algebra::Circle3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Algebra::Circle3<Real>::SetCenter(const Vector3Type& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Algebra::Circle3<Real>::SetNormal(const Vector3Type& aNormal) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    normal = aNormal;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Algebra::Circle3<Real>::SetRadius(Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    radius = aRadius;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator==(const Circle3<Real>& lhs, const Circle3<Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() && lhs.GetNormal() == rhs.GetNormal() && lhs.GetRadius() == rhs.GetRadius();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator!=(const Circle3<Real>& lhs, const Circle3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<(const Circle3<Real>& lhs, const Circle3<Real>& rhs)
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

    return lhs.GetRadius() < rhs.GetRadius();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator<=(const Circle3<Real>& lhs, const Circle3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>(const Circle3<Real>& lhs, const Circle3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Algebra::operator>=(const Circle3<Real>& lhs, const Circle3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_DETAIL_H
