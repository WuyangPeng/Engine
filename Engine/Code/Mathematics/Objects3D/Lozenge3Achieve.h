///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 17:46)

#ifndef MATHEMATICS_OBJECTS3D_LOZENGE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_LOZENGE3_ACHIEVE_H

#include "Lozenge3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Lozenge3<Real>::Lozenge3(const Rectangle3& rectangle, Real radius) noexcept
    : m_Rectangle{ rectangle }, m_Radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Lozenge3<Real>::IsValid() const noexcept
{
    if (Math<Real>::GetValue(0) < m_Radius)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::Lozenge3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rectangle;
}

template <typename Real>
Real Mathematics::Lozenge3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

#endif  // MATHEMATICS_OBJECTS3D_LOZENGE3_ACHIEVE_H
