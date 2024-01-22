/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 11:20)

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
Real Mathematics::Circle2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

#endif  // MATHEMATICS_OBJECTS_2D_CIRCLE2_ACHIEVE_H