///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 15:27)

/// 所谓的带状矩阵即：在矩阵A中，
/// 所有的非零元素都集中在以主对角线为中心的带状区域中。
/// 如 a11 a12 0   0   0   0
///    a21 a22 a23 0   0   0
///    a31 a32 a33 a34 0   0
///    0   a42 a43 a44 a45 0
///    0   0   a53 a54 a55 a56
///    0   0   0   a64 a65 a66
#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "BandedMatrix.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrixSolve final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BandedMatrixSolve<Real>;
        using Math = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrixSolve(int size, int lowerBandsNumber, int upperBandsNumber, const Real epsilon = Math::GetZeroTolerance());

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        [[nodiscard]] bool IsSolveValid() const;
        [[nodiscard]] Real GetProduct(const BandedMatrix& upperBandedMatrix, const BandedMatrix& lowerBandedMatrix, int row, int column) const;
#endif  // OPEN_CLASS_INVARIANT

        // 成员访问
        [[nodiscard]] int GetSize() const;
        [[nodiscard]] int GetLowerBandsNumber() const;
        [[nodiscard]] int GetUpperBandsNumber() const;
        [[nodiscard]] int GetStreamSize() const;
        [[nodiscard]] BandedMatrixSolveFlags GetSolve() const noexcept;
        void SetEpsilon(Real epsilon) noexcept;
        [[nodiscard]] Real GetEpsilon() const noexcept;

        // 重设大小会清空原有数据。
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, const Real epsilon = Math::GetZeroTolerance());

        // 对角线
        [[nodiscard]] ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        // 下三角
        // GetLowerBand(index):  0 <= index < LowerBandMax
        [[nodiscard]] int GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);

        // 上三角
        // GetUupperBand(index):  0 <= index < UpperBandMax
        [[nodiscard]] int GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);

        [[nodiscard]] Real& operator()(int row, int column);
        [[nodiscard]] const Real& operator()(int row, int column) const;

        // 便利函数用于初始化矩阵
        void SetZero();
        void SetIdentity();

        /// 方带状矩阵的系数A为A = L * L^T，其中L是下三角矩阵（L^T是一个上三角矩阵）。
        /// 这是一个LU分解，允许A的稳定的逆来解决A * X = B。
        /// 当因子分解是失败时，返回false。（L是不可逆的）。
        /// 如果成功，包括Cholesky分解。（L在A的下三角部分和L^ T在A的上三角部分）
        [[nodiscard]] bool CholeskyFactor();

        /// 求解线性系统A * X = B，其中A是一个NxN的带状矩阵，B是一个Nx1的矢量。未知的X是也是Nx1。
        /// 函数的输入vector是B，X被计算并被返回。
        /// 当且仅当有一个解决方案时，返回值是有效的，否则会抛出异常。
        /// 如果成功，包括Cholesky分解。（L在A的下三角部分和L^ T在A的上三角部分）
        [[nodiscard]] const VariableLengthVector SolveSystem(const VariableLengthVector& vector);

        /// 求解线性系统A * X= B，其中A是一个NxN的带状矩阵，B是一个NxM的矩阵。未知的X是也是NxM。
        /// 函数的输入matrix是B，X被计算并被返回。
        /// 当且仅当有一个解决方案时，返回值是有效的，否则会抛出异常。
        /// 如果成功，包括Cholesky分解。（L在A的下三角部分和L^ T在A的上三角部分）
        [[nodiscard]] const VariableMatrix SolveSystem(const VariableMatrix& matrix);

        [[nodiscard]] const VariableMatrix ToInputVariableMatrix() const;
        [[nodiscard]] const VariableMatrix ToCholeskyVariableMatrix() const;

    private:
        /// 线性系统为L * U * X = B，其中A = L * U和U = L^T，
        /// 减少到U * X = L^{-1} * B。返回值有效当且仅当操作成功。
        [[nodiscard]] const VariableLengthVector SolveLower(const VariableLengthVector& vector) const;

        /// 线性系统为U * X = L^{-1} * B，减少到 X = U^{-1} * L^{-1} * B。
        /// 返回值有效当且仅当操作成功。
        [[nodiscard]] const VariableLengthVector SolveUpper(const VariableLengthVector& vector) const;

        /// 线性系统为L * U * X = B，其中A = L * U和U = L^T，
        /// 减少到U * X = L^{-1} * B。返回值有效当且仅当操作成功。
        [[nodiscard]] const VariableMatrix SolveLower(const VariableMatrix& matrix) const;

        /// 线性系统为U * X = L^{-1} * B，减少到 X = U^{-1} * L^{-1} * B。
        /// 返回值有效当且仅当操作成功。
        [[nodiscard]] const VariableMatrix SolveUpper(const VariableMatrix& matrix) const;

    private:
        BandedMatrix m_Input;
        BandedMatrix m_Cholesky;
        BandedMatrixSolveFlags m_Solve;
        Real m_Epsilon;
    };

    using FloatBandedMatrixSolve = BandedMatrixSolve<float>;
    using DoubleBandedMatrixSolve = BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
