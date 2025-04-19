/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 21:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_LINEAR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_LINEAR_DETAIL_H

#include "RootsLinear.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::RootsLinear<T>::RootsLinear() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::RootsLinear<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::RootsLinear<T>::Solve(const T& g0, const T& g1, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试度数是否小于2。

    if (MathType::Approximate(g1, T{}))
    {
        /// 解集要么是全实值x (g0 = 0)，要么没有解(g0 != 0)。
        /// 无论哪种情况，都不报告根源。
        return 0;
    }

    /// 测试零值根。
    if (MathType::Approximate(g0, T{}))
    {
        roots.at(0) = { T{}, 1 };

        return 1;
    }

    /// 此时，g0和g1不为零。
    roots.at(0) = { -g0 / g1, 1 };

    return 1;
}

template <typename T>
int Mathematics::RootsLinear<T>::Solve(const T& m0, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    roots.at(0) = { -m0, 1 };

    return 1;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_LINEAR_DETAIL_H
