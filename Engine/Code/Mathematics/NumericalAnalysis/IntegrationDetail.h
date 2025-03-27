/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 14:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_INTEGRATION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_INTEGRATION_DETAIL_H

#include "Integration.h"
#include "RootsPolynomial.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>
#include <array>

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Integration<Real>::Integration() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Integration<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Integration<Real>::TrapezoidRule(int numSamples, Real a, Real b, const std::function<Real(Real)>& integrand)
{
    const auto h = (b - a) / (MathType::GetValue(numSamples) - MathType::GetValue(1));
    auto result = MathType::GetRational(1, 2) * (integrand(a) + integrand(b));
    for (auto i = 1; i <= numSamples - 2; ++i)
    {
        result += integrand(a + MathType::GetValue(i) * h);
    }
    result *= h;
    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Integration<Real>::Romberg(int order, Real a, Real b, const std::function<Real(Real)>& integrand)
{
    constexpr auto half = MathType::GetRational(1, 2);
    std::vector<std::array<Real, 2>> rom(order);
    auto h = b - a;
    rom.at(0).at(0) = half * h * (integrand(a) + integrand(b));
    for (auto i0 = 2, p0 = 1; i0 <= order; ++i0, p0 *= 2, h *= half)
    {
        /// 通过梯形规则进行近似。
        Real sum{};
        auto i1 = 1;
        for (; i1 <= p0; ++i1)
        {
            sum += integrand(a + h * (MathType::GetValue(i1) - half));
        }

        /// 理查森推断。
        rom.at(0).at(1) = half * (rom.at(0).at(0) + h * sum);
        for (auto i2 = 1, i2M1 = 0, p2 = 4; i2 < i0; ++i2, ++i2M1, p2 *= 4)
        {
            rom.at(i2).at(1) = (MathType::GetValue(p2) * rom.at(i2M1).at(1) - rom.at(i2M1).at(0)) / MathType::GetValue(p2 - 1);
        }

        for (i1 = 0; i1 < i0; ++i1)
        {
            rom.at(i1).at(0) = rom.at(i1).at(1);
        }
    }

    const auto result = rom.at(gsl::narrow_cast<size_t>(order) - 1).at(0);
    return result;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Integration<Real>::ComputeQuadratureInfo(int degree, std::vector<Real>& roots, std::vector<Real>& coefficients)
{
    constexpr auto zero = MathType::GetValue(0);
    constexpr auto one = MathType::GetValue(1);
    constexpr auto half = MathType::GetRational(1, 2);

    std::vector<std::vector<Real>> poly(gsl::narrow_cast<size_t>(degree) + 1);

    poly.at(0).resize(1);
    poly.at(0).at(0) = one;

    poly.at(1).resize(2);
    poly.at(1).at(0) = zero;
    poly.at(1).at(1) = one;

    for (auto n = 2, nm1 = 1, nm2 = 0, np1 = 3; n <= degree; ++n, ++nm1, ++nm2, ++np1)
    {
        auto mult0 = MathType::GetValue(nm1) / MathType::GetValue(n);
        auto mult1 = (MathType::GetValue(2) * MathType::GetValue(n) - MathType::GetValue(1)) / MathType::GetValue(n);

        poly.at(n).resize(np1);
        poly.at(n).at(0) = -mult0 * poly.at(nm2).at(0);
        for (int i = 1, im1 = 0; i <= nm2; ++i, ++im1)
        {
            poly.at(n).at(i) = mult1 * poly.at(nm1).at(im1) - mult0 * poly.at(nm2).at(i);
        }
        poly.at(n).at(nm1) = mult1 * poly.at(nm1).at(nm2);
        poly.at(n).at(n) = mult1 * poly.at(nm1).at(nm1);
    }

    roots.resize(degree);
    RootsPolynomial<Real>::Find(degree, poly.at(degree), 2048, roots);

    coefficients.resize(roots.size());
    const auto n = roots.size() - 1;
    std::vector<Real> subRoots(n);
    for (auto i = 0u; i < roots.size(); ++i)
    {
        auto denominator = MathType::GetValue(1);
        for (auto j = 0u, k = 0u; j < roots.size(); ++j)
        {
            if (j != i)
            {
                subRoots.at(k++) = roots.at(j);
                denominator *= roots.at(i) - roots.at(j);
            }
        }

        std::array<Real, 2> delta{ -one - subRoots.back(),
                                   +one - subRoots.back() };

        std::vector<std::array<Real, 2>> weights(n);
        weights.at(0).at(0) = half * delta.at(0) * delta.at(0);
        weights.at(0).at(1) = half * delta.at(1) * delta.at(1);
        for (auto k = 1u; k < n; ++k)
        {
            auto dk = MathType::GetValue(k);
            auto mult = -dk / (dk + MathType::GetValue(2));
            weights.at(k).at(0) = mult * delta.at(0) * weights.at(k - 1).at(0);
            weights.at(k).at(1) = mult * delta.at(1) * weights.at(k - 1).at(1);
        }

        struct Info
        {
            int numBits;
            std::array<Real, 2> product;
        };

        const auto numElements = (1 << boost::numeric_cast<int>(n - 1));
        std::vector<Info> info(numElements);
        info.at(0).numBits = 0;
        info.at(0).product.at(0) = one;
        info.at(0).product.at(1) = one;
        for (auto iPow = 1, r = 0; iPow < numElements; iPow <<= 1, ++r)
        {
            info.at(iPow).numBits = 1;
            info.at(iPow).product.at(0) = -one - subRoots.at(r);
            info.at(iPow).product.at(1) = +one - subRoots.at(r);
            for (auto m = 1, j = iPow + 1; m < iPow; ++m, ++j)
            {
                info.at(j).numBits = info.at(m).numBits + 1;
                info.at(j).product.at(0) = info.at(iPow).product.at(0) * info.at(m).product.at(0);
                info.at(j).product.at(1) = info.at(iPow).product.at(1) * info.at(m).product.at(1);
            }
        }

        std::vector<std::array<Real, 2>> sum(n);
        constexpr std::array<Real, 2> zero2{ zero, zero };
        std::fill(sum.begin(), sum.end(), zero2);
        for (auto k = 0u; k < info.size(); ++k)
        {
            sum.at(info.at(k).numBits).at(0) += info.at(k).product.at(0);
            sum.at(info.at(k).numBits).at(1) += info.at(k).product.at(1);
        }

        auto total = zero2;
        for (auto k = 0u; k < n; ++k)
        {
            total.at(0) += weights.at(n - 1 - k).at(0) * sum.at(k).at(0);
            total.at(1) += weights.at(n - 1 - k).at(1) * sum.at(k).at(1);
        }

        coefficients.at(i) = (total.at(1) - total.at(0)) / denominator;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Integration<Real>::GaussianQuadrature(const std::vector<Real>& roots, const std::vector<Real>& coefficients, Real a, Real b, const std::function<Real(Real)>& integrand)
{
    constexpr auto half = MathType::GetRational(1, 2);
    const auto radius = half * (b - a);
    const auto center = half * (b + a);
    Real result{};
    for (auto i = 0u; i < roots.size(); ++i)
    {
        result += coefficients.at(i) * integrand(radius * roots.at(i) + center);
    }
    result *= radius;
    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_INTEGRATION_DETAIL_H
