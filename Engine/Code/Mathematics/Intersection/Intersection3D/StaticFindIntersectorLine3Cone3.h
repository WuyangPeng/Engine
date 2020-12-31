// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Cone3.h"  
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Cone3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Cone3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Cone3 = Cone3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorLine3Cone3(const Line3& line, const Cone3& cone);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Cone3 GetCone() const;

		// The intersection set.  The possible intersection types are
		//   IT_EMTPY:   no intersection
		//   IT_POINT:   point[0] is the intersection point
		//   IT_SEGMENT: <point[0],point[1]> is the intersection segment
		//   IT_RAY:     point[0]+t*point[1] is the intersection ray
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Line3 mLine;
		Cone3 mCone;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorLine3Cone3 = StaticFindIntersectorLine3Cone3<float>;
	using DoubleStaticFindIntersectorLine3Cone3 = StaticFindIntersectorLine3Cone3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
