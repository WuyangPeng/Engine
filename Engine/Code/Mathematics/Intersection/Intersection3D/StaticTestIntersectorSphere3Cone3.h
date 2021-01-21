// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Cone3.h"  
#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSphere3Cone3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSphere3Cone3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Cone3 = Cone3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorSphere3Cone3(const Sphere3& sphere, const Cone3& cone, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Sphere3 GetSphere() const;
                [[nodiscard]] const Cone3 GetCone() const;

	private:
		// Static intersection queries.
		void Test();

	private:
		// The objects to intersect.
		Sphere3 m_Sphere;
		Cone3 mCone;
	};

	using FloatStaticTestIntersectorSphere3Cone3 = StaticTestIntersectorSphere3Cone3<float>;
	using DoubleStaticTestIntersectorSphere3Cone3 = StaticTestIntersectorSphere3Cone3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H
