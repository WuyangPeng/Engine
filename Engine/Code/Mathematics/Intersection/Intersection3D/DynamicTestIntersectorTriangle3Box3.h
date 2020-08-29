// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:47)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h" 
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Objects3D/Box3.h"  

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorTriangle3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorTriangle3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicTestIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, Real tmax,
											const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Triangle3 GetTriangle() const;
		const Box3 GetBox() const;

	private:
		// Dynamic test-intersection query.
		void Test();

		// The objects to intersect.
		Triangle3 mTriangle;
		Box3 mBox;
	};

	using DynamicTestIntersectorTriangle3Box3f = DynamicTestIntersectorTriangle3Box3<float>;
	using DynamicTestIntersectorTriangle3Box3d = DynamicTestIntersectorTriangle3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_H
