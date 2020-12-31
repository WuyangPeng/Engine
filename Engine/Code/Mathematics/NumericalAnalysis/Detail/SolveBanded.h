///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 14:49)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/BandedMatrix.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_HIDDEN_DECLARE SolveBanded final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SolveBanded<Real>;

        using Math = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using RealContainer = std::vector<Real>;

    public:
        explicit SolveBanded(const BandedMatrix& matrix, const RealContainer& inputVector, Real zeroTolerance = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] RealContainer GetResult() const;

    private:
        void Solve();
        void ForwardEliminate(int reduceRow);

    private:
        Real m_ZeroTolerance;
        BandedMatrix m_Matrix;
        RealContainer m_Output;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H
