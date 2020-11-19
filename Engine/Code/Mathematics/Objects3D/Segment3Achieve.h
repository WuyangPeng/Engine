///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 14:49)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_ACHIEVE_H

#include "Segment3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Segment3<Real>::Segment3(const Vector3D& beginPoint, const Vector3D& endPoint, const Real epsilon)
    : m_BeginPoint{ beginPoint },
      m_EndPoint{ endPoint },
      m_Center{ Math::GetRational(1, 2) * (m_BeginPoint + m_EndPoint) },
      m_Direction{ m_EndPoint - m_BeginPoint },
      m_Extent{ Vector3DTools::VectorMagnitude(m_Direction) / Math::GetValue(2) },
      m_Epsilon{ epsilon }
{
    m_Direction.Normalize(m_Epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Segment3<Real>::Segment3(Real extent, const Vector3D& center, const Vector3D& direction, const Real epsilon)
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
bool Mathematics::Segment3<Real>::IsValid() const noexcept
{
    try
    {
        if (m_Direction.IsNormalize(m_Epsilon) &&
            Vector3DTools::Approximate(m_BeginPoint, m_Center - m_Extent * m_Direction, m_Epsilon) &&
            Vector3DTools::Approximate(m_EndPoint, m_Center + m_Extent * m_Direction, m_Epsilon) &&
            Vector3DTools::Approximate(m_Center, Math::GetRational(1, 2) * (m_BeginPoint + m_EndPoint), m_Epsilon))
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
const Mathematics::Vector3D<Real> Mathematics::Segment3<Real>::GetBeginPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_BeginPoint;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Segment3<Real>::GetEndPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_EndPoint;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Segment3<Real>::GetCenterPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Segment3<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction;
}

template <typename Real>
Real Mathematics::Segment3<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent;
}

// private
template <typename Real>
void Mathematics::Segment3<Real>::ComputeCenterDirectionExtent()
{
    m_Center = Math::GetRational(1, 2) * (m_BeginPoint + m_EndPoint);
    m_Direction = m_EndPoint - m_BeginPoint;
    m_Extent = Vector3DTools::VectorMagnitude(m_Direction) / Math::GetValue(2);

    m_Direction.Normalize(m_Epsilon);
}

// private
template <typename Real>
void Mathematics::Segment3<Real>::ComputeEndPoints()
{
    m_BeginPoint = m_Center - m_Extent * m_Direction;
    m_EndPoint = m_Center + m_Extent * m_Direction;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::Segment3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Segment3{ m_Extent, m_Center + t * velocity, m_Direction, m_Epsilon };
}

#endif  // MATHEMATICS_OBJECTS3D_SEGMENT3_ACHIEVE_H
