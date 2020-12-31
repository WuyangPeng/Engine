// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:58)

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
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

		virtual ~StaticTestIntersectorRay3Triangle3();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Ray3 GetRay() const;
                [[nodiscard]] const Triangle3 GetTriangle() const;

	private:
		void Test();

	private:
		// 相交对象
		Ray3 m_Ray;
		Triangle3 m_Triangle;
	};

	using FloatStaticTestIntersectorRay3Triangle3 = StaticTestIntersectorRay3Triangle3<float>;
	using DoubleStaticTestIntersectorRay3Triangle3 = StaticTestIntersectorRay3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_H
