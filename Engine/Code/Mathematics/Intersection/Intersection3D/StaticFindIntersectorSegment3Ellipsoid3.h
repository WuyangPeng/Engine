// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Ellipsoid3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Ellipsoid3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Ellipsoid3 GetEllipsoid() const;

		// The intersection set.  The ellipsoid is considered a solid, so if the
		// segment is stricly inside the ellipsoid, the intersection type is
		// IT_SEGMENT and the function GetPoint(i) returns the segment end
		// points.  If you want the ellipsoid to be only the surface itself, and
		// you want a "no intersection" result when the segment is strictly
		// inside the ellipsoid, just compare the segment end points to the
		// values from GetPoint(i) whenever IT_SEGMENT is the type.  If they
		// are the same, consider this a "no intersection".
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection queries.
		void Find();

		// The objects to intersect.
		Segment3 m_Segment;
		Ellipsoid3 mEllipsoid;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorSegment3Ellipsoid3 = StaticFindIntersectorSegment3Ellipsoid3<float>;
	using DoubleStaticFindIntersectorSegment3Ellipsoid3 = StaticFindIntersectorSegment3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_H
