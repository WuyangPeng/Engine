// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"
 
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Capsule3.h" 
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Capsule3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;		
 
	public:
		StaticTestIntersectorLine3Capsule3 (const Line3& line,const Capsule3& capsule);
		
		// Object access.
		const Line3 GetLine () const;
		const Capsule3 GetCapsule () const;

	private:
		// Static intersection queries.
		void Test ();
		
		// The objects to intersect.
		Line3 mLine;
		Capsule3 mCapsule;	
	};
	
	using StaticTestIntersectorLine3Capsule3f = StaticTestIntersectorLine3Capsule3<float>;
	using StaticTestIntersectorLine3Capsule3d = StaticTestIntersectorLine3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_H
