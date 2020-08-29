// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H 

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine2Line2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorLine2Line2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold = Math::GetZeroTolerance());
		virtual ~StaticTestIntersectorLine2Line2();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Line2 GetLhsLine() const;
		const Line2 GetRhsLine() const;

		// �ཻ������ q = GetQuantity()������ǣ�	
		//   q = 0: �߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
		//   q = 1: ���ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
		//   q = INT_MAX:  �����ص��ġ�GetIntersection() ����IntersectionType::Line�� 
		int GetQuantity() const;

	private:
		void Test();

		// Ҫ�ཻ�Ķ���
		Line2 m_LhsLine;
		Line2 m_RhsLine;

		// �ཻ��
		int m_Quantity;
	};

	using StaticTestIntersectorLine2Line2f = StaticTestIntersectorLine2Line2<float>;
	using StaticTestIntersectorLine2Line2d = StaticTestIntersectorLine2Line2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H
