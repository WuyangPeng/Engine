///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:00)

#ifndef MATHEMATICS_OBJECTS3D_CONE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_CONE3_ACHIEVE_H

#include "Cone3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Cone3<Real>::Cone3(const Vector3D& vertex, const Vector3D& axis, const Real angle, const Real height, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : m_Vertex{ vertex },
      m_Axis{ axis },
      m_CosAngle{ Math::Cos(angle) },
      m_SinAngle{ Math::Sin(angle) },
      m_Height{ height },
      m_Epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= angle && angle <= Math::GetHalfPI(), "角度必须在第一象限！");

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Cone3<Real>::Cone3(const Real cosAngle, const Real sinAngle, const Real height, const Vector3D& vertex, const Vector3D& axis, const Real epsilon) noexcept
    : m_Vertex{ vertex }, m_Axis{ axis }, m_CosAngle{ cosAngle }, m_SinAngle{ sinAngle }, m_Height{ height }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Cone3<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::Approximate(m_CosAngle * m_CosAngle + m_SinAngle * m_SinAngle, Math::GetValue(1), m_Epsilon) &&
            m_Epsilon < m_Height &&
            m_Axis.IsNormalize(m_Epsilon))
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
const Mathematics::Vector3D<Real> Mathematics::Cone3<Real>::GetVertex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Vertex;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Cone3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Axis;
}

template <typename Real>
Real Mathematics::Cone3<Real>::GetCosAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_CosAngle;
}

template <typename Real>
Real Mathematics::Cone3<Real>::GetSinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SinAngle;
}

template <typename Real>
Real Mathematics::Cone3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Height;
}

#endif  // MATHEMATICS_OBJECTS3D_CONE3_ACHIEVE_H
