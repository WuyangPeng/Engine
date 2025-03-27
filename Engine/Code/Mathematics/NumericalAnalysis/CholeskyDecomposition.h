/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHOLESKY_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHOLESKY_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix/Matrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"

namespace Mathematics
{
    /// 编译时已知大小的实现
    template <typename Real, int N = 0>
    requires(std::is_arithmetic_v<Real> && 0 <= N)
    class CholeskyDecomposition
    {
    public:
        using ClassType = CholeskyDecomposition<Real, N>;

        using MatrixType = Algebra::Matrix<N, N, Real>;
        using VectorType = Algebra::Vector<N, Real>;
        using MathType = Math<Real>;

    public:
        CholeskyDecomposition() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 输入时，A是对称的。
        /// 仅修改了下部三角形部分。
        /// 输出时，下三角部分为L，其中A = L * L^T
        NODISCARD bool Factor(MatrixType& a);

        /// 求解L*Y = B，其中L是下三角形且可逆。
        /// Y的输入值是B。在输出时，Y是解。
        NODISCARD VectorType SolveLower(const MatrixType& l);

        /// 求解L^T*X = Y，其中L是下三角（L^T是上三角）且可逆。
        /// X的输入值是Y。在输出时，X是解。
        NODISCARD VectorType SolveUpper(const MatrixType& l);
    };

    /// 仅在运行时才知道大小的实现。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class CholeskyDecomposition<Real, 0>
    {
    public:
        using ClassType = CholeskyDecomposition<Real, 0>;

        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        explicit CholeskyDecomposition(int n) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 输入时，A是对称的。
        /// 仅修改了下部三角形部分。
        /// 输出时，下三角部分为L，其中A = L * L^T
        NODISCARD bool Factor(VariableMatrix& a);

        /// 求解L*Y = B，其中L是下三角形且可逆。
        /// Y的输入值是B。在输出时，Y是解。
        NODISCARD VariableLengthVector SolveLower(const VariableMatrix& l);

        /// 求解L^T*X = Y，其中L是下三角（L^T是上三角）且可逆。
        /// X的输入值是Y。在输出时，X是解。
        NODISCARD VariableLengthVector SolveUpper(const VariableMatrix& l);

    private:
        const int n;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHOLESKY_DECOMPOSITION_H
