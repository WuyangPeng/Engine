///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:25)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrixInvert final
    {
    public:
        using ClassType = BandedMatrixInvert<Real>;
        using Math = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using VariableMatrix = VariableMatrix<Real>;

    public:
        explicit BandedMatrixInvert(const BandedMatrix& matrix, Real zeroTolerance = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const VariableMatrix GetInvert() const;

    private:
        void Solve();
        void ForwardEliminate(int reduceRow);
        void BackwardEliminate(int reduceRow);

    private:
        Real m_ZeroTolerance;
        BandedMatrix m_Matrix;
        VariableMatrix m_Output;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H
