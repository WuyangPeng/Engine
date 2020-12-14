// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 16:15)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX2_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class ContBox2
	{
	public:
		using ClassType = ContBox2<Real>;
		using Vector2D = Vector2D<Real>;
		using Points = std::vector<Vector2D>;
		using Box2 = Box2<Real>;
		using Math = Math<Real>;

	public:
		ContBox2();

		CLASS_INVARIANT_DECLARE;

	public:
		// ��������С��������Χ�С�
		static const Box2 ContAlignedBox(const Points& points);

		// �����Ķ���߽�򡣰�Χ�������ǵ��ƽ��ֵ��
		// ��Χ�е�����Э������������������
		static const Box2 ContOrientedBox(const Points& points);

		// ���������
		// ��X = C + y0 * U0 + y1 * U1������C�ǰ�Χ�е����ĺ�U0��U1�Ǻ��ӵ������ᡣ
		// ���|y_i| <= E_i ,���������i�ڿ��У�����E_i�ǰ�Χ�еķ�Χ��
		static bool InBox(const Vector2D& point, const Box2& box);

		// ��������������������Χ�еĶ����Χ�С�
		// �������ܱ�֤�ǰ��������Χ�е���С�����Χ�С�
		static const Box2 MergeBoxes(const Box2& lhs, const Box2& rhs);
	};

	using ContBox2d = ContBox2<double>;
	using ContBox2f = ContBox2<float>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_BOX2_H
