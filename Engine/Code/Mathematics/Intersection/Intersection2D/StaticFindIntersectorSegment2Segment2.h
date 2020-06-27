// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_H 

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Objects2D/Segment2.h" 
#include "Mathematics/Intersection/StaticIntersector.h"

#include <array>

namespace Mathematics
{ 
	template <typename Real>
	class StaticFindIntersectorSegment2Segment2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment2Segment2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment, const Real dotThreshold = Math::sm_ZeroTolerance, const Real intervalThreshold = Math::sm_Zero);
		virtual ~StaticFindIntersectorSegment2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Segment2 GetLhsSegment() const;
		const Segment2 GetRhsSegment() const;

		// 相交测试使用线段的中心-范围形式。 
		// 如果从端点（Vector2D<Real>）开始并创建 Segment2<Real>对象，
		// 则到中心-范围格式的转换可能包含小的数字舍入误差。
		// 测试相交一个端点的两个线段的交集可能由于舍入误差而导致失败。
		// 为此，您可以指定一个小的正阈值，稍微放大线段的间隔。 默认值为零。
		Real GetIntervalThreshold() const;

		// 相交集。让 q = GetQuantity()。情况是：	 
		//   q = 0: 线段不相交， GetIntersection() 返回IntersectionType::Empty。
		//   q = 1: 线段相交于一个点。GetIntersection()返回IntersectionType::Point。
		//          访问相交点使用GetPoint(0)。
		//   q = 2: 线段是重叠的且相交是线段。 
		//          GetIntersection()返回IntersectionType::Segment。 
		//          访问相交线段终点使用GetPoint(0)和GetPoint(1)。
		int GetQuantity() const;
		const Vector2D GetPoint(int index) const;

	private:
		// 静态查找相交查询。
		void Find();

	private:
		// 要相交的对象。
		Segment2 m_LhsSegment;
		Segment2 m_RhsSegment;

		// 相交集
		int m_Quantity;

		Real m_IntervalThreshold;
		std::array<Vector2D, 2> m_Point;
	};

	using StaticFindIntersectorSegment2Segment2f = StaticFindIntersectorSegment2Segment2<float>;
	using StaticFindIntersectorSegment2Segment2d = StaticFindIntersectorSegment2Segment2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_H
