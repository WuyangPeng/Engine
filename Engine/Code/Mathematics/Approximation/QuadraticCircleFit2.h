// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 12:32)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

#include <vector>

namespace Mathematics
{
	// 如果你觉得你的点几乎是圆形的，使用这个。
	// 圆的形式C'[0]+C'[1]*X+C'[2]*Y+C'[3]*(X^2+Y^2)，
	// 其中Length(C') = 1
	// 该函数返回C = (C'[0]/C'[3],C'[1]/C'[3],C'[2]/C'[3])，
	// 所以拟合圆是C[0]+C[1]*X+C[2]*Y+X^2+Y^2。
	// 该中心是(xc,yc) = -0.5*(C[1],C[2])和
	// 半径为r = sqrt(xc*xc+yc*yc-C[0])。
	template <typename Real>
	class QuadraticCircleFit2
	{
	public:
		using ClassType = QuadraticCircleFit2<Real>;
		using Vector2D = Vector2D<Real>;

	public:
		explicit QuadraticCircleFit2(const std::vector<Vector2D>& points);

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetCenter() const;
		Real GetRadius() const;
		Real GetEigenValue() const;

	private:
		void Calculate(const std::vector<Vector2D>& points);

	private:
		constexpr static auto sm_EigenSystemSize = 4;

	private:
		Vector2D m_Center;
		Real m_Radius;
		Real m_EigenValue;
	};

	using QuadraticCircleFit2d = QuadraticCircleFit2<double>;
	using QuadraticCircleFit2f = QuadraticCircleFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_H
