// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 10:59)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_H
#define MATHEMATICS_ALGEBRA_MATRIX2_H

#include "Mathematics/MathematicsDll.h"

// 旋转矩阵的形式为 
//   Real = cos(t) -sin(t)
//       sin(t)  cos(t)
// 当t > 0表示在xy平面上逆时针旋转。

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
		// 如果标志为MatrixFlagsZero，创建零矩阵，否则创建单位矩阵。
		explicit Matrix2 (MatrixTypeFlags flag = MatrixTypeFlags::Zero);	

		// 输入矩阵在行r和列c
		Matrix2 (Real member00, Real member01, Real member10, Real member11);
		
		// 创建矩阵来自数组数字。
		// 输入数组是基于MatrixTypeFlags的输入的解释
		// MatrixTypeFlagsRow:  entry[0..3] = {m00,m01,m10,m11}  [row major]
		// MatrixTypeFlagsColumn: entry[0..3] = {m00,m10,m01,m11}  [column major]
		Matrix2 (const std::vector<Real>& entry, MatrixMajorFlags majorFlag);

     	// 创建基于输入矢量的矩阵。MatrixMajorFlags解释为 
		// MatrixTypeFlagsRow：向量是矩阵的行 
		// MatrixTypeFlagsColumn：向量是矩阵的列
		Matrix2 (const Vector2D& firstVector, const Vector2D& secondVector,MatrixMajorFlags majorFlag);
		explicit Matrix2 (const std::vector<Vector2D>& vectors,MatrixMajorFlags majorFlag = MatrixMajorFlags::Column);

		// 创建一个对角矩阵, member01 = member10 = 0.
		Matrix2 (Real member00, Real member11);

		// 创建一个旋转矩阵（角度为正 ->逆时针方向）.
		explicit Matrix2 (Real angle);

		// 创建一个张量积 U * V^T
		Matrix2 (const Vector2D& firstVector, const Vector2D& secondVector);

		CLASS_INVARIANT_DECLARE;

		// 创建各种矩阵。
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

		// 其它运算
		const Matrix2 Inverse(const Real epsilon = Math::sm_ZeroTolerance) const;
		const Matrix2 Adjoint () const;
		Real Determinant () const;

		// 矩阵必须是一个旋转矩阵，下面函数才有效。
		// Orthonormalize函数使用Gram-Schmidt正交化施加到所述旋转矩阵。
		// 角度必须为弧度，而不是度数。
		Real ExtractAngle () const;
		void Orthonormalize ();

		// 矩阵必须是对称矩阵。
		// 系数M = Real * D * Real^T ，其中Real = [u0|u1] 是一个列为u0和u1的旋转矩阵且
		// D = diag(d0,d1)是一个对角矩阵，这里对角线项为d0和d1。
		// 特征向量u[i]对应的特征向量d[i]。特征值排序为d0 <= d1。
		// 返回值的第一部分为rotation，第二部分为diagonal。
		const Matrix2EigenDecomposition EigenDecomposition (const Real epsilon = Math::sm_ZeroTolerance) const;

		// 特殊矩阵。
		static const Matrix2 sm_Zero;
		static const Matrix2 sm_Identity;

	private:
		// Table存储为行主序。
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
