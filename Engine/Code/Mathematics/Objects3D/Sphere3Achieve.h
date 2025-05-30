/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:37)

#ifndef MATHEMATICS_OBJECTS_3D_SPHERE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_SPHERE3_ACHIEVE_H

#include "Sphere3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Sphere3<Real>::Sphere3(const Vector3Type& center, Real radius) noexcept
    : center{ center }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Sphere3<Real>::Sphere3() noexcept
    : center{}, radius{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Sphere3<Real>::IsValid() const noexcept
{
    if (MathType::GetValue(0) <= radius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Sphere3<Real>::Vector3Type Mathematics::Sphere3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Real Mathematics::Sphere3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
void Mathematics::Sphere3<Real>::SetSphere(const Vector3Type& aCenter, Real aRadius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = aCenter;
    radius = aRadius;
}

#endif  // MATHEMATICS_OBJECTS_3D_SPHERE3_ACHIEVE_H