///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/02 13:48)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_EULER_ANGLES_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_EULER_ANGLES_DETAIL_H

#include "EulerAngles.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Flags/EulerResultType.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::EulerAngles<Real>::EulerAngles() noexcept
    : axis{},
      angle{},
      result{ EulerResult::Invalid }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::EulerAngles<Real>::EulerAngles(int axis0, int axis1, int axis2, Real angle0, Real angle1, Real angle2) noexcept
    : axis{ axis0, axis1, axis2 },
      angle{ angle0, angle1, angle2 },
      result{ EulerResult::Unique }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::EulerAngles<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::EulerResult Mathematics::Algebra::EulerAngles<Real>::GetEulerResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::Algebra::EulerAngles<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis.at(index);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::EulerAngles<Real>::GetAngle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return angle.at(index);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::EulerAngles<Real>::SetEulerResult(EulerResult eulerResult) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    result = eulerResult;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::EulerAngles<Real>::SetAxis(int aAxis0, int aAxis1, int aAxis2) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis = { aAxis0, aAxis1, aAxis2 };
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::EulerAngles<Real>::SetAngle(Real aAngle0, Real aAngle1, Real aAngle2) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    angle = { aAngle0, aAngle1, aAngle2 };
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_EULER_ANGLES_DETAIL_H
