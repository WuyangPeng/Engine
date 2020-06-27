// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:18)

#ifndef MATHEMATICS_OBJECTS3D_CAPSULE3_H
#define MATHEMATICS_OBJECTS3D_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Segment3.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Capsule3
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Capsule3<Real>;
		using Segment3 = Segment3<Real>;

	public:
		// 胶囊体是一组从线段中等距的点， 公共距离被称为半径。
		Capsule3(const Segment3& segment, Real radius);

		CLASS_INVARIANT_DECLARE;

		const Segment3 GetSegment() const;
		Real GetRadius() const;

	private:
		Segment3 m_Segment;
		Real m_Radius;
	};

	using Capsule3f = Capsule3<float>;
	using Capsule3d = Capsule3<double>;
}

#endif // MATHEMATICS_OBJECTS3D_CAPSULE3_H
