/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:18)

#ifndef MATHEMATICS_OBJECTS_2D_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_OBJECTS_2D_SEGMENT2_ACHIEVE_H

#include "Segment2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Segment2<Real>::Segment2(const Vector2& beginPoint, const Vector2& endPoint, Real epsilon)
    : beginPoint{ beginPoint },
      endPoint{ endPoint },
      center{ Math::GetRational(1, 2) * (beginPoint + endPoint) },
      direction{ endPoint - beginPoint },
      extent{ Vector2Tools::GetLength(direction) / Math::GetValue(2) },
      epsilon{ epsilon }
{
    direction.Normalize(epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Segment2<Real>::Segment2(Real extent, const Vector2& center, const Vector2& direction, Real epsilon)
    : beginPoint{ center - extent * direction },
      endPoint{ center + extent * direction },
      center{ center },
      direction{ direction },
      extent{ extent },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Segment2<Real>::IsValid() const noexcept
{
    try
    {
        if (direction.IsNormalize(epsilon) &&
            Vector2Tools::Approximate(beginPoint, center - extent * direction, epsilon) &&
            Vector2Tools::Approximate(endPoint, center + extent * direction, epsilon) &&
            Vector2Tools::Approximate(center, Math::GetRational(1, 2) * (beginPoint + endPoint), epsilon))
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
typename Mathematics::Segment2<Real>::Vector2 Mathematics::Segment2<Real>::GetBeginPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return beginPoint;
}

template <typename Real>
typename Mathematics::Segment2<Real>::Vector2 Mathematics::Segment2<Real>::GetEndPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endPoint;
}

template <typename Real>
typename Mathematics::Segment2<Real>::Vector2 Mathematics::Segment2<Real>::GetCenterPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
typename Mathematics::Segment2<Real>::Vector2 Mathematics::Segment2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction;
}

template <typename Real>
Real Mathematics::Segment2<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent;
}

template <typename Real>
void Mathematics::Segment2<Real>::ComputeCenterDirectionExtent()
{
    center = Math::GetRational(1, 2) * (beginPoint + endPoint);
    direction = endPoint - beginPoint;
    extent = Math::GetRational(1, 2) * Vector2Tools::GetLength(direction);

    direction.Normalize(epsilon);
}

template <typename Real>
void Mathematics::Segment2<Real>::ComputeEndPoints()
{
    beginPoint = center - extent * direction;
    endPoint = center + extent * direction;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::Segment2<Real>::GetMove(Real t, const Vector2& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Segment2{ extent, center + t * velocity, direction, epsilon };
}

#endif  // MATHEMATICS_OBJECTS_2D_SEGMENT2_ACHIEVE_H
