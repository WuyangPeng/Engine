// Copyright (c) 2011-2020
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
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid);

		// Object access.
		const Segment3 GetSegment() const;
		const Box3 GetBox() const;

		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Static find-intersection query.  The point(s) of intersection are
		// accessed by GetQuantity() and GetPoint(i).
		void Find();

		// The objects to intersect.
		Segment3 mSegment;
		Box3 mBox;
		bool mSolid;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};

	using StaticFindIntersectorSegment3Box3f = StaticFindIntersectorSegment3Box3<float>;
	using StaticFindIntersectorSegment3Box3d = StaticFindIntersectorSegment3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H
