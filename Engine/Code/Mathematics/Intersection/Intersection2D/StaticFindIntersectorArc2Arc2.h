// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:34)

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

		// �ཻ��Ϊ��̬�����ཻ��ѯ��
		// m_Point�Ĵ�СΪ0,1��2��
		// ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
		//   IntersectionType::Point:  ��ͬ���ཻ��
		//   IntersectionType::Other:  Բ���ص��㳬��һ�㡣 
		// �ཻ����GetIntersectionArc()�� m_Point����Ч�ġ�
		int GetQuantity() const;
		const Vector2D GetPoint(int index) const;
		const Arc2 GetIntersectionArc() const;

	private:
		// ��̬�����ཻ��ѯ��
		void Find();

	private:
		// Ҫ�ཻ�Ķ���
		Arc2 m_LhsArc;
		Arc2 m_RhsArc;

		// �ཻ��
		std::vector<Vector2D> m_Point;
		Arc2 m_IntersectionArc;
	};

	using StaticFindIntersectorArc2Arc2f = StaticFindIntersectorArc2Arc2<float>;
	using StaticFindIntersectorArc2Arc2d = StaticFindIntersectorArc2Arc2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
