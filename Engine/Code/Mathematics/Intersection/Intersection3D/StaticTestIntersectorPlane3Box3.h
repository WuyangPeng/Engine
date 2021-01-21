// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorPlane3Box3(const Plane3& plane, const Box3& box, const Real epsilon = Math::GetZeroTolerance());

	CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Plane3 GetPlane() const;
        [[nodiscard]] const Box3 GetBox() const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The box is culled if it is on the negative side
		// of the plane.
        [[nodiscard]] bool BoxIsCulled() const;

	private:
		// Static intersection query.
		void Test();

	private:
		// The objects to intersect.
		Plane3 m_Plane;
		Box3 m_Box;
	};

	using FloatStaticTestIntersectorPlane3Box3 = StaticTestIntersectorPlane3Box3<float>;
	using DoubleStaticTestIntersectorPlane3Box3 = StaticTestIntersectorPlane3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_H
