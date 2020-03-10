// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/11 16:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Arc2.h" 
#include "Mathematics/Objects2D/Circle2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorArc2Circle2 : public StaticIntersector<Real, Vector2D>		
	{
	public:
		using ClassType = StaticFindIntersectorArc2Circle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Circle2 = Circle2<Real>;
		using Arc2 = Arc2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>; 
		
	public:
		StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle,const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticFindIntersectorArc2Circle2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Arc2 GetArc() const;
		const Circle2 GetCircle() const;

		// 相交集为静态查找相交查询。
		// m_Point.size()为0,1或2。
		// 当0 < m_Point.size()时，解释取决于相交类型。
		//   IntersectionType::Point:  m_Point 不同的相交点
		//   IntersectionType::Other:  圆弧在圆上。相交弧由GetIntersectionArc()返回。
		//   m_Point是无效的。
		int GetQuantity() const;
		const Vector2D GetPoint(int index) const;
		const Arc2 GetIntersectionArc() const;

	private:
		// 静态查找相交查询。
		void Find();

	private:
		// 要相交的对象。
		Arc2 m_Arc;
		Circle2 m_Circle;

		// 相交集
		std::vector<Vector2D> m_Point;
	};

	using StaticFindIntersectorArc2Circle2f = StaticFindIntersectorArc2Circle2<float>;
	using StaticFindIntersectorArc2Circle2d = StaticFindIntersectorArc2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
