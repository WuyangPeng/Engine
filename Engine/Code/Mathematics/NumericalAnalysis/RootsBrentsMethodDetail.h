/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 10:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BRENTS_METHOD_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BRENTS_METHOD_DETAIL_H

#include "RootsBrentsMethod.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::RootsBrentsMethod<Real>::RootsBrentsMethod() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::RootsBrentsMethod<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::RootsBrentsMethod<Real>::Find(const std::function<Real(Real)>& f, Real t0, Real t1, int maxIterations, Real negFTolerance, Real posFTolerance, Real stepTTolerance, Real convTTolerance, Real& root)
{
    /// 参数验证。
    if (t1 <= t0 || maxIterations == 0 || negFTolerance > Real{} || posFTolerance < Real{} || stepTTolerance < Real{} || convTTolerance < Real{})
    {
        /// 输入无效。
        return false;
    }

    auto f0 = f(t0);
    if (negFTolerance <= f0 && f0 <= posFTolerance)
    {
        /// 该端点是满足函数容差的近似根。
        root = t0;
        return true;
    }

    auto f1 = f(t1);
    if (negFTolerance <= f1 && f1 <= posFTolerance)
    {
        /// 该端点是满足函数容差的近似根。
        root = t1;
        return true;
    }

    if (f0 * f1 > Real{})
    {
        /// 输入间隔必须绑定根。
        return false;
    }

    if (std::fabs(f0) < std::fabs(f1))
    {
        /// 交换t0和t1，使|F(t1)| <= |F(t0)|。
        /// 数字t1被认为是对根的最佳估计。
        std::swap(t0, t1);
        std::swap(f0, f1);
    }

    /// 初始化根搜索的值。
    auto t2 = t0;
    auto t3 = t0;
    auto f2 = f0;
    auto prevBisected = true;

    /// 根搜索。
    for (auto i = 0; i < maxIterations; ++i)
    {
        auto fDiff01 = f0 - f1;
        auto fDiff02 = f0 - f2;
        auto fDiff12 = f1 - f2;
        auto invFDiff01 = MathType::GetValue(1) / fDiff01;
        Real s{};
        if (!MathType::Approximate(fDiff02, Real{}) && !MathType::Approximate(fDiff12, Real{}))
        {
            /// 使用逆二次插值。
            auto infFDiff02 = MathType::GetValue(1) / fDiff02;
            auto invFDiff12 = MathType::GetValue(1) / fDiff12;
            s = t0 * f1 * f2 * invFDiff01 * infFDiff02 -
                t1 * f0 * f2 * invFDiff01 * invFDiff12 +
                t2 * f0 * f1 * infFDiff02 * invFDiff12;
        }
        else
        {
            /// 使用反向线性插值（割线法）。
            s = (t1 * f0 - t0 * f1) * invFDiff01;
        }

        /// 计算接受或拒绝测试中所需的值。
        auto tDiffSAvr = s - MathType::GetRational(3, 4) * t0 - MathType::GetRational(1, 4) * t1;
        auto tDiffS1 = s - t1;
        const auto absTDiffS1 = std::fabs(tDiffS1);
        const auto absTDiff12 = std::fabs(t1 - t2);
        const auto absTDiff23 = std::fabs(t2 - t3);

        auto currBisected = false;
        if (tDiffSAvr * tDiffS1 > Real{})
        {
            /// 值s不在0.75*t0 + 0.25*t1和t1之间。
            /// 注：该算法有时t0 < t1，但有时t1 < t0，因此度间测试不使用简单的比较。
            currBisected = true;
        }
        else if (prevBisected)
        {
            /// 布伦特的第一个测试，以确定是否接受插值s值。
            currBisected = (absTDiffS1 >= MathType::GetRational(1, 2) * absTDiff12) || (absTDiff12 <= stepTTolerance);
        }
        else
        {
            // 布伦特的第二次测试，以确定是否接受插值的s值。
            currBisected = (absTDiffS1 >= MathType::GetRational(1, 2) * absTDiff23) || (absTDiff23 <= stepTTolerance);
        }

        if (currBisected)
        {
            // 其中一个附加测试失败，因此拒绝插值的s值，而是使用平分。
            s = MathType::GetRational(1, 2) * (t0 + t1);
            if (!MathType::Approximate(s, t0) || !MathType::Approximate(s, t1))
            {
                // 数字t0和t1是连续的浮点数。
                root = s;
                return true;
            }
            prevBisected = true;
        }
        else
        {
            prevBisected = false;
        }

        // 在新的估计值处评估函数，并测试收敛性。
        auto fs = f(s);
        if (negFTolerance <= fs && fs <= posFTolerance)
        {
            root = s;
            return true;
        }

        // 更新子区间以将新的估计值作为端点包括在内。
        t3 = t2;
        t2 = t1;
        f2 = f1;
        if (f0 * fs < Real{})
        {
            t1 = s;
            f1 = fs;
        }
        else
        {
            t0 = s;
            f0 = fs;
        }

        /// 当子区间足够小时，允许算法终止。
        if (std::fabs(t1 - t0) <= convTTolerance)
        {
            root = t1;
            return true;
        }

        /// 循环不变量是，t1是根估计，F(t0)*F(t1) < 0 and |F(t1)| <= |F(t0)|。
        if (std::fabs(f0) < std::fabs(f1))
        {
            std::swap(t0, t1);
            std::swap(f0, f1);
        }
    }

    // 未能在指定的迭代次数中收敛。
    return false;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BRENTS_METHOD_DETAIL_H
