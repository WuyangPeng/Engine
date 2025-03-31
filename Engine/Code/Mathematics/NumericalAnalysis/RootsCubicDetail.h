/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/21 21:31)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_CUBIC_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_CUBIC_DETAIL_H

#include "Algebra/PolynomialRootDetail.h"
#include "RootsCubic.h"
#include "RootsQuadraticDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Functions.h"
#include "Mathematics/Rational/BinaryScientificRationalDetail.h"

template <typename T>
Mathematics::RootsCubic<T>::RootsCubic() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::RootsCubic<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::RootsCubic<T>::Solve(bool useBisection, const T& g0, const T& g1, const T& g2, const T& g3, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试度数是否小于3。
    if (MathType::Approximate(g3, T{}))
    {
        return RootsQuadraticType::Solve(useBisection, g0, g1, g2, roots);
    }

    /// 测试零值根。
    if (MathType::Approximate(g0, T{}))
    {
        return HasZeroValuedRoots(useBisection, g1, g2, g3, roots);
    }

    /// 此时，g0和g3不为零。
    /// 将一般三次方变换为凹三次方，求解其根，并将其逆变换为一般三次的根。
    auto rD0 = Rational::CreateZero();
    auto rD1 = Rational::CreateZero();
    auto rM2Div3 = Rational::CreateZero();
    ComputeClassifiers(Rational{ g0 }, Rational{ g1 }, Rational{ g2 }, Rational{ g3 }, rD0, rD1, rM2Div3);

    std::array rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, rD0, rD1, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX() - rM2Div3), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsCubic<T>::Solve(bool useBisection, const T& m0, const T& m1, const T& m2, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试零值根。
    if (MathType::Approximate(m0, T{}))
    {
        return HasZeroValuedRoots(useBisection, m1, m2, roots);
    }

    /// 此时，p0和p3不为零。将一次三次方变换为凹三次方，
    /// 求解其根，并将其逆变换为一次三次方的根。
    auto rD0 = Rational::CreateZero();
    auto rD1 = Rational::CreateZero();
    auto rM2Div3 = Rational::CreateZero();
    ComputeClassifiers(Rational{ m0 }, Rational{ m1 }, Rational{ m2 }, rD0, rD1, rM2Div3);

    std::array rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, rD0, rD1, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX() - rM2Div3), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsCubic<T>::Solve(bool useBisection, const T& d0, const T& d1, PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 立方体已经被压低，所以不需要变换和逆变换。
    /// 在T != Rational的情况下需要一份副本，在这种情况下会发生隐含的转换。
    std::array rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, Rational{ d0 }, Rational{ d1 }, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX()), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsCubic<T>::ComputeDepressedRoots(bool useBisection, const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots)
{
    if (useBisection)
    {
        return ComputeDepressedRootsBisection(rD0, rD1, rRoots);
    }
    else
    {
        return ComputeDepressedRootsClosedForm(rD0, rD1, rRoots);
    }
}

template <typename T>
int Mathematics::RootsCubic<T>::HasZeroValuedRoots(bool useBisection, const T& g1, const T& g2, const T& g3, PolynomialRootContainer& roots)
{
    if (MathType::Approximate(g1, T{}))
    {
        if (MathType::Approximate(g2, T{}))
        {
            roots.at(0) = { T{}, 3 };
            return 1;
        }
        else
        {
            auto numRoots = RootsLinearType::Solve(g2, g3, roots);
            roots.at(numRoots++) = { T{}, 2 };
            std::sort(roots.begin(), roots.begin() + numRoots);
            return numRoots;
        }
    }
    else
    {
        auto numRoots = RootsQuadraticType::Solve(useBisection, g1, g2, g3, roots);
        roots.at(numRoots++) = { T{}, 1 };
        std::sort(roots.begin(), roots.begin() + numRoots);
        return numRoots;
    }
}

template <typename T>
int Mathematics::RootsCubic<T>::HasZeroValuedRoots(bool useBisection, const T& m1, const T& m2, PolynomialRootContainer& roots)
{
    if (MathType::Approximate(m1, T{}))
    {
        if (MathType::Approximate(m2, T{}))
        {
            roots.at(0) = { T{}, 3 };
            return 1;
        }
        else
        {
            auto numRoots = RootsLinearType::Solve(m2, roots);
            roots.at(numRoots++) = { T{}, 2 };
            std::sort(roots.begin(), roots.begin() + numRoots);
            return numRoots;
        }
    }
    else
    {
        auto numRoots = RootsQuadraticType::Solve(useBisection, m1, m2, roots);
        roots.at(numRoots++) = { T{}, 1 };
        std::sort(roots.begin(), roots.begin() + numRoots);
        return numRoots;
    }
}

template <typename T>
void Mathematics::RootsCubic<T>::ComputeClassifiers(const Rational& rG0, const Rational& rG1, const Rational& rG2, const Rational& rG3, Rational& rD0, Rational& rD1, Rational& rM2Div3)
{
    const auto rM0 = rG0 / rG3;
    const auto rM1 = rG1 / rG3;
    const auto rM2 = rG2 / rG3;
    ComputeClassifiers(rM0, rM1, rM2, rD0, rD1, rM2Div3);
}

template <typename T>
void Mathematics::RootsCubic<T>::ComputeClassifiers(const Rational& rM0, const Rational& rM1, const Rational& rM2, Rational& rD0, Rational& rD1, Rational& rM2Div3)
{
    rM2Div3 = Rational{ 1, 3 } * rM2;
    rD0 = rM0 - rM2Div3 * (rM1 - Rational{ 2 } * rM2Div3 * rM2Div3);
    rD1 = rM1 - rM2 * rM2Div3;
}

template <typename T>
int Mathematics::RootsCubic<T>::ComputeDepressedRootsBisection(const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots) requires(std::is_arithmetic_v<T>)
{
    const auto signD0 = rD0.GetSign();
    const auto signD1 = rD1.GetSign();
    if (signD0 == 0)
    {
        if (signD1 > 0)
        {
            /// 一个实根，重数1。
            rRoots.at(0) = { Rational{ 0 }, 1 };
            return 1;
        }
        else if (signD1 < 0)
        {
            std::array quadraticRoot{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            /// 三个实根，每个复数为1。
            auto numRoots = RootsQuadraticType::ComputeDepressedRoots(true, rD1, quadraticRoot);
            rRoots.at(0) = quadraticRoot.at(0);
            rRoots.at(1) = quadraticRoot.at(1);
            rRoots.at(numRoots++) = { Rational(0), 1 };
            std::sort(rRoots.begin(), rRoots.begin() + numRoots);
            return numRoots;
        }
        else  // signD1 = 0
        {
            /// 一个实根，多重数3。
            rRoots.at(0) = { Rational(0), 3 };
            return 1;
        }
    }

    if (signD1 == 0)  // 和 d0 != 0
    {
        /// 一个实根，重数1。
        auto d0 = static_cast<T>(rD0);
        auto b = std::max(MathType::GetValue(1), std::fabs(d0));
        auto f = [&d0](T x) noexcept {
            return Fma(x, x * x, d0);
        };

        /// 区间[-b,b]上的双截。
        const Rational half{ 0.5 };
        auto xMin = -b;
        auto xMax = b;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(0) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };
        return 1;
    }

    auto rDelta = Rational{ -27 } * rD0 * rD0 + Rational{ -4 } * rD1 * rD1 * rD1;

    if (const auto signDelta = rDelta.GetSign();
        signDelta > 0)
    {
        /// 三个实根，每个复数为1。
        ///  F(x) = x^3 + d1 * x + d0的导数是F'(x) = 3 * x^2 + d1，
        ///  并且必须有两个实根x0和x1，这意味着d1 < 0。
        ///  设s = sqrt(-d1 / 3)。
        ///  F'(x) 根是x0 = -s 和 x1 = s。
        ///  使用萨缪尔森不等式，根的边界区间是[-2 * s, 2 * s]。
        ///  将区间划分为[-2 * s, -s], [-s, s]和[s, 2 * s]。
        ///  在每个区间上使用平分来估计F(x)的根。
        std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
        MAYBE_UNUSED const auto roots = RootsQuadraticType::ComputeDepressedRoots(true, Rational(1, 3) * rD1, rQRoots);
        auto rS = rQRoots.at(1).GetX();
        auto rTwoS = Rational{ 2 } * rS;
        auto d0 = static_cast<T>(rD0);
        auto d1 = static_cast<T>(rD1);
        auto s = static_cast<T>(rS);
        auto twoS = static_cast<T>(rTwoS);
        auto f = [&d0, &d1](T x) noexcept {
            return std::fma(x, std::fma(x, x, d1), d0);
        };

        const Rational half{ 0.5 };

        /// 区间[-2 * s, s]上的双截
        auto xMin = -twoS;
        auto xMax = -s;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(0) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };

        /// 区间[-2 * s, s]上的双截
        xMin = -s;
        xMax = s;
        PolynomialRootType::PolynomialRootBisect(f, +1, -1, xMin, xMax);
        rRoots.at(1) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };

        /// 区间[s, 2 * s]上的双截
        xMin = s;
        xMax = twoS;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(2) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };
        return 3;
    }
    else if (signDelta < 0)
    {
        /// 一个实根，重数1。
        /// F(x)的柯西界为b = max{1,|d0|,|d1|}。
        /// 在区间 [-b,b]上使用平分来估计根。
        auto d0 = static_cast<T>(rD0);
        auto d1 = static_cast<T>(rD1);
        auto b = std::max(MathType::GetValue(1), std::max(std::fabs(d0), std::fabs(d1)));
        auto f = [&d0, &d1](T x) noexcept {
            return std::fma(x, std::fma(x, x, d1), d0);
        };

        /// 区间[-b,b]上的双截。
        const Rational half{ 0.5 };
        auto xMin = -b;
        auto xMax = b;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(0) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };
        return 1;
    }
    else  // delta = 0
    {
        /// 一个实根，重数1。
        /// 一个实根，多重数2。
        /// 根是有理数，所以对于每个根x，F(x) = 0 。
        auto rX0 = Rational{ -3, 2 } * rD0 / rD1;
        auto rX1 = Rational{ -2 } * rX0;
        if (rX0 < rX1)
        {
            rRoots.at(0) = { rX0, 2 };
            rRoots.at(1) = { rX1, 1 };
        }
        else
        {
            rRoots.at(0) = { rX1, 1 };
            rRoots.at(1) = { rX0, 2 };
        }
        return 2;
    }
}

template <typename T>
int Mathematics::RootsCubic<T>::ComputeDepressedRootsBisection(const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots) requires(!std::is_arithmetic_v<T>)
{
    const auto signD0 = rD0.GetSign();
    const auto signD1 = rD1.GetSign();
    if (signD0 == 0)
    {
        if (signD1 > 0)
        {
            /// 一个实根，重数1。
            rRoots.at(0) = { Rational{ 0 }, 1 };
            return 1;
        }
        else if (signD1 < 0)
        {
            std::array quadraticRoot{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            /// 三个实根，每个复数为1。
            auto numRoots = RootsQuadraticType::ComputeDepressedRoots(true, rD1, quadraticRoot);
            rRoots.at(0) = quadraticRoot.at(0);
            rRoots.at(1) = quadraticRoot.at(1);
            rRoots.at(numRoots++) = { Rational(0), 1 };
            std::sort(rRoots.begin(), rRoots.begin() + numRoots);
            return numRoots;
        }
        else  // signD1 = 0
        {
            /// 一个实根，多重数3。
            rRoots.at(0) = { Rational(0), 3 };
            return 1;
        }
    }

    if (signD1 == 0)  // 和 d0 != 0
    {
        /// 一个实根，重数1。
        auto d0 = static_cast<T>(rD0);
        auto b = std::max(T{ 1 }, Fabs(d0));
        auto f = [&d0](T x) {
            return Fma(x, x * x, d0);
        };

        /// 区间[-b,b]上的双截。
        const Rational half{ 0.5 };
        auto xMin = -b;
        auto xMax = b;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(0) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };
        return 1;
    }

    auto rDelta = Rational{ -27 } * rD0 * rD0 + Rational{ -4 } * rD1 * rD1 * rD1;

    if (const auto signDelta = rDelta.GetSign();
        signDelta > 0)
    {
        /// 三个实根，每个复数为1。
        ///  F(x) = x^3 + d1 * x + d0的导数是F'(x) = 3 * x^2 + d1，
        ///  并且必须有两个实根x0和x1，这意味着d1 < 0。
        ///  设s = sqrt(-d1 / 3)。
        ///  F'(x) 根是x0 = -s 和 x1 = s。
        ///  使用萨缪尔森不等式，根的边界区间是[-2 * s, 2 * s]。
        ///  将区间划分为[-2 * s, -s], [-s, s]和[s, 2 * s]。
        ///  在每个区间上使用平分来估计F(x)的根。
        std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
        MAYBE_UNUSED const auto roots = RootsQuadraticType::ComputeDepressedRoots(true, Rational(1, 3) * rD1, rQRoots);
        auto rS = rQRoots.at(1).GetX();
        auto rTwoS = Rational{ 2 } * rS;
        auto d0 = static_cast<T>(rD0);
        auto d1 = static_cast<T>(rD1);
        auto s = static_cast<T>(rS);
        auto twoS = static_cast<T>(rTwoS);
        auto f = [&d0, &d1](T x) {
            return Fma(x, Fma(x, x, d1), d0);
        };

        const Rational half{ 0.5 };

        /// 区间[-2 * s, s]上的双截
        auto xMin = -twoS;
        auto xMax = -s;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(0) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };

        /// 区间[-2 * s, s]上的双截
        xMin = -s;
        xMax = s;
        PolynomialRootType::PolynomialRootBisect(f, +1, -1, xMin, xMax);
        rRoots.at(1) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };

        /// 区间[s, 2 * s]上的双截
        xMin = s;
        xMax = twoS;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(2) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };
        return 3;
    }
    else if (signDelta < 0)
    {
        /// 一个实根，重数1。
        /// F(x)的柯西界为b = max{1,|d0|,|d1|}。
        /// 在区间 [-b,b]上使用平分来估计根。
        auto d0 = static_cast<T>(rD0);
        auto d1 = static_cast<T>(rD1);
        auto b = std::max(T{ 1 }, std::max(Fabs(d0), Fabs(d1)));
        auto f = [&d0, &d1](T x) {
            return Fma(x, Fma(x, x, d1), d0);
        };

        /// 区间[-b,b]上的双截。
        const Rational half{ 0.5 };
        auto xMin = -b;
        auto xMax = b;
        PolynomialRootType::PolynomialRootBisect(f, -1, +1, xMin, xMax);
        rRoots.at(0) = { half * (Rational{ xMin } + Rational{ xMax }), 1 };
        return 1;
    }
    else  // delta = 0
    {
        /// 一个实根，重数1。
        /// 一个实根，多重数2。
        /// 根是有理数，所以对于每个根x，F(x) = 0 。
        auto rX0 = Rational{ -3, 2 } * rD0 / rD1;
        auto rX1 = Rational{ -2 } * rX0;
        if (rX0 < rX1)
        {
            rRoots.at(0) = { rX0, 2 };
            rRoots.at(1) = { rX1, 1 };
        }
        else
        {
            rRoots.at(0) = { rX1, 1 };
            rRoots.at(1) = { rX0, 2 };
        }
        return 2;
    }
}

template <typename T>
int Mathematics::RootsCubic<T>::ComputeDepressedRootsClosedForm(const Rational& rD0, const Rational& rD1, RationalPolynomialRootContainer& rRoots)
{
    const auto signD0 = rD0.GetSign();
    const auto signD1 = rD1.GetSign();
    if (signD0 == 0)
    {
        if (signD1 > 0)
        {
            /// 一个实根，重数1。
            rRoots.at(0) = { Rational{ 0 }, 1 };
            return 1;
        }
        else if (signD1 < 0)
        {
            /// 三个实根，每个复数为1。
            auto rSqrtNegD1 = Sqrt(-rD1);
            rRoots.at(2) = { rSqrtNegD1, 1 };
            rRoots.at(1) = { Rational{ 0 }, 1 };
            rSqrtNegD1.Negate();
            rRoots.at(0) = { rSqrtNegD1, 1 };
            return 3;
        }
        else  // signD1 = 0
        {
            /// 一个实根，多重数3。
            rRoots.at(0) = { Rational(0), 3 };
            return 1;
        }
    }

    if (signD1 == 0)  // and d0 != 0
    {
        /// 一个实根，重数1。
        const Rational r1Div3{ 1, 3 };
        if (rD0.GetSign() > 0)
        {
            rRoots.at(0) = { -Pow(rD0, r1Div3), 1 };
        }
        else
        {
            rRoots.at(0) = { Pow(-rD0, r1Div3), 1 };
        }
        return 1;
    }

    auto rDelta = Rational{ -27 } * rD0 * rD0 + Rational{ -4 } * rD1 * rD1 * rD1;

    if (const auto signDelta = rDelta.GetSign();
        signDelta > 0)
    {
        /// 三个实根，每个复数为1。
        const Rational rSqrt3{ std::sqrt(3.0) };
        const Rational r3Div2{ 3, 2 };
        const Rational r1Div3{ 1, 3 };
        auto rD1Div3 = rD1 * r1Div3;
        auto rRho = Pow(Fabs(rD1Div3), r3Div2);
        auto rCbrtRho = Pow(rRho, r1Div3);
        auto rTheta = Atan2(Sqrt(rDelta / Rational{ 27 }), -rD0);
        auto rThetaDiv3 = rTheta * r1Div3;
        auto rCosThetaDiv3 = Cos(rThetaDiv3);
        auto rSinThetaDiv3 = Sin(rThetaDiv3);
        auto rTemp0 = rCbrtRho * rCosThetaDiv3;
        auto rTemp1 = rSqrt3 * rCbrtRho * rSinThetaDiv3;
        auto r0 = Rational{ 2 } * rTemp0;
        auto r1 = -rTemp0 - rTemp1;
        auto r2 = -rTemp0 + rTemp1;
        if (rSinThetaDiv3.GetSign() > 0)
        {
            rRoots.at(0) = { r1, 1 };
            rRoots.at(1) = { r2, 1 };
            rRoots.at(2) = { r0, 1 };
        }
        else
        {
            rRoots.at(0) = { r2, 1 };
            rRoots.at(1) = { r1, 1 };
            rRoots.at(2) = { r0, 1 };
        }
        return 3;
    }
    else if (signDelta < 0)
    {
        /// 一个实根，重数1。
        const Rational r1Div3{ 1, 3 };
        auto rSqrtNegDeltaDiv27 = Sqrt(-rDelta / Rational{ 27 });
        auto rD1Div3 = rD1 * r1Div3;
        if (signD0 < 0)
        {
            auto rW = Rational{ 1, 2 } * (-rD0 + rSqrtNegDeltaDiv27);
            auto rCbrtW = Pow(rW, r1Div3);
            auto r0 = rCbrtW - rD1Div3 / rCbrtW;
            rRoots.at(0) = { r0, 1 };
        }
        else
        {
            auto rNegY = Rational{ 1, 2 } * (rD0 + rSqrtNegDeltaDiv27);
            auto rCbrtY = -Pow(rNegY, r1Div3);
            auto r0 = rCbrtY - rD1Div3 / rCbrtY;
            rRoots.at(0) = { r0, 1 };
        }
        return 1;
    }
    else  // delta = 0
    {
        /// 一个实根，重数1。
        /// 一个实根，多重数2。
        /// 根是有理数，所以对于每个根x，F(x) = 0。
        auto rX0 = Rational{ -3, 2 } * rD0 / rD1;
        auto rX1 = Rational{ -2 } * rX0;
        if (rX0 < rX1)
        {
            rRoots.at(0) = { rX0, 2 };
            rRoots.at(1) = { rX1, 1 };
        }
        else
        {
            rRoots.at(0) = { rX1, 1 };
            rRoots.at(1) = { rX0, 2 };
        }
        return 2;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_CUBIC_DETAIL_H
