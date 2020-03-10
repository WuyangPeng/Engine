// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 11:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Capsule3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Capsule3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
 
	public:
		StaticFindIntersectorSegment3Capsule3 (const Segment3& segment,const Capsule3& capsule);
		
		// Object access.
		const Segment3 GetSegment () const;
		const Capsule3 GetCapsule () const;

		// The intersection set.
		int GetQuantity () const;
		const Vector3D GetPoint (int i) const;
		Real GetParameter (int i) const;  // segment parameters for points
   
	private:
		// Static intersection queries.
		void Find ();
		
		// The objects to intersect.
		Segment3 mSegment;
		Capsule3 mCapsule;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
		Real mParameter[2];
	};
	
	using StaticFindIntersectorSegment3Capsule3f = StaticFindIntersectorSegment3Capsule3<float>;
	using StaticFindIntersectorSegment3Capsule3d = StaticFindIntersectorSegment3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H
