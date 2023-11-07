///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:21)

#ifndef MATHEMATICS_OBJECTS_3D_LOZENGE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_LOZENGE3_DETAIL_H

#include "Lozenge3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Lozenge3<Real>::Lozenge3(const Rectangle3& rectangle, Real radius) noexcept
    : rectangle{ rectangle }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Lozenge3<Real>::IsValid() const noexcept
{
    if (Math<Real>::GetValue(0) < radius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::Lozenge3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
Real Mathematics::Lozenge3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

#endif  // MATHEMATICS_OBJECTS_3D_LOZENGE3_DETAIL_H
