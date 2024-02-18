/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/31 10:25)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Detail/Matrix/MatrixTable.h"
#include "Mathematics/Algebra/Vector/Vector.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics::Algebra
{
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    class Matrix
    {
    public:
        using ClassType = Matrix<NumRows, NumColumns, Real>;

        using Math = Math<Real>;
        using MatrixTable = MatrixTable<NumRows, NumColumns, Real>;
        static constexpr auto numElements = NumRows * NumColumns;
        using Container = std::array<Real, numElements>;
        using BaseContainer = std::vector<Real>;

    public:
        Matrix() noexcept;

        /// 该表完全由输入初始化。
        /// 无论活动存储方案是否是MATHEMATICS_USE_ROW_MAJOR，
        /// 都必须按行主顺序指定“值”。
        explicit Matrix(const Container& values);
        explicit Matrix(const BaseContainer& values);

        /// 对于0 <= row < NumRows and 0 <= column < NumColumns，
        /// 元素(row,column) 为1，所有其他元素均为0。
        /// 如果row或column中的任何一个无效，则创建零矩阵。
        /// 这为创建标准欧几里得基矩阵提供了便利；
        /// 另请参见MakeUnit(int,int)和Unit(int,int)。
        Matrix(int row, int column);

        CLASS_INVARIANT_DECLARE;

        NODISCARD BaseContainer GetBaseContainer() const;

        /// 存储表示形式透明的成员访问。
        /// 在行row和列column中的矩阵条目是A(row,column)。
        /// 第一个operator()返回的是const引用，而不是Real值。
        /// 这支持通过需要指向数据的常量指针的标准文件操作进行写入。
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        /// 按行或按列访问成员。
        void SetRow(int row, const Vector<NumColumns, Real>& vector);
        void SetColumn(int column, const Vector<NumRows, Real>& vector);

        NODISCARD Vector<NumColumns, Real> GetRow(int row) const;
        NODISCARD Vector<NumRows, Real> GetColumn(int column) const;

        /// 通过一维索引访问成员。
        /// 注：当存储器是行主存储器还是列主存储器无关紧要时，这些访问器对于矩阵项的操作非常有用。
        /// 不要使用公开存储约定的结构，如matrix[column + NumColumns * row]或matrix[row + NumRows * column]。
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        /// 排序容器和几何排序的比较。
        NODISCARD bool operator==(const Matrix& rhs) const;
        NODISCARD bool operator!=(const Matrix& rhs) const;
        NODISCARD bool operator<(const Matrix& rhs) const;
        NODISCARD bool operator<=(const Matrix& rhs) const;
        NODISCARD bool operator>(const Matrix& rhs) const;
        NODISCARD bool operator>=(const Matrix& rhs) const;

        /// 特殊矩阵。

        /// 所有组件均为0。
        void MakeZero();

        /// 分量(row,column)为1，其余均为零。
        void MakeUnit(int row, int column);

        /// 对角线条目1，其他条目0，即使不是正方形
        void MakeIdentity();

        static Matrix Zero() noexcept;
        static Matrix Unit(int row, int column);
        static Matrix Identity();

        /// 一元运算。
        NODISCARD Matrix operator+() const noexcept;
        NODISCARD Matrix operator-() const;

        /// 线性代数运算。
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(Real scalar);
        Matrix& operator/=(Real scalar);

    private:
        MatrixTable table;
    };

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator+(const Matrix<NumRows, NumColumns, Real>& lhs, const Matrix<NumRows, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator-(const Matrix<NumRows, NumColumns, Real>& lhs, const Matrix<NumRows, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator*(const Matrix<NumRows, NumColumns, Real>& lhs, Real scalar);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator*(Real scalar, const Matrix<NumRows, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator/(const Matrix<NumRows, NumColumns, Real>& lhs, Real scalar);

    /// 几何运算。
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real L1Norm(const Matrix<NumRows, NumColumns, Real>& matrix);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real L2Norm(const Matrix<NumRows, NumColumns, Real>& matrix);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real LInfinityNorm(const Matrix<NumRows, NumColumns, Real>& matrix);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N, N, Real> Inverse(const Matrix<N, N, Real>& matrix, bool* reportInvertibility = nullptr);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real Determinant(const Matrix<N, N, Real>& matrix);

    /// M^T
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumColumns, NumRows, Real> Transpose(const Matrix<NumRows, NumColumns, Real>& matrix);

    /// M*V
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<NumRows, Real> operator*(const Matrix<NumRows, NumColumns, Real>& matrix, const Vector<NumColumns, Real>& vector);

    /// V^T*M
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<NumColumns, Real> operator*(const Vector<NumRows, Real>& vector, const Matrix<NumRows, NumColumns, Real>& matrix);

    /// A*B
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator*(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> Multiply(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// A*B^T
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> MultiplyTransposition(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// A^T*B
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> TranspositionMultiply(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// A^T*B^T
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> TranspositionMultiplyTransposition(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// M*D, D 是对角线 NumColumns-by-NumColumns
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> Multiply(const Matrix<NumRows, NumColumns, Real>& matrix, const Vector<NumColumns, Real>& diagonal);

    /// D*M, D 是对角线 NumRows-by-NumRows
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> Multiply(const Vector<NumRows, Real>& diagonal, const Matrix<NumRows, NumColumns, Real>& matrix);

    /// U*V^T, U 是 NumRows-by-1, V 是 Num-Cols-by-1, 结果是 NumRows-by-NumCols.
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> OuterProduct(const Vector<NumRows, Real>& u, const Vector<NumColumns, Real>& v);

    /// 对角矩阵的初始化，其对角项是D的分量。
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N, N, Real> MakeDiagonal(const Vector<N, Real>& diagonal);

    /// 通过将上部N-by-N块设置为输入N-by-N矩阵，
    /// 并将除最后一行和最后一列条目设置为1之外的所有其他条目设置为0，
    /// 创建(N+1)-by-(N+1)矩阵H。
    template <int N, typename Real>
    requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N + 1, N + 1, Real> HomogeneousLift(const Matrix<N, N, Real>& matrix);

    /// 提取输入N-by-N 矩阵的上(N-1)-by-(N-1)块。
    template <int N, typename Real>
    requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N - 1, N - 1, Real> HomogeneousProject(const Matrix<N, N, Real>& matrix);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_H
