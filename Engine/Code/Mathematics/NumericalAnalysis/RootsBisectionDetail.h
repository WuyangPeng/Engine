/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 14:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION_DETAIL_H

#include "RootsBisection.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::RootsBisection<Real>::RootsBisection() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::RootsBisection<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::RootsBisection<Real>::Find(const std::function<Real(Real)>& f, Real t0, Real t1, int maxIterations, Real& root)
{
    root = t0;

    if (t0 < t1)
    {
        /// 测试端点以查看F(t)是否为零。
        auto f0 = f(t0);
        if (Math::Approximate(f0, Real{}))
        {
            root = t0;
            return 1;
        }

        auto f1 = f(t1);
        if (Math::Approximate(f1, Real{}))
        {
            root = t1;
            return 1;
        }

        if (f0 * f1 > Real{})
        {
            /// 目前还不知道区间是否为根的边界。
            return 0;
        }

        auto i = 2;
        for (; i <= maxIterations; ++i)
        {
            root = Math::GetRational(1, 2) * (t0 + t1);
            if (Math::Approximate(root, t0) || Math::Approximate(root, t1))
            {
                /// 数字t0和t1是连续的浮点数。
                break;
            }

            auto fm = f(root);
            auto product = fm * f0;
            if (product < Real{})
            {
                t1 = root;
                f1 = fm;
            }
            else if (product > Real{})
            {
                t0 = root;
                f0 = fm;
            }
            else
            {
                break;
            }
        }
        return i;
    }
    else
    {
        /// 间隔终结点无效。
        return 0;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::RootsBisection<Real>::Find(const std::function<Real(Real)>& f, Real t0, Real t1, Real f0, Real f1, int maxIterations, Real& root)
{
    root = t0;

    if (t0 < t1)
    {
        /// 测试端点以查看F(t)是否为零。
        if (Math::Approximate(f0, Real{}))
        {
            root = t0;
            return 1;
        }

        if (Math::Approximate(f1, Real{}))
        {
            root = t1;
            return 1;
        }

        if (f0 * f1 > Real{})
        {
            /// 目前还不知道区间是否为根的边界。
            return 0;
        }

        auto i = 2;
        root = t0;
        for (; i <= maxIterations; ++i)
        {
            root = Math::GetRational(1, 2) * (t0 + t1);
            if (Math::Approximate(root, t0) || Math::Approximate(root, t1))
            {
                /// 数字t0和t1是连续的浮点数。
                break;
            }

            auto fm = f(root);
            auto product = fm * f0;
            if (product < Real{})
            {
                t1 = root;
                f1 = fm;
            }
            else if (product > Real{})
            {
                t0 = root;
                f0 = fm;
            }
            else
            {
                break;
            }
        }
        return i;
    }
    else
    {
        /// 间隔终结点无效。
        return 0;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION_DETAIL_H
