// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:04)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    // 对一组点的最小二次拟合圆。
    // 如果迭代的次数已超过maxIterations，触发一个断言。尝试增加迭代的最大数量。
    // 如果initialCenterIsAverage被设置为“真”，
    // 圆心的初始值猜测是数据点的平均值。
    // 如果数据点沿着一条小弧簇，CircleFit2是收敛速度很慢。
    // 如果initialCenterIsAverage被设置为“假”，
    // 圆心的初始值猜测使用一个二次方程，
    // 表示一个圆的系数的最小二乘法来估算。
    // 这种做法往往会迅速收敛。
    template <typename Real>
    class CircleFit2
    {
    public:
        using ClassType = CircleFit2<Real>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        
    public:
        CircleFit2(const std::vector<Vector2D>& points,int maxIterations,bool initialCenterIsAverage);
        
      CLASS_INVARIANT_DECLARE;
        
        const Circle2 GetCircle() const;
        
    private:
        void Calculate(const std::vector<Vector2D>& points,int maxIterations,bool initialCenterIsAverage);
		const Vector2D GetAveragePoint(const std::vector<Vector2D>& points);
		void Iteration(const std::vector<Vector2D>& points, const Vector2D& average);

    private:
        Circle2 m_Circle;
    };

	using CircleFit2d = CircleFit2<double>;
	using CircleFit2f = CircleFit2<float>;
}

#endif // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
