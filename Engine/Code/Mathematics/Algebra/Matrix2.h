// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:59)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_H
#define MATHEMATICS_ALGEBRA_MATRIX2_H

#include "Mathematics/MathematicsDll.h"

// ��ת�������ʽΪ 
//   Real = cos(t) -sin(t)
//       sin(t)  cos(t)
// ��t > 0��ʾ��xyƽ������ʱ����ת��

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "CoreTools/DataTypes/TableDetail.h"
#include "Matrix2EigenDecompositionDetail.h"

#include <boost/operators.hpp>
#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class  Matrix2 : private boost::additive<Matrix2<Real>,
							 boost::multiplicative<Matrix2<Real>,Real>>
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");
		
		using ClassType = Matrix2<Real>;
		using Table2 = CoreTools::Table<2,2,Real>;
		using Vector2D = Vector2D<Real>;
		using Math = Math<Real>;
		using Matrix2EigenDecomposition = Matrix2EigenDecomposition<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		// �����־ΪMatrixFlagsZero����������󣬷��򴴽���λ����
		explicit Matrix2 (MatrixTypeFlags flag = MatrixTypeFlags::Zero);	

		// �����������r����c
		Matrix2 (Real member00, Real member01, Real member10, Real member11);
		
		// �������������������֡�
		// ���������ǻ���MatrixTypeFlags������Ľ���
		// MatrixTypeFlagsRow:  entry[0..3] = {m00,m01,m10,m11}  [row major]
		// MatrixTypeFlagsColumn: entry[0..3] = {m00,m10,m01,m11}  [column major]
		Matrix2 (const std::vector<Real>& entry, MatrixMajorFlags majorFlag);

     	// ������������ʸ���ľ���MatrixMajorFlags����Ϊ 
		// MatrixTypeFlagsRow�������Ǿ������ 
		// MatrixTypeFlagsColumn�������Ǿ������
		Matrix2 (const Vector2D& firstVector, const Vector2D& secondVector,MatrixMajorFlags majorFlag);
		explicit Matrix2 (const std::vector<Vector2D>& vectors,MatrixMajorFlags majorFlag = MatrixMajorFlags::Column);

		// ����һ���ԽǾ���, member01 = member10 = 0.
		Matrix2 (Real member00, Real member11);

		// ����һ����ת���󣨽Ƕ�Ϊ�� ->��ʱ�뷽��.
		explicit Matrix2 (Real angle);

		// ����һ�������� U * V^T
		Matrix2 (const Vector2D& firstVector, const Vector2D& secondVector);

		CLASS_INVARIANT_DECLARE;

		// �������־���
		void MakeZero ();
		void MakeIdentity ();
		void MakeDiagonal (Real member00, Real member11);
		void MakeRotation (Real angle);
		void MakeTensorProduct (const Vector2D& lhs, const Vector2D& rhs);

		const Real* operator[](int row) const;
		Real* operator[](int row);
		const Real& operator()(int row,int column) const;
		Real& operator()(int row,int column);
	
		const Matrix2 operator- () const;
		Matrix2& operator+= (const Matrix2& rhs);
		Matrix2& operator-= (const Matrix2& rhs);
		Matrix2& operator*= (Real scalar);
		Matrix2& operator/= (Real scalar);		

		// lhs^T * M * rhs
		Real QuadraticForm (const Vector2D& lhs, const Vector2D& rhs) const;

		// M^T
		const Matrix2 Transpose () const;

		// M * rhs
		Matrix2& operator*= (const Matrix2& rhs);		

		// ��������
		const Matrix2 Inverse(const Real epsilon = Math::sm_ZeroTolerance) const;
		const Matrix2 Adjoint () const;
		Real Determinant () const;

		// ���������һ����ת�������溯������Ч��
		// Orthonormalize����ʹ��Gram-Schmidt������ʩ�ӵ�������ת����
		// �Ƕȱ���Ϊ���ȣ������Ƕ�����
		Real ExtractAngle () const;
		void Orthonormalize ();

		// ��������ǶԳƾ���
		// ϵ��M = Real * D * Real^T ������Real = [u0|u1] ��һ����Ϊu0��u1����ת������
		// D = diag(d0,d1)��һ���ԽǾ�������Խ�����Ϊd0��d1��
		// ��������u[i]��Ӧ����������d[i]������ֵ����Ϊd0 <= d1��
		// ����ֵ�ĵ�һ����Ϊrotation���ڶ�����Ϊdiagonal��
		const Matrix2EigenDecomposition EigenDecomposition (const Real epsilon = Math::sm_ZeroTolerance) const;

		// �������
		static const Matrix2 sm_Zero;
		static const Matrix2 sm_Identity;

	private:
		// Table�洢Ϊ������
		Table2 m_Entry;		
	};

	// mat * mat
	template <typename Real>
	const Matrix2<Real> operator* (const Matrix2<Real>& lhs,const Matrix2<Real>& rhs);

	// mat * vec
	template <typename Real>
	const Vector2D<Real> operator* (const Matrix2<Real>& matrix,const Vector2D<Real>& vector);

	// vec^T * mat
	template <typename Real>
	const Vector2D<Real> operator* (const Vector2D<Real>& vector,const Matrix2<Real>& matrix);

	// lhs^T * rhs
	template <typename Real>
	const Matrix2<Real> TransposeTimes (const Matrix2<Real>& lhs,const Matrix2<Real>& rhs);

	// lhs * rhs^T
	template <typename Real>
	const Matrix2<Real> TimesTranspose (const Matrix2<Real>& lhs,const Matrix2<Real>& rhs);

	// lhs^T * rhs^T
	template <typename Real>
	const Matrix2<Real> TransposeTimesTranspose (const Matrix2<Real>& lhs,const Matrix2<Real>& rhs);

	template <typename Real>
	bool Approximate(const Matrix2<Real>& lhs,const Matrix2<Real>& rhs,const Real epsilon);

	template <typename Real>
	bool Approximate(const Matrix2<Real>& lhs,const Matrix2<Real>& rhs);

	using Matrix2f = Matrix2<float>;
	using Matrix2d= Matrix2<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX2_H
