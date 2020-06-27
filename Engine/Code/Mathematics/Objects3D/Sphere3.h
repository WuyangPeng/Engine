// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:24)

#ifndef MATHEMATICS_OBJECTS3D_SPHERE3_H
#define MATHEMATICS_OBJECTS3D_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Sphere3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Sphere3<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;

	public:
		// 球体被表示为|X-C| = Real，其中C为中心，Real为半径。
		Sphere3(const Vector3D& center, Real radius);
		Sphere3();

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetCenter() const;
		Real GetRadius() const;

		void SetSphere(const Vector3D& center, Real radius);

	private:
		Vector3D m_Center;
		Real m_Radius;
	};

	using Sphere3f = Sphere3<float>;
	using Sphere3d = Sphere3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_SPHERE3_H
