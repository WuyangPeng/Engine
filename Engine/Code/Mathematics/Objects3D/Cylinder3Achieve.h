///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 15:06)

#ifndef MATHEMATICS_OBJECTS3D_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_CYLINDER3_ACHIEVE_H

#include "Cylinder3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Cylinder3<Real>::Cylinder3(const Line3& axis, Real radius, Real height) noexcept
    : axis{ axis }, radius{ radius }, height{ height }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Cylinder3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= radius && Math::GetValue(0) <= height)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::Cylinder3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis;
}

template <typename Real>
Real Mathematics::Cylinder3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
Real Mathematics::Cylinder3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return height;
}

#endif  // MATHEMATICS_OBJECTS3D_CYLINDER3_ACHIEVE_H