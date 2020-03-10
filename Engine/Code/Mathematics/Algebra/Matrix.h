// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 10:55)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_H
#define MATHEMATICS_ALGEBRA_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>
#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix : private boost::additive<Matrix<Real>,
																boost::multiplicative<Matrix<Real>,Real,
																boost::totally_ordered<Matrix<Real>>>> 
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Matrix<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;
		using Math = Math<Real>;	
		using Matrix3 = Matrix3<Real>;
		using APoint = APoint<Real>;
		using AVector = AVector<Real>;
		using Vector4D = Vector4D<Real>;
		using HomogeneousPoint = HomogeneousPoint<Real>;

	public:
		// 如果标志为MatrixFlagsZero，创建零矩阵，
		// 否则创建单位矩阵。
		explicit Matrix (MatrixTypeFlags flag = MatrixTypeFlags::Zero);

		Matrix (const Matrix& rhs);
		explicit Matrix (const Matrix3& rhs);
	
		// 输入矩阵在行r和列c
		Matrix  (Real member00, Real member01, Real member02, Real member03, 
			     Real member10, Real member11, Real member12, Real member13, 
			     Real member20, Real member21, Real member22, Real member23,
				 Real member30, Real member31, Real member32, Real member33);		

		// 创建矩阵来自数组数字。
		// 输入数组是基于MatrixTypeFlags的输入的解释
		// MatrixTypeFlagsRow:  
		// entry[0..15] = { m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33 } [row major]
		// MatrixTypeFlagsColumn: 
		// entry[0..15] = { m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,m32,m03,m13,m23,m33 } [col major]
		Matrix (const std::vector<Real>& entry, MatrixMajorFlags majorFlag);		

		// 创建基于输入矢量的矩阵。MatrixMajorFlags解释为 
		// MatrixTypeFlagsRow：向量是矩阵的行 
		// MatrixTypeFlagsColumn：向量是矩阵的列
		Matrix (const Vector4D& firstVector,const Vector4D& secondVector,
			    const Vector4D& thirdVector,const Vector4D& fourthVector,
				MatrixMajorFlags majorFlag);

		Matrix (const AVector& firstVector,const AVector& secondVector,
			    const AVector& thirdVector,const APoint& point,
				MatrixMajorFlags majorFlag);

		// 创建一个对角矩阵,
		Matrix (Real member00, Real member11, Real member22);
	
		// 创建一个旋转矩阵（角度为正 ->逆时针方向）。angle必须为弧度，不是角度。
		Matrix (const AVector& axis, Real angle);

		Matrix& operator= (const Matrix& rhs);
		Matrix& operator= (const Matrix3& rhs);

		CLASS_INVARIANT_DECLARE;

		// Matrix的上3x3的块复制到Matrix3f对象。
		const Matrix3 GetMatrix3() const;

		// 坐标访问
		const Real* operator[] (int row) const;
		Real* operator[] (int row);
		const Real& operator() (int row, int column) const;
		Real& operator() (int row, int column);
		void SetRow (int row, const HomogeneousPoint& point);
		const HomogeneousPoint GetRow (int row) const;
		void SetColumn (int column, const HomogeneousPoint& point);
		const HomogeneousPoint GetColumn (int column) const;

		// 矩阵存储为行主序。在返回的数组中，以列主序存储。
		const std::vector<Real> GetColumnMajor () const;			

		// 算术运算	
		const Matrix operator- () const;	
		Matrix& operator+= (const Matrix& rhs);
		Matrix& operator-= (const Matrix& rhs);
		Matrix& operator*= (Real scalar);
		Matrix& operator/= (Real scalar);

		// 矩阵操作
		void MakeZero ();  // Z
		void MakeIdentity ();  // I
		void MakeDiagonal (Real member00, Real member11, Real member22);  // D
		void MakeRotation (const AVector& axis, Real angle);  // Real
		
		const Matrix Transpose () const;  // M^T
		const Matrix Inverse (const Real epsilon = Math::sm_ZeroTolerance) const;  // M^{-1}
		const Matrix Adjoint () const;  // M^{adj}

		const Matrix Invert3x3(const Real epsilon = Math::sm_ZeroTolerance) const;

		Real Determinant () const;  // det(M)

		Matrix& operator*= (const Matrix& rhs);

		// 只对左上角3x3矩阵进行运算
		const Matrix TimesDiagonal (const APoint& diag) const;  // M * D
		const Matrix DiagonalTimes (const APoint& diag) const;  // D * M
		
		void Orthonormalize (); // 适用于左上3x3的块		

		// 计算一个二次型。
		// p0^T * M * p1
		Real QuadraticForm (const HomogeneousPoint& firstPoint,const HomogeneousPoint& secondPoint) const; 

		// 投影矩阵到一个指定的平面
		// 这个平面包含“原点”和单位长度的“向量”。		
		void MakeObliqueProjection(const APoint& origin, const AVector& normal,const AVector& direction);
		
		// 设置透视投影矩阵到指定的平面上。
		// 这个平面有一个“origin”和单位长度的“normal”。	
		// “eye”是投影的原点。
		void MakePerspectiveProjection(const APoint& origin,const AVector& normal, const APoint& eye);

		// 反射矩阵到一个指定的平面
		// 这个平面包含“原点”和单位长度的“向量”。	
		void MakeReflection (const APoint& origin, const AVector& normal);

		// 特殊矩阵。
		static const Matrix sm_Zero;
		static const Matrix sm_Identity;	

	private:
		// 矩阵存储为行主序 
		Real m_Entry[16];
	};

	// 调试输出。
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Matrix<Real>& matrix);	

	// 比较（仅使用于STL容器）
	template <typename Real>
	bool operator== (const Matrix<Real>& lhs,const Matrix<Real>& rhs);

	template <typename Real>
	bool operator< (const Matrix<Real>& lhs,const Matrix<Real>& rhs);

	template <typename Real>
	const Matrix<Real> operator* (const Matrix<Real>& lhs,const Matrix<Real>& rhs);  // M * mat

	template <typename Real>
	const Matrix<Real>  TransposeTimes (const Matrix<Real>& lhs,const Matrix<Real>& rhs);  // M^T * mat

	template <typename Real>
	const Matrix<Real>  TimesTranspose (const Matrix<Real>& lhs,const Matrix<Real>& rhs);  // M * mat^T

	template <typename Real>
	const Matrix<Real>  TransposeTimesTranspose(const Matrix<Real>& lhs,const Matrix<Real>& rhs); // M^T * mat^T

	// 矩阵和齐次点之间的运算。
	// M和p为齐次对象（M并不被要求是仿射的，p也不要求有w = 1）。
	// M * p
	template <typename Real>
	const HomogeneousPoint<Real> operator*(const Matrix<Real>& matrix,const HomogeneousPoint<Real>& point);  

	// p * M
	template <typename Real>
	const HomogeneousPoint<Real> operator*(const HomogeneousPoint<Real>& point,const Matrix<Real>& matrix); 

	// M * p[0], ..., M * p[n-1]
	template <typename Real>
	const std::vector<HomogeneousPoint<Real> > BatchMultiply(const Matrix<Real>& matrix,const std::vector<HomogeneousPoint<Real> >& inputPoints);  

	// 仿射矩阵和仿射点之间的操作。
	// M * p
	template <typename Real>
	const APoint<Real> operator* (const Matrix<Real>& matrix,const APoint<Real>& point); 

	// M * p[0], ..., M * p[n-1]
	template <typename Real>
	const std::vector<APoint<Real> > BatchMultiply(const Matrix<Real>& matrix,const std::vector<APoint<Real>>& inputPoints);  

	// 仿射矩阵和仿射向量之间的操作。
	// M * v
	template <typename Real>
	const AVector<Real> operator* (const Matrix<Real>& matrix,const AVector<Real>& point); 

	// M * v[0], ..., M * v[n-1]
	template <typename Real>
	const std::vector<AVector<Real> > BatchMultiply(const Matrix<Real>& matrix,const std::vector<AVector<Real> >& inputPoints); 

	template <typename Real>
	bool Approximate(const Matrix<Real>& lhs,const Matrix<Real>& rhs,const Real epsilon);

	template <typename Real>
	bool Approximate(const Matrix<Real>& lhs,const Matrix<Real>& rhs);

	using Matrixf = Matrix<float>;
	using Matrixd = Matrix<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX_H
