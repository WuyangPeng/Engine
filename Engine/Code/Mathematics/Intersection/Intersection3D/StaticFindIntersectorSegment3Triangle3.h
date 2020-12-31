// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Triangle3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Triangle3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Triangle3 GetTriangle() const;

		// Find-intersection query.  The point of intersection is
		//   P = origin + t*direction = b0*V0 + b1*V1 + b2*V2		
		 [[nodiscard]] Real GetSegmentParameter() const;
                [[nodiscard]] Real GetTriBary0() const;
                 [[nodiscard]] Real GetTriBary1() const;
                [[nodiscard]] Real GetTriBary2() const;

		// NOTE: These functions were intended to be called after the dynamic
		// find-intersection query.  For the 'bool Find()' query, it was intended
		// that you use GetSegmentParameter() or the three GetTriBary?() functions
		// to compute the contact point yourself.  Now the functions also support
		// the 'bool Find()' query.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		void Find();

		// The objects to intersect.
		Segment3 m_Segment;
		Triangle3 m_Triangle;

		// Information about the stationary intersection set.
		Real m_SegmentParameter, m_TriBary0, m_TriBary1, m_TriBary2;

		// Information about the dynamic intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorSegment3Triangle3 = StaticFindIntersectorSegment3Triangle3<float>;
	using DoubleStaticFindIntersectorSegment3Triangle3 = StaticFindIntersectorSegment3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
