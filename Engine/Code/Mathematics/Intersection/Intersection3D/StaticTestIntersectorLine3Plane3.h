// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:54)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Plane3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorLine3Plane3(const Line3& line, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance());
		virtual ~StaticTestIntersectorLine3Plane3();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Plane3 GetPlane() const;

	private:
		void Test();

	private:
		// �ཻ����
		Line3 m_Line;
		Plane3 m_Plane;
	};

	using FloatStaticTestIntersectorLine3Plane3 = StaticTestIntersectorLine3Plane3<float>;
	using DoubleStaticTestIntersectorLine3Plane3 = StaticTestIntersectorLine3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_H
