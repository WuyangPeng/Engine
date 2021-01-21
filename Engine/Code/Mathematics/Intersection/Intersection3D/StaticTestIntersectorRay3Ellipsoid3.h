// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"   
#include "Mathematics/Objects3D/Ellipsoid3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay3Ellipsoid3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorRay3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorRay3Ellipsoid3(const Ray3& ray, const Ellipsoid3& ellipsoid, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Ray3 GetRay() const;
                [[nodiscard]] const Ellipsoid3 GetEllipsoid() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Ray3 m_Ray;
		Ellipsoid3 m_Ellipsoid;
	};

	using FloatStaticTestIntersectorRay3Ellipsoid3 = StaticTestIntersectorRay3Ellipsoid3<float>;
	using DoubleStaticTestIntersectorRay3Ellipsoid3 = StaticTestIntersectorRay3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_H
