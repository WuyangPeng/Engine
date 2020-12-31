///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 18:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Mathematics
{
    template <typename Real, template <typename> class Matrix>
    class MATHEMATICS_HIDDEN_DECLARE SolveSymmetricConjugateGradient final : private boost::noncopyable
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SolveSymmetricConjugateGradient<Real, Matrix>;
        using MatrixType = Matrix<Real>; 
        using RealContainer = std::vector<Real>;

    public:
        explicit SolveSymmetricConjugateGradient(const MatrixType& matrix, const RealContainer& input, Real zeroTolerance = Math<Real>::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        RealContainer GetResult() const;

    private:
        void CalculateNormal(const RealContainer& input) noexcept;
        void FirstIteration();
        void RemainingIterations();

        Real Dot(const RealContainer& lhs, const RealContainer& rhs) const noexcept;

        void Multiply();
        void UpdateOutput() noexcept;
        void UpdateAmend1() noexcept;
        void UpdateAmend2() noexcept;

    private:
        Real m_ZeroTolerance;
        const MatrixType& m_Matrix;
        int m_Size;
        RealContainer m_InputAmend1;
        RealContainer m_InputAmend2;
        RealContainer m_Product;
        Real m_Normal;
        RealContainer m_Output;
        Real m_Dot0;
        Real m_Dot1;
        Real m_Alpha;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_H
