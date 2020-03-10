// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 11:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Segment3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Plane3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
 
	public:
		StaticFindIntersectorSegment3Plane3 (const Segment3& segment,const Plane3& plane);
		
		// Object access.
		const Segment3 GetSegment () const;
		const Plane3 GetPlane () const;
		
		Real GetSegmentParameter () const;
		
	private:
		// Find-intersection query.  The point of intersection is
		// P = origin + t*direction, with |t| <= e, where e is the segment
		// extent.
		void Find ();
		
		// The objects to intersect.
		Segment3 mSegment;
		Plane3 mPlane;
		
		// Information about the intersection set.
		Real mSegmentParameter;
	};
	
	using StaticFindIntersectorSegment3Plane3f = StaticFindIntersectorSegment3Plane3<float>;
	using StaticFindIntersectorSegment3Plane3d = StaticFindIntersectorSegment3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H
