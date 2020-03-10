// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 10:05)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorSegment3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorSegment3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   

	public:
		DynamicTestIntersectorSegment3Box3 (const Segment3& segment, const Box3& box,bool solid,Real tmax,
										    const Vector3D& lhsVelocity,const Vector3D& rhsVelocity,const Real epsilon = Math::sm_ZeroTolerance);
		
		// Object access.
		const Segment3 GetSegment () const;
		const Box3 GetBox () const;

	private:
		// Dynamic test-intersection query.
		void Test ();
    
		// The objects to intersect.
		Segment3 mSegment;
		Box3 mBox;
		bool mSolid;		
	};
	
	using DynamicTestIntersectorSegment3Box3f = DynamicTestIntersectorSegment3Box3<float>;
	using DynamicTestIntersectorSegment3Box3d = DynamicTestIntersectorSegment3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
