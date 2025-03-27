/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrix.h"
#include "CoreTools/MemoryTools/LexicoArray2.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/Matrix/Matrix2x2.h"
#include "Mathematics/Algebra/Matrix/Matrix3x3.h"
#include "Mathematics/Algebra/Matrix/Matrix4x4.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

/// 求解矩阵A为NxN的线性方程组。
/// 当a可逆时，函数的返回值为“true”。
/// 在这种情况下，解决方案X和解决方案是有效的。
/// 如果返回值为'false'，则A不可逆，X和Y无效，因此不要使用它们。
/// 当矩阵被传递为Real*时，存储顺序被假定为与您选择的MATHEMATICS_USE_ROW_MAJOR或!MATHEMATICS_USE_ROW_MAJOR一致。
//
/// 使用共轭梯度算法的线性求解器基于G.H.Golub和Charles F.Van Loan在“矩阵计算，第二版”中的讨论，
/// 约翰霍普金斯出版社，巴尔的摩医学院，1993年第四版。
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
        using Vector3Type = std::array<Real, 3>;
        using Matrix3 = std::array<Vector3Type, 3>;
        using BandedMatrix = BandedMatrix<Real>;
        using SparseMatrix = SparseMatrix<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

        using Matrix2x2 = Algebra::Matrix2x2<Real>;
        using Matrix3x3 = Algebra::Matrix3x3<Real>;
        using Matrix4x4 = Algebra::Matrix4x4<Real>;
        using AlgebraVector2 = Algebra::Vector2<Real>;
        using AlgebraVector3 = Algebra::Vector3<Real>;
        using AlgebraVector4 = Algebra::Vector4<Real>;
        using AlgebraSparseMatrix = std::map<std::array<int, 2>, Real>;

    public:
        explicit LinearSystem(Real zeroTolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetZeroTolerance(Real newZeroTolerance) noexcept;

        // 2×2和3x3系统（避免了高斯消元的开销）
        NODISCARD Vector2 Solve2(const Matrix2& matrix, const Vector2& vector) const;

        NODISCARD Vector3Type Solve3(const Matrix3& matrix, const Vector3Type& vector) const;

        // 输入:
        //     matrix[iSize][iSize], 项是 matrix[row][col]
        // 输出:
        //     求逆矩阵失败抛出异常，否则返回逆矩阵。
        NODISCARD VariableMatrix Inverse(const VariableMatrix& matrix) const;

        // 输入:
        //     A[iSize][iSize] 系数矩阵，项是 A[row][col]
        //     B[iSize] 向量, 项是 B[row]
        // 输出:
        //     求逆矩阵失败抛出异常，否则返回X[iSize]。
        //     X[iSize] 是解X 在 AX = B

        // 必须保证输入vector和输出vector大小为iSize的一维数组。
        NODISCARD RealContainer Solve(const VariableMatrix& matrix, const RealContainer& vector) const;

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
        NODISCARD RealContainer SolveTriDiagonal(int size, const RealContainer& lower, const RealContainer& mainDdiagonal, const RealContainer& upper, const RealContainer& right) const;

        // 输入:
        //     矩阵是三对角矩阵。
        //     下对角线是常数lower
        //     主对角线是常数main
        //     上对角线是常数upper
        //     右手边 right[size]
        // 输出:
        //     求解失败抛出异常，否则返回U[size]，是解。

        // 必须保证right和output大小为size的一维数组。
        NODISCARD RealContainer SolveConstTridiagonal(int size, Real lower, Real mainDdiagonal, Real upper, const RealContainer& right) const;

        // 解决方案采用共轭梯度法。
        // 输入:
        //    A[size][size] Symmetrix矩阵，项是 A[row][col]
        //    B[size] 向量, 项是 B[row]
        // 输出:
        //    X[size] 是解 x 为 Ax = B

        // 必须保证inputVector和outputVector为大小为size的一维数组。
        NODISCARD RealContainer SolveSymmetricConjugateGradient(const VariableMatrix& matrix, const RealContainer& vector) const;

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
        NODISCARD RealContainer SolveSymmetricConjugateGradient(const SparseMatrix& matrix, const RealContainer& vector) const;

        // 求解带状矩阵系统。
        // 输入:
        //     matrix, 一个带状矩阵
        //     vector[size] 向量,项是 vector[row]
        // 输出:
        //     求解失败抛出异常，
        //     返回X[size] 是解 X 在 AX = B

        // 必须保证inputVector和outputVector为大小为size的一维数组。
        NODISCARD RealContainer SolveBanded(const BandedMatrix& matrix, const RealContainer& vector) const;

        // 求带状矩阵的逆
        // 输入:
        //     matrix, 带状矩阵
        // 输出:
        //     求逆失败抛出异常，否则返回逆矩阵
        NODISCARD VariableMatrix Invert(const BandedMatrix& matrix) const;

        /// 通过直接反转矩阵来求解2x2、3x3和4x4系统。
        /// 这避免了在小维度中高斯消除的开销。
        NODISCARD static bool Solve(const Matrix2x2& a, const AlgebraVector2& b, AlgebraVector2& x);

        NODISCARD static bool Solve(const Matrix3x3& a, const AlgebraVector3& b, AlgebraVector3& x);

        NODISCARD static bool Solve(const Matrix4x4& a, const AlgebraVector4& b, AlgebraVector4& x);

        /// 求解A*X = B，其中B为Nx1，解X为Nx1。
        NODISCARD static bool Solve(int n, const RealContainer& a, const RealContainer& b, RealContainer& x);

        /// 求解A*X = B，其中B为NxM，解X为NxM。
        NODISCARD static bool Solve(int n, int m, const RealContainer& a, const RealContainer& b, RealContainer& x);

        /// 求解A*X = B，其中A是三对角的。
        /// 函数需要A的次对角线、对角线和超对角线。
        /// 对角线输入必须有N个元素。
        /// 次对角线和超对角线输入必须具有N-1个元素。
        NODISCARD static bool SolveTriDiagonal(int n, const RealContainer& subDiagonal, const RealContainer& diagonal, const RealContainer& superDiagonal, const RealContainer& b, RealContainer& x);

        /// 求解A*X = B，其中A是三对角的。
        /// 该函数期望A的subDiagonal、对角线和superDiagonal。
        /// 此外，subDiagonal元素是常数，对角线元素是常量，superDiagonal元素是常数。
        NODISCARD static bool SolveConstantTriDiagonal(int n, Real subDiagonal, Real diagonal, Real superDiagonal, const RealContainer& b, RealContainer& x);

        /// 使用共轭梯度法求解A*X=B，其中A是对称的。
        /// 您必须指定迭代的最大次数和终止迭代的容差。
        /// 公差的合理选择是1e-06f 表示 'float或1e-08 表示 'double'
        NODISCARD static int SolveSymmetricConjugateGradient(int n, RealContainer& a, const RealContainer& b, RealContainer& x, int maxIterations, Real tolerance);

        /// 使用共轭梯度法求解A*X = B，其中A是稀疏和对称的。
        /// 对称矩阵A的非零项存储在映射中，该映射的键是对(i,j)，
        /// 并且其值是实数。对(i,j)是值在数组中的位置。
        /// 由于A是对称的，因此只应存储(i,j)和(j,i) 中的一个。
        /// 列向量B被存储为连续值的数组。
        /// 您必须指定迭代的最大次数和终止迭代的容差。
        /// 公差的合理选择是1e-06f 表示 'float或1e-08 表示 'double'
        NODISCARD static int SolveSymmetricConjugateGradient(int n, const AlgebraSparseMatrix& a, const RealContainer& b, RealContainer& x, int maxIterations, Real tolerance);

#if defined(MATHEMATICS_USE_ROW_MAJOR)

        using LexicoArray2 = CoreTools::LexicoArray2<true, typename RealContainer::iterator>;

#else  // !MATHEMATICS_USE_ROW_MAJOR

        using LexicoArray2 = CoreTools::LexicoArray2<false, typename RealContainer::iterator>;

#endif  // MATHEMATICS_USE_ROW_MAJOR

    private:
        /// 支持共轭梯度法。
        NODISCARD static Real Dot(int n, const RealContainer& u, const RealContainer& v);

        static void Mul(int n, RealContainer& a, const RealContainer& x, RealContainer& p);

        static void Mul(const AlgebraSparseMatrix& a, const RealContainer& x, RealContainer& p);

        static void UpdateX(int n, RealContainer& x, Real alpha, const RealContainer& p);

        static void UpdateR(int n, RealContainer& r, Real alpha, const RealContainer& w);

        static void UpdateP(int n, RealContainer& p, Real beta, const RealContainer& r);

    private:
        // 线性系统求解容差。
        // 默认 = MathType<Real>::GetZeroTolerance()
        Real zeroTolerance;
    };

    using LinearSystemF = LinearSystem<float>;
    using LinearSystemD = LinearSystem<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
