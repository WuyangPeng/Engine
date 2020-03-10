// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Cone3.h"  
#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSphere3Cone3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSphere3Cone3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Cone3 = Cone3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   
		
	public:
		StaticTestIntersectorSphere3Cone3 (const Sphere3& sphere, const Cone3& cone);
		
		// Object access.
		const Sphere3 GetSphere () const;
		const Cone3 GetCone () const;

	private:
		// Static intersection queries.
		void Test ();
		
	private:
		// The objects to intersect.
		Sphere3 mSphere;
		Cone3 mCone;
	};
	
	using StaticTestIntersectorSphere3Cone3f = StaticTestIntersectorSphere3Cone3<float>;
	using StaticTestIntersectorSphere3Cone3d = StaticTestIntersectorSphere3Cone3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H
