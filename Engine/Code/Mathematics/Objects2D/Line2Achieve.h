///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 16:16)

#ifndef MATHEMATICS_OBJECTS2D_LINE2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_LINE2_ACHIEVE_H

#include "Line2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::Line2<Real>::Line2(const Vector2D& origin, const Vector2D& direction, const Real epsilon) noexcept
    : m_Origin{ origin }, m_Direction{ direction }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Line2<Real>::IsValid() const noexcept
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
const Mathematics::Vector2D<Real> Mathematics::Line2<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Origin;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Line2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction;
}

template <typename Real>
void Mathematics::Line2<Real>::SetDirection(const Vector2D& direction) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Direction = direction;
}

template <typename Real>
void Mathematics::Line2<Real>::SetOrigin(const Vector2D& origin) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Origin = origin;
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::Line2<Real>::GetMove(Real t, const Vector2D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Line2{ m_Origin + t * velocity, m_Direction, m_Epsilon };
}

template <typename Real>
Real Mathematics::Line2<Real>::DotProduct() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector2DTools::DotProduct(m_Direction, m_Origin);
}

#endif  // MATHEMATICS_OBJECTS2D_LINE2_ACHIEVE_H