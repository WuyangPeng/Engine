// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 16:27)

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

		// �ཻ������ q = GetQuantity()������ǣ�	
		//   q = 0: �߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
		//   q = 1: ���ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
		//          �����ཻ��ʹ��GetPoint()��
		//   q = INT_MAX:  �����ص��ġ�GetIntersection() ����IntersectionType::Line�� 
		int GetQuantity() const;
		const Vector2D GetPoint() const;

	private:
		void Find();

		// Ҫ�ཻ�Ķ���
		Line2 m_LhsLine;
		Line2 m_RhsLine;

		// �ཻ��
		int m_Quantity;
		Vector2D m_Point;
	}; 

	using StaticFindIntersectorLine2Line2f = StaticFindIntersectorLine2Line2<float>;
	using StaticFindIntersectorLine2Line2d = StaticFindIntersectorLine2Line2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
