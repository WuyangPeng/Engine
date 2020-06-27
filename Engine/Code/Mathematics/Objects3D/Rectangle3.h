// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:23)

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
		// 点Real(s,t) = C+s0*U0+s1*U1，其中C是矩形的中心，U0和U1是单位长度的垂直轴。
		// 参数s0和s1是由约束|s0| <= e0 和|s1| <= e1，
		// 其中e0 > 0和e1 > 0称为矩形的范围。
		Rectangle3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, Real extent0, Real extent1, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetCenter() const;
		const Vector3D GetFirstAxis() const;
		const Vector3D GetSecondAxis() const;
		Real GetFirstExtent() const;
		Real GetSecondExtent() const;

		const Vector3D GetAxis(int index) const;
		Real GetExtent(int index) const;

		// 返回矩形的四个顶点
		const std::vector<Vector3D> ComputeVertices() const;

		// 获取矩形角。
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
