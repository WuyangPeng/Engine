///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:37)

#ifndef MATHEMATICS_ALGEBRA_AXIS_ANGLE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXIS_ANGLE_ACHIEVE_H

#include "AxisAngle.h"
#include "Vector3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AxisAngle<Real>::AxisAngle(Real angle, const Vector3& axis) noexcept
    : angle{ angle }, axis{ axis }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AxisAngle<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxisAngle<Real>::GetAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AxisAngle<Real>::Vector3 Mathematics::AxisAngle<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

#endif  // MATHEMATICS_ALGEBRA_AXIS_ANGLE_ACHIEVE_H
