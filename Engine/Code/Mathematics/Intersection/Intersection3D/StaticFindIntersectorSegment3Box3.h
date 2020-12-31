// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"   
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
	using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Box3 GetBox() const;

		 [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static find-intersection query.  The point(s) of intersection are
		// accessed by GetQuantity() and GetPoint(i).
		void Find();

		// The objects to intersect.
		Segment3 m_Segment;
		Box3 m_Box;
		bool m_Solid;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorSegment3Box3 = StaticFindIntersectorSegment3Box3<float>;
	using DoubleStaticFindIntersectorSegment3Box3 = StaticFindIntersectorSegment3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H
