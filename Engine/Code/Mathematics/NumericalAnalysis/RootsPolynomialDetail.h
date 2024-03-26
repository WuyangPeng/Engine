/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 14:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_POLYNOMIAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_POLYNOMIAL_DETAIL_H

#include "RootsPolynomial.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::RootsPolynomial<Real>::RootsPolynomial() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::RootsPolynomial<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveQuadratic(const Rational& p0, const Rational& p1, const Rational& p2, std::map<Real, int>& rmMap)
{
    const Rational rat2{ 2 };
    const auto q0 = p0 / p2;
    const auto q1 = p1 / p2;
    const auto q1Half = q1 / rat2;
    const auto c0 = q0 - q1Half * q1Half;

    std::map<Rational, int> rmLocalMap{};
    SolveDepressedQuadratic(c0, rmLocalMap);

    rmMap.clear();
    for (auto& rm : rmLocalMap)
    {
        const auto root = rm.first - q1Half;
        rmMap.emplace(static_cast<Real>(root), rm.second);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveCubic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, std::map<Real, int>& rmMap)
{
    const Rational rat2{ 2 };
    const Rational rat3{ 3 };
    const auto q0 = p0 / p3;
    const auto q1 = p1 / p3;
    const auto q2 = p2 / p3;
    const auto q2Third = q2 / rat3;
    const auto c0 = q0 - q2Third * (q1 - rat2 * q2Third * q2Third);
    const auto c1 = q1 - q2 * q2Third;

    std::map<Rational, int> rmLocalMap{};
    SolveDepressedCubic(c0, c1, rmLocalMap);

    rmMap.clear();
    for (auto& rm : rmLocalMap)
    {
        const auto root = rm.first - q2Third;
        rmMap.insert(static_cast<Real>(root), rm.second);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveQuartic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, const Rational& p4, std::map<Real, int>& rmMap)
{
    const Rational rat2{ 2 };
    const Rational rat3{ 3 };
    const Rational rat4{ 4 };
    const Rational rat6{ 6 };
    const auto q0 = p0 / p4;
    const auto q1 = p1 / p4;
    const auto q2 = p2 / p4;
    const auto q3 = p3 / p4;
    const auto q3Fourth = q3 / rat4;
    const auto q3FourthSqr = q3Fourth * q3Fourth;
    const auto c0 = q0 - q3Fourth * (q1 - q3Fourth * (q2 - q3FourthSqr * rat3));
    const auto c1 = q1 - rat2 * q3Fourth * (q2 - rat4 * q3FourthSqr);
    const auto c2 = q2 - rat6 * q3FourthSqr;

    std::map<Rational, int> rmLocalMap{};
    SolveDepressedQuartic(c0, c1, c2, rmLocalMap);

    rmMap.clear();
    for (auto& rm : rmLocalMap)
    {
        const auto root = rm.first - q3Fourth;
        rmMap.insert(static_cast<Real>(root), rm.second);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoQuadratic(const Rational& p0, const Rational& p1, const Rational& p2, std::vector<int>& info)
{
    const Rational rat2{ 2 };
    const auto q0 = p0 / p2;
    const auto q1 = p1 / p2;
    const auto q1Half = q1 / rat2;
    const auto c0 = q0 - q1Half * q1Half;

    info.clear();
    info.reserve(2);
    GetRootInfoDepressedQuadratic(c0, info);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoCubic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, std::vector<int>& info)
{
    const Rational rat2{ 2 };
    const Rational rat3{ 3 };
    const auto q0 = p0 / p3;
    const auto q1 = p1 / p3;
    const auto q2 = p2 / p3;
    const auto q2Third = q2 / rat3;
    const auto c0 = q0 - q2Third * (q1 - rat2 * q2Third * q2Third);
    const auto c1 = q1 - q2 * q2Third;

    info.clear();
    info.reserve(3);
    GetRootInfoDepressedCubic(c0, c1, info);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoQuartic(const Rational& p0, const Rational& p1, const Rational& p2, const Rational& p3, const Rational& p4, std::vector<int>& info)
{
    const Rational rat2{ 2 };
    const Rational rat3{ 3 };
    const Rational rat4{ 4 };
    const Rational rat6{ 6 };
    const auto q0 = p0 / p4;
    const auto q1 = p1 / p4;
    const auto q2 = p2 / p4;
    const auto q3 = p3 / p4;
    const auto q3Fourth = q3 / rat4;
    const auto q3FourthSqr = q3Fourth * q3Fourth;
    const auto c0 = q0 - q3Fourth * (q1 - q3Fourth * (q2 - q3FourthSqr * rat3));
    const auto c1 = q1 - rat2 * q3Fourth * (q2 - rat4 * q3FourthSqr);
    const auto c2 = q2 - rat6 * q3FourthSqr;

    info.clear();
    info.reserve(4);
    GetRootInfoDepressedQuartic(c0, c1, c2, info);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::RootsPolynomial<Real>::Find(int degree, const std::vector<Real>& c, int maxIterations, std::vector<Real>& roots)
{
    if (degree >= 0 && !c.empty())
    {
        constexpr Real zero{};

        while (degree >= 0 && Math::Approximate(c.at(degree), zero))
        {
            --degree;
        }

        if (degree > 0)
        {
            /// 计算柯西边界。
            constexpr auto one = Math::GetValue(1);

            auto invLeading = one / c.at(degree);

            auto maxValue = zero;
            for (auto i = 0; i < degree; ++i)
            {
                const auto value = std::fabs(c.at(i) * invLeading);
                if (value > maxValue)
                {
                    maxValue = value;
                }
            }

            auto bound = one + maxValue;

            return FindRecursive(degree, c, -bound, bound, maxIterations, roots);
        }
        else if (degree == 0)
        {
            /// 多项式是一个非零常数。
            return 0;
        }
        else
        {
            /// 该多项式完全为零。
            roots.at(0) = zero;

            return 1;
        }
    }
    else
    {
        // 无效的度数或c。.
        return 0;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::RootsPolynomial<Real>::Find(int degree, const std::vector<Real>& c, Real tMin, Real tMax, int maxIterations, Real& root)
{
    constexpr Real zero{};
    auto pMin = Evaluate(degree, c, tMin);
    if (Math::Approximate(pMin, zero))
    {
        root = tMin;
        return true;
    }
    auto pMax = Evaluate(degree, c, tMax);
    if (Math::Approximate(pMax, zero))
    {
        root = tMax;
        return true;
    }

    if (pMin * pMax > zero)
    {
        /// 目前还不知道区间是否为根的边界。
        return false;
    }

    if (tMin >= tMax)
    {
        /// 间隔结束时间的顺序无效。
        return false;
    }

    for (auto i = 1; i <= maxIterations; ++i)
    {
        root = Math::GetRational(1, 2) * (tMin + tMax);

        /// 当tMin和tMax是连续的浮点数时，此测试是为 'float'或'double'设计的。
        if (Math::Approximate(root, tMin) || Math::Approximate(root, tMax))
        {
            break;
        }

        const auto p = Evaluate(degree, c, root);
        const auto product = p * pMin;
        if (product < zero)
        {
            tMax = root;
            pMax = p;
        }
        else if (product > zero)
        {
            tMin = root;
            pMin = p;
        }
        else
        {
            break;
        }
    }

    return true;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveDepressedQuadratic(const Rational& c0, std::map<Rational, int>& rmMap)
{
    constexpr Rational zero{};
    if (c0 < zero)
    {
        /// 两个简单的根。
        Rational root1{ std::sqrt(static_cast<double>(-c0)) };
        const auto root0 = -root1;
        rmMap.emplace(root0, 1);
        rmMap.emplace(root1, 1);
    }
    else if (c0 == zero)
    {
        /// 一个双根
        rmMap.emplace(zero, 2);
    }
    else  // c0 > 0
    {
        /// 一对复杂的共轭根。
        /// Complex z0 = -q1/2 - i*sqrt(c0);
        /// Complex z0conj = -q1/2 + i*sqrt(c0);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveDepressedCubic(const Rational& c0, const Rational& c1, std::map<Rational, int>& rmMap)
{
    /// 处理c0 = 0的特殊情况，
    /// 在这种情况下，多项式简化为下压二次多项式。
    constexpr Rational zero{};
    if (Math::Approximate(c0, zero))
    {
        SolveDepressedQuadratic(c1, rmMap);
        auto iter = rmMap.find(zero);
        if (iter != rmMap.end())
        {
            /// 二次方的根为零，所以重数必须增加。
            ++iter->second;
        }
        else
        {
            /// 二次型的根不是零。插入立方体的那个。
            rmMap.emplace(zero, 1);
        }
        return;
    }

    /// 处理c0的特殊情况 c0 != 0 and c1 = 0.
    constexpr auto oneThird = 1.0 / 3.0;
    if (Math::Approximate(c1, zero))
    {
        /// 一个简单的真正根。
        Rational root0{};
        if (c0 > zero)
        {
            root0 = Rational{ -std::pow(static_cast<double>(c0), oneThird) };
        }
        else
        {
            root0 = Rational{ std::pow(-static_cast<double>(c0), oneThird) };
        }
        rmMap.emplace(root0, 1);

        /// 一个复共轭对。
        /// Complex z0 = root0*(-1 - i*sqrt(3))/2;
        /// Complex z0conj = root0*(-1 + i*sqrt(3))/2;
        return;
    }

    /// 此时， c0 != 0和 c1 != 0.
    const Rational rat2{ 2 };
    const Rational rat3{ 3 };
    const Rational rat4{ 4 };
    const Rational rat27{ 27 };
    const Rational rat108{ 108 };

    const auto delta = -(rat4 * c1 * c1 * c1 + rat27 * c0 * c0);
    if (delta > zero)
    {
        /// 三个简单的根。
        const auto deltaDiv108 = delta / rat108;
        const auto betaRe = -c0 / rat2;
        const auto betaIm = std::sqrt(deltaDiv108);
        const auto theta = std::atan2(betaIm, betaRe);
        const auto thetaDiv3 = theta / rat3;
        const auto angle = static_cast<double>(thetaDiv3);
        Rational cs{ std::cos(angle) };
        Rational sn{ std::sin(angle) };
        const auto rhoSqr = betaRe * betaRe + betaIm * betaIm;
        Rational rhoPowThird{ std::pow(static_cast<double>(rhoSqr), 1.0 / 6.0) };
        const auto temp0 = rhoPowThird * cs;
        const auto temp1 = rhoPowThird * sn * Rational{ std::sqrt(3.0) };
        const auto root0 = rat2 * temp0;
        const auto root1 = -temp0 - temp1;
        const auto root2 = -temp0 + temp1;
        rmMap.emplace(root0, 1);
        rmMap.emplace(root1, 1);
        rmMap.emplace(root2, 1);
    }
    else if (delta < zero)
    {
        /// 一个简单的根。
        const auto deltaDiv108 = delta / rat108;
        const auto temp0 = -c0 / rat2;
        Rational temp1{ std::sqrt(-static_cast<double>(deltaDiv108)) };
        const auto temp2 = temp0 - temp1;
        const auto temp3 = temp0 + temp1;
        if (temp2 >= zero)
        {
            temp2 = Rational{ std::pow(static_cast<double>(temp2), oneThird) };
        }
        else
        {
            temp2 = Rational{ -std::pow(-static_cast<double>(temp2), oneThird) };
        }
        if (temp3 >= zero)
        {
            temp3 = Rational{ std::pow(static_cast<double>(temp3), oneThird) };
        }
        else
        {
            temp3 = Rational{ -std::pow(-static_cast<double>(temp3), oneThird) };
        }
        const auto root0 = temp2 + temp3;
        rmMap.emplace(root0, 1);

        /// 一个复共轭对。
        /// Complex z0 = (-root0 - i*sqrt(3*root0*root0+4*c1))/2;
        /// Complex z0conj = (-root0 + i*sqrt(3*root0*root0+4*c1))/2;
    }
    else  // delta = 0
    {
        /// 一个单根和一个复根。
        const auto root0 = -rat3 * c0 / (rat2 * c1);
        const auto root1 = -rat2 * root0;
        rmMap.emplace(root0, 2);
        rmMap.emplace(root1, 1);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveDepressedQuartic(const Rational& c0, const Rational& c1, const Rational& c2, std::map<Rational, int>& rmMap)
{
    /// 处理c0=0的特殊情况，在这种情况下，多项式减少为一个压低的三次方。
    constexpr Rational zero{};
    if (Math::Approximate(c0, zero))
    {
        SolveDepressedCubic(c1, c2, rmMap);
        auto iter = rmMap.find(zero);
        if (iter != rmMap.end())
        {
            /// 三次方的根为零，因此必须增加多重性。
            ++iter->second;
        }
        else
        {
            /// 立方体的根不是零。插入四次方的那个。
            rmMap.emplace(zero, 1);
        }
        return;
    }

    /// 处理c1=0的特殊情况，在这种情况下，四次方是双二次方
    ///   x^4 + c1*x^2 + c0 = (x^2 + c2/2)^2 + (c0 - c2^2/4)
    if (Math::Approximate(c1, zero))
    {
        SolveBiquadratic(c0, c2, rmMap);
        return;
    }

    /// 此时，c0 != 0和c1 != 0，这是必须使用特殊三次多项式的根的通用求解器的要求。
    const Rational rat2{ 2 };
    const Rational rat4{ 4 };
    const Rational rat8{ 8 };
    const Rational rat12{ 12 };
    const Rational rat16{ 16 };
    const Rational rat27{ 27 };
    const Rational rat36{ 36 };

    const auto c0Sqr = c0 * c0;
    const auto c1Sqr = c1 * c1;
    const auto c2Sqr = c2 * c2;
    const auto delta = c1Sqr * (-rat27 * c1Sqr + rat4 * c2 * (rat36 * c0 - c2Sqr)) + rat16 * c0 * (c2Sqr * (c2Sqr - rat8 * c0) + rat16 * c0Sqr);
    const auto a0 = rat12 * c0 + c2Sqr;
    const auto a1 = rat4 * c0 - c2Sqr;

    if (delta > zero)
    {
        if (c2 < zero && a1 < zero)
        {
            /// 四个简单的真正根。
            std::map<Real, int> rmCubicMap{};
            SolveCubic(c1Sqr - rat4 * c0 * c2, rat8 * c0, rat4 * c2, -rat8, rmCubicMap);
            Rational t{ rmCubicMap.rbegin()->first };
            const auto alphaSqr = rat2 * t - c2;
            Rational alpha{ std::sqrt(std::max(static_cast<double>(alphaSqr), 0.0)) };
            auto sgnC1 = 0.0;
            if (c1 > zero)
            {
                sgnC1 = 1.0;
            }
            else
            {
                sgnC1 = -1.0;
            }
            const auto arg = t * t - c0;
            Rational beta{ sgnC1 * std::sqrt(std::max(static_cast<double>(arg), 0.0)) };
            const auto d0 = alphaSqr - rat4 * (t + beta);
            Rational sqrtD0{ std::sqrt(std::max(static_cast<double>(d0), 0.0)) };
            const auto d1 = alphaSqr - rat4 * (t - beta);
            Rational sqrtD1{ std::sqrt(std::max(static_cast<double>(d1), 0.0)) };
            const auto root0 = (alpha - sqrtD0) / rat2;
            const auto root1 = (alpha + sqrtD0) / rat2;
            const auto root2 = (-alpha - sqrtD1) / rat2;
            const auto root3 = (-alpha + sqrtD1) / rat2;
            rmMap.emplace(root0, 1);
            rmMap.emplace(root1, 1);
            rmMap.emplace(root2, 1);
            rmMap.emplace(root3, 1);
        }
        else  // c2 >= 0 or a1 >= 0
        {
            /// 两个复共轭对。值alpha、D0和D1是if块的值。
            /// Complex z0 = (alpha - i*sqrt(-D0))/2;
            /// Complex z0conj = (alpha + i*sqrt(-D0))/2;
            /// Complex z1 = (-alpha - i*sqrt(-D1))/2;
            /// Complex z1conj = (-alpha + i*sqrt(-D1))/2;
        }
    }
    else if (delta < zero)
    {
        /// 两个简单实根，一个复共轭对。
        std::map<Real, int> rmCubicMap{};
        SolveCubic(c1Sqr - rat4 * c0 * c2, rat8 * c0, rat4 * c2, -rat8, rmCubicMap);
        Rational t{ rmCubicMap.rbegin()->first };
        const auto alphaSqr = rat2 * t - c2;
        Rational alpha{ std::sqrt(std::max(static_cast<double>(alphaSqr), 0.0)) };
        auto sgnC1 = 0.0;
        if (c1 > zero)
        {
            sgnC1 = 1.0;
        }
        else
        {
            sgnC1 = -1.0;
        }
        const auto arg = t * t - c0;
        Rational beta{ sgnC1 * std::sqrt(std::max(static_cast<double>(arg), 0.0)) };
        Rational root0{};
        Rational root1{};
        if (sgnC1 > 0.0)
        {
            const auto d1 = alphaSqr - rat4 * (t - beta);
            Rational sqrtD1{ std::sqrt(std::max(static_cast<double>(d1), 0.0)) };
            root0 = (-alpha - sqrtD1) / rat2;
            root1 = (-alpha + sqrtD1) / rat2;

            /// 一个复共轭对。
            /// Complex z0 = (alpha - i*sqrt(-D0))/2;
            /// Complex z0conj = (alpha + i*sqrt(-D0))/2;
        }
        else
        {
            const auto d0 = alphaSqr - rat4 * (t + beta);
            Rational sqrtD0{ std::sqrt(std::max(static_cast<double>(d0), 0.0)) };
            root0 = (alpha - sqrtD0) / rat2;
            root1 = (alpha + sqrtD0) / rat2;

            /// 一个复共轭对。
            /// Complex z0 = (-alpha - i*sqrt(-D1))/2;
            /// Complex z0conj = (-alpha + i*sqrt(-D1))/2;
        }
        rmMap.emplace(root0, 1);
        rmMap.emplace(root1, 1);
    }
    else  // delta = 0
    {
        if (a1 > zero || (c2 > zero && (a1 != zero || c1 != zero)))
        {
            /// 一个双实根，一个复共轭对。
            const Rational rat9{ 9 };
            const auto root0 = -c1 * a0 / (rat9 * c1Sqr - rat2 * c2 * a1);
            rmMap.emplace(root0, 2);

            /// 一个复共轭对。
            /// Complex z0 = -root0 - i*sqrt(c2 + root0^2);
            /// Complex z0conj = -root0 + i*sqrt(c2 + root0^2);
        }
        else
        {
            const Rational rat3{ 3 };
            if (!Math::Approximate(a0, zero))
            {
                /// 一个双实根，两个简单实根。
                const Rational rat9{ 9 };
                const auto root0 = -c1 * a0 / (rat9 * c1Sqr - rat2 * c2 * a1);
                const auto alpha = rat2 * root0;
                const auto beta = c2 + rat3 * root0 * root0;
                const auto discr = alpha * alpha - rat4 * beta;
                Rational temp1{ std::sqrt(std::max(static_cast<double>(discr), 0.0)) };
                const auto root1 = (-alpha - temp1) / rat2;
                const auto root2 = (-alpha + temp1) / rat2;
                rmMap.emplace(root0, 2);
                rmMap.emplace(root1, 1);
                rmMap.emplace(root2, 1);
            }
            else
            {
                /// 一个三重实根，一个简单实根。
                const auto root0 = -rat3 * c1 / (rat4 * c2);
                const auto root1 = -rat3 * root0;
                rmMap.emplace(root0, 3);
                rmMap.emplace(root1, 1);
            }
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::SolveBiquadratic(const Rational& c0, const Rational& c2, std::map<Rational, int>& rmMap)
{
    /// 求解x^4 + c2*x^2 + c0 = 0。我们知道 c0 != 0，所以x=0不是根。
    /// 定义u = -c2/2 和 v = c2^2/4 - c0 = u^2 - c0。使用二次公式，
    ///   x^2 在 { u-sqrt(v), u+sqrt(v) }中
    /// 计算平方根，
    ///   x is in { -sqrt(u-sqrt(v)), sqrt(u-sqrt(v)),
    ///             -sqrt(u+sqrt(v)), sqrt(u+sqrt(v)) }
    /// 因为我们知道c0 != 0，这意味着0不是根，
    /// 它必须是 u-sqrt(v) != 0和u+sqrt(v) != 0.
    ///
    /// 设z = a+b*i与b != 0。平方根是+/- (c+d*i)
    ///  这里
    ///   c = sqrt((a+sqrt(a^2+b^2))/2)
    ///   d = sign(b) * sqrt((-a+sqrt(a^2+b^2))/2)
    ///
    /// v > 0, u-sqrt(v) > 0 [implies u+sqrt(v) > 0]: (block 23)
    ///   四个实根: r0, -r0, r1, -r1
    ///     r0 = sqrt(u-sqrt(v))
    ///     r1 = sqrt(u+sqrt(v))
    ///
    /// v > 0, u+sqrt(v) < 0 [implies u-sqrt(v) < 0]: (block 24)
    ///  两个复共轭对: z0, conj(z0), -z1, -conj(z1)
    ///     z0 = sqrt(-u+sqrt(v)) * i
    ///     z1 = sqrt(-u-sqrt(v)) * i
    ///
    /// v > 0, u-sqrt(v) < 0, u+sqrt(v) > 0: (block 25)
    ///   两个实根，一个复共轭对: r0, -r0, z0, conj(z0)
    ///    r0 = sqrt(u+sqrt(v))
    ///    z0 = sqrt(-u+sqrt(v)) * i
    ///
    /// v < 0: (block 26)
    ///   两个复共轭对: z0, conj(z0), -z0, -conj(z0)
    ///     z0 = sqrt((u+sqrt(u^2-v))/2) - sqrt((-u+sqrt(u^2-v))/2) * i
    ///        = sqrt((-c2/2+sqrt(c0))/2) - sqrt((c2/2+sqrt(c0))/2) * i
    ///
    /// v = 0, u > 0: (block 27)
    ///   两个实根，每个根具有多重性 2: r0, -r0
    ///     r0 = sqrt(u) = sqrt(-c2/2)
    ///
    /// v = 0, u < 0: (block 28)
    ///   两个复共轭对： z0, conj(z0), -z0, -conj(z0)
    ///     z0 = sqrt(-u) * i = sqrt(c2/2) * i

    constexpr Rational zero{};
    const auto u = c2 / Rational{ -2 };
    const auto v = u * u - c0;
    if (v > zero)
    {
        const auto sqrtV = std::sqrt(v);
        const auto upSqrtV = u + sqrtV;

        /// 计算 u - sqrt(v) = c0 / (u + sqrt(v))以避免相减消除。
        const auto umSqrtV = c0 / upSqrtV;
        if (umSqrtV > zero)
        {
            /// 实数根: r0, -r0, r1, -r1
            /// r0 = sqrt(u-sqrt(v))
            /// r1 = sqrt(u+sqrt(v))
            const auto r0 = std::sqrt(umSqrtV);
            const auto r1 = std::sqrt(upSqrtV);
            rmMap.emplace(r0, 1);
            rmMap.emplace(-r0, 1);
            rmMap.emplace(r1, 1);
            rmMap.emplace(-r1, 1);
        }
        else if (upSqrtV < zero)
        {
            /// 复杂的根: z0, conj(z0), -z1, -conj(z1)
            /// z0 = sqrt(-u+sqrt(v)) * i
            /// z1 = sqrt(-u-sqrt(v)) * i
        }
        else  // umSqrtV < 0 and upSqrtV > 0
        {
            /// 实根: r0, -r0
            /// 复杂的根: z0, conj(z0)
            /// r0 = sqrt(u+sqrt(v))
            /// z0 = sqrt(-u+sqrt(v)) * i
            const auto r0 = std::sqrt(upSqrtV);
            rmMap.emplace(r0, 1);
            rmMap.emplace(-r0, 1);
        }
    }
    else if (v < zero)
    {
        /// 复杂的根: z0, conj(z0), -z0, -conj(z0)
        /// z0 = sqrt((u+sqrt(u^2-v))/2)
        ///      - sqrt((-u+sqrt(u^2-v))/2) * i
    }
    else  // v = 0
    {
        if (u > zero)
        {
            /// 实根: r0, r0, -r0, -r0
            /// r0 = sqrt(u)
            const auto r0 = std::sqrt(u);
            rmMap.emplace(r0, 2);
            rmMap.emplace(-r0, 2);
        }
        else  // u < 0
        {
            /// 复杂的根: z0, conj(z0), z0, conj(z0)
            /// z0 = sqrt(-u) * i
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoDepressedQuadratic(const Rational& c0, std::vector<int>& info)
{
    constexpr Rational zero{};
    if (c0 < zero)
    {
        /// 两个简单的根。
        info.emplace_back(1);
        info.emplace_back(1);
    }
    else if (c0 == zero)
    {
        /// 一个double根。
        info.emplace_back(2);  // 根为零
    }
    else  // c0 > 0
    {
        /// 一对复杂的共轭根。
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoDepressedCubic(const Rational& c0, const Rational& c1, std::vector<int>& info)
{
    /// 处理c0 = 0的特殊情况，在这种情况下，多项式简化为下压二次多项式。
    constexpr Rational zero{};
    if (c0 == zero)
    {
        if (c1 == zero)
        {
            info.emplace_back(3);  /// 零的三根
        }
        else
        {
            info.emplace_back(1);  /// 简单零根
            GetRootInfoDepressedQuadratic(c1, info);
        }
        return;
    }

    const Rational rat4{ 4 };
    const Rational rat27{ 27 };
    const auto delta = -(rat4 * c1 * c1 * c1 + rat27 * c0 * c0);
    if (delta > zero)
    {
        /// 三个简单的真正根源。
        info.emplace_back(1);
        info.emplace_back(1);
        info.emplace_back(1);
    }
    else if (delta < zero)
    {
        /// 一个简单的真正根源。
        info.emplace_back(1);
    }
    else  // delta = 0
    {
        /// 一个简单实根和一个二重实根。
        info.emplace_back(1);
        info.emplace_back(2);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoDepressedQuartic(const Rational& c0, const Rational& c1, const Rational& c2, std::vector<int>& info)
{
    /// 处理c0 = 0的特殊情况，在这种情况下，多项式减少为一个压低的三次方。
    constexpr Rational zero{};
    if (c0 == zero)
    {
        if (c1 == zero)
        {
            if (c2 == zero)
            {
                info.emplace_back(4);  /// 零的四次根
            }
            else
            {
                info.emplace_back(2);  /// 零的二重根
                GetRootInfoDepressedQuadratic(c2, info);
            }
        }
        else
        {
            info.emplace_back(1);  /// 简单零根
            GetRootInfoDepressedCubic(c1, c2, info);
        }
        return;
    }

    /// 处理 c1 = 0的特殊情况，在这种情况下，四次方是双二次方
    ///   x^4 + c1*x^2 + c0 = (x^2 + c2/2)^2 + (c0 - c2^2/4)
    if (c1 == zero)
    {
        GetRootInfoBiquadratic(c0, c2, info);
        return;
    }

    /// 此时，c0 != 0和c1 != 0，
    /// 这是必须使用特殊三次多项式的根的通用求解器的要求。

    const Rational rat4{ 4 };
    const Rational rat8{ 8 };
    const Rational rat12{ 12 };
    const Rational rat16{ 16 };
    const Rational rat27{ 27 };
    const Rational rat36{ 36 };

    const auto c0Sqr = c0 * c0;
    const auto c1Sqr = c1 * c1;
    const auto c2Sqr = c2 * c2;
    const auto delta = c1Sqr * (-rat27 * c1Sqr + rat4 * c2 * (rat36 * c0 - c2Sqr)) + rat16 * c0 * (c2Sqr * (c2Sqr - rat8 * c0) + rat16 * c0Sqr);
    const auto a0 = rat12 * c0 + c2Sqr;
    const auto a1 = rat4 * c0 - c2Sqr;

    if (delta > zero)
    {
        if (c2 < zero && a1 < zero)
        {
            /// 四个简单的真正根源
            info.emplace_back(1);
            info.emplace_back(1);
            info.emplace_back(1);
            info.emplace_back(1);
        }
        else  // c2 >= 0 or a1 >= 0
        {
            /// 两个复共轭对。
        }
    }
    else if (delta < zero)
    {
        /// 两个简单实根，一个复共轭对。
        info.emplace_back(1);
        info.emplace_back(1);
    }
    else  // delta = 0
    {
        if (a1 > zero || (c2 > zero && (a1 != zero || c1 != zero)))
        {
            /// 一个双实根，一个复共轭对。
            info.emplace_back(2);
        }
        else
        {
            if (a0 != zero)
            {
                /// 一个双实根，两个简单实根。
                info.emplace_back(2);
                info.emplace_back(1);
                info.emplace_back(1);
            }
            else
            {
                /// 一个三重实根，一个简单实根。
                info.emplace_back(3);
                info.emplace_back(1);
            }
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <typename Rational>
void Mathematics::RootsPolynomial<Real>::GetRootInfoBiquadratic(const Rational& c0, const Rational& c2, std::vector<int>& info)
{
    constexpr Rational zero{};
    const auto u = c2 / Rational{ -2 };
    const auto v = u * u - c0;
    if (v > zero)
    {
        Rational sqrtV{ std::sqrt(v) };
        Rational upSqrtV = u + sqrtV;
        Rational umSqrtV = c0 / upSqrtV;
        if (umSqrtV > zero)
        {
            // 四个简单的根。
            info.emplace_back(1);
            info.emplace_back(1);
            info.emplace_back(1);
            info.emplace_back(1);
        }
        else if (upSqrtV < zero)
        {
            // 两个简单复共轭对。
        }
        else  // umSqrtV < 0 and upSqrtV > 0
        {
            /// 两个简单实根，一个复共轭对。
            info.emplace_back(1);
            info.emplace_back(1);
        }
    }
    else if (v < zero)
    {
        /// 两个简单复共轭对
    }
    else  // v = 0
    {
        if (u > zero)
        {
            /// 两个双实根。
            info.emplace_back(2);
            info.emplace_back(2);
        }
        else  // u < 0
        {
            /// 双复共轭对
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::RootsPolynomial<Real>::FindRecursive(int degree, const std::vector<Real>& c, Real tMin, Real tMax, int maxIterations, std::vector<Real>& roots)
{
    /// 递归的基础。
    constexpr Real zero{};
    auto root = zero;
    if (degree == 1)
    {
        int numRoots{};
        if (!Math::Approximate(c.at(1), zero))
        {
            root = -c.at(0) / c.at(1);
            numRoots = 1;
        }
        else if (!Math::Approximate(c.at(0), zero))
        {
            root = zero;
            numRoots = 1;
        }
        else
        {
            numRoots = 0;
        }

        if (numRoots > 0 && tMin <= root && root <= tMax)
        {
            roots.at(0) = root;
            return 1;
        }
        return 0;
    }

    /// 求按1/次缩放的导数多项式的根。
    /// 缩放避免了系数的阶乘增长；
    /// 例如，在没有缩放的情况下，
    /// 高阶项x^d通过多次微分变为(d!)*x。
    /// 通过缩放，我们得到了x。这导致了寻根器更好的数值行为。
    const auto derivativeDegree = degree - 1;
    std::vector<Real> derivativeCoefficients(gsl::narrow_cast<size_t>(derivativeDegree) + 1);
    std::vector<Real> derivativeRoots(derivativeDegree);
    for (auto i = 0, ip1 = 1; i <= derivativeDegree; ++i, ++ip1)
    {
        derivativeCoefficients.at(i) = c.at(ip1) * Math::GetValue(ip1) / Math::GetValue(degree);
    }
    const auto numDerivativeRoots = FindRecursive(degree - 1, derivativeCoefficients, tMin, tMax, maxIterations, derivativeRoots);

    int numRoots = 0;
    if (numDerivativeRoots > 0)
    {
        /// 在[tMin,derivativeRoots[0]]上查找根
        if (Find(degree, c, tMin, derivativeRoots.at(0), maxIterations, root))
        {
            roots.at(numRoots++) = root;
        }

        /// 在 [derivativeRoots[i],derivativeRoots[i+1]]上查找根
        for (auto i = 0, ip1 = 1; i <= numDerivativeRoots - 2; ++i, ++ip1)
        {
            if (Find(degree, c, derivativeRoots.at(i), derivativeRoots.at(ip1), maxIterations, root))
            {
                roots.at(numRoots++) = root;
            }
        }

        /// 在[derivativeRoots[numDerivativeRoots-1],tMax]上查找根
        if (Find(degree, c, derivativeRoots.at(gsl::narrow_cast<size_t>(numDerivativeRoots) - 1), tMax, maxIterations, root))
        {
            roots.at(numRoots++) = root;
        }
    }
    else
    {
        /// 多项式在[tMin,tMax]上是单调的，因此最多有一个根。
        if (Find(degree, c, tMin, tMax, maxIterations, root))
        {
            roots.at(numRoots++) = root;
        }
    }
    return numRoots;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::RootsPolynomial<Real>::Evaluate(int degree, const std::vector<Real>& c, Real t)
{
    auto i = degree;
    auto result = c.at(i);
    while (--i >= 0)
    {
        result = t * result + c.at(i);
    }
    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_POLYNOMIAL_DETAIL_H
