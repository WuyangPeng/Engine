///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/22 14:45)

#ifndef MATHEMATICS_OBJECTS_2D_SECTOR2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_SECTOR2_DETAIL_H

#include "Sector2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Sector2<Real>::Sector2() noexcept
    : vertex{},
      radius{ MathType::GetValue(1) },
      direction{ MathType::GetValue(1), MathType::GetValue(0) },
      angle{ MathType::GetPI() },
      cosAngle{ MathType::GetValue(-1) },
      sinAngle{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Sector2<Real>::Sector2(const Vector2Type& inVertex, Real inRadius, const Vector2Type& inDirection, Real inAngle) noexcept
    : vertex{ inVertex },
      radius{ inRadius },
      direction{ inDirection },
      angle{ inAngle },
      cosAngle{ MathType::GetValue(-1) },
      sinAngle{}
{
    SetAngle(inAngle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Sector2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Sector2<Real>::SetAngle(Real inAngle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    angle = inAngle;
    cosAngle = MathType::Cos(angle);
    sinAngle = MathType::Sin(angle);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Sector2<Real>::Vector2Type Mathematics::Sector2<Real>::GetVertex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertex;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Sector2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Sector2<Real>::Vector2Type Mathematics::Sector2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return direction;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Sector2<Real>::GetAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Sector2<Real>::GetCosAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Sector2<Real>::GetSinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinAngle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Sector2<Real>::SetVertex(const Vector2Type& aVertex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertex = aVertex;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Sector2<Real>::SetRadius(Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    radius = aRadius;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Sector2<Real>::SetDirection(const Vector2Type& aDirection) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    direction = aDirection;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Sector2<Real>::Contains(const Vector2Type& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto diff = point - vertex;
    const auto length = Length(diff);

    return length <= radius && length * cosAngle <= Dot(direction, diff);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const Sector2<Real>& lhs, const Sector2<Real>& rhs)
{
    return lhs.GetVertex() == rhs.GetVertex() && lhs.GetRadius() == rhs.GetRadius() && lhs.GetDirection() == rhs.GetDirection() && lhs.GetAngle() == rhs.GetAngle();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator!=(const Sector2<Real>& lhs, const Sector2<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const Sector2<Real>& lhs, const Sector2<Real>& rhs)
{
    if (lhs.GetVertex() < rhs.GetVertex())
    {
        return true;
    }

    if (rhs.GetVertex() < lhs.GetVertex())
    {
        return false;
    }

    if (lhs.GetRadius() < rhs.GetRadius())
    {
        return true;
    }

    if (rhs.GetRadius() < lhs.GetRadius())
    {
        return false;
    }

    if (lhs.GetDirection() < rhs.GetDirection())
    {
        return true;
    }

    if (rhs.GetDirection() < lhs.GetDirection())
    {
        return false;
    }

    return lhs.GetAngle() < rhs.GetAngle();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<=(const Sector2<Real>& lhs, const Sector2<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>(const Sector2<Real>& lhs, const Sector2<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>=(const Sector2<Real>& lhs, const Sector2<Real>& rhs)
{
    return !(rhs < lhs);
}

#endif  // MATHEMATICS_OBJECTS_2D_SECTOR2_DETAIL_H
