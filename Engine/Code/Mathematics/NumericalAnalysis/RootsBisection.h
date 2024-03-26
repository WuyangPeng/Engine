/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 14:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <functional>

/// 计算函数F(t)在区间[t0, t1]上的根。
/// 调用方指定最大迭代次数，以防您希望根的精度有限。
/// 但是，该函数是为本机类型（Real = float/double）设计的。
/// 如果指定了足够多的迭代次数，寻根器将平分，
/// 直到F(t)等于零[这是一个取决于如何构造F(t)进行评估的条件]或中点(t0 + t1)/2个数值舍入到tmin或tmax。
/// 当然，要求t0 < t1。
/// Find的返回值为：
///  0: F(t0)*F(t1) > 0, 我们无法确定根
///  1: F(t0) = 0 or F(t1) = 0
///  2..maxIterations: 平分的数量加上一个maxIterations+1：执行的循环没有中断（没有收敛）
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class RootsBisection
    {
    public:
        using ClassType = RootsBisection<Real>;

        using Math = Math<Real>;

    public:
        RootsBisection() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 当F(t0)和F(t1)未知时，使用此函数。
        NODISCARD static int Find(const std::function<Real(Real)>& f, Real t0, Real t1, int maxIterations, Real& root);

        /// 如果f0 = F(t0)和f1 = F(t1)是已知的，则将它们传递到平分线。
        /// 当|f0|或|f1|是无穷大时，这很有用，
        /// 并且你可以通过符号（f0）或符号（f1）而不是无穷大，
        /// 因为平分线只关心f的符号。
        NODISCARD static int Find(const std::function<Real(Real)>& f, Real t0, Real t1, Real f0, Real f1, int maxIterations, Real& root);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION_H
