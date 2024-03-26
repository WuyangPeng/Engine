/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 14:26)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_RESULT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_RESULT_DETAIL_H

#include "LevenbergMarquardtMinimizerResult.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::LevenbergMarquardtMinimizerResult<T>::LevenbergMarquardtMinimizerResult() noexcept
    : minLocation{},
      minError{},
      minErrorDifference{},
      minUpdateLength{},
      numIterations{ 0 },
      numAdjustments{ 0 },
      converged{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::LevenbergMarquardtMinimizerResult<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename Mathematics::LevenbergMarquardtMinimizerResult<T>::VariableLengthVector Mathematics::LevenbergMarquardtMinimizerResult<T>::GetMinLocation() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minLocation;
}

template <typename T>
T Mathematics::LevenbergMarquardtMinimizerResult<T>::GetMinError() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minError;
}

template <typename T>
T Mathematics::LevenbergMarquardtMinimizerResult<T>::GetMinErrorDifference() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minErrorDifference;
}

template <typename T>
T Mathematics::LevenbergMarquardtMinimizerResult<T>::GetMinUpdateLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minUpdateLength;
}

template <typename T>
int Mathematics::LevenbergMarquardtMinimizerResult<T>::GetNumIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numIterations;
}

template <typename T>
int Mathematics::LevenbergMarquardtMinimizerResult<T>::GetNumAdjustments() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numAdjustments;
}

template <typename T>
bool Mathematics::LevenbergMarquardtMinimizerResult<T>::IsConverged() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return converged;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetMinLocation(const VariableLengthVector& aMinLocation)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minLocation = aMinLocation;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetMinError(T aMinError) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minError = aMinError;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetMinErrorDifference(T aMinErrorDifference) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minErrorDifference = aMinErrorDifference;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetMinUpdateLength(T aMinUpdateLength) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minUpdateLength = aMinUpdateLength;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetNumIterations(int aNumIterations) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    numIterations = aNumIterations;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::AddNumIterations() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ++numIterations;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetNumAdjustments(int aNumAdjustments) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    numAdjustments = aNumAdjustments;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::AddNumAdjustments() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ++numAdjustments;
}

template <typename T>
void Mathematics::LevenbergMarquardtMinimizerResult<T>::SetConverged(bool aConverged) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    converged = aConverged;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_RESULT_DETAIL_H
