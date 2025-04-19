/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 16:58)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CIRCLE2_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Objects2D/Circle2.h"

/// 圆与一组点的最小二乘拟合。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCircle2
    {
    public:
        using ClassType = ApproximationCircle2<Real>;

        using Circle2Type = Circle2<Real>;
        using Vector2Type = Algebra::Vector2<Real>;
        using Vector2Container = std::vector<Vector2Type>;
        using MathType = Math<Real>;

    public:
        ApproximationCircle2() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 当算法的线性系统可解时，返回值为'true'，否则为'false'。
        /// 如果返回'false'，则圆心和半径将设置为零值。
        NODISCARD bool FitUsingSquaredLengths(const Vector2Container& points, Circle2Type& circle);

        /// 使用长度来拟合点，以驱动最小二乘算法。
        /// 如果initialCenterIsAverage设置为“false”，
        /// 则初始圆心的初始猜测将计算为数据点的平均值。
        /// 如果数据点沿着一个小圆弧聚集，则算法收敛较慢。
        /// 如果initialCenterIsAverage设置为“true”，
        /// 则按原样使用传入圆心来启动迭代算法。
        /// 这种方法往往比使用点的平均值更快地收敛，但可能比FitUsingSquaredLengths慢得多。
        ///
        /// 值epsilon可以被选择为用于比较连续估计的圆心的正数，
        /// 当圆心差的长度小于或等于epsilon时终止迭代。
        ///
        /// 返回值是使用的迭代次数。
        /// 如果是输入的maxIterations，则可以接受结果，
        /// 也可以通过将initialCenterIsAverage设置为“true”再次调用函数来优化结果。
        NODISCARD int FitUsingLengths(const Vector2Container& points,
                                      int maxIterations,
                                      bool initialCenterIsAverage,
                                      Circle2Type& circle,
                                      Real epsilon = Real{});
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CIRCLE2_H
