// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Capsule3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Capsule3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorSegment3Capsule3(const Segment3& segment, const Capsule3& capsule);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Capsule3 GetCapsule() const;

		// The intersection set.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;
                [[nodiscard]] Real GetParameter(int index) const;  // segment parameters for points

	private:
		// Static intersection queries.
		void Find();

		// The objects to intersect.
		Segment3 m_Segment;
		Capsule3 mCapsule;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
		Real mParameter[2];
	};

	using FloatStaticFindIntersectorSegment3Capsule3 = StaticFindIntersectorSegment3Capsule3<float>;
	using DoubleStaticFindIntersectorSegment3Capsule3 = StaticFindIntersectorSegment3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H
