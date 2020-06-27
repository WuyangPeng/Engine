// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 10:15)

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
		// ֧�������ֽ⡣��Tridiagonalize�����ɽ�Householder�任����
		// �������ת����identity�������Ѿ���tridiagonal�����򷵻�ֵ��'false'��
		// ����ת����һ������ͷ���ֵ��'true'��
		// QLAlgorithm���ء�true�����ҽ���QL��������������
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
