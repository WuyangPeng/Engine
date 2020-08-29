// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	// Find-intersection query.  The point of intersection is
	// P = origin + t*direction.
	template <typename Real>
	class StaticFindIntersectorLine3Plane3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorLine3Plane3(const Line3& line, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance());

		virtual ~StaticFindIntersectorLine3Plane3();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Line3 GetLine() const;
		const Plane3 GetPlane() const;

		Real GetLineParameter() const;

	private:
		void Find();

	private:
		// 相交对象
		Line3 m_Line;
		Plane3 m_Plane;

		// 相交对象集信息
		Real m_LineParameter;
	};

	using StaticFindIntersectorLine3Plane3f = StaticFindIntersectorLine3Plane3<float>;
	using StaticFindIntersectorLine3Plane3d = StaticFindIntersectorLine3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H
