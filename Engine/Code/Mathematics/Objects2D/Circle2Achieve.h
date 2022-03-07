///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 10:20)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_ACHIEVE_H

#include "Circle2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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
void Mathematics::Circle2<Real>::SetCircle(const Vector2& newCenter, Real newRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = newCenter;
    radius = newRadius;
}

template <typename Real>
Real Mathematics::Circle2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

#endif  // MATHEMATICS_OBJECTS2D_CIRCLE2_ACHIEVE_H