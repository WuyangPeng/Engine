///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:51)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_DETAIL_H

#include "NaturalSpline1.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::NaturalSpline1<Real>::NaturalSpline1(bool free, int numSamples, const std::vector<Real>& times, const std::vector<Real>& values)
    : numSamples{ numSamples }, numSegments{ numSamples - 1 }, times{ times }, a{ values }, b{}, c{}, d{}
{
    MATHEMATICS_ASSERTION_0(numSamples >= 2, "无效输入。\n");

    if (free)
    {
        CreateFreeSpline();
    }
    else
    {
        CreatePeriodicSpline();
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::NaturalSpline1<Real>::NaturalSpline1(int numSamples, const std::vector<Real>& times, const std::vector<Real>& values, Real slopeFirst, Real slopeLast)
    : numSamples{ numSamples }, numSegments{ numSamples - 1 }, times{ times }, a{ values }, b{}, c{}, d{}
{
    MATHEMATICS_ASSERTION_0(numSamples >= 2, "无效输入。\n");

    CreateClampedSpline(slopeFirst, slopeLast);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::NaturalSpline1<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::NaturalSpline1<Real>::GetFunction(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    GetKeyInfo(t, key, dt);

    return a.at(key) + dt * (b.at(key) + dt * (c.at(key) + dt * d.at(key)));
}

template <typename Real>
Real Mathematics::NaturalSpline1<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    GetKeyInfo(t, key, dt);

    return b.at(key) + dt * (c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * ((Math<Real>::GetValue(3)) * dt));
}

template <typename Real>
Real Mathematics::NaturalSpline1<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    GetKeyInfo(t, key, dt);

    return c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * ((Math<Real>::GetValue(6)) * dt);
}

template <typename Real>
Real Mathematics::NaturalSpline1<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    GetKeyInfo(t, key, dt);

    return Math<Real>::GetValue(6) * d.at(key);
}

template <typename Real>
int Mathematics::NaturalSpline1<Real>::GetNumSegments() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numSegments;
}

template <typename Real>
std::vector<Real> Mathematics::NaturalSpline1<Real>::GetA() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return a;
}

template <typename Real>
std::vector<Real> Mathematics::NaturalSpline1<Real>::GetB() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return b;
}

template <typename Real>
std::vector<Real> Mathematics::NaturalSpline1<Real>::GetC() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return c;
}

template <typename Real>
std::vector<Real> Mathematics::NaturalSpline1<Real>::GetD() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return d;
}

template <typename Real>
void Mathematics::NaturalSpline1<Real>::CreateFreeSpline()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    b.resize(numSegments);
    c.resize(gsl::narrow_cast<size_t>(numSegments) + 1);
    d.resize(numSegments);

    std::vector<Real> delta(numSamples);
    std::vector<Real> invDelta(numSamples);
    std::vector<Real> fDeriv(numSamples);

    for (auto i = 0; i < numSamples; ++i)
    {
        delta.at(i) = times.at(gsl::narrow_cast<size_t>(i) + 1) - times.at(i);
        invDelta.at(i) = (Math<Real>::GetValue(1)) / delta.at(i);
        fDeriv.at(i) = (a.at(gsl::narrow_cast<size_t>(i) + 1) - a.at(i)) * invDelta.at(i);
    }

    const auto numSegmentsM1 = numSegments - 1;
    std::vector<Real> diagonal(numSegmentsM1);
    std::vector<Real> rhs(numSegmentsM1);
    for (auto i = 0; i < numSegmentsM1; ++i)
    {
        diagonal.at(i) = (Math<Real>::GetValue(2)) * (delta.at(gsl::narrow_cast<size_t>(i) + 1) + delta.at(i));
        rhs.at(i) = Math<Real>::GetValue(3) * (fDeriv.at(gsl::narrow_cast<size_t>(i) + 1) - fDeriv.at(i));
    }

    std::vector<Real> upper{ delta };
    if (!upper.empty())
    {
        upper.erase(upper.begin());
    }

    c = LinearSystem<Real>().SolveTridiagonal(numSegmentsM1, delta, diagonal, upper, rhs);
    c.insert(c.begin(), Math<Real>::GetValue(0));
    c.emplace_back(Math<Real>::GetValue(0));

    constexpr auto oneThird = Math<Real>::GetRational(1, 3);
    for (auto i = 0; i < numSegments; ++i)
    {
        b.at(i) = fDeriv.at(i) - delta.at(i) * oneThird * (c.at(gsl::narrow_cast<size_t>(i) + 1) + (Math<Real>::GetValue(2)) * c.at(i));
        d.at(i) = oneThird * (c.at(gsl::narrow_cast<size_t>(i) + 1) - c.at(i)) * invDelta.at(i);
    }
}

template <typename Real>
void Mathematics::NaturalSpline1<Real>::CreateClampedSpline(Real slopeFirst, Real slopeLast)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    b.resize(gsl::narrow_cast<size_t>(numSegments) + 1);
    c.resize(numSegments);
    d.resize(numSegments);

    std::vector<Real> delta(numSamples);
    std::vector<Real> invDelta(numSamples);
    std::vector<Real> fDeriv(numSamples);

    for (auto i = 0; i < numSamples; ++i)
    {
        delta.at(i) = times.at(gsl::narrow_cast<size_t>(i) + 1) - times.at(i);
        invDelta.at(i) = (Math<Real>::GetValue(1)) / delta.at(i);
        fDeriv.at(i) = (a.at(gsl::narrow_cast<size_t>(i) + 1) - a.at(i)) * invDelta.at(i);
    }

    const auto numSegmentsM1 = numSegments - 1;
    std::vector<Real> diagonal(numSegmentsM1);
    std::vector<Real> rhs(numSegmentsM1);
    for (auto i = 0; i < numSegmentsM1; ++i)
    {
        diagonal.at(i) = (Math<Real>::GetValue(2)) * (delta.at(gsl::narrow_cast<size_t>(i) + 1) + delta.at(i));
        rhs.at(i) = Math<Real>::GetValue(3) * (delta.at(i) * fDeriv.at(gsl::narrow_cast<size_t>(i) + 1) + delta.at(gsl::narrow_cast<size_t>(i) + 1) * fDeriv.at(i));
    }

    rhs.at(0) -= slopeFirst * delta.at(1);
    const auto segmentIndex = numSegments - 2;
    rhs.at(segmentIndex) -= slopeLast * delta.at(segmentIndex);

    std::vector<Real> lower{};
    for (auto i = 2u; i < delta.size(); ++i)
    {
        lower.emplace_back(delta.at(i));
    }

    b = LinearSystem<Real>().SolveTridiagonal(numSegmentsM1, lower, diagonal, delta, rhs);
    b.insert(c.begin(), slopeFirst);
    b.emplace_back(slopeLast);

    constexpr auto oneThird = Math<Real>::GetRational(1, 3);
    for (auto i = 0; i < numSegments; ++i)
    {
        c.at(i) = (Math<Real>::GetValue(3) * fDeriv.at(i) - b.at(gsl::narrow_cast<size_t>(i) + 1) - (Math<Real>::GetValue(2)) * b.at(i)) * invDelta.at(i);
        d.at(i) = oneThird * (b.at(gsl::narrow_cast<size_t>(i) + 1) - b.at(i) - (Math<Real>::GetValue(2)) * delta.at(i) * c.at(i)) * invDelta.at(i) * invDelta.at(i);
    }
}

template <typename Real>
void Mathematics::NaturalSpline1<Real>::CreatePeriodicSpline()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    b.resize(numSegments);
    c.resize(numSegments);
    d.resize(numSegments);

    const auto size = 4 * numSegments;
    VariableMatrix<Real> mat{ size, size };
    VariableLengthVector<Real> rhs{ size };

    auto i = 0;
    auto j = 0;
    for (; i < numSegments - 1; ++i, j += 4)
    {
        auto delta = times.at(gsl::narrow_cast<size_t>(i) + 1) - times.at(i);
        auto delta2 = delta * delta;
        auto delta3 = delta * delta2;

        mat[j + 0][j + 0] = Math<Real>::GetValue(1);
        mat[j + 0][j + 1] = Math<Real>::GetValue(0);
        mat[j + 0][j + 2] = Math<Real>::GetValue(0);
        mat[j + 0][j + 3] = Math<Real>::GetValue(0);
        mat[j + 1][j + 0] = Math<Real>::GetValue(1);
        mat[j + 1][j + 1] = delta;
        mat[j + 1][j + 2] = delta2;
        mat[j + 1][j + 3] = delta3;
        mat[j + 2][j + 0] = Math<Real>::GetValue(0);
        mat[j + 2][j + 1] = Math<Real>::GetValue(1);
        mat[j + 2][j + 2] = (Math<Real>::GetValue(2)) * delta;
        mat[j + 2][j + 3] = (Math<Real>::GetValue(3)) * delta2;
        mat[j + 3][j + 0] = Math<Real>::GetValue(0);
        mat[j + 3][j + 1] = Math<Real>::GetValue(0);
        mat[j + 3][j + 2] = Math<Real>::GetValue(1);
        mat[j + 3][j + 3] = (Math<Real>::GetValue(3)) * delta;

        const auto k = j + 4;
        mat[j + 0][k + 0] = Math<Real>::GetValue(0);
        mat[j + 0][k + 1] = Math<Real>::GetValue(0);
        mat[j + 0][k + 2] = Math<Real>::GetValue(0);
        mat[j + 0][k + 3] = Math<Real>::GetValue(0);
        mat[j + 1][k + 0] = Math<Real>::GetValue(-1);
        mat[j + 1][k + 1] = Math<Real>::GetValue(0);
        mat[j + 1][k + 2] = Math<Real>::GetValue(0);
        mat[j + 1][k + 3] = Math<Real>::GetValue(0);
        mat[j + 2][k + 0] = Math<Real>::GetValue(0);
        mat[j + 2][k + 1] = Math<Real>::GetValue(-1);
        mat[j + 2][k + 2] = Math<Real>::GetValue(0);
        mat[j + 2][k + 3] = Math<Real>::GetValue(0);
        mat[j + 3][k + 0] = Math<Real>::GetValue(0);
        mat[j + 3][k + 1] = Math<Real>::GetValue(0);
        mat[j + 3][k + 2] = Math<Real>::GetValue(-1);
        mat[j + 3][k + 3] = Math<Real>::GetValue(0);
    }

    auto delta = times.at(gsl::narrow_cast<size_t>(i) + 1) - times.at(i);
    auto delta2 = delta * delta;
    auto delta3 = delta * delta2;

    mat[j + 0][j + 0] = Math<Real>::GetValue(1);
    mat[j + 0][j + 1] = Math<Real>::GetValue(0);
    mat[j + 0][j + 2] = Math<Real>::GetValue(0);
    mat[j + 0][j + 3] = Math<Real>::GetValue(0);
    mat[j + 1][j + 0] = Math<Real>::GetValue(1);
    mat[j + 1][j + 1] = delta;
    mat[j + 1][j + 2] = delta2;
    mat[j + 1][j + 3] = delta3;
    mat[j + 2][j + 0] = Math<Real>::GetValue(0);
    mat[j + 2][j + 1] = Math<Real>::GetValue(1);
    mat[j + 2][j + 2] = (Math<Real>::GetValue(2)) * delta;
    mat[j + 2][j + 3] = (Math<Real>::GetValue(3)) * delta2;
    mat[j + 3][j + 0] = Math<Real>::GetValue(0);
    mat[j + 3][j + 1] = Math<Real>::GetValue(0);
    mat[j + 3][j + 2] = Math<Real>::GetValue(1);
    mat[j + 3][j + 3] = (Math<Real>::GetValue(3)) * delta;

    constexpr auto k = 0;
    mat[j + 0][k + 0] = Math<Real>::GetValue(0);
    mat[j + 0][k + 1] = Math<Real>::GetValue(0);
    mat[j + 0][k + 2] = Math<Real>::GetValue(0);
    mat[j + 0][k + 3] = Math<Real>::GetValue(0);
    mat[j + 1][k + 0] = Math<Real>::GetValue(-1);
    mat[j + 1][k + 1] = Math<Real>::GetValue(0);
    mat[j + 1][k + 2] = Math<Real>::GetValue(0);
    mat[j + 1][k + 3] = Math<Real>::GetValue(0);
    mat[j + 2][k + 0] = Math<Real>::GetValue(0);
    mat[j + 2][k + 1] = Math<Real>::GetValue(-1);
    mat[j + 2][k + 2] = Math<Real>::GetValue(0);
    mat[j + 2][k + 3] = Math<Real>::GetValue(0);
    mat[j + 3][k + 0] = Math<Real>::GetValue(0);
    mat[j + 3][k + 1] = Math<Real>::GetValue(0);
    mat[j + 3][k + 2] = Math<Real>::GetValue(-1);
    mat[j + 3][k + 3] = Math<Real>::GetValue(0);

    for (i = 0, j = 0; i < numSegments; ++i, j += 4)
    {
        rhs[j + 0] = a.at(i);
        rhs[j + 1] = Math<Real>::GetValue(0);
        rhs[j + 2] = Math<Real>::GetValue(0);
        rhs[j + 3] = Math<Real>::GetValue(0);
    }

    VariableLengthVector<Real> coeff{ size };
    //bool solved =
    //   LinearSystem<Real>().Solve(mat, rhs.GetSize(), coeff.GetSize());
    // MATHEMATICS_ASSERTION_0(solved, "Failed to solve linear system\n");
    //WM5_UNUSED(solved);

    for (i = 0, j = 0; i < numSegments; ++i)
    {
        j++;
        b.at(i) = coeff[j++];
        c.at(i) = coeff[j++];
        d.at(i) = coeff[j++];
    }
}

template <typename Real>
void Mathematics::NaturalSpline1<Real>::GetKeyInfo(Real t, int& key, Real& dt) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (t <= times.at(0))
    {
        key = 0;
        dt = Math<Real>::GetValue(0);
    }
    else if (t >= times.at(numSegments))
    {
        key = numSegments - 1;
        dt = times.at(numSegments) - times.at(key);
    }
    else
    {
        for (auto i = 0; i < numSegments; ++i)
        {
            if (t < times.at(gsl::narrow_cast<size_t>(i) + 1))
            {
                key = i;
                dt = t - times.at(i);
                break;
            }
        }
    }
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_DETAIL_H
