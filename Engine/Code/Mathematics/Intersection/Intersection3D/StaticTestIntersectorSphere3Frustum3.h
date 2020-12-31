// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"   
#include "Mathematics/Objects3D/Frustum3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSphere3Frustum3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSphere3Frustum3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Frustum3 = Frustum3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorSphere3Frustum3(const Sphere3& sphere, const Frustum3& frustum);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Sphere3 GetSphere() const;
                [[nodiscard]] const Frustum3 GetFrustum() const;

	private:
		// Static intersection query.
		void Test();

	private:
		// The objects to intersect.
		Sphere3 m_Sphere;
		Frustum3 mFrustum;
	};

	using FloatStaticTestIntersectorSphere3Frustum3 = StaticTestIntersectorSphere3Frustum3<float>;
	using DoubleStaticTestIntersectorSphere3Frustum3 = StaticTestIntersectorSphere3Frustum3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H
