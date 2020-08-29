// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:36)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h" 

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"  
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine2Segment2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorLine2Segment2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorLine2Segment2(const Line2& line, const Segment2& segment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::sm_Zero);
		virtual ~StaticFindIntersectorLine2Segment2();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Line2 GetLine() const;
		const Segment2 GetSegment() const;

		// �ཻ����ʹ���߶ε�����-��Χ��ʽ�� 
		// ����Ӷ˵㣨Vector2D<Real>����ʼ������ Segment2<Real>����
		// ������-��Χ��ʽ��ת�����ܰ���С������������
		// �����ཻһ���˵�������߶εĽ�����������������������ʧ�ܡ�
		// Ϊ�ˣ�������ָ��һ��С������ֵ����΢�Ŵ��߶εļ���� Ĭ��ֵΪ�㡣		
		Real GetIntervalThreshold() const;

		// �ཻ������ q = GetQuantity()������ǣ�	 
		//   q = 0: ֱ��-�߶β��ཻ�� GetIntersection() ����IntersectionType::Empty��
		//   q = 1: ֱ��-�߶��ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
		//          �����ཻ��ʹ��GetPoint(0)��
		//   q = 2: ֱ��-�߶����ص������ཻ���߶Ρ� 
		//          GetIntersection()����IntersectionType::Segment�� 	
		int GetQuantity() const;
		const Vector2D GetPoint() const;

	private:
		// ��̬�����ཻ��ѯ��
		void Find();

	private:
		// Ҫ�ཻ�Ķ���
		Line2 m_Line;
		Segment2 m_Segment;

		// �ཻ��
		int m_Quantity;

		Real m_IntervalThreshold;
		Vector2D m_Point;
	};

	using StaticFindIntersectorLine2Segment2f = StaticFindIntersectorLine2Segment2<float>;
	using StaticFindIntersectorLine2Segment2d = StaticFindIntersectorLine2Segment2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_H
