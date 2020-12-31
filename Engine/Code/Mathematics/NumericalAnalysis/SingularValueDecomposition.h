///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/30 10:27)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingularValueDecomposition final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingularValueDecomposition<Real>;
        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        // ����ֵ�ֽ⣬M = L * D * Transpose(Real)��
        // ����L��Real��������D�ǶԽǾ�����Խ����ǷǸ�����
        // �۲�MΪm��n�������� m >= nʱ��L��m��m��Real��n��n��D��m��n;
        // ��M��D������ͬ�Ĵ�С������һ�������Ρ�
        explicit SingularValueDecomposition(const VariableMatrix& matrix);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const VariableMatrix GetLeftMatrix() const;
        [[nodiscard]] const VariableMatrix GetDiagonalMatrix() const;
        [[nodiscard]] const VariableMatrix GetRightTransposeMatrix() const;

    private:
        void Calculate(const VariableMatrix& matrix);

        // ����VʹV[0] = 1����(I - 2 * V * V^T / V^T * V) * X����һ������ȫ���㡣����V��
        [[nodiscard]] static const VariableLengthVector HouseholderVector(const VariableLengthVector& vector);

        // ���� A Ϊ (I - 2 * V * V^T / V^T * V) * A.
        static void HouseholderPremultiply(const VariableLengthVector& vector, VariableMatrix& matrix);

        // ���� A Ϊ A * (I - 2 * V * V^T / V^T * V).
        static void HouseholderPostmultiply(const VariableLengthVector& vector, VariableMatrix& matrix);

        // ����A = Q * Real��Q��������Real�������ǡ�
        void HouseholderQR();

    private:
        VariableMatrix m_Left;
        VariableMatrix m_Diagonal;
        VariableMatrix m_RightTranspose;
    };

    using FloatSingularValueDecomposition = SingularValueDecomposition<float>;
    using DoubleSingularValueDecomposition = SingularValueDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
