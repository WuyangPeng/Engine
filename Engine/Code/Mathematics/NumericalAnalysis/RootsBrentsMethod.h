/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 10:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BRENTS_METHOD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BRENTS_METHOD_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <functional>

/// 这是Brent方法的一个实现，用于计算F(t0)*F(t1) < 0的区间[t0,t1]上函数的根。
/// 该方法使用逆二次插值来生成根估计，但如果必要，则返回到逆线性插值（割线法）。
/// 此外，基于先前的迭代，当插值估计的质量不够时，该方法将返回到平分。
///
///   maxIterations:
///     用于定位根的最大迭代次数。这应该是正数。
///   negFTolerance, posFTolerance:
///   当函数值F(t)满足negFTolerance <= F(t) <= posFTolerance时，接受根估计t。
///   这些值必须满足：negFTolerance <= 0, posFTolerance >= 0。
///   stepTTolerance:
///   在接受插值t值作为下一个根估计值之前，布伦特方法需要进行额外的测试。
///   其中一个测试比较连续迭代的差异，并要求其大于用户指定的t容差（以确保取得进展）。
///   这个参数是公差，应该是非负的。
///   convTTolerance:
///   当当前子区间[tSub0,tSub1]足够小时，例如|tSub1 - tSub0| <= tolerance时，允许终止根搜索。
///   这个参数是公差，应该是非负的。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class RootsBrentsMethod
    {
    public:
        using ClassType = RootsBrentsMethod<Real>;

        using Math = Math<Real>;

    public:
        RootsBrentsMethod() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// F(t0)*F(t1) <= 0是必要的，在这种情况下，函数返回“true”，“root”是有效的；
        /// 否则，函数将返回“false”，并且“root”无效（不要使用它）。
        /// 当F(t0)*F(t1) > 0时，区间很可能包含一个根，
        /// 但我们不知道。如果t0 >= t1，函数也会返回“false”。
        static bool Find(std::function<Real(Real)> const& f,
                         Real t0,
                         Real t1,
                         int maxIterations,
                         Real negFTolerance,
                         Real posFTolerance,
                         Real stepTTolerance,
                         Real convTTolerance,
                         Real& root);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BRENTS_METHOD_H
