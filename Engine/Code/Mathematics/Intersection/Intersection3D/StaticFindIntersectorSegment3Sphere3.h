// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere);

		// Object access.
		const Segment3 GetSegment() const;
		const Sphere3 GetSphere() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;
		Real GetSegmentParameter(int i) const;

		Real ZeroThreshold;  // default = Math<Real>::GetZeroTolerance()

	private:
		// Static intersection queries.		
		void Find();

		// The objects to intersect.
		Segment3 mSegment;
		Sphere3 mSphere;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
		Real mSegmentParameter[2];
	};

	using StaticFindIntersectorSegment3Sphere3f = StaticFindIntersectorSegment3Sphere3<float>;
	using StaticFindIntersectorSegment3Sphere3d = StaticFindIntersectorSegment3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
