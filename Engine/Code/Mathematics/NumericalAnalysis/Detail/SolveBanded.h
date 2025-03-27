/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/BandedMatrix.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE SolveBanded final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SolveBanded<Real>;

        using MathType = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using RealContainer = std::vector<Real>;

    public:
        SolveBanded(BandedMatrix matrix, RealContainer inputVector, Real zeroTolerance = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD RealContainer GetResult() const;

    private:
        void Solve();
        void ForwardEliminate(int reduceRow);

    private:
        Real zeroTolerance;
        BandedMatrix matrix;
        RealContainer output;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H
