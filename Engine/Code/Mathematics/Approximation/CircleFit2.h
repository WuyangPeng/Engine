///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:25)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
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

        using Vector2 = Vector2<Real>;
        using Circle2 = Circle2<Real>;
        using PointType = std::vector<Vector2>;
        using MathType = Math<Real>;

    public:
        CircleFit2(const PointType& points, int maxIterations, bool initialCenterIsAverage);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Circle2 GetCircle() const noexcept;

    private:
        void Calculate(const PointType& points, int maxIterations, bool initialCenterIsAverage);
        NODISCARD Vector2 GetAveragePoint(const PointType& points);
        void Iteration(const PointType& points, const Vector2& average);

    private:
        Circle2 circle;
    };

    using CircleFit2F = CircleFit2<float>;
    using CircleFit2D = CircleFit2<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_H
