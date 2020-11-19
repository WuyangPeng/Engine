///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 13:40)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_ACHIEVE_H

#include "Circle2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Circle2<Real>::Circle2(const Vector2D& center, Real radius) noexcept
    : m_Center{ center }, m_Radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Circle2<Real>::Circle2() noexcept
    : m_Center{}, m_Radius{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Circle2<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Radius)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Circle2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
void Mathematics::Circle2<Real>::SetCircle(const Vector2D& center, Real radius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Center = center;
    m_Radius = radius;
}

template <typename Real>
Real Mathematics::Circle2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

#endif  // MATHEMATICS_OBJECTS2D_CIRCLE2_ACHIEVE_H