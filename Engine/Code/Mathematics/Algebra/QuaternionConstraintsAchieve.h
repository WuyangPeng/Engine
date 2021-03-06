///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 18:37)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_ACHIEVE_H

#include "QuaternionConstraints.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::QuaternionConstraints<Real>::QuaternionConstraints(Real minAngle, Real maxAngle) noexcept
    : m_MinAngle{ minAngle },
      m_MaxAngle{ maxAngle },
      m_CosMinAngle{ Math::Cos(m_MinAngle) },
      m_SinMinAngle{ Math::Sin(m_MinAngle) },
      m_CosMaxAngle{ Math::Cos(m_MaxAngle) },
      m_SinMaxAngle{ Math::Sin(m_MaxAngle) },
      m_DiffCosMaxMin{ m_CosMaxAngle - m_CosMinAngle },
      m_DiffSinMaxMin{ m_SinMaxAngle - m_SinMinAngle },
      m_AvrAngle{ Math::GetRational(1, 2) * (m_MinAngle + m_MaxAngle) },
      m_CosAvrAngle{ Math::Cos(m_AvrAngle) },
      m_SinAvrAngle{ Math::Sin(m_AvrAngle) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuaternionConstraints<Real>::IsValid() const noexcept
{
    if (-Math::GetHalfPI() <= m_MinAngle && m_MinAngle <= Math::GetHalfPI() && m_MinAngle <= m_MaxAngle && m_MaxAngle <= Math::GetHalfPI())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuaternionConstraints<Real>::IsValid(Real x, Real y) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(Math::Approximate(Math::Sqrt(x * x + y * y), Math::GetValue(1)), "(x,y)必须是单位长度！");

    // 测试(x,y)是否满足约束条件。
    auto xm = x - m_CosMinAngle;
    auto ym = y - m_SinMinAngle;
    if (ym * m_DiffCosMaxMin <= xm * m_DiffSinMaxMin)
    {
        return true;
    }

    // 测试(-x,-y)是否满足约束条件。
    auto xp = x + m_CosMinAngle;
    auto yp = y + m_SinMinAngle;
    if (xp * m_DiffSinMaxMin <= yp * m_DiffCosMaxMin)
    {
        return true;
    }

    return false;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetCosMinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_CosMinAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetSinMinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SinMinAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetCosMaxAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_CosMaxAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetSinMaxAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SinMaxAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetCosAvrAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_CosAvrAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetSinAvrAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SinAvrAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetMinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>::GetMaxAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxAngle;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_ACHIEVE_H
