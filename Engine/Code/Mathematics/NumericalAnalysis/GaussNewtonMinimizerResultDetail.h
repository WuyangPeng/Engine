/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 13:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_RESULT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_RESULT_DETAIL_H

#include "GaussNewtonMinimizerResult.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::GaussNewtonMinimizerResult<Real>::GaussNewtonMinimizerResult() noexcept
    : minLocation{},
      minError{},
      minErrorDifference{},
      minUpdateLength{},
      numIterations{},
      converged{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::GaussNewtonMinimizerResult<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::GaussNewtonMinimizerResult<Real>::VariableLengthVector Mathematics::GaussNewtonMinimizerResult<Real>::GetMinLocation() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minLocation;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::SetMinLocation(const VariableLengthVector& aMinLocation)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minLocation = aMinLocation;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::GaussNewtonMinimizerResult<Real>::GetMinError() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minError;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::SetMinError(Real aMinError) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minError = aMinError;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::GaussNewtonMinimizerResult<Real>::GetMinErrorDifference() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minErrorDifference;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::SetMinErrorDifference(Real aMinErrorDifference) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minErrorDifference = aMinErrorDifference;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::GaussNewtonMinimizerResult<Real>::GetMinUpdateLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minUpdateLength;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::SetMinUpdateLength(Real aMinUpdateLength) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minUpdateLength = aMinUpdateLength;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::GaussNewtonMinimizerResult<Real>::GetNumIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numIterations;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::SetNumIterations(int aNumIterations) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    numIterations = aNumIterations;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::AddNumIterations() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ++numIterations;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::GaussNewtonMinimizerResult<Real>::GetConverged() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return converged;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::GaussNewtonMinimizerResult<Real>::SetConverged(bool aConverged) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    converged = aConverged;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_RESULT_DETAIL_H
