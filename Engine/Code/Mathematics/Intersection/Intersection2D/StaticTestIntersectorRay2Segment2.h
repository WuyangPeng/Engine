// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_H 

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h" 
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay2Segment2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorRay2Segment2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold = Math::sm_ZeroTolerance, const Real intervalThreshold = Math::sm_Zero);
		virtual ~StaticTestIntersectorRay2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray2 GetRay() const;
		const Segment2 GetSegment() const;

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
		void Test();

	private:
		// Ҫ�ཻ�Ķ���
		Ray2 m_Ray;
		Segment2 m_Segment;

		// �ཻ��
		int m_Quantity;

		Real m_IntervalThreshold;
	};

	using StaticTestIntersectorRay2Segment2f = StaticTestIntersectorRay2Segment2<float>;
	using StaticTestIntersectorRay2Segment2d = StaticTestIntersectorRay2Segment2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_H
