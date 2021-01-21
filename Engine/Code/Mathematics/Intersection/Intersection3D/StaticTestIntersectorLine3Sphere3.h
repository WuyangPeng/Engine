// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Sphere3.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorLine3Sphere3(const Line3& line, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Sphere3 GetSphere() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Line3 m_Line;
		Sphere3 m_Sphere;
	};

	using FloatStaticTestIntersectorLine3Sphere3 = StaticTestIntersectorLine3Sphere3<float>;
	using DoubleStaticTestIntersectorLine3Sphere3 = StaticTestIntersectorLine3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_SPHERE3_H
