// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"   
#include "Mathematics/Objects3D/Frustum3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSphere3Frustum3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSphere3Frustum3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Frustum3 = Frustum3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticTestIntersectorSphere3Frustum3 (const Sphere3& sphere, const Frustum3& frustum);

		// Object access.
		const Sphere3 GetSphere () const;
		const Frustum3 GetFrustum () const;

	private:
		// Static intersection query.
		void Test ();
		
	private:
		// The objects to intersect.
		Sphere3 mSphere;
		Frustum3 mFrustum;
	};
	
	using StaticTestIntersectorSphere3Frustum3f = StaticTestIntersectorSphere3Frustum3<float>;
	using StaticTestIntersectorSphere3Frustum3d = StaticTestIntersectorSphere3Frustum3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H
