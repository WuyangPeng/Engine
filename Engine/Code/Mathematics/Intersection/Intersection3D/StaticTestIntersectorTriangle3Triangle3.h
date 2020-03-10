// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/12 14:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorTriangle3Triangle3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorTriangle3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Plane3 = Plane3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticTestIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle,const Triangle3& rhsTriangle,const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticTestIntersectorTriangle3Triangle3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Triangle3 GetLhsTriangle() const;
		const Triangle3 GetRhsTriangle() const;

	private:
		void Test();

	private:	
		// 要相交的对象。
		Triangle3 m_LhsTriangle;
		Triangle3 m_RhsTriangle;
	};
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
