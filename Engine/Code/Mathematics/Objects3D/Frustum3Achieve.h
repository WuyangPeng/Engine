///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 18:38)

#ifndef MATHEMATICS_OBJECTS3D_FRUSTUM3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_FRUSTUM3_ACHIEVE_H

#include "Frustum3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Frustum3<Real>::Frustum3(const Vector3D& origin, const Vector3D& directionVector, const Vector3D& upVector, const Vector3D& rightVector, Real directionMin,
                                      Real directionMax, Real upBound, Real rightBound, const Real epsilon) noexcept
    : m_Origin{ origin },
      m_DirectionVector{ directionVector },
      m_UpVector{ upVector },
      m_RightVector{ rightVector },
      m_DirectionMin{ directionMin },
      m_DirectionMax{ directionMax },
      m_UpBound{ upBound },
      m_RightBound{ rightBound },
      m_DirectionRatio{ directionMax / directionMin },
      m_MTwoUF{ Math::GetValue(-2) * upBound * directionMax },
      m_MTwoRF{ Math::GetValue(-2) * rightBound * directionMax },
      m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Frustum3<Real>::IsValid() const noexcept
{
    try
    {
        if (m_DirectionVector.IsNormalize(m_Epsilon) && m_UpVector.IsNormalize(m_Epsilon) && m_RightVector.IsNormalize(m_Epsilon) &&
            Math::GetValue(0) < m_DirectionMin && m_DirectionMin < m_DirectionMax && Math::GetValue(0) < m_RightBound && Math::GetValue(0) < m_UpBound)
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
const Mathematics::Vector3D<Real> Mathematics::Frustum3<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Origin;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Frustum3<Real>::GetDirectionVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionVector;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Frustum3<Real>::GetUpVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UpVector;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Frustum3<Real>::GetRightVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RightVector;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetDirectionMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionMin;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetDirectionMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionMax;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetUpBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UpBound;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetRightBound() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RightBound;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetDirectionRatio() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionRatio;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetMTwoUF() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MTwoUF;
}

template <typename Real>
Real Mathematics::Frustum3<Real>::GetMTwoRF() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MTwoRF;
}

template <typename Real>
const typename Mathematics::Frustum3<Real>::VerticesType Mathematics::Frustum3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto directionScaled = m_DirectionMin * m_DirectionVector;
    auto upScaled = m_UpBound * m_UpVector;
    auto rightScaled = m_RightBound * m_RightVector;

    constexpr auto vertexSize = 8;

    VerticesType vertex(vertexSize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    vertex[0] = directionScaled - upScaled - rightScaled;
    vertex[1] = directionScaled - upScaled + rightScaled;
    vertex[2] = directionScaled + upScaled + rightScaled;
    vertex[3] = directionScaled + upScaled - rightScaled;

    for (auto i = 0; i < vertexSize / 2; ++i)
    {
        auto temp1 = m_DirectionRatio * vertex[i];
        auto temp2 = m_Origin + temp1;
        const auto temp = i + vertexSize / 2;
        vertex[temp] = temp2;
        vertex[i] += m_Origin;
    }

#include STSTEM_WARNING_POP

    return vertex;
}

template <typename Real>
const Mathematics::Frustum3<Real> Mathematics::Frustum3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Frustum3{ GetOrigin() + t * velocity,
                     GetDirectionVector(),
                     GetUpVector(),
                     GetRightVector(),
                     GetDirectionMin(),
                     GetDirectionMax(),
                     GetUpBound(),
                     GetRightBound(),
                     m_Epsilon };
}

// private
template <typename Real>
void Mathematics::Frustum3<Real>::Update() noexcept
{
    m_DirectionRatio = m_DirectionMax / m_DirectionMin;
    m_MTwoUF = Math::GetValue(-2) * m_UpBound * m_DirectionMax;
    m_MTwoRF = Math::GetValue(-2) * m_RightBound * m_DirectionMax;
}

#endif  // MATHEMATICS_OBJECTS3D_FRUSTUM3_ACHIEVE_H
