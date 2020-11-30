///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/25 15:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"

#include <deque>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_HIDDEN_DECLARE LinearSystemInverse final
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

        // ����:
        //     matrix[iSize][iSize], ���� matrix[row][col]
        // ���:
        //     �������ʧ���׳��쳣�����򷵻������
        [[nodiscard]] const VariableMatrix GetInverse() const;

        [[nodiscard]] const RealContainer GetResult() const;

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
        Real m_ZeroTolerance;  // Ĭ�� = Math::GetZeroTolerance()
        VariableMatrix m_Inverse;
        int m_Size;
        IndexContainer m_ColumnsIndex;
        IndexContainer m_RowIndex;
        PivotedType m_Pivoted;
        int m_CurrentRow;
        int m_CurrentColumn;
        Real m_CurrentMaxValue;
        RealContainer m_Output;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
