///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 10:45)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_RAY2_ACHIEVE_H

#include "Ray2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Ray2<Real>::Ray2(const Vector2& origin, const Vector2& direction, const Real epsilon) noexcept
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
typename Mathematics::Ray2<Real>::Vector2 Mathematics::Ray2<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
typename Mathematics::Ray2<Real>::Vector2 Mathematics::Ray2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::Ray2<Real>::GetMove(Real t, const Vector2& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Ray2{ origin + t * velocity, direction, epsilon };
}

#endif  // MATHEMATICS_OBJECTS2D_RAY2_ACHIEVE_H