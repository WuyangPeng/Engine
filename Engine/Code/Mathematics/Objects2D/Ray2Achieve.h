/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:19)

#ifndef MATHEMATICS_OBJECTS_2D_RAY2_ACHIEVE_H
#define MATHEMATICS_OBJECTS_2D_RAY2_ACHIEVE_H

#include "Ray2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Ray2<Real>::Ray2(const Vector2Type& origin, const Vector2Type& direction, Real epsilon) noexcept
    : origin{ origin },
      direction{ direction },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Ray2<Real>::IsValid() const noexcept
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
typename Mathematics::Ray2<Real>::Vector2Type Mathematics::Ray2<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
typename Mathematics::Ray2<Real>::Vector2Type Mathematics::Ray2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::Ray2<Real>::GetMove(Real t, const Vector2Type& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Ray2{ origin + t * velocity, direction, epsilon };
}

#endif  // MATHEMATICS_OBJECTS_2D_RAY2_ACHIEVE_H