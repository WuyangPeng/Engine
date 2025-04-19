/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:19)

#ifndef MATHEMATICS_OBJECTS_2D_LINE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS_2D_LINE2_ACHIEVE_H

#include "Line2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::Line2<Real>::Line2(const Vector2Type& origin, const Vector2Type& direction, Real epsilon) noexcept
    : origin{ origin }, direction{ direction }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Line2<Real>::IsValid() const noexcept
{
    try
    {
        if (direction.IsNormalize(epsilon))
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Line2<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Line2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction;
}

template <typename Real>
void Mathematics::Line2<Real>::SetDirection(const Vector2Type& newDirection) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    direction = newDirection;
}

template <typename Real>
void Mathematics::Line2<Real>::SetOrigin(const Vector2Type& newOrigin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    origin = newOrigin;
}

template <typename Real>
Mathematics::Line2<Real> Mathematics::Line2<Real>::GetMove(Real t, const Vector2Type& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Line2{ origin + t * velocity, direction, epsilon };
}

template <typename Real>
Real Mathematics::Line2<Real>::DotProduct() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector2ToolsType::DotProduct(direction, origin);
}

#endif  // MATHEMATICS_OBJECTS_2D_LINE2_ACHIEVE_H