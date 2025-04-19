/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:52)

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

        using MathType = Math<Real>;
        using VariableMatrixType = VariableMatrix<Real>;
        using RealContainer = std::vector<Real>;

    public:
        explicit LinearSystemInverse(const VariableMatrixType& matrix, const RealContainer& input, Real zeroTolerance = MathType::GetZeroTolerance());
        explicit LinearSystemInverse(const VariableMatrixType& matrix, Real zeroTolerance = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        // ����:
        //     matrix[iSize][iSize], ���� matrix[row][col]
        // ���:
        //     �������ʧ���׳��쳣�����򷵻������
        NODISCARD VariableMatrixType GetInverse() const;

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
        // ����ϵͳ����ݲ
        Real zeroTolerance;  // Ĭ�� = MathType::GetZeroTolerance()
        VariableMatrixType inverse;
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
