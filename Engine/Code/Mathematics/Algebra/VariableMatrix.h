/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/05 14:17)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "VariableLengthVector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

/// 当定义了MATHEMATICS_USE_MATRIX_VECTOR时，
/// 矩阵运算应用为左乘。
/// 例如，给定的矩阵M和向量V，矩阵乘矢量为M * V。
/// 也就是说，V被当作一个列向量。
/// 一些图形API使用V * M，其中V被视为行向量。
/// 在这些环境中，矩阵“M”是真正的M所表示的转置。
/// 类似地，应用2个矩阵运算M0和M1，以该顺序，
/// 则计算M1*M0对一个向量的转换是（M1 * M0）* V = M1 *（M0* V）。
/// 一些图形API使用M0 * M1，但同样这些矩阵是指这里所表示的转置。
/// 因此，你一定要小心你如何在图形API接口中转换代码。
///
/// 矩阵被储存为行主序保存，matrix[row][col]。

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableMatrix final : private boost::additive<VariableMatrix<Real>, boost::multiplicative<VariableMatrix<Real>, Real, boost::totally_ordered<VariableMatrix<Real>>>>
    {
    public:
        using ClassType = VariableMatrix<Real>;

        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using ContainerType = std::vector<Real>;
        using VectorContainerType = std::vector<VariableLengthVector>;

    public:
        /// 长度为零，numRows和numCols设置为零。
        VariableMatrix() noexcept = default;

        /// 长度为numRows * numCols，元素初始化为零。
        VariableMatrix(int rowsNumber, int columnsNumber);

        ///  对于0 <= row < numRows和 0 <= column < numCols，
        ///  元素(row,column)为1，其他所有元素均为0。
        ///  如果row或column中的任何一个无效，则创建零矩阵。
        ///  这为创建标准欧几里得基矩阵提供了便利；
        ///  另请参见MakeUnit(int,int)和Unit(int,int)。
        VariableMatrix(int rowsNumber, int columnsNumber, int row, int column);

        VariableMatrix(int rowsNumber, int columnsNumber, const ContainerType& entry);
        explicit VariableMatrix(VectorContainerType matrix) noexcept;
        explicit VariableMatrix(const Matrix2& rhs);
        explicit VariableMatrix(const Matrix3& rhs);

        CLASS_INVARIANT_DECLARE;

        /// 存储表示形式透明的成员访问。
        /// 在行row和列column中的矩阵条目是A(row,column)。
        /// 第一个operator()返回的是const引用，而不是Real值。
        /// 这支持通过需要指向数据的常量指针的标准文件操作进行写入。
        /// 使用SetSize会清空旧数据。
        void SetSize(int rowsNumber, int columnsNumber);
        NODISCARD int GetRowsNumber() const;
        NODISCARD int GetColumnsNumber() const;
        NODISCARD int GetElementsNumber() const;
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        /// 通过一维索引访问成员。
        /// 注：当存储器是行主存储器还是列主存储器无关紧要时，
        /// 这些访问器对于矩阵项的操作非常有用。
        /// 不要使用公开存储约定的结构，如M[column+NumCols*row]或M[row+NumRows*column]。
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        NODISCARD ContainerType GetContainer() const;
        void SetContainer(int rowsNumber, int columnsNumber, const ContainerType& entry);

        /// 按行或按列访问成员。输入向量的元素数量必须与矩阵大小相适应。
        void SetRow(int row, const VariableLengthVector& vector);
        NODISCARD VariableLengthVector GetRow(int row) const;
        void SetColumn(int column, const VariableLengthVector& vector);
        NODISCARD VariableLengthVector GetColumn(int column) const;
        void ResetMatrix(const VectorContainerType& matrix);

        /// 支持交换行和列。
        void SwapRows(int lhsRow, int rhsRow);
        void SwapColumns(int lhsColumns, int rhsColumns);

        NODISCARD bool Equal(const VariableMatrix& rhs) const;
        NODISCARD bool Less(const VariableMatrix& rhs) const;

        /// 对于矩阵乘法：“this”矩阵列的数目必须等于rhs矩阵行的数目
        VariableMatrix& operator*=(const VariableMatrix& rhs);

        /// 一元运算。
        NODISCARD VariableMatrix operator+() const;
        NODISCARD VariableMatrix operator-() const;

        /// 线性代数运算。

        /// 矩阵必须有相同的大小（相同的行数和列数）
        /// 对于矩阵的加法和减法运算。
        VariableMatrix& operator+=(const VariableMatrix& rhs);
        VariableMatrix& operator-=(const VariableMatrix& rhs);
        VariableMatrix& operator*=(Real scalar);
        VariableMatrix& operator/=(Real scalar);

        /// 几何运算。
        NODISCARD Real L1Norm() const;
        NODISCARD Real L2Norm() const;
        NODISCARD Real LInfinityNorm() const;

        NODISCARD VariableMatrix Inverse(bool* reportInvertibility = nullptr) const;
        NODISCARD Real Determinant() const;

        /// vector0^T * M * vector1
        /// （numColumns(M) = size(vector1) 和
        /// numRows(M) = size(vector0) 是必须的）
        NODISCARD Real QuadraticForm(const VariableLengthVector& vector0, const VariableLengthVector& vector1) const;

        // M^T
        NODISCARD VariableMatrix Transpose() const;

        NODISCARD Matrix3 GetMatrix3() const;

        /// 特殊矩阵。

        /// 所有组件均为0。
        void MakeZero();

        /// 分量 (row,column) 为1，其余均为零。
        void MakeUnit(int row, int column);

        /// 对角线条目1，其他条目0，即使是非正方形条目。
        void MakeIdentity();

        NODISCARD static VariableMatrix Zero(int rowsNumber, int columnsNumber);
        NODISCARD static VariableMatrix Unit(int rowsNumber, int columnsNumber, int row, int column);
        NODISCARD static VariableMatrix Identity(int rowsNumber, int columnsNumber);

    private:
        /// 该矩阵存储在列主序来自二维数组。
        /// 行主序或列主序的惯例由您选择。
        VectorContainerType container;
    };

    /// 比较 (仅使用在STL容器)。
    /// 矩阵必须有相同的大小（相同行数和列数）
    /// 排序容器和几何排序的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> Multiply(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M * v (numColumns(matrix) = size(vector) 是必须的)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableLengthVector<Real> operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    /// v^T * M (numRows(matrix) = size(vector) 是必须的)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableLengthVector<Real> operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix);

    /// M * mat^T (numColumns(lhs) = numColumns(rhs) 是必须的)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> MultiplyTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M^T * mat (numRows(lhs) = numRows(rhs) 是必须的)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> TransposeMultiply(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M^T * mat^T (numRows(lhs) = numColumns(rhs) 是必须的)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> TransposeMultiplyTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M*D，D为正方形对角线（存储为矢量）
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> Multiply(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& diagonal);

    /// D*M, D为正方形对角线（存储为矢量）
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> Multiply(const VariableLengthVector<Real>& diagonal, const VariableMatrix<Real>& matrix);

    /// U*V^T，U是N乘1，V是M乘1，结果是N乘M。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> OuterProduct(const VariableLengthVector<Real>& u, const VariableLengthVector<Real>& v);

    /// 对角矩阵的初始化，其对角项是D的分量，即使是非平方的。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> MakeDiagonal(int rowsNumber, int columnsNumber, const VariableLengthVector<Real>& diagonal);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    /// 调试输出。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    std::ostream& operator<<(std::ostream& stream, const VariableMatrix<Real>& matrix);

    using VariableMatrixF = VariableMatrix<float>;
    using VariableMatrixD = VariableMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
