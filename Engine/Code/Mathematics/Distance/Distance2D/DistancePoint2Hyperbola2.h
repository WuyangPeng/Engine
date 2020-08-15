// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 15:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Algebra/Vector2D.h"  
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	// 计算(x0,y0)与标准双曲线F(x,y) = (x/a)^2 - (y/b)^2 - 1 = 0之间的距离
	// 其中a> 0且b> 0。 考虑当(x0,y0)在第一象限中时的情况，所以x0 >= 0 和 y0 >= 0。
	// 最近的点(x,y)也在第一象限中。 
	// 在几何，向量D =D = (x0-x,y0-y)必须垂直于(x,y)处的双曲线。
	// 法线是N = 梯度(Q)/2 =(x / a^2,-y / b^2)。

	// 解决方案1（简化为四次多项式）：
	// 因为D和N是平行的，所以导致等式G(x,y) = (x0-x)*y/b^2 + (y0-y)*x/a^2 = 0。
	// 可以从两个方程F(x,y) = 0 和G(x,y) = 0中消除变量y，	
	//   P(x) = c0 + c1*x + c2*x^2 + c3*x^3 + c4*x^4 = 0
	// 这里
	//   c0 = -a^6*x0^2
	//   c1 = 2*a^4*(a^2+b^2)*x0,
	//   c2 = -a^2*((a^2+b^2)^2 - a^2*x0^2 + b^2*y0^2)
	//   c3 = -2*a*(a^2+b^2)*x0
	//   c4 = (a^2+b^2)^2
	// 您可以计算P(x) = 0的根。对于每个根对于x = r，y = s求解F(r,y) = 0。 
	// 计算从 (x0,y0)到(r,s)的距离。 在从这样的(r,s)的所有距离中，
	// 选择最小距离作为从(x0,y0)到双曲线的距离。
	// 数值上，根查找不健壮，因此要谨慎使用此算法。

	// 解决方案2（稳健）：
	// 因为D和N是平行的，所以必须存在D = t*N的标量t;
	// 即(x0-x,y0-y) = t*(x/a^2,-y/b^2)。
	// 虽然在算法中不需要，通过几何：sign(t) = sign(F(x0,y0))。 一些代数导致
	//   (x,y) = x0/(1 + t/a^2), y0/(1 - t/b^2))
	// 知道(x,y)在第一象限中，t值必须满足-a^2 <= t <= b^2。 
	// 将 (x,y) 代入F(x,y) = 0导致H(t) = x0^2/(1 + t/a^2)^2 - y0^2/(1 - t/b^2)^2 - 1 = 0。
	// H(t)的图在t = -a^2和t = b^2处具有垂直渐近线。
	// 我们只关心图的-a^2 <= t <= b^2。 
	// 注意，当t从右边接近-a^2时，H（t）变为+无穷大。
	// 当t从左边接近b^2时，H（t）变为-无穷大。
	// 导数H'(t)最多在一次项为零;
	// 事实上，你可以解开闭合形式的H'(t) = 0。 
	// 该条件和在渐近线处的H(t)的行为保证H(t)是 -a^2 <= t <= b^2的递减函数，
	// 在这种情况下H(t) = 0具有唯一根 在此间隔。
	// 因此，您可以使用二分法来鲁棒地计算根。 这是我们使用的实现。	 
	template <typename Real>
	class DistancePoint2Hyperbola2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistancePoint2Hyperbola2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 
		using Math = Math<Real>;

	public:
		DistancePoint2Hyperbola2(const Vector2D& point, const Vector2D& extent);
		virtual ~DistancePoint2Hyperbola2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector2D GetPoint() const;
		const Vector2D GetExtent() const;

		// 静态距离查询。
		  const DistanceResult GetSquared() const override;

		// 函数计算动态距离查询。	
		  const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Real GetHyperbola(Real t, const Vector2D&  reciprocalExtentSquared) const;

	private:
		Vector2D m_Point;
		Vector2D m_Extent;
	};

	using DistancePoint2Hyperbola2f = DistancePoint2Hyperbola2<float>;
	using DistancePoint2Hyperbola2d = DistancePoint2Hyperbola2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_H
