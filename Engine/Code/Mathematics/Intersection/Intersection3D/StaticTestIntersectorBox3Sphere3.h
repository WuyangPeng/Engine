// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 13:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"
  
#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorBox3Sphere3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorBox3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>; 
		using Math = Math<Real>;		
		 
	public:
		StaticTestIntersectorBox3Sphere3 (const Box3& box, const Sphere3& sphere);
		
		// Object access.
		const Box3 GetBox () const;
		const Sphere3 GetSphere () const;

	private:
		// Test-intersection query.
		void Test ();		 
		
		// The objects to intersect.
		Box3 mBox;
		Sphere3 mSphere;		
	};
	
	using StaticTestIntersectorBox3Sphere3f = StaticTestIntersectorBox3Sphere3<float>;
	using StaticTestIntersectorBox3Sphere3d = StaticTestIntersectorBox3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_H
