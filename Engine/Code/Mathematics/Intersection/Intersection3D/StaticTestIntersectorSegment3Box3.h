// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"
   
#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSegment3Box3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSegment3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;  		
		
	public:
		StaticTestIntersectorSegment3Box3 (const Segment3& segment, const Box3& box,bool solid);
		
		// Object access.
		const Segment3 GetSegment () const;
		const Box3 GetBox () const;

	private:
		// Static test-intersection query.
		void Test ();
		
		// The objects to intersect.
		Segment3 mSegment;
		Box3 mBox;
		bool mSolid;		
	};
	
	using StaticTestIntersectorSegment3Box3f = StaticTestIntersectorSegment3Box3<float>;
	using StaticTestIntersectorSegment3Box3d = StaticTestIntersectorSegment3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
