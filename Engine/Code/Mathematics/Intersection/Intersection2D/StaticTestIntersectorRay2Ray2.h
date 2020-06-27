// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:41)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H 

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay2Ray2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorRay2Ray2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold = Math::sm_ZeroTolerance);
		virtual ~StaticTestIntersectorRay2Ray2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray2 GetLhsRay() const;
		const Ray2 GetRhsRay() const;

		// 相交集。让 q = GetQuantity()。情况是：	
		//   q = 0: 射线不相交， GetIntersection() 返回IntersectionType::Empty。
		//   q = 1: 射线相交于一个点。GetIntersection()返回IntersectionType::Point。	
		//   q = 2: 射线是重叠的且相交是线段。 这种情况只发生在D1 = -D0。
		//          GetIntersection()返回IntersectionType::Segment。 	
		//   q = INT_MAX:  射线是重叠的且相交是射线。
		//                 这种情况只发生在D1 = D0。
		//                 GetIntersection()返回IntersectionType::Ray。 
		int GetQuantity() const;

	private:
		void Test();

	private:
		// 要相交的对象。
		Ray2 m_LhsRay;
		Ray2 m_RhsRay;

		// 相交集
		int m_Quantity;
	};

	using StaticTestIntersectorRay2Ray2f = StaticTestIntersectorRay2Ray2<float>;
	using StaticTestIntersectorRay2Ray2d = StaticTestIntersectorRay2Ray2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
