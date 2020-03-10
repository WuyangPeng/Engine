// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 16:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h" 
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class StaticFindIntersectorLine2Ray2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorLine2Ray2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Ray2 = Ray2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>; 
		
	public:
		StaticFindIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold = Math::sm_ZeroTolerance);
		virtual ~StaticFindIntersectorLine2Ray2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
 
		// ��Ա����
		const Line2 GetLine () const;
		const Ray2 GetRay () const;

		// �ཻ������ q = GetQuantity()������ǣ�
		//   q = 0: �ߺ����߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
		//   q = 1: �ߺ������ཻ��һ���㡣GetIntersection()����IntersectionType::Point��	
		//          �����ཻ��ʹ��GetPoint(0)��
		//   q = INT_MAX:  �ߺ��������ص��ġ�GetIntersection() ����IntersectionType::Line�� 
		int GetQuantity() const;
		const Vector2D GetPoint() const;

	private:
		// ��̬�ཻ���Ҳ�ѯ��
		void Find ();

	private:
		// Ҫ�ཻ�Ķ���
		Line2 m_Line;
		Ray2 m_Ray;

		// �ཻ����Ϣ
		int m_Quantity;	
		Vector2D m_Point;
	};

	using StaticFindIntersectorLine2Ray2f = StaticFindIntersectorLine2Ray2<float>;
	using StaticFindIntersectorLine2Ray2d = StaticFindIntersectorLine2Ray2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_H
