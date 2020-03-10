// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/12 13:53)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{

	template <typename Real>
	class StaticTestIntersectorLine3Plane3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticTestIntersectorLine3Plane3(const Line3& line, const Plane3& plane,const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticTestIntersectorLine3Plane3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		const Line3 GetLine() const;
		const Plane3 GetPlane() const;

	private:
		void Test();
		
	private: 
		// 相交对象
		Line3 m_Line;
		Plane3 m_Plane;
	};

	using StaticTestIntersectorLine3Plane3f = StaticTestIntersectorLine3Plane3<float>;
	using StaticTestIntersectorLine3Plane3d = StaticTestIntersectorLine3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_H
