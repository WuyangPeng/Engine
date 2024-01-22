/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:44)

#ifndef MATHEMATICS_OBJECTS_3D_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_CAPSULE3_ACHIEVE_H

#include "Capsule3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Capsule3<Real>::Capsule3(const Segment3& segment, Real radius) noexcept
    : segment{ segment }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Capsule3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::Capsule3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Real Mathematics::Capsule3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return radius;
}

#endif  // MATHEMATICS_OBJECTS_3D_CAPSULE3_ACHIEVE_H