/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 13:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_RESULT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class GaussNewtonMinimizerResult
    {
    public:
        using ClassType = GaussNewtonMinimizerResult<Real>;

        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        GaussNewtonMinimizerResult() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableLengthVector GetMinLocation() const;
        void SetMinLocation(const VariableLengthVector& aMinLocation);

        NODISCARD Real GetMinError() const noexcept;
        void SetMinError(Real aMinError) noexcept;

        NODISCARD Real GetMinErrorDifference() const noexcept;
        void SetMinErrorDifference(Real aMinErrorDifference) noexcept;

        NODISCARD Real GetMinUpdateLength() const noexcept;
        void SetMinUpdateLength(Real aMinUpdateLength) noexcept;

        NODISCARD int GetNumIterations() const noexcept;
        void SetNumIterations(int aNumIterations) noexcept;
        void AddNumIterations() noexcept;

        NODISCARD bool GetConverged() const noexcept;
        void SetConverged(bool aConverged) noexcept;

    private:
        VariableLengthVector minLocation;
        Real minError;
        Real minErrorDifference;
        Real minUpdateLength;
        int numIterations;
        bool converged;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_RESULT_H
