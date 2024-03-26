/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 22:07)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUADRATIC_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUADRATIC_DETAIL_H

#include "Algebra/PolynomialRootDetail.h"
#include "RootsQuadratic.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Functions.h"
#include "Mathematics/Rational/BinaryScientificRationalDetail.h"

template <typename T>
Mathematics::RootsQuadratic<T>::RootsQuadratic() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::RootsQuadratic<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::RootsQuadratic<T>::Solve(bool useBisection, const T& g0, const T& g1, const T& g2, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试度数是否小于2。
    if (Math::Approximate(g2, T{}))
    {
        return RootsLinear::Solve(g0, g1, roots);
    }

    /// 测试零值根。
    if (Math::Approximate(g0, T{}))
    {
        return HasZeroValuedRoots(g1, g2, roots);
    }

    /// 此时，g0和g2不为零。将一般二次型变换为抑制二次型，
    /// 求解其根，并将其逆变换为一般二次的根。
    auto rD0 = Rational::CreateZero();
    auto rM1Div2 = Rational::CreateZero();
    ComputeClassifiers(Rational{ g0 }, Rational{ g1 }, Rational{ g2 }, rD0, rM1Div2);

    std::array rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, rD0, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX() - rM1Div2), rRoots.at(i).GetM() };
    }

    return numRoots;
}

template <typename T>
int Mathematics::RootsQuadratic<T>::Solve(bool useBisection, const T& m0, const T& m1, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试零值根。
    if (Math::Approximate(m0, T{}))
    {
        return HasZeroValuedRoots(m1, roots);
    }

    /// 此时m0不为零。将monic二次型变换为下凹二次型，
    /// 求解其根，并将其逆变换为monic二次型的根。
    auto rD0 = Rational::CreateZero();
    auto rM1Div2 = Rational::CreateZero();
    ComputeClassifiers(Rational{ m0 }, Rational{ m1 }, rD0, rM1Div2);

    std::array rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, rD0, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX() - rM1Div2), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsQuadratic<T>::Solve(bool useBisection, const T& d0, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 二次方已经被压低，所以不需要变换和逆变换。
    /// 在 T != Rational的情况下需要一份副本，在这种情况下会发生隐含的转换。
    std::array rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, Rational{ d0 }, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX()), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsQuadratic<T>::ComputeDepressedRoots(bool useBisection, const Rational& rD0, RationalPolynomialRootContainer& rRoots)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (useBisection)
    {
        return ComputeDepressedRootsBisection(rD0, rRoots);
    }
    else
    {
        return ComputeDepressedRootsClosedForm(rD0, rRoots);
    }
}

template <typename T>
int Mathematics::RootsQuadratic<T>::HasZeroValuedRoots(const T& g1, const T& g2, PolynomialRootContainer& roots)
{
    if (Math::Approximate(g1, T{}))
    {
        roots.at(0) = { T{}, 2 };
        return 1;
    }
    else
    {
        auto numRoots = RootsLinear::Solve(g1, g2, roots);
        roots.at(numRoots++) = { T{}, 1 };
        std::sort(roots.begin(), roots.begin() + numRoots);
        return numRoots;
    }
}

template <typename T>
int Mathematics::RootsQuadratic<T>::HasZeroValuedRoots(const T& m1, PolynomialRootContainer& roots)
{
    if (Math::Approximate(m1, T{}))
    {
        roots.at(0) = { T{}, 2 };
        return 1;
    }
    else
    {
        auto numRoots = RootsLinear::Solve(m1, roots);
        roots.at(numRoots++) = { T{}, 1 };
        std::sort(roots.begin(), roots.begin() + numRoots);
        return numRoots;
    }
}

template <typename T>
void Mathematics::RootsQuadratic<T>::ComputeClassifiers(const Rational& rG0, const Rational& rG1, const Rational& rG2, Rational& rD0, Rational& rM1Div2)
{
    const auto rM0 = rG0 / rG2;
    const auto rM1 = rG1 / rG2;
    ComputeClassifiers(rM0, rM1, rD0, rM1Div2);
}

template <typename T>
void Mathematics::RootsQuadratic<T>::ComputeClassifiers(const Rational& rM0, const Rational& rM1, Rational& rD0, Rational& rM1Div2)
{
    rM1Div2 = Rational{ 0.5 } * rM1;
    rD0 = rM0 - rM1Div2 * rM1Div2;
}

template <typename T>
int Mathematics::RootsQuadratic<T>::ComputeDepressedRootsBisection(const Rational& rD0, RationalPolynomialRootContainer& rRoots)
{
    const auto signD0 = rD0.GetSign();
    if (signD0 > 0)
    {
        /// 两个非实根，每个根的重数为1。
        return 0;
    }

    if (signD0 == 0)
    {
        /// 一个实根，多重数2。
        rRoots.at(0) = { Rational{ 0 }, 2 };
        return 1;
    }

    /// 两个实根，每个根的复数为1。
    /// F(x)的柯西界为b = max{1,|d_0|}$。
    /// 使用区间 [-b,b]上的平分来估计根。
    auto d0 = static_cast<T>(rD0);
    auto b = std::max(Math::GetValue(1), std::fabs(d0));
    auto f = [&d0](T x) noexcept {
        return Fma(x, x, d0);
    };

    /// 区间[0,b]上的双截。多项式是一个偶函数，所以我们不必在区间[-b,0]上平分。
    auto xMin = T{};
    auto xMax = b;
    PolynomialRoot::PolynomialRootBisect(f, -1, +1, xMin, xMax);
    auto average = Rational{ 0.5 } * (Rational{ xMin } + Rational{ xMax });
    rRoots.at(1) = { average, 1 };
    average.Negate();
    rRoots.at(0) = { average, 1 };
    return 2;
}

template <typename T>
int Mathematics::RootsQuadratic<T>::ComputeDepressedRootsClosedForm(const Rational& rD0, RationalPolynomialRootContainer& rRoots)
{
    const auto signD0 = rD0.GetSign();
    if (signD0 > 0)
    {
        /// 两个非实根，每个根的重数为1。
        return 0;
    }

    if (signD0 == 0)
    {
        /// 一个实根，多重数2。
        rRoots.at(0) = { Rational(0), 2 };
        return 1;
    }

    /// 两个实根，每个根的复数为1。使用根的闭合形式表示。
    auto rSqrtNegD0 = Sqrt(-rD0);
    rRoots.at(1) = { rSqrtNegD0, 1 };
    rSqrtNegD0.Negate();
    rRoots.at(0) = { rSqrtNegD0, 1 };
    return 2;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUADRATIC_DETAIL_H
