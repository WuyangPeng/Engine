// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Sphere3.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Sphere3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>; 		
		
	public:
		StaticTestIntersectorLine3Sphere3 (const Line3& line, const Sphere3& sphere);
		
		// Object access.
		const Line3 GetLine () const;
		const Sphere3 GetSphere () const;
		
	private:
		// Static intersection queries.
		void Test ();

		// The objects to intersect.
		Line3 mLine;
		Sphere3 mSphere;
	};
	
	using StaticTestIntersectorLine3Sphere3f = StaticTestIntersectorLine3Sphere3<float>;
	using StaticTestIntersectorLine3Sphere3d = StaticTestIntersectorLine3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_H
