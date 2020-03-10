// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"
 
#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Frustum3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorBox3Frustum3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorBox3Frustum3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Frustum3 = Frustum3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticTestIntersectorBox3Frustum3 (const Box3& box, const Frustum3& frustum);
		
		// Object access.
		const Box3 GetBox () const;
		const Frustum3 GetFrustum () const;

	private:
		// Test-intersection query.
		void Test ();
		
	private:
		// The objects to intersect.
		Box3 mBox;
		Frustum3 mFrustum;
	};

	using StaticTestIntersectorBox3Frustum3f = StaticTestIntersectorBox3Frustum3<float>;
	using StaticTestIntersectorBox3Frustum3d = StaticTestIntersectorBox3Frustum3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H
