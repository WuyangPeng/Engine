// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/11 18:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H 

#include "Mathematics/Objects2D/Ray2.h" 
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class StaticTestIntersectorLine2Ray2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorLine2Ray2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Ray2 = Ray2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;
		
	public:
		StaticTestIntersectorLine2Ray2(const Line2& line, const Ray2& ray,const Real dotThreshold = Math::sm_ZeroTolerance);
		virtual ~StaticTestIntersectorLine2Ray2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
 
		// 成员访问
		const Line2 GetLine () const;
		const Ray2 GetRay () const;

		// 相交集。让 q = GetQuantity()。情况是：
		//   q = 0: 线和射线不相交， GetIntersection() 返回IntersectionType::Empty。
		//   q = 1: 线和射线相交于一个点。GetIntersection()返回IntersectionType::Point。	
		//   q = INT_MAX:  线和射线是重叠的。GetIntersection() 返回IntersectionType::Line。 
		int GetQuantity() const;

	private:
		// 静态相交查找查询。
		void Test ();

	private:
		// 要相交的对象。
		Line2 m_Line;
		Ray2 m_Ray;

		// 相交集信息
		int m_Quantity;		
	};

	using StaticTestIntersectorLine2Ray2f = StaticTestIntersectorLine2Ray2<float>;
	using StaticTestIntersectorLine2Ray2d = StaticTestIntersectorLine2Ray2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
