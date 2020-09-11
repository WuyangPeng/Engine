// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:13)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_H
#define MATHEMATICS_ALGEBRA_MATRIX4_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "CoreTools/DataTypes/TableDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Matrix4 : private boost::additive<Matrix4<Real>, boost::multiplicative<Matrix4<Real>, Real>>
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Matrix4<Real>;
		using Table4 = CoreTools::Table<4, 4, Real>;
		using Vector4D = Vector4D<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Vector4DTools = Vector4DTools<Real>;

	public:
		// 如果标志为MatrixFlagsZero，创建零矩阵，
		// 否则创建单位矩阵。
		explicit Matrix4(MatrixInitType flag = MatrixInitType::Zero);

		// 输入矩阵在行r和列c
		Matrix4(Real member00, Real member01, Real member02, Real member03,
				Real member10, Real member11, Real member12, Real member13,
				Real member20, Real member21, Real member22, Real member23,
				Real member30, Real member31, Real member32, Real member33);

		// 创建矩阵来自数组数字。
		// 输入数组是基于MatrixTypeFlags的输入的解释
		// MatrixTypeFlagsRow:  
		// entry[0..15]={m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,
		//               m23,m30,m31,m32,m33} [row major]
		// MatrixTypeFlagsColumn: 
		// entry[0..15]={m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,
		//               m32,m03,m13,m23,m33} [col major]
		Matrix4(const std::vector<Real>& entry, MatrixMajorFlags majorFlag);

		CLASS_INVARIANT_DECLARE;

		// 创建各种矩阵。
		void MakeZero();
		void MakeIdentity();

		const Real* operator[](int row) const;
		Real* operator[](int row);
		const Real& operator()(int row, int column) const;
		Real& operator()(int row, int column);

		const Matrix4 operator- () const;
		Matrix4& operator+= (const Matrix4& rhs);
		Matrix4& operator-= (const Matrix4& rhs);
		Matrix4& operator*= (Real scalar);
		Matrix4& operator/= (Real scalar);

		// lhs^T * M * rhs
		Real QuadraticForm(const Vector4D& lhs, const Vector4D& rhs) const;

		// M^T
		const Matrix4 Transpose() const;

		// M * rhs
		Matrix4& operator*= (const Matrix4& rhs);

		// 其它运算
		const Matrix4 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
		const Matrix4 Adjoint() const;
		Real Determinant() const;

		// 投影矩阵到一个指定的平面
		// （包含“原点”和单位长度的“向量”）。
		void MakeObliqueProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& direction);

		void MakePerspectiveProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& eye);

		// 通过指定的平面反射矩阵。
		void MakeReflection(const Vector3D& normal, const Vector3D& origin);

		void MakeFrustumMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance);
		void MakePerspectiveMatrix44(Real fieldOfViewY, Real aspect, Real nearDistance, Real farDistance);
		void MakeOrthoMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance);
		void MakeOrthoNormalMatrix44(const Vector3D& xDirection, const Vector3D& yDirection, const Vector3D& zDirection);

		// 特殊矩阵。
		static const Matrix4 sm_Zero;
		static const Matrix4 sm_Identity;

	private:
		// Table存储为行主序。
		Table4 m_Entry;
	};

	// M * vec
	template <typename Real>
	const Vector4D<Real> operator* (const Matrix4<Real>& matrix, const Vector4D<Real>& vector);
	// v^T * M
	template <typename Real>
	const Vector4D<Real> operator* (const Vector4D<Real>& vector, const Matrix4<Real>& matrix);

	// M * mat
	template <typename Real>
	const Matrix4<Real> operator* (const Matrix4<Real>& lhs, const Matrix4<Real>& rhs);

	// M^T * mat
	template <typename Real>
	const Matrix4<Real> TransposeTimes(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs);

	// M * mat^T
	template <typename Real>
	const Matrix4<Real> TimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs);

	// M^T * mat^T
	template <typename Real>
	const Matrix4<Real> TransposeTimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs);

	template <typename Real>
	bool Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs, const Real epsilon);

	template <typename Real>
	bool Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs);

	using Matrix4f = Matrix4<float>;
	using Matrix4d = Matrix4<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX4_H
