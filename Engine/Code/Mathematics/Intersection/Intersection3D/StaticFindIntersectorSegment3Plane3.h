// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Segment3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Plane3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorSegment3Plane3(const Segment3& segment, const Plane3& plane);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Plane3 GetPlane() const;

		 [[nodiscard]] Real GetSegmentParameter() const;

	private:
		// Find-intersection query.  The point of intersection is
		// P = origin + t*direction, with |t| <= e, where e is the segment
		// extent.
		void Find();

		// The objects to intersect.
		Segment3 m_Segment;
		Plane3 m_Plane;

		// Information about the intersection set.
		Real m_SegmentParameter;
	};

	using FloatStaticFindIntersectorSegment3Plane3 = StaticFindIntersectorSegment3Plane3<float>;
	using DoubleStaticFindIntersectorSegment3Plane3 = StaticFindIntersectorSegment3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H
