// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/11 16:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class StaticFindIntersectorLine2Line2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorLine2Line2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>; 
		
	public:
		StaticFindIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold = Math::sm_ZeroTolerance);
		virtual ~StaticFindIntersectorLine2Line2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Line2 GetLhsLine() const;
		const Line2 GetRhsLine() const;

		// 相交集。让 q = GetQuantity()。情况是：	
		//   q = 0: 线不相交， GetIntersection() 返回IntersectionType::Empty。
		//   q = 1: 线相交于一个点。GetIntersection()返回IntersectionType::Point。
		//          访问相交点使用GetPoint()。
		//   q = INT_MAX:  线是重叠的。GetIntersection() 返回IntersectionType::Line。 
		int GetQuantity() const;
		const Vector2D GetPoint() const;

	private:
		void Find();

		// 要相交的对象。
		Line2 m_LhsLine;
		Line2 m_RhsLine;

		// 相交集
		int m_Quantity;
		Vector2D m_Point;
	}; 

	using StaticFindIntersectorLine2Line2f = StaticFindIntersectorLine2Line2<float>;
	using StaticFindIntersectorLine2Line2d = StaticFindIntersectorLine2Line2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
