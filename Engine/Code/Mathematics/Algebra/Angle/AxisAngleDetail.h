/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/31 10:25)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_DETAIL_H

#include "AxisAngle.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::AxisAngle<N, Real>::AxisAngle() noexcept
    : axis{}, angle{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::AxisAngle<N, Real>::AxisAngle(const Vector& axis, Real angle) noexcept
    : axis{ axis }, angle{ angle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::AxisAngle<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::AxisAngle<N, Real>::Vector Mathematics::Algebra::AxisAngle<N, Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::AxisAngle<N, Real>::GetAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::AxisAngle<N, Real>::SetAxis(const Vector& aAxis) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis = aAxis;
}

template <int N, typename Real>
requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::AxisAngle<N, Real>::SetAngle(Real aAngle) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    angle = aAngle;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_DETAIL_H
