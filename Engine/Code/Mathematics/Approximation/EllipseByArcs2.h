// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 12:28)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
	// 椭圆为(x/a)^2 + (y/b)^2 = 1，
	// 但仅在第一象限中的部分(x >= 0 and y >= 0)近似。
	// 生成numArcs >= 2 的弧构造对应于所述曲率在
	// 椭圆点(a,0) 和 (0,b)的加权平均值中。
	// 返回的输入点数组有numArcs+1个元素和
	// 返回输入圆心和半径每个数组有numArc元素。
	// m_Points[i]和m_Points[i+1]相关联的弧
	// 具有中心m_Center[i]和半径的m_Radius[i]。

	template <typename Real>
	class EllipseByArcs2
	{
	public:
		using ClassType = EllipseByArcs2<Real>;
		using Vector2D = Vector2D<Real>;
		using Arc2 = Arc2<Real>;
		using Circle2 = Circle2<Real>;

	public:
		EllipseByArcs2(Real begin, Real end, size_t numArcs);

		CLASS_INVARIANT_DECLARE;

		const std::vector<Vector2D> GetPoints() const;
		const std::vector<Circle2> GetCircle2() const;

		const Arc2 GetArc2(int index) const;
		int getNumArcs() const;

	private:
		void Calculate(Real begin, Real end);

	private:
		std::vector<Vector2D> m_Points;
		std::vector<Circle2> m_Circle;
	};

	using EllipseByArcs2d = EllipseByArcs2<double>;
	using EllipseByArcs2f = EllipseByArcs2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_H
