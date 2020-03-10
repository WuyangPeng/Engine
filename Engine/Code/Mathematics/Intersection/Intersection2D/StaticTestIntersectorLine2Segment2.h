// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 18:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H 

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class StaticTestIntersectorLine2Segment2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorLine2Segment2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;
		  
		
		
	public:
		StaticTestIntersectorLine2Segment2(const Line2& line, const Segment2& segment,const Real dotThreshold = Math::sm_ZeroTolerance,const Real intervalThreshold = Real{});
		virtual ~StaticTestIntersectorLine2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

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
		//   q = 2: ֱ��-�߶����ص������ཻ���߶Ρ� 
		//          GetIntersection()����IntersectionType::Segment�� 	
		int GetQuantity() const;

	private:
		// ��̬�����ཻ��ѯ��
		void Test ();   

	private:
		// Ҫ�ཻ�Ķ���
		Line2 m_Line;
		Segment2 m_Segment;

		// �ཻ��
		int m_Quantity;
 
		Real m_IntervalThreshold; 
	};

	using StaticTestIntersectorLine2Segment2f = StaticTestIntersectorLine2Segment2<float>;
	using StaticTestIntersectorLine2Segment2d = StaticTestIntersectorLine2Segment2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H
