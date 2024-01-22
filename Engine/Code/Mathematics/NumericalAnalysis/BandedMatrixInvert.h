/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real>
    class BandedMatrixInvert final
    {
    public:
        using ClassType = BandedMatrixInvert<Real>;

        using Math = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using VariableMatrix = VariableMatrix<Real>;

    public:
        explicit BandedMatrixInvert(const BandedMatrix& matrix, Real zeroTolerance = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableMatrix GetInvert() const;

    private:
        void Solve();
        void ForwardEliminate(int reduceRow);
        void BackwardEliminate(int reduceRow);

    private:
        Real zeroTolerance;
        BandedMatrix matrix;
        VariableMatrix output;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H
