///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 16:49)

#ifndef MATHEMATICS_OBJECTS2D_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_SEGMENT2_ACHIEVE_H

#include "Segment2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Segment2<Real>::Segment2(const Vector2D& beginPoint, const Vector2D& endPoint, const Real epsilon)
    : m_BeginPoint{ beginPoint },
      m_EndPoint{ endPoint },
      m_Center{ Math::GetRational(1, 2) * (m_BeginPoint + m_EndPoint) },
      m_Direction{ m_EndPoint - m_BeginPoint },
      m_Extent{ Vector2DTools::VectorMagnitude(m_Direction) / Math::GetValue(2) },
      m_Epsilon{ epsilon }
{
    m_Direction.Normalize(m_Epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Segment2<Real>::Segment2(Real extent, const Vector2D& center, const Vector2D& direction, const Real epsilon)
    : m_BeginPoint{ center - extent * direction },
      m_EndPoint{ center + extent * direction },
      m_Center{ center },
      m_Direction{ direction },
      m_Extent{ extent },
      m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Segment2<Real>::IsValid() const noexcept
{
    try
    {
        if (m_Direction.IsNormalize(m_Epsilon) &&
            Vector2DTools::Approximate(m_BeginPoint, m_Center - m_Extent * m_Direction, m_Epsilon) &&
            Vector2DTools::Approximate(m_EndPoint, m_Center + m_Extent * m_Direction, m_Epsilon) &&
            Vector2DTools::Approximate(m_Center, Math::GetRational(1, 2) * (m_BeginPoint + m_EndPoint), m_Epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>::GetBeginPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_BeginPoint;
}

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>::GetEndPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_EndPoint;
}

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>::GetCenterPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction;
}

template <typename Real>
Real Mathematics::Segment2<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent;
}

// private
template <typename Real>
void Mathematics::Segment2<Real>::ComputeCenterDirectionExtent()
{
    m_Center = Math::GetRational(1, 2) * (m_BeginPoint + m_EndPoint);
    m_Direction = m_EndPoint - m_BeginPoint;
    m_Extent = Math::GetRational(1, 2) * Vector2DTools::VectorMagnitude(m_Direction);

    m_Direction.Normalize(m_Epsilon);
}

// private
template <typename Real>
void Mathematics::Segment2<Real>::ComputeEndPoints()
{
    m_BeginPoint = m_Center - m_Extent * m_Direction;
    m_EndPoint = m_Center + m_Extent * m_Direction;
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::Segment2<Real>::GetMove(Real t, const Vector2D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Segment2{ m_Extent, m_Center + t * velocity, m_Direction, m_Epsilon };
}

#endif  // MATHEMATICS_OBJECTS2D_SEGMENT2_ACHIEVE_H
