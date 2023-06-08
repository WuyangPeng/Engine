///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"

#include <deque>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE LinearSystemInverse final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = LinearSystemInverse<Real>;
        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using RealContainer = std::vector<Real>;

    public:
        explicit LinearSystemInverse(const VariableMatrix& matrix, const RealContainer& input, Real zeroTolerance = Math::GetZeroTolerance());
        explicit LinearSystemInverse(const VariableMatrix& matrix, Real zeroTolerance = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        // 输入:
        //     matrix[iSize][iSize], 项是 matrix[row][col]
        // 输出:
        //     求逆矩阵失败抛出异常，否则返回逆矩阵。
        NODISCARD VariableMatrix GetInverse() const;

        NODISCARD RealContainer GetResult() const;

    private:
        using IndexContainer = std::vector<int>;
        using PivotedType = std::deque<bool>;

    private:
        void Inverse();

        void Inverse(int index);
        void SwapRows();
        void ScaleRow();
        void CalculateCurrentMaxValue();
        void ZeroOutPivotColumnLocations();
        void ZeroOutPivotColumnLocations(int outerIndex);
        void Rearrangement();

    private:
        // 线性系统求解容差。
        Real zeroTolerance;  // 默认 = Math::GetZeroTolerance()
        VariableMatrix inverse;
        int size;
        IndexContainer columnsIndex;
        IndexContainer rowIndex;
        PivotedType pivoted;
        int currentRow;
        int currentColumn;
        Real currentMaxValue;
        RealContainer output;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
