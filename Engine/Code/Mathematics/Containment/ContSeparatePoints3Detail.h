///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:41)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_DETAIL_H

#include "ContSeparatePoints3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/ComputationalGeometry/ConvexHull3.h"

#include <gsl/util>

template <typename Real>
Mathematics::ContSeparatePoints3<Real>::ContSeparatePoints3(const std::vector<Vector3<Real>>& points0, const std::vector<Vector3<Real>>& points1, Plane3<Real>& separatingPlane)
    : separated{}
{
    ConvexHull3<Real> hull0{ points0, Math<Real>::GetRational(1, 1000), QueryType::Int64 };

    MATHEMATICS_ASSERTION_0(hull0.GetDimension() == 3, "代码目前仅支持非共线点\n");
    if (hull0.GetDimension() < 3)
    {
        return;
    }

    const auto numTriangles0 = hull0.GetNumSimplices();
    auto indices0 = hull0.GetIndices();

    ConvexHull3<Real> hull1{ points1, Math<Real>::GetRational(1, 1000), QueryType::Int64 };

    MATHEMATICS_ASSERTION_0(hull1.GetDimension() == 3, "代码目前仅支持非共线点\n");
    if (hull1.GetDimension() < 3)
    {
        return;
    }

    const auto numTriangles1 = hull1.GetNumSimplices();
    auto indices1 = hull1.GetIndices();

    Vector3<Real> diff0{};
    Vector3<Real> diff1{};
    for (auto i = 0; i < numTriangles0; ++i)
    {
        auto i0 = indices0.at(3 * gsl::narrow_cast<size_t>(i));
        auto i1 = indices0.at(3 * gsl::narrow_cast<size_t>(i) + 1);
        auto i2 = indices0.at(3 * gsl::narrow_cast<size_t>(i) + 2);

        separatingPlane = Plane3<Real>{ points0.at(i0), points0.at(i1), points0.at(i2) };

        const auto side1 = OnSameSide(separatingPlane, indices1, points1);

        if (side1)
        {
            const auto side0 = WhichSide(separatingPlane, indices0, points0);
            if (side0 * side1 <= 0)
            {
                separated = true;
                return;
            }
        }
    }

    for (auto i = 0; i < numTriangles1; ++i)
    {
        auto i0 = indices1.at(3 * gsl::narrow_cast<size_t>(i));
        auto i1 = indices1.at(3 * gsl::narrow_cast<size_t>(i) + 1);
        auto i2 = indices1.at(3 * gsl::narrow_cast<size_t>(i) + 2);

        separatingPlane = Plane3<Real>{ points1.at(i0), points1.at(i1), points1.at(i2) };

        const auto side0 = OnSameSide(separatingPlane, indices0, points0);
        if (side0)
        {
            const auto side1 = WhichSide(separatingPlane, indices1, points1);
            if (side0 * side1 <= 0)
            {
                separated = true;
                return;
            }
        }
    }

    std::set<std::pair<int, int>> edgeSet0{};
    for (auto i = 0; i < numTriangles0; ++i)
    {
        auto i0 = indices0.at(3 * gsl::narrow_cast<size_t>(i));
        auto i1 = indices0.at(3 * gsl::narrow_cast<size_t>(i) + 1);
        auto i2 = indices0.at(3 * gsl::narrow_cast<size_t>(i) + 2);
        edgeSet0.insert(std::make_pair(i0, i1));
        edgeSet0.insert(std::make_pair(i0, i2));
        edgeSet0.insert(std::make_pair(i1, i2));
    }

    std::set<std::pair<int, int>> edgeSet1{};
    for (auto i = 0; i < numTriangles1; ++i)
    {
        auto i0 = indices1.at(3 * gsl::narrow_cast<size_t>(i));
        auto i1 = indices1.at(3 * gsl::narrow_cast<size_t>(i) + 1);
        auto i2 = indices1.at(3 * gsl::narrow_cast<size_t>(i) + 2);
        edgeSet1.insert(std::make_pair(i0, i1));
        edgeSet1.insert(std::make_pair(i0, i2));
        edgeSet1.insert(std::make_pair(i1, i2));
    }

    for (auto e0iter = edgeSet0.begin(); e0iter != edgeSet0.end(); ++e0iter)
    {
        diff0 = points0.at(e0iter->second) - points0.at(e0iter->first);

        for (auto e1iter = edgeSet0.begin(); e1iter != edgeSet0.end(); ++e1iter)
        {
            diff1 = points1.at(e1iter->second) - points1.at(e1iter->first);

            separatingPlane = Plane3<Real>(Vector3Tools<Real>::UnitCrossProduct(diff0, diff1), points0.at(e0iter->first));

            const auto side0 = OnSameSide(separatingPlane, indices0, points0);
            const auto side1 = OnSameSide(separatingPlane, indices1, points1);

            if (side0 * side1 < 0)
            {
                separated = true;
                return;
            }
        }
    }

    separated = false;

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContSeparatePoints3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::ContSeparatePoints3<Real>::operator bool() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return separated;
}

template <typename Real>
int Mathematics::ContSeparatePoints3<Real>::OnSameSide(const Plane3<Real>& plane, const std::vector<int>& indices, const std::vector<Vector3<Real>>& points)
{
    auto posSide = 0;
    auto negSide = 0;

    const auto numTriangles = boost::numeric_cast<int>(indices.size());
    for (auto t = 0; t < numTriangles; ++t)
    {
        for (auto i = 0; i < 3; ++i)
        {
            const auto index = 3 * t + i;
            auto v = indices.at(index);
            auto c0 = Vector3Tools<Real>::DotProduct(plane.GetNormal(), points.at(v));
            if (c0 > plane.GetConstant() + Math<Real>::GetZeroTolerance())
            {
                ++posSide;
            }
            else if (c0 < plane.GetConstant() - Math<Real>::GetZeroTolerance())
            {
                ++negSide;
            }

            if (posSide && negSide)
            {
                return 0;
            }
        }
    }

    return (posSide ? +1 : -1);
}

template <typename Real>
int Mathematics::ContSeparatePoints3<Real>::WhichSide(const Plane3<Real>& plane, const std::vector<int>& indices, const std::vector<Vector3<Real>>& points)
{
    const auto numTriangles = boost::numeric_cast<int>(indices.size());
    for (auto t = 0; t < numTriangles; ++t)
    {
        for (auto i = 0; i < 3; ++i)
        {
            const auto index = 3 * t + i;
            auto v = indices.at(index);
            auto c0 = Vector3Tools<Real>::DotProduct(plane.GetNormal(), points.at(v));
            if (c0 > plane.GetConstant() + Math<Real>::GetZeroTolerance())
            {
                return +1;
            }
            if (c0 < plane.GetConstant() - Math<Real>::GetZeroTolerance())
            {
                return -1;
            }
        }
    }

    return 0;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_DETAIL_H