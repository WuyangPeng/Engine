// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 10:16)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"   
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorSphere3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorSphere3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;    

	public:
		DynamicTestIntersectorSphere3Sphere3 (const Sphere3& sphere0,const Sphere3& sphere1,Real tmax, 
											  const Vector3D& lhsVelocity,const Vector3D& rhsVelocity,const Real epsilon = Math::sm_ZeroTolerance);
		
		// Object access.
		const Sphere3 GetSphere0 () const;
		const Sphere3 GetSphere1 () const;		 

	private:
		// Dynamic test-intersection query.
		void Test ();

		// The objects to intersect.
		Sphere3 mSphere0;
		Sphere3 mSphere1;		
	};
	
	using DynamicTestIntersectorSphere3Sphere3f = DynamicTestIntersectorSphere3Sphere3<float>;
	using DynamicTestIntersectorSphere3Sphere3d = DynamicTestIntersectorSphere3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
