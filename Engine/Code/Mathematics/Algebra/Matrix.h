// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:55)

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
		// �����־ΪMatrixFlagsZero�����������
		// ���򴴽���λ����
		explicit Matrix (MatrixTypeFlags flag = MatrixTypeFlags::Zero);

		Matrix (const Matrix& rhs);
		explicit Matrix (const Matrix3& rhs);
	
		// �����������r����c
		Matrix  (Real member00, Real member01, Real member02, Real member03, 
			     Real member10, Real member11, Real member12, Real member13, 
			     Real member20, Real member21, Real member22, Real member23,
				 Real member30, Real member31, Real member32, Real member33);		

		// �������������������֡�
		// ���������ǻ���MatrixTypeFlags������Ľ���
		// MatrixTypeFlagsRow:  
		// entry[0..15] = { m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33 } [row major]
		// MatrixTypeFlagsColumn: 
		// entry[0..15] = { m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,m32,m03,m13,m23,m33 } [col major]
		Matrix (const std::vector<Real>& entry, MatrixMajorFlags majorFlag);		

		// ������������ʸ���ľ���MatrixMajorFlags����Ϊ 
		// MatrixTypeFlagsRow�������Ǿ������ 
		// MatrixTypeFlagsColumn�������Ǿ������
		Matrix (const Vector4D& firstVector,const Vector4D& secondVector,
			    const Vector4D& thirdVector,const Vector4D& fourthVector,
				MatrixMajorFlags majorFlag);

		Matrix (const AVector& firstVector,const AVector& secondVector,
			    const AVector& thirdVector,const APoint& point,
				MatrixMajorFlags majorFlag);

		// ����һ���ԽǾ���,
		Matrix (Real member00, Real member11, Real member22);
	
		// ����һ����ת���󣨽Ƕ�Ϊ�� ->��ʱ�뷽�򣩡�angle����Ϊ���ȣ����ǽǶȡ�
		Matrix (const AVector& axis, Real angle);

		Matrix& operator= (const Matrix& rhs);
		Matrix& operator= (const Matrix3& rhs);

		CLASS_INVARIANT_DECLARE;

		// Matrix����3x3�Ŀ鸴�Ƶ�Matrix3f����
		const Matrix3 GetMatrix3() const;

		// �������
		const Real* operator[] (int row) const;
		Real* operator[] (int row);
		const Real& operator() (int row, int column) const;
		Real& operator() (int row, int column);
		void SetRow (int row, const HomogeneousPoint& point);
		const HomogeneousPoint GetRow (int row) const;
		void SetColumn (int column, const HomogeneousPoint& point);
		const HomogeneousPoint GetColumn (int column) const;

		// ����洢Ϊ�������ڷ��ص������У���������洢��
		const std::vector<Real> GetColumnMajor () const;			

		// ��������	
		const Matrix operator- () const;	
		Matrix& operator+= (const Matrix& rhs);
		Matrix& operator-= (const Matrix& rhs);
		Matrix& operator*= (Real scalar);
		Matrix& operator/= (Real scalar);

		// �������
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

		// ֻ�����Ͻ�3x3�����������
		const Matrix TimesDiagonal (const APoint& diag) const;  // M * D
		const Matrix DiagonalTimes (const APoint& diag) const;  // D * M
		
		void Orthonormalize (); // ����������3x3�Ŀ�		

		// ����һ�������͡�
		// p0^T * M * p1
		Real QuadraticForm (const HomogeneousPoint& firstPoint,const HomogeneousPoint& secondPoint) const; 

		// ͶӰ����һ��ָ����ƽ��
		// ���ƽ�������ԭ�㡱�͵�λ���ȵġ���������		
		void MakeObliqueProjection(const APoint& origin, const AVector& normal,const AVector& direction);
		
		// ����͸��ͶӰ����ָ����ƽ���ϡ�
		// ���ƽ����һ����origin���͵�λ���ȵġ�normal����	
		// ��eye����ͶӰ��ԭ�㡣
		void MakePerspectiveProjection(const APoint& origin,const AVector& normal, const APoint& eye);

		// �������һ��ָ����ƽ��
		// ���ƽ�������ԭ�㡱�͵�λ���ȵġ���������	
		void MakeReflection (const APoint& origin, const AVector& normal);

		// �������
		static const Matrix sm_Zero;
		static const Matrix sm_Identity;	

	private:
		// ����洢Ϊ������ 
		Real m_Entry[16];
	};

	// ���������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const Matrix<Real>& matrix);	

	// �Ƚϣ���ʹ����STL������
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

	// �������ε�֮������㡣
	// M��pΪ��ζ���M������Ҫ���Ƿ���ģ�pҲ��Ҫ����w = 1����
	// M * p
	template <typename Real>
	const HomogeneousPoint<Real> operator*(const Matrix<Real>& matrix,const HomogeneousPoint<Real>& point);  

	// p * M
	template <typename Real>
	const HomogeneousPoint<Real> operator*(const HomogeneousPoint<Real>& point,const Matrix<Real>& matrix); 

	// M * p[0], ..., M * p[n-1]
	template <typename Real>
	const std::vector<HomogeneousPoint<Real> > BatchMultiply(const Matrix<Real>& matrix,const std::vector<HomogeneousPoint<Real> >& inputPoints);  

	// �������ͷ����֮��Ĳ�����
	// M * p
	template <typename Real>
	const APoint<Real> operator* (const Matrix<Real>& matrix,const APoint<Real>& point); 

	// M * p[0], ..., M * p[n-1]
	template <typename Real>
	const std::vector<APoint<Real> > BatchMultiply(const Matrix<Real>& matrix,const std::vector<APoint<Real>>& inputPoints);  

	// �������ͷ�������֮��Ĳ�����
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
