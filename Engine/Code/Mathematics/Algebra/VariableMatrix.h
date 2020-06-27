// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:15)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "Mathematics/Base/Math.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

// 矩阵运算应用为左乘。
// 例如，给定的矩阵M和向量V，矩阵乘矢量为M * V。
// 也就是说，V被当作一个列向量。
// 一些图形API使用V * M，其中V被视为行向量。
// 在这些环境中，矩阵“M”是真正的M所表示的转置。
// 类似地，应用2个矩阵运算M0和M1，以该顺序，
// 则计算M1*M0对一个向量的转换是（M1 * M0）* V = M1 *（M0* V）。
// 一些图形API使用M0 * M1，但同样这些矩阵是指这里所表示的转置。
// 因此，你一定要小心你如何在图形API接口中转换代码。
//
// 矩阵被储存为行主序保存，matrix[row][col].

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableMatrix : private boost::additive<VariableMatrix<Real>,
																		boost::multiplicative<VariableMatrix<Real>, Real,
																		boost::totally_ordered<VariableMatrix<Real> > > >
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = VariableMatrix<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;
		using Math = Math<Real>;
		using VariableLengthVector = VariableLengthVector<Real>;
		using Matrix3 = Matrix3<Real>;
		using Matrix2 = Matrix2<Real>;

	public:
		explicit VariableMatrix(int rowsNumber = 0, int columnsNumber = 0);
		VariableMatrix(int rowsNumber, int columnsNumber, const std::vector<Real>& entry);
		VariableMatrix(int rowsNumber, int columnsNumber, const std::vector<std::vector<Real> >& matrix);
		VariableMatrix(const VariableMatrix& rhs);
		explicit VariableMatrix(const Matrix3& rhs);
		explicit VariableMatrix(const Matrix2& rhs);
		~VariableMatrix();

		VariableMatrix& operator= (const VariableMatrix& rhs);

		CLASS_INVARIANT_DECLARE;

		// 成员访问

		// 使用ResetSize会清空旧数据。
		void ResetSize(int rowsNumber, int columnsNumber);
		int GetRowsNumber() const noexcept;
		int GetColumnsNumber() const noexcept;
		int GetElementsNumber() const noexcept;
		const Real* GetElements() const;
		Real* GetElements();
		const Real* operator[] (int row) const;
		Real* operator[] (int row);
		const Real& operator() (int row, int column) const;
		Real& operator() (int row, int column);

		void SetIdentity();

		void SetRow(int row, const VariableLengthVector& vector);
		const VariableLengthVector GetRow(int row) const;
		void SetColumn(int column, const VariableLengthVector& vector);
		const VariableLengthVector GetColumn(int column) const;
		void ResetMatrix(int rowsNumber, int columnsNumber, const std::vector<Real>& entry);
		void ResetMatrix(int rowsNumber, int columnsNumber, const std::vector<std::vector<Real> >& matrix);

		// 支持交换行和列。
		void SwapRows(int firstRow, int secondRow);
		void SwapColumns(int firstColumns, int secondColumns);

		// 对于矩阵乘法：“this”矩阵列的数目必须等于rhs矩阵行的数目
		VariableMatrix& operator*= (const VariableMatrix& rhs);

		const VariableMatrix operator- () const;

		// 矩阵必须有相同的大小（相同的行数和列数）
		// 对于矩阵的加法和减法运算。
		VariableMatrix& operator+= (const VariableMatrix& rhs);
		VariableMatrix& operator-= (const VariableMatrix& rhs);
		VariableMatrix& operator*= (Real scalar);
		VariableMatrix& operator/= (Real scalar);

		// firstVector^T * M * secondVector 
		// （numColumns(M) = size(secondVector) 和
		// numRows(M) = size(firstVector) 是必须的）
		Real QuadraticForm(const VariableLengthVector& firstVector, const VariableLengthVector& secondVector) const;

		// M^T
		const VariableMatrix Transpose() const;

		const Matrix3 GetMatrix3() const;

		void Swap(VariableMatrix& rhs);

	private:
		// 该矩阵存储在列主序来自二维数组。
		int m_RowsNumber;
		int m_ColumnsNumber;
		int m_ElementsNumber;
		Real** m_Entry;
	};

	// 比较 (仅使用在STL容器)。
	// 矩阵必须有相同的大小（相同的行数和列数）
	template <typename Real>
	bool operator== (const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

	template <typename Real>
	bool operator<  (const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

	template <typename Real>
	const VariableMatrix<Real> operator* (const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

	// M * v (numColumns(matrix) = size(vector) 是必须的)
	template <typename Real>
	const VariableLengthVector<Real> operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

	// v^T * M (numRows(matrix) = size(vector) 是必须的)
	template <typename Real>
	const VariableLengthVector<Real> operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix);

	// M^T * mat (numRows(lhs) = numRows(rhs) 是必须的)
	template <typename Real>
	const VariableMatrix<Real> TransposeTimes(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

	// M * mat^T (numColumns(lhs) = numColumns(rhs) 是必须的)
	template <typename Real>
	const VariableMatrix<Real> TimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

	// M^T * mat^T (numRows(lhs) = numColumns(rhs) 是必须的)
	template <typename Real>
	const VariableMatrix<Real> TransposeTimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

	template <typename Real>
	bool Approximate(const VariableMatrix <Real>& lhs, const VariableMatrix <Real>& rhs, const Real epsilon);

	template <typename Real>
	bool Approximate(const VariableMatrix <Real>& lhs, const VariableMatrix <Real>& rhs);

	// 调试输出。
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const VariableMatrix<Real>& matrix);

	using VariableMatrixf = VariableMatrix<float>;
	using VariableMatrixd = VariableMatrix<double>;
}

#endif // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
