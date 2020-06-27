// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:15)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class Tridiagonalize
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Tridiagonalize<Real>;
		using Matrix3 = Matrix3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		explicit Tridiagonalize(const Matrix3& matrix);

		CLASS_INVARIANT_DECLARE;

		bool IsReflection() const;
		const Matrix3 GetRotation() const;
		const Vector3D GetDiagonal() const;

	private:
		// 支持特征分解。该Tridiagonalize函数可将Householder变换矩阵。
		// 如果这种转变是identity（矩阵已经是tridiagonal），则返回值是'false'。
		// 否则，转换是一个反射和返回值是'true'。
		// QLAlgorithm返回“true”当且仅当QL迭代方案收敛。
		void Init();
		bool QLAlgorithm();
		static bool IsValueNear(Real subdiagonal, Real lhsDiagonal, Real rhsDiagonal);
		void UpdateDiagonal(int lhsIndex, int rhsIndex);
		void GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue);

	private:
		Matrix3 m_InputMatrix;
		Matrix3 m_OutputMatrix;
		Real m_Diagonal[3];
		Real m_Subdiagonal[2];
		bool m_Reflection;
	};
}

#endif // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
