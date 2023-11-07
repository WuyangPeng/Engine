///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 11:15)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Mathematics
{
    template <typename Real, template <typename> class Matrix>
    class SolveSymmetricConjugateGradient final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SolveSymmetricConjugateGradient<Real, Matrix>;

        using MatrixType = Matrix<Real>;
        using RealContainer = std::vector<Real>;

    public:
        explicit SolveSymmetricConjugateGradient(const MatrixType& matrix, const RealContainer& input, Real zeroTolerance = Math<Real>::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD RealContainer GetResult() const;

    private:
        void CalculateNormal(const RealContainer& input) noexcept;
        void FirstIteration();
        void RemainingIterations();

        NODISCARD Real Dot(const RealContainer& lhs, const RealContainer& rhs) const noexcept;

        void Multiply();
        void UpdateOutput() noexcept;
        void UpdateAmend1() noexcept;
        void UpdateAmend2() noexcept;

    private:
        Real zeroTolerance;
        const MatrixType& matrix;
        int size;
        RealContainer inputAmend1;
        RealContainer inputAmend2;
        RealContainer product;
        Real normal;
        RealContainer output;
        Real dot0;
        Real dot1;
        Real alpha;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H
