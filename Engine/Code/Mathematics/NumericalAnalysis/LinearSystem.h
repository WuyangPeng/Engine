///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 11:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrix.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Base/MathDetail.h"

#include <map>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE LinearSystem final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = LinearSystem<Real>;
        using Math = Math<Real>;
        using RealContainer = std::vector<Real>;
        using Vector2 = std::array<Real, 2>;
        using Matrix2 = std::array<Vector2, 2>;
        using Vector3 = std::array<Real, 3>;
        using Matrix3 = std::array<Vector3, 3>;
        using BandedMatrix = BandedMatrix<Real>;
        using SparseMatrix = SparseMatrix<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        explicit LinearSystem(Real zeroTolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetZeroTolerance(Real zeroTolerance) noexcept;

        // 2×2和3x3系统（避免了高斯消元的开销）
        [[nodiscard]] Vector2 Solve2(const Matrix2& matrix, const Vector2& vector) const;

        [[nodiscard]] Vector3 Solve3(const Matrix3& matrix, const Vector3& vector) const;

        // 输入:
        //     matrix[iSize][iSize], 项是 matrix[row][col]
        // 输出:
        //     求逆矩阵失败抛出异常，否则返回逆矩阵。
        [[nodiscard]] const VariableMatrix Inverse(const VariableMatrix& matrix) const;

        // 输入:
        //     A[iSize][iSize] 系数矩阵，项是 A[row][col]
        //     B[iSize] 向量, 项是 B[row]
        // 输出:
        //     求逆矩阵失败抛出异常，否则返回X[iSize]。
        //     X[iSize] 是解X 在 AX = B

        // 必须保证输入vector和输出vector大小为iSize的一维数组。
        [[nodiscard]] RealContainer Solve(const VariableMatrix& matrix, const RealContainer& vector) const;

        // 输入:
        //     矩阵是三对角矩阵。
        //     下对角线 lower[size - 1]
        //     主对角线 main[size]
        //     上对角线 upper[size - 1]
        //     右手边 right[size]
        // 输出:
        //     求解失败抛出异常，否则返回U[size]，是解。

        // 必须保证lower和upper大小为size - 1的一维数组。
        // main、right和output大小为size的一维数组。
        [[nodiscard]] RealContainer SolveTridiagonal(int size, const RealContainer& lower, const RealContainer& mainDdiagonal, const RealContainer& upper, const RealContainer& right) const;

        // 输入:
        //     矩阵是三对角矩阵。
        //     下对角线是常数lower
        //     主对角线是常数main
        //     上对角线是常数upper
        //     右手边 right[size]
        // 输出:
        //     求解失败抛出异常，否则返回U[size]，是解。

        // 必须保证right和output大小为size的一维数组。
        [[nodiscard]] RealContainer SolveConstTridiagonal(int size, Real lower, Real mainDdiagonal, Real upper, const RealContainer& right) const;

        // 解决方案采用共轭梯度法。
        // 输入:
        //    A[size][size] Symmetrix矩阵，项是 A[row][col]
        //    B[size] 向量, 项是 B[row]
        // 输出:
        //    X[size] 是解 x 为 Ax = B

        // 必须保证inputVector和outputVector为大小为size的一维数组。
        [[nodiscard]] RealContainer SolveSymmetricConjugateGradient(const VariableMatrix& matrix, const RealContainer& vector) const;

        // 稀疏对称矩阵共轭梯度法。
        // 输入:
        // 在Symmetrix矩阵matrix的非零条目存储在一个映射，其键对(i,j)，其值是实数。
        // 一对(i,j)为所述数组中的值的位置。
        // 只有(i,j) 和(j,i)应存放，因为matrix是对称的。
        // 该代码假定你知道怎么设置matrix.
        // 列矢量vector被存储为连续值的数组。
        // 输出:
        //    X[size] 是解 x 为 Ax = B

        // 必须保证inputVector和outputVector为大小为size的一维数组。
        [[nodiscard]] RealContainer SolveSymmetricConjugateGradient(const SparseMatrix& matrix, const RealContainer& vector) const;

        // 求解带状矩阵系统。
        // 输入:
        //     matrix, 一个带状矩阵
        //     vector[size] 向量,项是 vector[row]
        // 输出:
        //     求解失败抛出异常，
        //     返回X[size] 是解 X 在 AX = B

        // 必须保证inputVector和outputVector为大小为size的一维数组。
        [[nodiscard]] RealContainer SolveBanded(const BandedMatrix& matrix, const RealContainer& vector) const;

        // 求带状矩阵的逆
        // 输入:
        //     matrix, 带状矩阵
        // 输出:
        //     求逆失败抛出异常，否则返回逆矩阵
        [[nodiscard]] const VariableMatrix Invert(const BandedMatrix& matrix) const;

    private:
        // 线性系统求解容差。
        // 默认 = Math<Real>::GetZeroTolerance()
        Real m_ZeroTolerance;
    };

    using FloatLinearSystem = LinearSystem<float>;
    using DoubleLinearSystem = LinearSystem<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
