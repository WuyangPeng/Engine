// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorLine3Box3(const Line3& line, const Box3& box);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Box3 GetBox() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Line3 mLine;
		Box3 m_Box;
	};

	using FloatStaticTestIntersectorLine3Box3 = StaticTestIntersectorLine3Box3<float>;
	using DoubleStaticTestIntersectorLine3Box3 = StaticTestIntersectorLine3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_H
