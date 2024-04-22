/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:20)

#ifndef MATHEMATICS_OBJECTS_2D_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS_2D_CIRCLE2_ACHIEVE_H

#include "Circle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Circle2<Real>::Circle2(const Vector2& center, Real radius) noexcept
    : center{ center }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Circle2<Real>::Circle2() noexcept
    : center{}, radius{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Circle2<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= radius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Circle2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
void Mathematics::Circle2<Real>::SetCircle(const Vector2& aCenter, Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = aCenter;
    radius = aRadius;
}

template <typename Real>
void Mathematics::Circle2<Real>::SetCenter(const Vector2& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = aCenter;
}

template <typename Real>
void Mathematics::Circle2<Real>::SetCenter(const AlgebraVector2& aCenter)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = Vector2{ aCenter[0], aCenter[1] };
}

template <typename Real>
void Mathematics::Circle2<Real>::SetCenterX(Real x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center.SetX(x);
}

template <typename Real>
void Mathematics::Circle2<Real>::SetCenterY(Real y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center.SetY(y);
}

template <typename Real>
void Mathematics::Circle2<Real>::SetRadius(Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    radius = aRadius;
}

template <typename Real>
Real Mathematics::Circle2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

#endif  // MATHEMATICS_OBJECTS_2D_CIRCLE2_ACHIEVE_H