// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 16:19)

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

		// �ཻ��Ϊ��̬�����ཻ��ѯ��
		// m_Point.size()Ϊ0,1��2��
		// ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
		//   IntersectionType::Point:  m_Point ��ͬ���ཻ��
		//   IntersectionType::Other:  Բ����Բ�ϡ��ཻ����GetIntersectionArc()���ء�
		//   m_Point����Ч�ġ�
		int GetQuantity() const;
		const Vector2D GetPoint(int index) const;
		const Arc2 GetIntersectionArc() const;

	private:
		// ��̬�����ཻ��ѯ��
		void Find();

	private:
		// Ҫ�ཻ�Ķ���
		Arc2 m_Arc;
		Circle2 m_Circle;

		// �ཻ��
		std::vector<Vector2D> m_Point;
	};

	using StaticFindIntersectorArc2Circle2f = StaticFindIntersectorArc2Circle2<float>;
	using StaticFindIntersectorArc2Circle2d = StaticFindIntersectorArc2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
