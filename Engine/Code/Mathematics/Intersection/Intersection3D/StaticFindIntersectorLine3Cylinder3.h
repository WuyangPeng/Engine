// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Cylinder3.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Cylinder3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Cylinder3 = Cylinder3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorLine3Cylinder3(const Line3& line, const Cylinder3& cylinder);

	CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Line3 GetLine() const;
        [[nodiscard]] const Cylinder3 GetCylinder() const;

		// The intersection set.
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Line3 mLine;
		Cylinder3 mCylinder;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];

	public:
		// Shared by IntrRay3Cylinder3 and IntrSegment3Cylinder3.
            [[nodiscard]] static int Find(const Vector3D& origin, const Vector3D& dir, const Cylinder3& cylinder, Real t[2]);
	};

	using FloatStaticFindIntersectorLine3Cylinder3 = StaticFindIntersectorLine3Cylinder3<float>;
	using DoubleStaticFindIntersectorLine3Cylinder3 = StaticFindIntersectorLine3Cylinder3<double>;

}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
