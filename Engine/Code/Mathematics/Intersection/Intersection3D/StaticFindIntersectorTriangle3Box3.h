// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorTriangle3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorTriangle3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box);

	CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Triangle3 GetTriangle() const;
        [[nodiscard]] const Box3 GetBox() const;

		// The intersection set.
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static test-intersection query.
		void Find();

		// The objects to intersect.
		Triangle3 m_Triangle;
		Box3 m_Box;

		// The intersections for static query.  A triangle can intersect a box
		// in at most 7 vertices.
		int m_Quantity;
		Vector3D m_Point[7];
	};

	using FloatStaticFindIntersectorTriangle3Box3 = StaticFindIntersectorTriangle3Box3<float>;
	using DoubleStaticFindIntersectorTriangle3Box3 = StaticFindIntersectorTriangle3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H
