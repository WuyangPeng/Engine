// Copyright (c) 2011-2020
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
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle);

		// Object access.
		const Segment3 GetSegment() const;
		const Triangle3 GetTriangle() const;

		// Find-intersection query.  The point of intersection is
		//   P = origin + t*direction = b0*V0 + b1*V1 + b2*V2		
		Real GetSegmentParameter() const;
		Real GetTriBary0() const;
		Real GetTriBary1() const;
		Real GetTriBary2() const;

		// NOTE: These functions were intended to be called after the dynamic
		// find-intersection query.  For the 'bool Find()' query, it was intended
		// that you use GetSegmentParameter() or the three GetTriBary?() functions
		// to compute the contact point yourself.  Now the functions also support
		// the 'bool Find()' query.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		void Find();

		// The objects to intersect.
		Segment3 mSegment;
		Triangle3 mTriangle;

		// Information about the stationary intersection set.
		Real mSegmentParameter, mTriBary0, mTriBary1, mTriBary2;

		// Information about the dynamic intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};

	using StaticFindIntersectorSegment3Triangle3f = StaticFindIntersectorSegment3Triangle3<float>;
	using StaticFindIntersectorSegment3Triangle3d = StaticFindIntersectorSegment3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
