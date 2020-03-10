// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 13:51)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>
#include <type_traits>
#include <vector>

// ��������Ӧ��Ϊ��ˡ�
// ���磬�����ľ���M������V�������ʸ��ΪM * V��
// Ҳ����˵��V������һ����������
// һЩͼ��APIʹ��V * M������V����Ϊ��������
// ����Щ�����У�����M����������M����ʾ��ת�á�
// ���Ƶأ�Ӧ��2����������M0��M1���Ը�˳��
// �����M1*M0��һ��������ת���ǣ�M1 * M0��* V = M1 *��M0* V����
// һЩͼ��APIʹ��M0 * M1����ͬ����Щ������ָ��������ʾ��ת�á�
// ��ˣ���һ��ҪС���������ͼ��API�ӿ���ת�����롣
//
// ���󱻴���Ϊ�����򱣴棬matrix[row][col].

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableMatrix : private boost::additive<VariableMatrix<Real>,		                          	
		                                                                boost::multiplicative<VariableMatrix<Real>,Real,
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
		explicit VariableMatrix (int rowsNumber = 0, int columnsNumber = 0);
		VariableMatrix (int rowsNumber, int columnsNumber,const std::vector<Real>& entry);
		VariableMatrix (int rowsNumber, int columnsNumber,const std::vector<std::vector<Real> >& matrix);
		VariableMatrix (const VariableMatrix& rhs);
		explicit VariableMatrix (const Matrix3& rhs);
		explicit VariableMatrix (const Matrix2& rhs);
		~VariableMatrix ();

		VariableMatrix& operator= (const VariableMatrix& rhs);

		CLASS_INVARIANT_DECLARE;

		// ��Ա����

		// ʹ��ResetSize����վ����ݡ�
		void ResetSize (int rowsNumber, int columnsNumber);
		int GetRowsNumber() const noexcept;
		int GetColumnsNumber() const noexcept;
		int GetElementsNumber() const noexcept;
		const Real* GetElements () const;
		Real* GetElements ();
		const Real* operator[] (int row) const;
		Real* operator[] (int row);
		const Real& operator() (int row, int column) const;
		Real& operator() (int row, int column);

		void SetIdentity();

		void SetRow (int row, const VariableLengthVector& vector);
		const VariableLengthVector GetRow (int row) const;
		void SetColumn (int column, const VariableLengthVector& vector);
		const VariableLengthVector GetColumn (int column) const;
		void ResetMatrix (int rowsNumber, int columnsNumber, const std::vector<Real>& entry);
		void ResetMatrix (int rowsNumber, int columnsNumber, const std::vector<std::vector<Real> >& matrix);
  
		// ֧�ֽ����к��С�
		void SwapRows (int firstRow, int secondRow);
		void SwapColumns (int firstColumns, int secondColumns);	

		// ���ھ���˷�����this�������е���Ŀ�������rhs�����е���Ŀ
		VariableMatrix& operator*= (const VariableMatrix& rhs);

		const VariableMatrix operator- () const;

		// �����������ͬ�Ĵ�С����ͬ��������������
		// ���ھ���ļӷ��ͼ������㡣
		VariableMatrix& operator+= (const VariableMatrix& rhs);
		VariableMatrix& operator-= (const VariableMatrix& rhs);
		VariableMatrix& operator*= (Real scalar);
		VariableMatrix& operator/= (Real scalar);		

		// firstVector^T * M * secondVector 
		// ��numColumns(M) = size(secondVector) ��
		// numRows(M) = size(firstVector) �Ǳ���ģ�
		Real QuadraticForm(const VariableLengthVector& firstVector,const VariableLengthVector& secondVector) const;

		// M^T
		const VariableMatrix Transpose () const;		

		const Matrix3 GetMatrix3() const;
 
		void Swap(VariableMatrix& rhs);

	private:
		// �þ���洢�����������Զ�ά���顣
		int m_RowsNumber;
		int m_ColumnsNumber;
		int m_ElementsNumber;
		Real** m_Entry;
	};

	// �Ƚ� (��ʹ����STL����)��
	// �����������ͬ�Ĵ�С����ͬ��������������
	template <typename Real>
	bool operator== (const VariableMatrix<Real>& lhs,const VariableMatrix<Real>& rhs);

	template <typename Real>
	bool operator<  (const VariableMatrix<Real>& lhs,const VariableMatrix<Real>& rhs);

	template <typename Real>
	const VariableMatrix<Real> operator* (const VariableMatrix<Real>& lhs,const VariableMatrix<Real>& rhs);

	// M * v (numColumns(matrix) = size(vector) �Ǳ����)
	template <typename Real>
	const VariableLengthVector<Real> operator*(const VariableMatrix<Real>& matrix,const VariableLengthVector<Real>& vector);

	// v^T * M (numRows(matrix) = size(vector) �Ǳ����)
	template <typename Real>
	const VariableLengthVector<Real> operator*(const VariableLengthVector<Real>& vector,const VariableMatrix<Real>& matrix);

	// M^T * mat (numRows(lhs) = numRows(rhs) �Ǳ����)
	template <typename Real>
	const VariableMatrix<Real> TransposeTimes (const VariableMatrix<Real>& lhs,const VariableMatrix<Real>& rhs);

	// M * mat^T (numColumns(lhs) = numColumns(rhs) �Ǳ����)
	template <typename Real>
	const VariableMatrix<Real> TimesTranspose(const VariableMatrix<Real>& lhs,const VariableMatrix<Real>& rhs);

	// M^T * mat^T (numRows(lhs) = numColumns(rhs) �Ǳ����)
	template <typename Real>
	const VariableMatrix<Real> TransposeTimesTranspose(const VariableMatrix<Real>& lhs,const VariableMatrix<Real>& rhs);

	template <typename Real>
	bool Approximate(const VariableMatrix <Real>& lhs,const VariableMatrix <Real>& rhs,const Real epsilon);
	
	template <typename Real>
	bool Approximate(const VariableMatrix <Real>& lhs,const VariableMatrix <Real>& rhs);

	// ���������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const VariableMatrix<Real>& matrix);
	
    using VariableMatrixf = VariableMatrix<float>;
	using VariableMatrixd = VariableMatrix<double>;
}

#endif // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
