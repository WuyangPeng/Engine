// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 18:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_H 

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Segment2.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class StaticTestIntersectorSegment2Segment2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorSegment2Segment2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;
		
	public:
		StaticTestIntersectorSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment,const Real dotThreshold = Math::sm_ZeroTolerance,const Real intervalThreshold = Real{});
		virtual ~StaticTestIntersectorSegment2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Segment2 GetLhsSegment() const;
		const Segment2 GetRhsSegment() const;
		 
		// �ཻ����ʹ���߶ε�����-��Χ��ʽ�� 
		// ����Ӷ˵㣨Vector2D<Real>����ʼ������ Segment2<Real>����
		// ������-��Χ��ʽ��ת�����ܰ���С������������
		// �����ཻһ���˵�������߶εĽ�����������������������ʧ�ܡ�
		// Ϊ�ˣ�������ָ��һ��С������ֵ����΢�Ŵ��߶εļ���� Ĭ��ֵΪ�㡣
		Real GetIntervalThreshold() const;

		// �ཻ������ q = GetQuantity()������ǣ�	 
		//   q = 0: �߶β��ཻ�� GetIntersection() ����IntersectionType::Empty��
		//   q = 1: �߶��ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
		//   q = 2: �߶����ص������ཻ���߶Ρ� 
		//          GetIntersection()����IntersectionType::Segment�� 
		int GetQuantity() const;

	private:
		// ��̬�����ཻ��ѯ��
		void Test ();   

	private:
		// Ҫ�ཻ�Ķ���
		Segment2 m_LhsSegment;
		Segment2 m_RhsSegment;

		// �ཻ��
		int m_Quantity;
 
		Real m_IntervalThreshold; 
	};

	using StaticTestIntersectorSegment2Segment2f = StaticTestIntersectorSegment2Segment2<float>;
	using StaticTestIntersectorSegment2Segment2d = StaticTestIntersectorSegment2Segment2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_H
