// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/12 14:16)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay3Triangle3 : public StaticIntersector<Real, Vector3D>
	{
	public:		
		using ClassType = StaticTestIntersectorRay3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon = Math::sm_ZeroTolerance);

		virtual ~StaticTestIntersectorRay3Triangle3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		const Ray3 GetRay() const;
		const Triangle3 GetTriangle () const; 

	private:	
		void Test();
		
	private: 
		// 相交对象
		Ray3 m_Ray;
		Triangle3 m_Triangle; 		
	};

	using StaticTestIntersectorRay3Triangle3f = StaticTestIntersectorRay3Triangle3<float>;
	using StaticTestIntersectorRay3Triangle3d = StaticTestIntersectorRay3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_H
