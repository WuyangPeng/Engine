/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 14:04)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_CONTROL_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_CONTROL_DETAIL_H

#include "ApproximationCone3EllipseAndPointsControl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::ApproximationCone3EllipseAndPointsControl() noexcept
    : penalty{ MathType::GetValue(1) },
      maxSubdivisions{ 8 },
      maxBisections{ 64 },
      epsilon{ MathType::GetValue(1e-08) },
      tolerance{ MathType::GetValue(1e-04) },
      padding{ MathType::GetValue(1e-03) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::ValidParameters() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return penalty > Real{} && maxSubdivisions > 0 && maxBisections > 0 && epsilon > Real{} && tolerance > Real{} && padding > Real{};
}
template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::GetPenalty() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return penalty;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::GetMaxSubdivisions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxSubdivisions;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::GetMaxBisections() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxBisections;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return epsilon;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::GetTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tolerance;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::GetPadding() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return padding;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::SetPenalty(Real aPenalty) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    penalty = aPenalty;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::SetMaxSubdivisions(int aMaxSubdivisions) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxSubdivisions = aMaxSubdivisions;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::SetMaxBisections(int aMaxBisections) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxBisections = aMaxBisections;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::SetEpsilon(Real aEpsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    epsilon = aEpsilon;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::SetTolerance(Real aTolerance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tolerance = aTolerance;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3EllipseAndPointsControl<Real>::SetPadding(Real aPadding) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    padding = aPadding;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_CONTROL_DETAIL_H
