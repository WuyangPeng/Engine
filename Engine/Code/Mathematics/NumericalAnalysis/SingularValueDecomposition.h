/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

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

        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        // 奇异值分解，M = L * D * Transpose(Real)，
        // 其中L和Real是正交和D是对角矩阵，其对角项是非负数。
        // 观察M为m乘n矩阵，其中 m >= n时，L是m乘m，Real是n乘n和D是m乘n;
        // 即M和D具有相同的大小，但不一定正方形。
        explicit SingularValueDecomposition(const VariableMatrix& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableMatrix GetLeftMatrix() const;
        NODISCARD VariableMatrix GetDiagonalMatrix() const;
        NODISCARD VariableMatrix GetRightTransposeMatrix() const;

    private:
        void Calculate(const VariableMatrix& matrix);

        // 计算V使V[0] = 1，和(I - 2 * V * V^T / V^T * V) * X除第一部分外全是零。返回V。
        NODISCARD static VariableLengthVector HouseholderVector(const VariableLengthVector& vector);

        // 覆盖 A 为 (I - 2 * V * V^T / V^T * V) * A.
        static void HouseholderPremultiply(const VariableLengthVector& vector, VariableMatrix& matrix);

        // 覆盖 A 为 A * (I - 2 * V * V^T / V^T * V).
        static void HouseholderPostmultiply(const VariableLengthVector& vector, VariableMatrix& matrix);

        // 因子A = Q * Real，Q是正交和Real是上三角。
        void HouseholderQR();

    private:
        VariableMatrix left;
        VariableMatrix diagonal;
        VariableMatrix rightTranspose;
    };

    using SingularValueDecompositionF = SingularValueDecomposition<float>;
    using SingularValueDecompositionD = SingularValueDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
