/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 13:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUARTIC_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUARTIC_DETAIL_H

#include "Algebra/PolynomialRootDetail.h"
#include "RootsCubicDetail.h"
#include "RootsQuadraticDetail.h"
#include "RootsQuartic.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/BinaryScientificRationalDetail.h"

template <typename T>
Mathematics::RootsQuartic<T>::RootsQuartic() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::RootsQuartic<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::RootsQuartic<T>::Solve(bool useBisection,
                                        const T& g0,
                                        const T& g1,
                                        const T& g2,
                                        const T& g3,
                                        const T& g4,
                                        PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试度数是否小于4。

    if (MathType::Approximate(g4, T{}))
    {
        return RootsCubic::Solve(useBisection, g0, g1, g2, g3, roots);
    }

    /// 测试零值根。
    if (MathType::Approximate(g0, T{}))
    {
        return HasZeroValuedRoots(useBisection, g1, g2, g3, g4, roots);
    }

    /// 此时，g0和g4不为零。
    /// 将一般四次方变换为凹四次方，求解其根，并将其逆变换为一般四次的根。
    Rational rD0{ 0 };
    Rational rD1{ 0 };
    Rational rD2{ 0 };
    Rational rM3Div4{ 0 };
    ComputeClassifiers(Rational{ g0 }, Rational{ g1 }, Rational{ g2 }, Rational{ g3 }, Rational{ g4 }, rD0, rD1, rD2, rM3Div4);

    RationalPolynomialRootContainer rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, rD0, rD1, rD2, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX() - rM3Div4), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsQuartic<T>::Solve(bool useBisection,
                                        const T& m0,
                                        const T& m1,
                                        const T& m2,
                                        const T& m3,
                                        PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 测试零值根。
    if (MathType::Approximate(m0, T{}))
    {
        return HasZeroValuedRoots(useBisection, m1, m2, m3, roots);
    }

    /// 此时，m0和m4不为零。
    /// 将一般四次方变换为凹四次方，求解其根，并将其逆变换为一般四次的根。
    Rational rD0{ 0 };
    Rational rD1{ 0 };
    Rational rD2{ 0 };
    Rational rM3Div4{ 0 };
    ComputeClassifiers(Rational{ m0 }, Rational{ m1 }, Rational{ m2 }, Rational{ m3 }, rD0, rD1, rD2, rM3Div4);

    RationalPolynomialRootContainer rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, rD0, rD1, rD2, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX() - rM3Div4), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsQuartic<T>::Solve(bool useBisection,
                                        const T& d0,
                                        const T& d1,
                                        const T& d2,
                                        PolynomialRootContainer& roots) requires(std::is_floating_point_v<T> || std::is_same_v<T, Rational>)
{
    /// 四次方已经被压低了，所以不需要变换和逆变换。
    /// 在T != Rational的情况下需要一份副本理性，在这种情况下会发生隐含的转换。
    RationalPolynomialRootContainer rRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    const auto numRoots = ComputeDepressedRoots(useBisection, Rational{ d0 }, Rational{ d1 }, Rational{ d2 }, rRoots);
    for (auto i = 0; i < numRoots; ++i)
    {
        roots.at(i) = { static_cast<T>(rRoots.at(i).GetX()), rRoots.at(i).GetM() };
    }
    return numRoots;
}

template <typename T>
int Mathematics::RootsQuartic<T>::ComputeDepressedRoots(bool useBisection,
                                                        const Rational& rD0,
                                                        const Rational& rD1,
                                                        const Rational& rD2,
                                                        RationalPolynomialRootContainer& rRoots)
{
    if (useBisection)
    {
        return ComputeDepressedRootsBisection(rD0, rD1, rD2, rRoots);
    }
    else
    {
        return ComputeDepressedRootsClosedForm(rD0, rD1, rD2, rRoots);
    }
}

template <typename T>
int Mathematics::RootsQuartic<T>::HasZeroValuedRoots(bool useBisection,
                                                     const T& g1,
                                                     const T& g2,
                                                     const T& g3,
                                                     const T& g4,
                                                     PolynomialRootContainer& roots)
{
    if (MathType::Approximate(g1, T{}))
    {
        if (MathType::Approximate(g2, T{}))
        {
            if (MathType::Approximate(g3, T{}))
            {
                roots.at(0) = { T{}, 4 };
                return 1;
            }
            else
            {
                auto numRoots = RootsLinear<T>::Solve(g3, g4, roots);
                roots.at(numRoots++) = { T{}, 3 };
                std::sort(roots.begin(), roots.begin() + numRoots);
                return numRoots;
            }
        }
        else
        {
            auto numRoots = RootsQuadratic<T>::Solve(useBisection, g2, g3, g4, roots);
            roots.at(numRoots++) = { T{}, 2 };
            std::sort(roots.begin(), roots.begin() + numRoots);
            return numRoots;
        }
    }
    else
    {
        auto numRoots = RootsCubic::Solve(useBisection, g1, g2, g3, g4, roots);
        roots.at(numRoots++) = { T{}, 1 };
        std::sort(roots.begin(), roots.begin() + numRoots);
        return numRoots;
    }
}

template <typename T>
int Mathematics::RootsQuartic<T>::HasZeroValuedRoots(bool useBisection,
                                                     const T& m1,
                                                     const T& m2,
                                                     const T& m3,
                                                     PolynomialRootContainer& roots)
{
    if (MathType::Approximate(m1, T{}))
    {
        if (MathType::Approximate(m2, T{}))
        {
            if (MathType::Approximate(m3, T{}))
            {
                roots.at(0) = { T{}, 4 };
                return 1;
            }
            else
            {
                auto numRoots = RootsLinear<T>::Solve(m3, roots);
                roots.at(numRoots++) = { T{}, 3 };
                std::sort(roots.begin(), roots.begin() + numRoots);
                return numRoots;
            }
        }
        else
        {
            auto numRoots = RootsQuadratic<T>::Solve(useBisection, m2, m3, roots);
            roots.at(numRoots++) = { T{}, 2 };
            std::sort(roots.begin(), roots.begin() + numRoots);
            return numRoots;
        }
    }
    else
    {
        auto numRoots = RootsCubic::Solve(useBisection, m1, m2, m3, roots);
        roots.at(numRoots++) = { T{}, 1 };
        std::sort(roots.begin(), roots.begin() + numRoots);
        return numRoots;
    }
}

template <typename T>
void Mathematics::RootsQuartic<T>::ComputeClassifiers(const Rational& rG0,
                                                      const Rational& rG1,
                                                      const Rational& rG2,
                                                      const Rational& rG3,
                                                      const Rational& rG4,
                                                      Rational& rD0,
                                                      Rational& rD1,
                                                      Rational& rD2,
                                                      Rational& rM3Div4)
{
    const auto rM0 = rG0 / rG4;
    const auto rM1 = rG1 / rG4;
    const auto rM2 = rG2 / rG4;
    const auto rM3 = rG3 / rG4;
    ComputeClassifiers(rM0, rM1, rM2, rM3, rD0, rD1, rD2, rM3Div4);
}

template <typename T>
void Mathematics::RootsQuartic<T>::ComputeClassifiers(const Rational& rM0,
                                                      const Rational& rM1,
                                                      const Rational& rM2,
                                                      const Rational& rM3,
                                                      Rational& rD0,
                                                      Rational& rD1,
                                                      Rational& rD2,
                                                      Rational& rM3Div4)
{
    rM3Div4 = Rational(1, 4) * rM3;
    const auto rM3Div4Sqr = rM3Div4 * rM3Div4;
    rD0 = rM0 - rM3Div4 * (rM1 - rM3Div4 * (rM2 - Rational(3) * rM3Div4Sqr));
    rD1 = rM1 - Rational(2) * rM3Div4 * (rM2 - Rational(4) * rM3Div4Sqr);
    rD2 = rM2 - Rational(6) * rM3Div4Sqr;
}

template <typename T>
int Mathematics::RootsQuartic<T>::SolveBiquadratic(bool useBisection, const Rational& rD0, const Rational& rD2, RationalPolynomialRootContainer& rRoots)
{
    const auto rS = Rational{ -0.5 } * rD2;
    const auto rT = rS * rS - rD0;

    if (const auto signT = rT.GetSign();
        signT > 0)
    {
        std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
        std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(useBisection, -rT, rQRoots);
        const auto rSqrtT = rQRoots.at(1).GetX();
        const auto rSpSqrtT = rS + rSqrtT;
        const auto rSmSqrtT = rD0 / rSpSqrtT;
        const auto signSpSqrtT = rSpSqrtT.GetSign();

        if (const auto signSmSqrtT = rSmSqrtT.GetSign();
            signSmSqrtT > 0)
        {
            /// 四个实数的根。
            std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(useBisection, -rSmSqrtT, rQRoots);
            const auto r0 = rQRoots.at(1).GetX();
            std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(useBisection, -rSpSqrtT, rQRoots);
            const auto r1 = rQRoots.at(1).GetX();
            rRoots.at(0) = { r0, 1 };
            rRoots.at(1) = { -r0, 1 };
            rRoots.at(2) = { r1, 1 };
            rRoots.at(3) = { -r1, 1 };
            std::sort(rRoots.begin(), rRoots.begin() + 4);
            return 4;
        }
        else if (signSpSqrtT < 0)
        {
            /// 两个复共轭对。
            return 0;
        }
        else  // signSmSqrtT < 0 and signSpSqrtT > 0
        {
            /// 两个实根，一个复共轭对。
            std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(useBisection, -rSpSqrtT, rQRoots);

            if (const auto r0 = rQRoots.at(1).GetX();
                r0.GetSign() > 0)
            {
                rRoots.at(0) = { -r0, 1 };
                rRoots.at(1) = { r0, 1 };
            }
            else
            {
                rRoots.at(0) = { r0, 1 };
                rRoots.at(1) = { -r0, 1 };
            }
            return 2;
        }
    }
    else if (signT < 0)
    {
        /// 两个复共轭对。
        return 0;
    }
    else
    {
        if (rS.GetSign() > 0)
        {
            /// 两个实根，每个根的重数为2。
            std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(useBisection, -rS, rQRoots);

            if (const auto r0 = rQRoots.at(1).GetX();
                r0.GetSign() > 0)
            {
                rRoots.at(0) = { -r0, 2 };
                rRoots.at(1) = { r0, 2 };
            }
            else
            {
                rRoots.at(0) = { r0, 2 };
                rRoots.at(1) = { -r0, 2 };
            }
            return 2;
        }
        else
        {
            /// 复数为2的一个复共轭对。
            return 0;
        }
    }
}

template <typename T>
int Mathematics::RootsQuartic<T>::ComputeDepressedRootsBisection(const Rational& rD0,
                                                                 const Rational& rD1,
                                                                 const Rational& rD2,
                                                                 RationalPolynomialRootContainer& rRoots)
{
    const auto signD0 = rD0.GetSign();
    const auto signD1 = rD1.GetSign();
    const auto signD2 = rD2.GetSign();
    if (signD0 == 0)
    {
        if (signD1 == 0)
        {
            if (signD2 > 0)
            {
                /// 一个实根，多重数2。
                rRoots.at(0) = { Rational(0), 2 };
                return 1;
            }
            else if (signD2 < 0)
            {
                /// 三个实根，一个重数为2，两个重数1。
                std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
                std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(true, rD2, rQRoots);
                auto rSqrtNegD2 = rQRoots.at(1).GetX();
                rRoots.at(0) = { -rSqrtNegD2, 1 };
                rRoots.at(1) = { Rational(0), 2 };
                rRoots.at(2) = { rSqrtNegD2, 1 };
                return 3;
            }
            else
            {
                /// 一个实根，多重数4。
                rRoots.at(0) = { Rational(0), 4 };
                return 1;
            }
        }
        else
        {
            /// 零是多重数1的根。三次解算器计算其他根。
            std::array temp{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            auto numRoots = RootsCubic::ComputeDepressedRoots(true, rD1, rD2, temp);
            rRoots.at(0) = temp.at(0);
            rRoots.at(1) = temp.at(1);
            rRoots.at(2) = temp.at(2);
            rRoots.at(numRoots++) = { Rational(0), 1 };
            std::sort(rRoots.begin(), rRoots.begin() + numRoots);
            return numRoots;
        }
    }

    /// 此时 d0 != 0.
    if (signD1 == 0)
    {
        return SolveBiquadratic(true, rD0, rD2, rRoots);
    }

    /// 此时, d0 != 0 和 d != 0.
    auto rD0Sqr = rD0 * rD0;
    auto rD1Sqr = rD1 * rD1;
    auto rD2Sqr = rD2 * rD2;
    auto rDelta = rD1Sqr * (Rational{ -27 } * rD1Sqr +
                            Rational{ 4 } * rD2 * (Rational{ 36 } * rD0 - rD2Sqr)) +
                  Rational{ 16 } * rD0 * (rD2Sqr * (rD2Sqr - Rational{ 8 } * rD0) + Rational{ 16 } * rD0Sqr);

    const auto signDelta = rDelta.GetSign();
    if (signDelta == 0)
    {
        /// 处理重复的根。
        auto rA0 = Rational{ 12 } * rD0 + rD2Sqr;
        if (rA0.GetSign() == 0)
        {
            /// 情况(x-r0)^3 (x-r1), d2 < 0保证。
            auto r0 = Rational{ -0.75 } * rD1 / rD2;
            auto r1 = Rational{ -3 } * r0;
            if (r0 < r1)
            {
                rRoots.at(0) = { r0, 3 };
                rRoots.at(1) = { r1, 1 };
            }
            else
            {
                rRoots.at(0) = { r1, 1 };
                rRoots.at(1) = { r0, 3 };
            }
            return 2;
        }

        /// 保证非零分母。
        auto rA1 = Rational{ 4 } * rD0 - rD2Sqr;
        auto r0 = -rD1 * rA0 / (Rational{ 9 } * rD1Sqr - Rational{ 2 } * rD2 * rA1);
        rRoots.at(0) = { r0, 2 };

        if (auto rqDiscriminant = -(rD2 + Rational{ 2 } * r0 * r0);
            rqDiscriminant.GetSign() > 0)
        {
            /// 情况 (x-r0)^2 (x-r1) (x-r2).
            std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(true, -rqDiscriminant, rQRoots);
            auto rSqrtQDiscriminant = rQRoots.at(1).GetX();
            auto r1 = -r0 - rSqrtQDiscriminant;
            auto r2 = -r0 + rSqrtQDiscriminant;
            rRoots.at(1) = { r1, 1 };
            rRoots.at(2) = { r2, 1 };
            std::sort(rRoots.begin(), rRoots.begin() + 3);
            return 3;
        }

        /// 情况 (x-r0)^2 (x-z0) (x-z0c).
        return 1;
    }

    if (signDelta > 0 && rD2.GetSign() > 0)
    {
        /// 两个复共轭对。
        return 0;
    }

    /// 将判别式（monic cubic）转换为压低的cubic。
    auto rM0 = Rational{ 0.125 } * (Rational{ 4 } * rD0 * rD2 - rD1Sqr);
    auto rM1 = -rD0;
    auto rM2 = Rational{ -0.5 } * rD2;
    auto rM2Div3 = Rational{ 1, 3 } * rM2;
    auto rC0 = rM0 - rM2Div3 * (rM1 - Rational{ 2 } * rM2Div3 * rM2Div3);
    auto rC1 = rM1 - rM2 * rM2Div3;

    /// 计算凹陷立方体的根。
    /// 压低多项式的最小根对应于monic多项式的最大根。
    /// 还要对根进行逆变换。
    std::array rCRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    std::ignore = RationalRootsCubic::ComputeDepressedRoots(true, rC0, rC1, rCRoots);
    auto rT = rCRoots.at(0).GetX() - rM2Div3;

    std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    auto rAlphaSqr = Rational(2) * rT - rD2;
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(true, -rAlphaSqr, rQRoots);
    auto rAlpha = rQRoots.at(1).GetX();
    auto rSignD1 = (rD1.GetSign() > 0 ? Rational(1) : Rational(-1));
    auto rArg = rT * rT - rD0;
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(true, -rArg, rQRoots);
    auto rBeta = rSignD1 * rQRoots.at(1).GetX();
    auto rDiscriminant0 = rAlphaSqr - Rational(4) * (rT + rBeta);
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(true, -rDiscriminant0, rQRoots);
    auto rSqrtDiscriminant0 = rQRoots.at(1).GetX();
    auto rDiscriminant1 = rAlphaSqr - Rational(4) * (rT - rBeta);
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(true, -rDiscriminant1, rQRoots);
    auto rSqrtDiscriminant1 = rQRoots.at(1).GetX();

    const Rational half{ 0.5 };
    if (signDelta > 0)
    {
        // 情况 (x-r0)(x-r1)(x-r2)(x-r3).
        auto r0 = half * (rAlpha - rSqrtDiscriminant0);
        auto r1 = half * (rAlpha + rSqrtDiscriminant0);
        auto r2 = half * (-rAlpha - rSqrtDiscriminant1);
        auto r3 = half * (-rAlpha + rSqrtDiscriminant1);
        rRoots.at(0) = { r0, 1 };
        rRoots.at(1) = { r1, 1 };
        rRoots.at(2) = { r2, 1 };
        rRoots.at(3) = { r3, 1 };
        std::sort(rRoots.begin(), rRoots.begin() + 4);
        return 4;
    }
    else  // signDelta < 0
    {
        /// 情况 (x-r0)(x-r1)(x-z0)(x-z0c).
        Rational r0{ 0 };
        Rational r1{ 0 };
        if (signD1 > 0)
        {
            r0 = half * (-rAlpha - rSqrtDiscriminant1);
            r1 = half * (-rAlpha + rSqrtDiscriminant1);
        }
        else
        {
            r0 = half * (rAlpha - rSqrtDiscriminant0);
            r1 = half * (rAlpha + rSqrtDiscriminant0);
        }
        rRoots.at(0) = { r0, 1 };
        rRoots.at(1) = { r1, 1 };
        return 2;
    }
}

template <typename T>
int Mathematics::RootsQuartic<T>::ComputeDepressedRootsClosedForm(const Rational& rD0,
                                                                  const Rational& rD1,
                                                                  const Rational& rD2,
                                                                  RationalPolynomialRootContainer& rRoots)
{
    const auto signD0 = rD0.GetSign();
    const auto signD1 = rD1.GetSign();
    const auto signD2 = rD2.GetSign();
    if (signD0 == 0)
    {
        if (signD1 == 0)
        {
            if (signD2 > 0)
            {
                /// 一个实根，多重数2。
                rRoots.at(0) = { Rational(0), 2 };
                return 1;
            }
            else if (signD2 < 0)
            {
                /// 三个实根，一个重数为2，两个重数1。
                std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
                std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(false, rD2, rQRoots);
                auto rSqrtNegD2 = rQRoots.at(1).GetX();
                rRoots.at(0) = { -rSqrtNegD2, 1 };
                rRoots.at(1) = { Rational(0), 2 };
                rRoots.at(2) = { rSqrtNegD2, 1 };
                return 3;
            }
            else
            {
                /// 一个实根，多重数4。
                rRoots.at(0) = { Rational{ 0 }, 4 };
                return 1;
            }
        }
        else
        {
            /// 零是多重数1的根。三次解算器计算其他根。
            std::array temp{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            auto numRoots = RationalRootsCubic::ComputeDepressedRoots(false, rD1, rD2, temp);

            rRoots.at(0) = temp.at(0);
            rRoots.at(1) = temp.at(1);
            rRoots.at(2) = temp.at(2);
            rRoots.at(numRoots++) = { Rational(0), 1 };
            std::sort(rRoots.begin(), rRoots.begin() + numRoots);
            return numRoots;
        }
    }

    /// 此时 d0 != 0.
    if (signD1 == 0)
    {
        return SolveBiquadratic(false, rD0, rD2, rRoots);
    }

    /// 此时, d0 != 0 和 d != 0.
    auto rD0Sqr = rD0 * rD0;
    auto rD1Sqr = rD1 * rD1;
    auto rD2Sqr = rD2 * rD2;
    auto rDelta = rD1Sqr * (Rational{ -27 } * rD1Sqr +
                            Rational{ 4 } * rD2 * (Rational{ 36 } * rD0 - rD2Sqr)) +
                  Rational{ 16 } * rD0 * (rD2Sqr * (rD2Sqr - Rational{ 8 } * rD0) + Rational{ 16 } * rD0Sqr);

    const auto signDelta = rDelta.GetSign();
    if (signDelta == 0)
    {
        /// 处理重复的根。
        auto rA0 = Rational{ 12 } * rD0 + rD2Sqr;
        if (rA0.GetSign() == 0)
        {
            /// 情况(x-r0)^3 (x-r1), d2 < 0 保证。
            auto r0 = Rational{ -0.75 } * rD1 / rD2;
            auto r1 = Rational{ -3 } * r0;
            if (r0 < r1)
            {
                rRoots.at(0) = { r0, 3 };
                rRoots.at(1) = { r1, 1 };
            }
            else
            {
                rRoots.at(0) = { r1, 1 };
                rRoots.at(1) = { r0, 3 };
            }
            return 2;
        }

        /// 保证非零分母。
        auto rA1 = Rational{ 4 } * rD0 - rD2Sqr;
        auto r0 = -rD1 * rA0 / (Rational{ 9 } * rD1Sqr - Rational{ 2 } * rD2 * rA1);
        rRoots.at(0) = { r0, 2 };

        if (auto rqDiscriminant = -(rD2 + Rational{ 2 } * r0 * r0);
            rqDiscriminant.GetSign() > 0)
        {
            /// 情况 (x-r0)^2 (x-r1) (x-r2).
            std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
            std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(false, -rqDiscriminant, rQRoots);
            auto rSqrtQDiscriminant = rQRoots.at(1).GetX();
            auto r1 = -r0 - rSqrtQDiscriminant;
            auto r2 = -r0 + rSqrtQDiscriminant;
            rRoots.at(1) = { r1, 1 };
            rRoots.at(2) = { r2, 1 };
            std::sort(rRoots.begin(), rRoots.begin() + 3);
            return 3;
        }

        /// 情况 (x-r0)^2 (x-z0) (x-z0c).
        return 1;
    }

    if (signDelta > 0 && rD2.GetSign() > 0)
    {
        /// 两个复共轭对。
        return 0;
    }

    /// 将判别式（monic cubic）转换为压低的cubic。
    auto rM0 = Rational{ 0.125 } * (Rational{ 4 } * rD0 * rD2 - rD1Sqr);
    auto rM1 = -rD0;
    auto rM2 = Rational{ -0.5 } * rD2;
    auto rM2Div3 = Rational{ 1, 3 } * rM2;
    auto rC0 = rM0 - rM2Div3 * (rM1 - Rational{ 2 } * rM2Div3 * rM2Div3);
    auto rC1 = rM1 - rM2 * rM2Div3;

    /// 计算凹陷立方体的根。
    /// 压低多项式的最小根对应于monic多项式的最大根。
    /// 还要对根进行逆变换。
    std::array rCRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    std::ignore = RationalRootsCubic ::ComputeDepressedRoots(false, rC0, rC1, rCRoots);
    auto rT = rCRoots.at(0).GetX() - rM2Div3;

    std::array rQRoots{ RationalPolynomialRoot::CreateZero(), RationalPolynomialRoot::CreateZero() };
    auto rAlphaSqr = Rational(2) * rT - rD2;
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(false, -rAlphaSqr, rQRoots);
    auto rAlpha = rQRoots.at(1).GetX();
    auto rSignD1 = (rD1.GetSign() > 0 ? Rational{ 1 } : Rational{ -1 });
    auto rArg = rT * rT - rD0;
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(false, -rArg, rQRoots);
    auto rBeta = rSignD1 * rQRoots.at(1).GetX();
    auto rDiscriminant0 = rAlphaSqr - Rational(4) * (rT + rBeta);
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(false, -rDiscriminant0, rQRoots);
    auto rSqrtDiscriminant0 = rQRoots.at(1).GetX();
    auto rDiscriminant1 = rAlphaSqr - Rational(4) * (rT - rBeta);
    std::ignore = RootsQuadratic<Rational>::ComputeDepressedRoots(false, -rDiscriminant1, rQRoots);
    auto rSqrtDiscriminant1 = rQRoots.at(1).GetX();

    const Rational half{ 0.5 };
    if (signDelta > 0)
    {
        /// 情况 (x-r0)(x-r1)(x-r2)(x-r3).
        auto r0 = half * (rAlpha - rSqrtDiscriminant0);
        auto r1 = half * (rAlpha + rSqrtDiscriminant0);
        auto r2 = half * (-rAlpha - rSqrtDiscriminant1);
        auto r3 = half * (-rAlpha + rSqrtDiscriminant1);
        rRoots.at(0) = { r0, 1 };
        rRoots.at(1) = { r1, 1 };
        rRoots.at(2) = { r2, 1 };
        rRoots.at(3) = { r3, 1 };
        std::sort(rRoots.begin(), rRoots.begin() + 4);
        return 4;
    }
    else  // signDelta < 0
    {
        /// 情况 (x-r0)(x-r1)(x-z0)(x-z0c).
        Rational r0{ 0 };
        Rational r1{ 0 };
        if (signD1 > 0)
        {
            r0 = half * (-rAlpha - rSqrtDiscriminant1);
            r1 = half * (-rAlpha + rSqrtDiscriminant1);
        }
        else
        {
            r0 = half * (rAlpha - rSqrtDiscriminant0);
            r1 = half * (rAlpha + rSqrtDiscriminant0);
        }
        rRoots.at(0) = { r0, 1 };
        rRoots.at(1) = { r1, 1 };
        return 2;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_QUARTIC_DETAIL_H
