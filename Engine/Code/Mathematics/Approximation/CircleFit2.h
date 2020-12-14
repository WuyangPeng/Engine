///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 17:46)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CircleFit2 final
    {
    public:
        using ClassType = CircleFit2<Real>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using PointType = std::vector<Vector2D>;
        using Math = Math<Real>;

    public:
        CircleFit2(const PointType& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Circle2 GetCircle() const noexcept;

    private:
        void Calculate(const PointType& points, int maxIterations, bool initialCenterIsAverage);
        [[nodiscard]] const Vector2D GetAveragePoint(const PointType& points);
        void Iteration(const PointType& points, const Vector2D& average);

    private:
        Circle2 m_Circle;
    };

    using FloatCircleFit2 = CircleFit2<float>;
    using DoubleCircleFit2 = CircleFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
