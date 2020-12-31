// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Torus3.h" 
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class  StaticFindIntersectorLine3Torus3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Torus3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Torus3 = Torus3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorLine3Torus3(const Line3& line, const Torus3& torus);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Torus3 GetTorus() const;

		// The intersection set (quantity is at most 4).
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Line3 mLine;
		Torus3 mTorus;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[4];
	};

	using FloatStaticFindIntersectorLine3Torus3 = StaticFindIntersectorLine3Torus3<float>;
	using DoubleStaticFindIntersectorLine3Torus3 = StaticFindIntersectorLine3Torus3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H
