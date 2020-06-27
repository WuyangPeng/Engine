// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_H 

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h" 
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay2Segment2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorRay2Segment2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold = Math::sm_ZeroTolerance, const Real intervalThreshold = Math::sm_Zero);
		virtual ~StaticTestIntersectorRay2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray2 GetRay() const;
		const Segment2 GetSegment() const;

		// 相交测试使用线段的中心-范围形式。 
		// 如果从端点（Vector2D<Real>）开始并创建 Segment2<Real>对象，
		// 则到中心-范围格式的转换可能包含小的数字舍入误差。
		// 测试相交一个端点的两个线段的交集可能由于舍入误差而导致失败。
		// 为此，您可以指定一个小的正阈值，稍微放大线段的间隔。 默认值为零。
		Real GetIntervalThreshold() const;

		// 相交集。让 q = GetQuantity()。情况是：	 
		//   q = 0: 线段不相交， GetIntersection() 返回IntersectionType::Empty。
		//   q = 1: 线段相交于一个点。GetIntersection()返回IntersectionType::Point。
		//   q = 2: 线段是重叠的且相交是线段。 
		//          GetIntersection()返回IntersectionType::Segment。 		
		int GetQuantity() const;

	private:
		// 静态查找相交查询。
		void Test();

	private:
		// 要相交的对象。
		Ray2 m_Ray;
		Segment2 m_Segment;

		// 相交集
		int m_Quantity;

		Real m_IntervalThreshold;
	};

	using StaticTestIntersectorRay2Segment2f = StaticTestIntersectorRay2Segment2<float>;
	using StaticTestIntersectorRay2Segment2d = StaticTestIntersectorRay2Segment2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_H
