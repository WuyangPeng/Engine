///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 17:09)

#ifndef MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H

#include "Euler.h"
#include "Flags/ExtractEulerResultType.h"
#include "Flags/MatrixFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Euler<Real>::Euler(ExtractEulerResultType type, ExtractEulerResultOrder order, Real x0Angle, Real y0Angle, Real z0Angle, Real x1Angle, Real y1Angle, Real z1Angle) noexcept
    : m_Type{ type }, m_Order{ order }, m_X0Angle{ x0Angle }, m_Y0Angle{ y0Angle },
      m_Z0Angle{ z0Angle }, m_X1Angle{ x1Angle }, m_Y1Angle{ y1Angle }, m_Z1Angle{ z1Angle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Euler<Real>::IsValid() const noexcept
{
    if (-Math::GetPI() <= m_X0Angle && m_X0Angle <= Math::GetPI() &&
        -Math::GetPI() <= m_Y0Angle && m_Y0Angle <= Math::GetPI() &&
        -Math::GetPI() <= m_Z0Angle && m_Z0Angle <= Math::GetPI() &&
        -Math::GetPI() <= m_X1Angle && m_X1Angle <= Math::GetPI() &&
        -Math::GetPI() <= m_Y1Angle && m_Y1Angle <= Math::GetPI() &&
        -Math::GetPI() <= m_Z1Angle && m_Z1Angle <= Math::GetPI())
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::ExtractEulerResultType Mathematics::Euler<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Type;
}

template <typename Real>
Mathematics::ExtractEulerResultOrder Mathematics::Euler<Real>::GetOrder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Order;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetX0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_X0Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetY0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Y0Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetZ0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Z0Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetX1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_X1Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetY1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Y1Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetZ1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Z1Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetAngle(MatrixRotationAxis axisIndex) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    switch (axisIndex)
    {
        case Mathematics::MatrixRotationAxis::X:
            return m_X0Angle;
        case Mathematics::MatrixRotationAxis::Y:
            return m_Y0Angle;
        default:
            return m_Z0Angle;
    }
}

template <typename Real>
void Mathematics::Euler<Real>::SetAngle(MatrixRotationAxis axisIndex, Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    switch (axisIndex)
    {
        case Mathematics::MatrixRotationAxis::X:
            m_X0Angle = angle;
            break;
        case Mathematics::MatrixRotationAxis::Y:
            m_Y0Angle = angle;
            break;
        default:
            m_Z0Angle = angle;
            break;
    }
}

#endif  // MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H
