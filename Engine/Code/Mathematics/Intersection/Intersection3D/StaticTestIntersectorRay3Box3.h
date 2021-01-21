// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Ray3.h"   

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorRay3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorRay3Box3(const Ray3& ray, const Box3& box, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;
                
		 [[nodiscard]] const Ray3 GetRay() const;
                [[nodiscard]] const Box3 GetBox() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Ray3 m_Ray;
		Box3 m_Box;
	};

	using FloatStaticTestIntersectorRay3Box3 = StaticTestIntersectorRay3Box3<float>;
	using DoubleStaticTestIntersectorRay3Box3 = StaticTestIntersectorRay3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_H
