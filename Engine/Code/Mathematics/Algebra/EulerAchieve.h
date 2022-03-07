///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 17:02)

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
    : extractEulerResultType{ type },
      order{ order },
      x0Angle{ x0Angle },
      y0Angle{ y0Angle },
      z0Angle{ z0Angle },
      x1Angle{ x1Angle },
      y1Angle{ y1Angle },
      z1Angle{ z1Angle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Euler<Real>::IsValid() const noexcept
{
    if (-Math::GetPI() <= x0Angle && x0Angle <= Math::GetPI() &&
        -Math::GetPI() <= y0Angle && y0Angle <= Math::GetPI() &&
        -Math::GetPI() <= z0Angle && z0Angle <= Math::GetPI() &&
        -Math::GetPI() <= x1Angle && x1Angle <= Math::GetPI() &&
        -Math::GetPI() <= y1Angle && y1Angle <= Math::GetPI() &&
        -Math::GetPI() <= z1Angle && z1Angle <= Math::GetPI())
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

    return extractEulerResultType;
}

template <typename Real>
Mathematics::ExtractEulerResultOrder Mathematics::Euler<Real>::GetOrder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return order;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetX0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return x0Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetY0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return y0Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetZ0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return z0Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetX1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return x1Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetY1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return y1Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetZ1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return z1Angle;
}

template <typename Real>
Real Mathematics::Euler<Real>::GetAngle(MatrixRotationAxis axisIndex) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    switch (axisIndex)
    {
        case Mathematics::MatrixRotationAxis::X:
            return x0Angle;
        case Mathematics::MatrixRotationAxis::Y:
            return y0Angle;
        default:
            return z0Angle;
    }
}

template <typename Real>
void Mathematics::Euler<Real>::SetAngle(MatrixRotationAxis axisIndex, Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    switch (axisIndex)
    {
        case Mathematics::MatrixRotationAxis::X:
            x0Angle = angle;
            break;
        case Mathematics::MatrixRotationAxis::Y:
            y0Angle = angle;
            break;
        default:
            z0Angle = angle;
            break;
    }
}

#endif  // MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H
