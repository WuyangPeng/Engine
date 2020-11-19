///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 18:20)

#ifndef MATHEMATICS_OBJECTS3D_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_CYLINDER3_ACHIEVE_H

#include "Cylinder3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Cylinder3<Real>::Cylinder3(const Line3& axis, Real radius, Real height) noexcept
    : m_Axis{ axis }, m_Radius{ radius }, m_Height{ height }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Cylinder3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Radius && Math::GetValue(0) <= m_Height)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::Cylinder3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Axis;
}

template <typename Real>
Real Mathematics::Cylinder3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
Real Mathematics::Cylinder3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Height;
}

#endif  // MATHEMATICS_OBJECTS3D_CYLINDER3_ACHIEVE_H