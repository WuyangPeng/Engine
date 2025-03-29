/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    template <typename Real>
    class SingularValueDecomposition final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingularValueDecomposition<Real>;

        using MathType = Math<Real>;
        using VariableMatrixType = VariableMatrix<Real>;
        using VariableLengthVectorType = VariableLengthVector<Real>;

    public:
        // ����ֵ�ֽ⣬M = L * D * Transpose(Real)��
        // ����L��Real��������D�ǶԽǾ�����Խ����ǷǸ�����
        // �۲�MΪm��n�������� m >= nʱ��L��m��m��Real��n��n��D��m��n;
        // ��M��D������ͬ�Ĵ�С������һ�������Ρ�
        explicit SingularValueDecomposition(const VariableMatrixType& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableMatrixType GetLeftMatrix() const;
        NODISCARD VariableMatrixType GetDiagonalMatrix() const;
        NODISCARD VariableMatrixType GetRightTransposeMatrix() const;

    private:
        void Calculate(const VariableMatrixType& matrix);

        // ����VʹV[0] = 1����(I - 2 * V * V^T / V^T * V) * X����һ������ȫ���㡣����V��
        NODISCARD static VariableLengthVectorType HouseholderVector(const VariableLengthVectorType& vector);

        // ���� A Ϊ (I - 2 * V * V^T / V^T * V) * A.
        static void HouseholderPremultiply(const VariableLengthVectorType& vector, VariableMatrixType& matrix);

        // ���� A Ϊ A * (I - 2 * V * V^T / V^T * V).
        static void HouseholderPostmultiply(const VariableLengthVectorType& vector, VariableMatrixType& matrix);

        // ����A = Q * Real��Q��������Real�������ǡ�
        void HouseholderQR();

    private:
        VariableMatrixType left;
        VariableMatrixType diagonal;
        VariableMatrixType rightTranspose;
    };

    using SingularValueDecompositionF = SingularValueDecomposition<float>;
    using SingularValueDecompositionD = SingularValueDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
