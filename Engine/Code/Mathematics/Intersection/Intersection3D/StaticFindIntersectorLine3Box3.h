// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Line3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorLine3Box3(const Line3& line, const Box3& box);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Box3 GetBox() const;

		// The intersection set.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection queries.
		void Find();

	 [[nodiscard]] static bool Clip(Real denom, Real numer, Real& t0, Real& t1);

		// The objects to intersect.
		Line3 mLine;
		Box3 m_Box;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];

	public:
		// Shared by IntrRay3Box3 and IntrSegment3Box3.
            [[nodiscard]] static bool DoClipping(Real t0, Real t1, const Vector3D& origin, const Vector3D& direction, const Box3& box, bool solid, int& quantity, Vector3D point[2], int& intrType);
	};

	using FloatStaticFindIntersectorLine3Box3 = StaticFindIntersectorLine3Box3<float>;
	using DoubleStaticFindIntersectorLine3Box3 = StaticFindIntersectorLine3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
