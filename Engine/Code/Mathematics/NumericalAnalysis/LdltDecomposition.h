/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/14 10:05)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LDLT_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LDLT_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix/Matrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"

/// 因子一个正对称矩阵A = L * D * L^T，
/// 其中L是对角线项均为1的下三角矩阵（L是下单位三角形），
/// 其中D是对角线项为正的对角矩阵。
namespace Mathematics
{
    template <typename T, int...>
    class LdltDecomposition;

    /// 编译时已知大小的实现。
    template <typename T, int N>
    requires(0 < N)
    class LdltDecomposition<T, N>
    {
    public:
        using ClassType = LdltDecomposition<T, N>;

        using Matrix = Algebra::Matrix<N, N, T>;
        using Vector = Algebra::Vector<N, T>;
        using MathType = Math<T>;

    public:
        LdltDecomposition() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 矩阵A必须是正定的。该实现仅使用A的下三角部分。
        /// 在输出时，L是下单位三角形，D是对角线。
        bool Factor(const Matrix& a, Matrix& l, Matrix& d);

        /// 在调用前用因子分解法求解正定A = L * D * L^T的A*X = B。
        static void Solve(const Matrix& l, const Matrix& d, const Vector& e, Vector& x);

        /// 在调用过程中用因子分解法求解正定A = L * D * L^T的A*X = B。
        void Solve(const Matrix& a, const Vector& b, Vector& x);
    };

    /// 仅在运行时才知道大小的实现。
    template <typename T>
    class LdltDecomposition<T>
    {
    public:
        using ClassType = LdltDecomposition<T>;

        using VariableMatrixType = VariableMatrix<T>;
        using VariableLengthVectorType = VariableLengthVector<T>;
        using MathType = Math<T>;

    public:
        explicit LdltDecomposition(int n);

        CLASS_INVARIANT_DECLARE;

        /// 矩阵A必须是正定的。该实现仅使用A的下三角部分。
        /// 在输出时，L是下单位三角形，D是对角线。
        bool Factor(const VariableMatrixType& a, VariableMatrixType& l, VariableMatrixType& d);

        /// 在调用前用因子分解法求解正定A = L * D * L^T的A*X = B。
        void Solve(const VariableMatrixType& l, const VariableMatrixType& d, const VariableLengthVectorType& b, VariableLengthVectorType& x);

        /// 在调用过程中用因子分解法求解正定A = L * D * L^T的A*X = B。
        void Solve(const VariableMatrixType& a, const VariableLengthVectorType& b, VariableLengthVectorType& x);

    private:
        const int n;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LDLT_DECOMPOSITION_H
