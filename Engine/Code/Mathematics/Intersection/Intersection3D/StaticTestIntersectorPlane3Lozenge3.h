// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Lozenge3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Lozenge3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Lozenge3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Lozenge3 = Lozenge3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorPlane3Lozenge3(const Plane3& plane, const Lozenge3& lozenge, const Real epsilon = Math::GetZeroTolerance());

		 CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Plane3 GetPlane() const;
                 [[nodiscard]] const Lozenge3 GetLozenge() const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The lozenge is culled if it is on the negative
		// side of the plane.
                [[nodiscard]] bool LozengeIsCulled() const;

	private:
		// Static intersection query.
		void Test();

		// The objects to intersect.		
		Plane3 m_Plane;
		Lozenge3 mLozenge;
	};

	using FloatStaticTestIntersectorPlane3Lozenge3 = StaticTestIntersectorPlane3Lozenge3<float>;
	using DoubleStaticTestIntersectorPlane3Lozenge3 = StaticTestIntersectorPlane3Lozenge3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_H
