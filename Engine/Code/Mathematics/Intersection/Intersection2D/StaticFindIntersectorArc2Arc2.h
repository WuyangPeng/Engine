// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Arc2.h" 
#include "Mathematics/Objects2D/Objects2DFwd.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorArc2Arc2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorArc2Arc2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Circle2 = Circle2<Real>;
		using Arc2 = Arc2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorArc2Arc2(const Arc2& lhsArc, const Arc2& rhsArc, const Real epsilon = Math::GetZeroTolerance());
		virtual ~StaticFindIntersectorArc2Arc2();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Arc2 GetLhsArc() const;
		const Arc2 GetRhsArc() const;

		// 相交集为静态查找相交查询。
		// m_Point的大小为0,1或2。
		// 当0 < m_Point.size()时，解释取决于相交类型。
		//   IntersectionType::Point:  不同的相交点
		//   IntersectionType::Other:  圆弧重叠点超过一点。 
		// 相交弧由GetIntersectionArc()。 m_Point是无效的。
		int GetQuantity() const;
		const Vector2D GetPoint(int index) const;
		const Arc2 GetIntersectionArc() const;

	private:
		// 静态查找相交查询。
		void Find();

	private:
		// 要相交的对象。
		Arc2 m_LhsArc;
		Arc2 m_RhsArc;

		// 相交集
		std::vector<Vector2D> m_Point;
		Arc2 m_IntersectionArc;
	};

	using StaticFindIntersectorArc2Arc2f = StaticFindIntersectorArc2Arc2<float>;
	using StaticFindIntersectorArc2Arc2d = StaticFindIntersectorArc2Arc2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
