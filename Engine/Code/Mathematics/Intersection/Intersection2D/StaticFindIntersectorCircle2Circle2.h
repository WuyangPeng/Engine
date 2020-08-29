// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Objects2D/Circle2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorCircle2Circle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorCircle2Circle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Circle2 = Circle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorCircle2Circle2(const Circle2& lhsCircle, const Circle2& rhsCircle, const Real epsilon = Math::GetZeroTolerance());
		virtual ~StaticFindIntersectorCircle2Circle2();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Circle2 GetLhsCircle() const;
		const Circle2 GetRhsCircle() const;

		// �ཻ��Ϊ��̬�����ཻ��ѯ��
		// m_Point.size()Ϊ0,1��2��
		// ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
		//   IntersectionType::Point:  m_Point ��ͬ���ཻ��
		//   IntersectionType::Other:  Բ��һ���ġ�����һ��Բ������GetIntersectionCircle���ء�
		//   m_Point����Ч�ġ� 	
		int GetQuantity() const;
		const Vector2D GetPoint(int index) const;
		const Circle2 GetIntersectionCircle() const;

	private:
		void Find();

	private:
		// Ҫ�ཻ�Ķ���
		Circle2 m_LhsCircle;
		Circle2 m_RhsCircle;

		// �ཻ�㡣	
		std::vector<Vector2D> m_Point;
	};

	using StaticFindIntersectorCircle2Circle2f = StaticFindIntersectorCircle2Circle2<float>;
	using StaticFindIntersectorCircle2Circle2d = StaticFindIntersectorCircle2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H
