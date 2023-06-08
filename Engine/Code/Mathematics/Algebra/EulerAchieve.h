///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 15:35)

#ifndef MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H

#include "Euler.h"
#include "Flags/ExtractEulerResultType.h"
#include "Flags/MatrixFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real> bool Mathematics::Euler<Real>::IsValid() const noexcept
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
requires std::is_arithmetic_v<Real>
Mathematics::ExtractEulerResultType Mathematics::Euler<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extractEulerResultType;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::ExtractEulerResultOrder Mathematics::Euler<Real>::GetOrder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return order;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetX0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return x0Angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetY0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return y0Angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetZ0Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return z0Angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetX1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return x1Angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetY1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return y1Angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetZ1Angle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return z1Angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Euler<Real>::GetAngle(MatrixRotationAxis axisIndex) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    switch (axisIndex)
    {
        case MatrixRotationAxis::X:
            return x0Angle;
        case MatrixRotationAxis::Y:
            return y0Angle;
        default:
            return z0Angle;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Euler<Real>::SetAngle(MatrixRotationAxis axisIndex, Real angle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    switch (axisIndex)
    {
        case MatrixRotationAxis::X:
            x0Angle = angle;
            break;
        case MatrixRotationAxis::Y:
            y0Angle = angle;
            break;
        default:
            z0Angle = angle;
            break;
    }
}

#endif  // MATHEMATICS_ALGEBRA_EULER_ACHIEVE_H
