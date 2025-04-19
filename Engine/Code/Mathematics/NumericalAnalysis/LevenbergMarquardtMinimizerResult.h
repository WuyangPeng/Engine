/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 14:26)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_RESULT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"

namespace Mathematics
{
    template <typename T>
    class LevenbergMarquardtMinimizerResult
    {
    public:
        using ClassType = LevenbergMarquardtMinimizerResult<T>;

        using VariableLengthVectorType = VariableLengthVector<T>;

    public:
        LevenbergMarquardtMinimizerResult() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableLengthVectorType GetMinLocation() const;
        NODISCARD T GetMinError() const noexcept;
        NODISCARD T GetMinErrorDifference() const noexcept;
        NODISCARD T GetMinUpdateLength() const noexcept;
        NODISCARD int GetNumIterations() const noexcept;
        NODISCARD int GetNumAdjustments() const noexcept;
        NODISCARD bool IsConverged() const noexcept;

        void SetMinLocation(const VariableLengthVectorType& aMinLocation);
        void SetMinError(T aMinError) noexcept;
        void SetMinErrorDifference(T aMinErrorDifference) noexcept;
        void SetMinUpdateLength(T aMinUpdateLength) noexcept;
        void SetNumIterations(int aNumIterations) noexcept;
        void AddNumIterations() noexcept;
        void SetNumAdjustments(int aNumAdjustments) noexcept;
        void AddNumAdjustments() noexcept;
        void SetConverged(bool aConverged) noexcept;

    private:
        VariableLengthVectorType minLocation;
        T minError;
        T minErrorDifference;
        T minUpdateLength;
        int numIterations;
        int numAdjustments;
        bool converged;
    };

}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_RESULT_H
