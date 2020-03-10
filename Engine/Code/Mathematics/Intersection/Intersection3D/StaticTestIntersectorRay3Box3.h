// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Ray3.h"   

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay3Box3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorRay3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>; 
		
	public:
		StaticTestIntersectorRay3Box3 (const Ray3& ray, const Box3& box);
		
		// Object access.
		const Ray3 GetRay () const;
		const Box3 GetBox () const;
		
	private:
		// Static intersection queries.
		void Test ();
		
		// The objects to intersect.
		Ray3 mRay;
		Box3 mBox;		
	};

	using StaticTestIntersectorRay3Box3f = StaticTestIntersectorRay3Box3<float>;
	using StaticTestIntersectorRay3Box3d = StaticTestIntersectorRay3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_H
