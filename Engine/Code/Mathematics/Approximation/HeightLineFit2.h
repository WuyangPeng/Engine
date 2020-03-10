// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:12)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H

#include "Mathematics/MathematicsDll.h"
 
#include "Mathematics/Objects2D/Line2.h"

#include <vector>

namespace Mathematics
{
	// 最小二乘平方拟合到线到(x,f(x)) 通过使用在y方向上的距离测量数据。
	// 由此产生的线由 y = A * x + B.	
	template <typename Real>
	class HeightLineFit2
	{
	public:
		using ClassType = HeightLineFit2<Real>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;

	public:
		explicit HeightLineFit2(const std::vector<Vector2D>& points);
 
		CLASS_INVARIANT_DECLARE;

		// 如果在定义A和B是（几乎）奇异线性方程组2x2的系数矩阵。
		// 返回值是false。
		// 在这种情况下，访问A和B会抛出异常。
		bool IsFit2Success() const;

		Real GetCoeffA() const;
		Real GetCoeffB() const;

	private:
		void Calculate(const std::vector<Vector2D>& points);

	private:
		Real m_CoeffA;
		Real m_CoeffB;
		bool m_IsFit2Success;
	};

	using HeightLineFit2d = HeightLineFit2<double>;
	using HeightLineFit2f = HeightLineFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_H
