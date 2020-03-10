// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:36)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Capsule3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorCapsule3Capsule3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorCapsule3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;		
 
	public:
		StaticTestIntersectorCapsule3Capsule3 (const Capsule3& capsule0,const Capsule3& capsule1);
		
		// Object access.
		const Capsule3 GetCapsule0 () const;
		const Capsule3 GetCapsule1 () const;

	private:
		// Static test-intersection query.
		void Test ();
		
	private:
		// The objects to intersect.
		Capsule3 mCapsule0;
		Capsule3 mCapsule1;
	};
	
	using StaticTestIntersectorCapsule3Capsule3f = StaticTestIntersectorCapsule3Capsule3<float>;
	using StaticTestIntersectorCapsule3Capsule3d = StaticTestIntersectorCapsule3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_H
