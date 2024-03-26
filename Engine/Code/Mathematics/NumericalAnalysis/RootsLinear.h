/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 21:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_LINEAR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_LINEAR_H

#include "Mathematics/MathematicsDll.h"

#include "Algebra/PolynomialRoot.h"
#include "Mathematics/Rational/BinaryScientificRational.h"
#include "Mathematics/Rational/UIntegerArbitraryPrecision32.h"

/// 计算具有实值系数的线性多项式的实值根。
/// 一般线性多项式为g(x) = g0 + g1 * x，
/// 而一次线性多项式为m(x) = m0 + x。
namespace Mathematics
{
    template <typename T>
    class RootsLinear
    {
    public:
        using ClassType = RootsLinear<T>;

        /// 使用有理算术和浮点算术的混合运算来求解根。
        /// roots[]数组必须至少有1个元素。
        /// 返回的int是root[]数组中有效根的数目（0或1）。
        using Rational = BinaryScientificRational<UIntegerArbitraryPrecision32>;
        using PolynomialRoot = Algebra::PolynomialRoot<T>;
        using PolynomialRootContainer = std::vector<PolynomialRoot>;
        using Math = Math<T>;

    public:
        RootsLinear() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 求解一般多项式 g0 + g1*x = 0.
        NODISCARD static int Solve(const T& g0, const T& g1, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);

        // 求解一次多项式 m0 + x = 0.
        NODISCARD static int Solve(const T& m0, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_LINEAR_H
