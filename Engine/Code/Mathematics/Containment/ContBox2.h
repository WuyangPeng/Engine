// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 16:15)

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
		// 计算点的最小的轴对齐包围盒。
		static const Box2 ContAlignedBox(const Points& points);

		// 计算点的定向边界框。包围盒中心是点的平均值。
		// 包围盒的轴是协方差矩阵的特征向量。
		static const Box2 ContOrientedBox(const Points& points);

		// 试验包含。
		// 设X = C + y0 * U0 + y1 * U1，其中C是包围盒的中心和U0和U1是盒子的正交轴。
		// 如果|y_i| <= E_i ,则对于所有i在框中，这里E_i是包围盒的范围。
		static bool InBox(const Vector2D& point, const Box2& box);

		// 构造包含另外两个定向包围盒的定向包围盒。
		// 其结果不能保证是包含输入包围盒的最小体积包围盒。
		static const Box2 MergeBoxes(const Box2& lhs, const Box2& rhs);
	};

	using ContBox2d = ContBox2<double>;
	using ContBox2f = ContBox2<float>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_BOX2_H
