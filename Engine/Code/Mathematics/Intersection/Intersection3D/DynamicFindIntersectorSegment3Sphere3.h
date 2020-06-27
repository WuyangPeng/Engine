// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:43)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorSegment3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorSegment3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax,
											  const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);

		// Object access.
		const Segment3 GetSegment() const;
		const Sphere3 GetSphere() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;
		Real GetSegmentParameter(int i) const;

		Real ZeroThreshold;  // default = Math<Real>::sm_ZeroTolerance

	private:
		// Dynamic find-intersection query.  The first point of contact is
		// accessed by GetPoint(0).  The first time of contact is accessed by
		// GetContactTime().
		void Find();

		// The objects to intersect.
		Segment3 mSegment;
		Sphere3 mSphere;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
		Real mSegmentParameter[2];
	};

	using DynamicFindIntersectorSegment3Sphere3f = DynamicFindIntersectorSegment3Sphere3<float>;
	using DynamicFindIntersectorSegment3Sphere3d = DynamicFindIntersectorSegment3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
