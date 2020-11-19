///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 16:34)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_RAY2_ACHIEVE_H

#include "Ray2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Ray2<Real>::Ray2(const Vector2D& origin, const Vector2D& direction, const Real epsilon) noexcept
    : m_Origin{ origin }, m_Direction{ direction }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ray2<Real>::IsValid() const noexcept
{
    try
    {
        if (m_Direction.IsNormalize(m_Epsilon))
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
typename const Mathematics::Ray2<Real>::Vector2D Mathematics::Ray2<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Origin;
}

template <typename Real>
typename const Mathematics::Ray2<Real>::Vector2D Mathematics::Ray2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction;
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::Ray2<Real>::GetMove(Real t, const Vector2D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Ray2{ m_Origin + t * velocity, m_Direction, m_Epsilon };
}

#endif  // MATHEMATICS_OBJECTS2D_RAY2_ACHIEVE_H