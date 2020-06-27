// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:23)

#ifndef MATHEMATICS_OBJECTS3D_RECTANGLE3_H
#define MATHEMATICS_OBJECTS3D_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Rectangle3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using Math = Math<Real>;

	public:
		// ��Real(s,t) = C+s0*U0+s1*U1������C�Ǿ��ε����ģ�U0��U1�ǵ�λ���ȵĴ�ֱ�ᡣ
		// ����s0��s1����Լ��|s0| <= e0 ��|s1| <= e1��
		// ����e0 > 0��e1 > 0��Ϊ���εķ�Χ��
		Rectangle3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, Real extent0, Real extent1, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetCenter() const;
		const Vector3D GetFirstAxis() const;
		const Vector3D GetSecondAxis() const;
		Real GetFirstExtent() const;
		Real GetSecondExtent() const;

		const Vector3D GetAxis(int index) const;
		Real GetExtent(int index) const;

		// ���ؾ��ε��ĸ�����
		const std::vector<Vector3D> ComputeVertices() const;

		// ��ȡ���νǡ�
		const Vector3D GetPPCorner() const;  // C + e0*A0 + e1*A1
		const Vector3D GetPMCorner() const;  // C + e0*A0 - e1*A1
		const Vector3D GetMPCorner() const;  // C - e0*A0 + e1*A1
		const Vector3D GetMMCorner() const;  // C - e0*A0 - e1*A1

	private:
		Vector3D m_Center;
		Vector3D m_Axis[2];
		Real m_Extent[2];

		Real m_Epsilon;
	};

	using Rectangle3f = Rectangle3<float>;
	using Rectangle3d = Rectangle3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_RECTANGLE3_H
