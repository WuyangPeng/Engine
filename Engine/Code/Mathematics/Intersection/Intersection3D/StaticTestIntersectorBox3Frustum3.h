// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Frustum3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorBox3Frustum3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorBox3Frustum3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Frustum3 = Frustum3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorBox3Frustum3(const Box3& box, const Frustum3& frustum);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Box3 GetBox() const;
                [[nodiscard]] const Frustum3 GetFrustum() const;

	private:
		// Test-intersection query.
		void Test();

	private:
		// The objects to intersect.
		Box3 m_Box;
		Frustum3 mFrustum;
	};

	using FloatStaticTestIntersectorBox3Frustum3 = StaticTestIntersectorBox3Frustum3<float>;
	using DoubleStaticTestIntersectorBox3Frustum3 = StaticTestIntersectorBox3Frustum3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H
