///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:51)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_DETAIL_H

#include "NaturalSpline2.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"
#include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::NaturalSpline2<Real>::NaturalSpline2(BoundaryType type, int numSegments, const std::vector<Real>& times, const std::vector<Vector2<Real>>& points)
    : ParentType{ numSegments, times }, a{ points }, b{}, c{}, d{}
{
    switch (type)
    {
        case BoundaryType::Free:
        {
            CreateFreeSpline();
            break;
        }
        case BoundaryType::Clamped:
        {
            const auto derStart = a.at(1) - a.at(0);
            const auto derFinal = a.at(this->GetSegments()) - a.at(gsl::narrow_cast<size_t>(this->GetSegments()) - 1);
            CreateClampedSpline(derStart, derFinal);
            break;
        }
        case BoundaryType::Closed:
        {
            CreateClosedSpline();
            break;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::NaturalSpline2<Real>::NaturalSpline2(int numSegments, const std::vector<Real>& times, const std::vector<Vector2<Real>>& points, const Vector2<Real>& derivativeStart, const Vector2<Real>& derivativeFinal)
    : ParentType{ numSegments, times }, a{ points }, b{}, c{}, d{}
{
    CreateClampedSpline(derivativeStart, derivativeFinal);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::NaturalSpline2<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::NaturalSpline2<Real>::CreateFreeSpline()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto numSegments = this->GetSegments();
    std::vector<Real> dt(numSegments);

    for (auto i = 0; i < this->GetSegments(); ++i)
    {
        dt.at(i) = this->GetTimes(i + 1) - this->GetTimes(i);
    }

    std::vector<Real> d2t(numSegments);
    for (auto i = 1; i < this->GetSegments(); ++i)
    {
        d2t.at(i) = this->GetTimes(i + 1) - this->GetTimes(i - 1);
    }

    std::vector<Vector2<Real>> alpha(numSegments);
    for (auto i = 1; i < this->GetSegments(); ++i)
    {
        auto numer = Math<Real>::GetValue(3) * (a.at(gsl::narrow_cast<size_t>(i) + 1) * dt.at(gsl::narrow_cast<size_t>(i) - 1) - a.at(i) * d2t.at(i) + a.at(gsl::narrow_cast<size_t>(i) - 1) * dt.at(i));
        auto invDenom = Math<Real>::GetValue(1) / (dt.at(gsl::narrow_cast<size_t>(i) - 1) * dt.at(i));
        alpha.at(i) = invDenom * numer;
    }

    const auto size = numSegments + 1;
    std::vector<Real> ell(size);
    std::vector<Real> mu(numSegments);
    std::vector<Vector2<Real>> z(size);

    ell.at(0) = Math<Real>::GetValue(1);
    mu.at(0) = Math<Real>::GetValue(0);
    z.at(0) = Vector2<Real>::GetZero();
    for (auto i = 1; i < this->GetSegments(); ++i)
    {
        ell.at(i) = (Math<Real>::GetValue(2)) * d2t.at(i) - dt.at(gsl::narrow_cast<size_t>(i) - 1) * mu.at(gsl::narrow_cast<size_t>(i) - 1);
        auto inv = (Math<Real>::GetValue(1)) / ell.at(i);
        mu.at(i) = inv * dt.at(i);
        z.at(i) = inv * (alpha.at(i) - z.at(gsl::narrow_cast<size_t>(i) - 1) * dt.at(gsl::narrow_cast<size_t>(i) - 1));
    }
    ell.at(numSegments) = Math<Real>::GetValue(1);
    z.at(numSegments) = Vector2<Real>::GetZero();

    b.resize(numSegments);
    c.resize(size);
    d.resize(numSegments);

    c.at(numSegments) = Vector2<Real>::GetZero();

    constexpr auto oneThird = Math<Real>::GetRational(1, 3);
    for (auto i = numSegments - 1; i >= 0; --i)
    {
        c.at(i) = z.at(i) - mu.at(i) * c.at(gsl::narrow_cast<size_t>(i) + 1);
        auto inv = Math<Real>::GetValue(1) / dt.at(i);
        b.at(i) = inv * (a.at(gsl::narrow_cast<size_t>(i) + 1) - a.at(i)) - oneThird * dt.at(i) * (c.at(gsl::narrow_cast<size_t>(i) + 1) + Math<Real>::GetValue(2) * c.at(i));
        d.at(i) = oneThird * inv * (c.at(gsl::narrow_cast<size_t>(i) + 1) - c.at(i));
    }
}

template <typename Real>
void Mathematics::NaturalSpline2<Real>::CreateClampedSpline(const Vector2<Real>& derivativeStart, const Vector2<Real>& derivativeFinal)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto numSegments = this->GetSegments();
    std::vector<Real> dt(numSegments);

    for (auto i = 0; i < numSegments; ++i)
    {
        dt.at(i) = this->GetTimes(i + 1) - this->GetTimes(i);
    }

    std::vector<Real> d2t(numSegments);
    for (auto i = 1; i < numSegments; ++i)
    {
        d2t.at(i) = this->GetTimes(i + 1) - this->GetTimes(i - 1);
    }

    const auto size = numSegments + 1;
    std::vector<Vector2<Real>> alpha(size);
    auto inv = (Math<Real>::GetValue(1)) / dt.at(0);
    alpha.at(0) = Math<Real>::GetValue(3) * (inv * (a.at(1) - a.at(0)) - derivativeStart);
    inv = (Math<Real>::GetValue(1)) / dt.at(gsl::narrow_cast<size_t>(numSegments) - 1);
    alpha.at(numSegments) = Math<Real>::GetValue(3) * (derivativeFinal - inv * (a.at(numSegments) - a.at(gsl::narrow_cast<size_t>(numSegments) - 1)));
    for (auto i = 1; i < numSegments; ++i)
    {
        auto numer = Math<Real>::GetValue(3) * (a.at(gsl::narrow_cast<size_t>(i) + 1) * dt.at(gsl::narrow_cast<size_t>(i) - 1) - a.at(i) * d2t.at(i) + a.at(gsl::narrow_cast<size_t>(i) - 1) * dt.at(i));
        auto invDenom = Math<Real>::GetValue(1) / (dt.at(gsl::narrow_cast<size_t>(i) - 1) * dt.at(i));
        alpha.at(i) = invDenom * numer;
    }

    std::vector<Real> ell(size);
    std::vector<Real> mu(numSegments);
    std::vector<Vector2<Real>> z(size);

    ell.at(0) = (Math<Real>::GetValue(2)) * dt.at(0);
    mu.at(0) = Math<Real>::GetRational(1, 2);
    inv = (Math<Real>::GetValue(1)) / ell.at(0);
    z.at(0) = inv * alpha.at(0);

    for (auto i = 1; i < numSegments; ++i)
    {
        ell.at(i) = (Math<Real>::GetValue(2)) * d2t.at(i) - dt.at(gsl::narrow_cast<size_t>(i) - 1) * mu.at(gsl::narrow_cast<size_t>(i) - 1);
        inv = (Math<Real>::GetValue(1)) / ell.at(i);
        mu.at(i) = inv * dt.at(i);
        z.at(i) = inv * (alpha.at(i) - z.at(gsl::narrow_cast<size_t>(i) - 1) * dt.at(gsl::narrow_cast<size_t>(i) - 1));
    }
    ell.at(numSegments) = dt.at(gsl::narrow_cast<size_t>(numSegments) - 1) * (Math<Real>::GetValue(2) - mu.at(gsl::narrow_cast<size_t>(numSegments) - 1));
    inv = (Math<Real>::GetValue(1)) / ell.at(numSegments);
    z.at(numSegments) = inv * (alpha.at(numSegments) - z.at(gsl::narrow_cast<size_t>(numSegments) - 1) * dt.at(gsl::narrow_cast<size_t>(numSegments) - 1));

    b.resize(numSegments);
    c.resize(size);
    d.resize(numSegments);

    c.at(numSegments) = z.at(numSegments);

    constexpr auto oneThird = Math<Real>::GetRational(1, 3);
    for (auto i = numSegments - 1; i >= 0; --i)
    {
        c.at(i) = z.at(i) - mu.at(i) * c.at(gsl::narrow_cast<size_t>(i) + 1);
        inv = (Math<Real>::GetValue(1)) / dt.at(i);
        b.at(i) = inv * (a.at(gsl::narrow_cast<size_t>(i) + 1) - a.at(i)) - oneThird * dt.at(i) * (c.at(gsl::narrow_cast<size_t>(i) + 1) + (Math<Real>::GetValue(2)) * c.at(i));
        d.at(i) = oneThird * inv * (c.at(gsl::narrow_cast<size_t>(i) + 1) - c.at(i));
    }
}

template <typename Real>
void Mathematics::NaturalSpline2<Real>::CreateClosedSpline()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto numSegments = this->GetSegments();
    std::vector<Real> dt(numSegments);

    for (auto i = 0; i < numSegments; ++i)
    {
        dt.at(i) = this->GetTimes(i + 1) - this->GetTimes(i);
    }

    VariableMatrix<Real> mat{ numSegments + 1, numSegments + 1 };
    mat[0][0] = Math<Real>::GetValue(1);
    mat[0][numSegments] = Math<Real>::GetValue(-1);
    for (auto i = 1; i <= numSegments - 1; ++i)
    {
        mat[i][i - 1] = dt.at(gsl::narrow_cast<size_t>(i) - 1);
        mat[i][i] = (Math<Real>::GetValue(2)) * (dt.at(gsl::narrow_cast<size_t>(i) - 1) + dt.at(i));
        mat[i][i + 1] = dt.at(i);
    }
    mat[numSegments][numSegments - 1] = dt.at(gsl::narrow_cast<size_t>(numSegments) - 1);
    mat[numSegments][0] = (Math<Real>::GetValue(2)) * (dt.at(gsl::narrow_cast<size_t>(numSegments) - 1) + dt.at(0));
    mat[numSegments][1] = dt.at(0);

    c.resize(gsl::narrow_cast<size_t>(numSegments) + 1);
    c.at(0) = Vector2<Real>::GetZero();

    for (auto i = 1; i <= numSegments - 1; ++i)
    {
        auto inv0 = (Math<Real>::GetValue(1)) / dt.at(i);
        auto inv1 = (Math<Real>::GetValue(1)) / dt.at(gsl::narrow_cast<size_t>(i) - 1);
        c.at(i) = Math<Real>::GetValue(3) * (inv0 * (a.at(gsl::narrow_cast<size_t>(i) + 1) - a.at(i)) - inv1 * (a.at(i) - a.at(gsl::narrow_cast<size_t>(i) - 1)));
    }
    auto inv0 = (Math<Real>::GetValue(1)) / dt.at(0);
    auto inv1 = (Math<Real>::GetValue(1)) / dt.at(gsl::narrow_cast<size_t>(numSegments) - 1);
    c.at(numSegments) = Math<Real>::GetValue(3) * (inv0 * (a.at(1) - a.at(0)) - inv1 * (a.at(0) - a.at(gsl::narrow_cast<size_t>(numSegments) - 1)));

    std::vector<Real> input(gsl::narrow_cast<size_t>(numSegments) + 1);

    for (auto i = 0; i <= numSegments; ++i)
    {
        input.at(i) = c.at(i).GetX();
    }
    auto output = LinearSystem<Real>().Solve(mat, input);
    for (auto i = 0; i <= numSegments; ++i)
    {
        c.at(i).SetX(output.at(i));
    }

    for (auto i = 0; i <= numSegments; ++i)
    {
        input.at(i) = c.at(i).GetY();
    }
    output = LinearSystem<Real>().Solve(mat, input);
    for (auto i = 0; i <= numSegments; ++i)
    {
        c.at(i)[1] = output.at(i);
    }

    constexpr auto oneThird = Math<Real>::GetRational(1, 3);
    b.resize(numSegments);
    d.resize(numSegments);
    for (auto i = 0; i < numSegments; ++i)
    {
        inv0 = (Math<Real>::GetValue(1)) / dt.at(i);
        b.at(i) = inv0 * (a.at(gsl::narrow_cast<size_t>(i) + 1) - a.at(i)) - oneThird * (c.at(gsl::narrow_cast<size_t>(i) + 1) + (Math<Real>::GetValue(2)) * c.at(i)) * dt.at(i);
        d.at(i) = oneThird * inv0 * (c.at(gsl::narrow_cast<size_t>(i) + 1) - c.at(i));
    }
}

template <typename Real>
std::vector<Mathematics::Vector2<Real>> Mathematics::NaturalSpline2<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return a;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::NaturalSpline2<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);

    return a.at(key) + dt * (b.at(key) + dt * (c.at(key) + dt * d.at(key)));
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::NaturalSpline2<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);

    return b.at(key) + dt * (c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * (Math<Real>::GetValue(3) * dt));
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::NaturalSpline2<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);

    return c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * (Math<Real>::GetValue(6) * dt);
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::NaturalSpline2<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto key = 0;
    Real dt{};
    this->GetKeyInfo(t, key, dt);

    return Math<Real>::GetValue(6) * d.at(key);
}

template <typename Real>
Real Mathematics::NaturalSpline2<Real>::GetSpeedKey(int key, Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto velocity = b.at(key) + t * (c.at(key) * (Math<Real>::GetValue(2)) + d.at(key) * ((Math<Real>::GetValue(3)) * t));

    return Vector2Tools<Real>::GetLength(velocity);
}

template <typename Real>
Real Mathematics::NaturalSpline2<Real>::GetLengthKey(int key, Real t0, Real t1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const SplineKey data{ this, key };

    return RombergIntegral<Real, SplineKey>(8, t0, t1, GetSpeedWithDataKey, &data).GetValue();
}

template <typename Real>
Real Mathematics::NaturalSpline2<Real>::GetSpeedWithDataKey(Real t, const SplineKey* data)
{
    if (data != nullptr)
    {
        return data->spline->GetSpeedKey(data->key, t);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("data指针为空。"));
    }
}

// NaturalSpline2::SplineKey

template <typename Real>
Mathematics::NaturalSpline2<Real>::SplineKey::SplineKey(const NaturalSpline2* spline, int key) noexcept
    : spline{ spline }, key{ key }
{
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_DETAIL_H