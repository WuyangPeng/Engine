///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 19:08)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_DETAIL_H

#include "ContEllipsoid3MinCR.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Random.h"

template <typename Real>
Mathematics::ContEllipsoid3MinCR<Real>::ContEllipsoid3MinCR(const std::vector<Vector3<Real>>& points, const Vector3<Real>& c, const Matrix3<Real>& r, std::array<Real, 3>& d)
{
    std::vector<Vector3<Real>> a(points.size());
    for (auto i = 0u; i < points.size(); ++i)
    {
        const auto diff = points.at(i) - c;
        const auto prod = diff * r;

        a.at(i).SetX(prod.GetX() * prod.GetX());
        a.at(i).SetY(prod.GetY() * prod.GetY());
        a.at(i).SetZ(prod.GetZ() * prod.GetZ());
    }

    MaxProduct(a, d);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContEllipsoid3MinCR<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::ContEllipsoid3MinCR<Real>::FindEdgeMax(std::vector<Vector3<Real>>& a, int& plane0, const int& plane1, std::array<Real, 3>& d)
{
    auto xDir = a.at(plane0)[1] * a.at(plane1)[2] - a.at(plane1)[1] * a.at(plane0)[2];
    auto yDir = a.at(plane0)[2] * a.at(plane1)[0] - a.at(plane1)[2] * a.at(plane0)[0];
    auto zDir = a.at(plane0)[0] * a.at(plane1)[1] - a.at(plane1)[0] * a.at(plane0)[1];

    auto a0 = d.at(0) * d.at(1) * zDir + d.at(0) * d.at(2) * yDir + d.at(1) * d.at(2) * xDir;
    auto a1 = Math<Real>::GetValue(2) * (d.at(2) * xDir * yDir + d.at(1) * xDir * zDir + d.at(0) * yDir * zDir);
    auto a2 = Math<Real>::GetValue(3) * (xDir * yDir * zDir);

    Real tFinal{};
    if (Math<Real>::Approximate(a2, Math<Real>::GetValue(0)))
    {
        auto invA2 = Math<Real>::GetValue(1) / a2;
        auto discr = a1 * a1 - Math<Real>::GetValue(4) * a0 * a2;
        discr = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
        tFinal = (a1 + discr) * invA2 / Math<Real>::GetValue(-2);
        if (a1 + (Math<Real>::GetValue(2)) * a2 * tFinal > Math<Real>::GetValue(0))
        {
            tFinal = Math<Real>::GetRational(1, 2) * (-a1 + discr) * invA2;
        }
    }
    else if (Math<Real>::Approximate(a1, Math<Real>::GetValue(0)))
    {
        tFinal = -a0 / a1;
    }
    else if (Math<Real>::Approximate(a0, Math<Real>::GetValue(0)))
    {
        tFinal = (a0 >= Math<Real>::GetValue(0) ? Math<Real>::maxReal : -Math<Real>::maxReal);
    }
    else
    {
        return;
    }

    if (tFinal < Math<Real>::GetValue(0))
    {
        tFinal = -tFinal;
        xDir = -xDir;
        yDir = -yDir;
        zDir = -zDir;
    }

    auto tMax = tFinal;
    auto plane2 = -1;
    const auto numPoints = boost::numeric_cast<int>(a.size());
    for (auto i = 0; i < numPoints; ++i)
    {
        if (i == plane0 || i == plane1)
        {
            continue;
        }

        auto norDotDir = a.at(i)[0] * xDir + a.at(i)[1] * yDir + a.at(i)[2] * zDir;
        if (norDotDir <= Math<Real>::GetValue(0))
        {
            continue;
        }

        auto numer = Math<Real>::GetValue(1) - a.at(i)[0] * d.at(0) - a.at(i)[1] * d.at(1) - a.at(i)[2] * d.at(2);
        if (numer < Math<Real>::GetValue(0))
        {
            MATHEMATICS_ASSERTION_0(numer >= -Math<Real>::GetZeroTolerance(), "意外情况\n");

            plane2 = i;
            tMax = Math<Real>::GetValue(0);
            break;
        }

        auto t = numer / norDotDir;
        if (0 <= t && t < tMax)
        {
            plane2 = i;
            tMax = t;
        }
    }

    d.at(0) += tMax * xDir;
    d.at(1) += tMax * yDir;
    d.at(2) += tMax * zDir;

    if (tMax == tFinal)
    {
        return;
    }

    if (tMax > Math<Real>::GetZeroTolerance())
    {
        plane0 = plane2;
        FindFacetMax(a, plane0, d);
        return;
    }
}

template <typename Real>
void Mathematics::ContEllipsoid3MinCR<Real>::FindFacetMax(std::vector<Vector3<Real>>& a, int& plane0, std::array<Real, 3>& d)
{
    Real tFinal{};
    Real xDir{};
    Real yDir{};
    Real zDir{};

    if (a.at(plane0)[0] > Math<Real>::GetZeroTolerance() && a.at(plane0)[1] > Math<Real>::GetZeroTolerance() && a.at(plane0)[2] > Math<Real>::GetZeroTolerance())
    {
        constexpr auto oneThird = Math<Real>::GetRational(1, 3);
        auto xMax = oneThird / a.at(plane0)[0];
        auto yMax = oneThird / a.at(plane0)[1];
        auto zMax = oneThird / a.at(plane0)[2];

        tFinal = Math<Real>::GetValue(1);
        xDir = xMax - d.at(0);
        yDir = yMax - d.at(1);
        zDir = zMax - d.at(2);
    }
    else
    {
        tFinal = Math<Real>::maxReal;

        if (a.at(plane0)[0] > Math<Real>::GetZeroTolerance())
        {
            xDir = Math<Real>::GetValue(0);
        }
        else
        {
            xDir = Math<Real>::GetValue(1);
        }

        if (a.at(plane0)[1] > Math<Real>::GetZeroTolerance())
        {
            yDir = Math<Real>::GetValue(0);
        }
        else
        {
            yDir = Math<Real>::GetValue(1);
        }

        if (a.at(plane0)[2] > Math<Real>::GetZeroTolerance())
        {
            zDir = Math<Real>::GetValue(0);
        }
        else
        {
            zDir = Math<Real>::GetValue(1);
        }
    }

    auto tMax = tFinal;
    auto plane1 = -1;
    const auto numPoints = boost::numeric_cast<int>(a.size());
    for (auto i = 0; i < numPoints; ++i)
    {
        if (i == plane0)
        {
            continue;
        }

        auto norDotDir = a.at(i)[0] * xDir + a.at(i)[1] * yDir + a.at(i)[2] * zDir;
        if (norDotDir <= Math<Real>::GetValue(0))
        {
            continue;
        }

        auto numer = Math<Real>::GetValue(1) - a.at(i)[0] * d.at(0) - a.at(i)[1] * d.at(1) - a.at(i)[2] * d.at(2);
        if (numer < Math<Real>::GetValue(0))
        {
            MATHEMATICS_ASSERTION_0(numer >= -Math<Real>::GetZeroTolerance(), "意外情况\n");

            plane1 = i;
            tMax = Math<Real>::GetValue(0);
            break;
        }

        auto t = numer / norDotDir;
        if (0 <= t && t < tMax)
        {
            plane1 = i;
            tMax = t;
        }
    }

    d.at(0) += tMax * xDir;
    d.at(1) += tMax * yDir;
    d.at(2) += tMax * zDir;

    if (Math<Real>::Approximate(tMax, Math<Real>::GetValue(1)))
    {
        return;
    }

    if (tMax > Math<Real>::GetZeroTolerance())
    {
        plane0 = plane1;
        FindFacetMax(a, plane0, d);
        return;
    }

    FindEdgeMax(a, plane0, plane1, d);
}

template <typename Real>
void Mathematics::ContEllipsoid3MinCR<Real>::MaxProduct(std::vector<Vector3<Real>>& a, std::array<Real, 3>& d)
{
    constexpr auto maxJitter = static_cast<Real>(1e-12);
    const auto numPoints = boost::numeric_cast<int>(a.size());

    for (auto i = 0; i < numPoints; ++i)
    {
        a.at(i)[0] += maxJitter * Random<Real>::UnitRandom();
        a.at(i)[1] += maxJitter * Random<Real>::UnitRandom();
        a.at(i)[2] += maxJitter * Random<Real>::UnitRandom();
    }

    auto plane = -1;
    auto zmax = Math<Real>::GetValue(0);
    for (auto i = 0; i < numPoints; ++i)
    {
        if (a.at(i)[2] > zmax)
        {
            zmax = a.at(i)[2];
            plane = i;
        }
    }
    MATHEMATICS_ASSERTION_0(plane != -1, "意外情况\n");

    d.at(0) = Math<Real>::GetValue(0);
    d.at(1) = Math<Real>::GetValue(0);
    d.at(2) = (Math<Real>::GetValue(1)) / zmax;
    FindFacetMax(a, plane, d);
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_DETAIL_H