///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:40)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_DETAIL_H

#include "ContMinBox2.h"
#include "ContMinBox3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/ComputationalGeometry/ConvexHull3.h"
#include "Mathematics/Meshes/EdgeKey.h"

template <typename Real>
Mathematics::ContMinBox3<Real>::ContMinBox3(const std::vector<Vector3<Real>>& points, Real epsilon, QueryType queryType)
{
    ConvexHull3<Real> kHull{ points, epsilon, queryType };
    const auto hullDim = kHull.GetDimension();

    if (hullDim == 0)
    {
        minBox.Set(points.at(0), Vector3<Real>::GetUnitX(), Vector3<Real>::GetUnitY(), Vector3<Real>::GetUnitZ(), Math<Real>::GetValue(0), Math<Real>::GetValue(0), Math<Real>::GetValue(0));

        return;
    }

    if (hullDim == 1)
    {
        auto pkHull1 = kHull.GetConvexHull1();
        auto hullIndices = pkHull1.GetIndices();

        auto center = Math<Real>::GetRational(1, 2) * (points.at(hullIndices.at(0)) + points.at(hullIndices.at(1)));
        auto diff = points.at(hullIndices.at(1)) - points.at(hullIndices.at(0));
        auto extent0 = Math<Real>::GetRational(1, 2) * Vector3Tools<Real>::GetLength(diff);
        auto extent1 = Math<Real>::GetValue(0);
        auto extent2 = Math<Real>::GetValue(0);

        diff.Normalize();

        const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(diff);

        minBox.Set(center,
                   vector3OrthonormalBasis.GetUVector(),
                   vector3OrthonormalBasis.GetVVector(),
                   vector3OrthonormalBasis.GetWVector(),
                   extent0,
                   extent1,
                   extent2);

        return;
    }

    std::vector<Vector2<Real>> points2{};
    Box2<Real> box2{};

    if (hullDim == 2)
    {
        const auto origin = kHull.GetPlaneOrigin();
        const auto w = Vector3Tools<Real>::CrossProduct(kHull.GetPlaneDirection(0), kHull.GetPlaneDirection(1));

        const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(w);
        const auto u = vector3OrthonormalBasis.GetUVector();
        const auto v = vector3OrthonormalBasis.GetVVector();

        const auto numPoints = boost::numeric_cast<int>(points.size());

        points2.resize(numPoints);
        for (auto i = 0; i < numPoints; ++i)
        {
            auto diff = points.at(i) - origin;
            points2.at(i).SetX(Vector3Tools<Real>::DotProduct(u, diff));
            points2.at(i).SetY(Vector3Tools<Real>::DotProduct(v, diff));
        }

        box2 = ContMinBox2<Real>{ points2, epsilon, queryType, false };

        minBox.Set(origin + box2.GetCenter().GetX() * u + box2.GetCenter().GetY() * v,
                   box2.GetAxis0().GetX() * u + box2.GetAxis0().GetY() * v,
                   box2.GetAxis1().GetX() * u + box2.GetAxis1().GetY() * v,
                   w,
                   box2.GetExtent0(),
                   box2.GetExtent1(),
                   Math<Real>::GetValue(0));

        return;
    }

    const auto hullQuantity = kHull.GetNumSimplices();
    const auto hullIndices = kHull.GetIndices();
    Real volume{};
    auto minVolume = Math<Real>::maxReal;

    std::set<int> uniqueIndices{};
    for (auto i = 0; i < 3 * hullQuantity; ++i)
    {
        uniqueIndices.emplace(hullIndices.at(i));
    }

    auto currentHullIndex = 0;

    std::set<EdgeKey> edges{};
    points2.resize(uniqueIndices.size());
    for (auto i = 0; i < hullQuantity; ++i)
    {
        auto v0 = hullIndices.at(currentHullIndex++);
        auto v1 = hullIndices.at(currentHullIndex++);
        auto v2 = hullIndices.at(currentHullIndex++);

        edges.emplace(v0, v1);
        edges.emplace(v1, v2);
        edges.emplace(v2, v0);

        auto origin = (points.at(v0) + points.at(v1) + points.at(v2)) / Math<Real>::GetValue(3);
        auto edge1 = points.at(v1) - points.at(v0);
        auto edge2 = points.at(v2) - points.at(v0);
        const auto w = Vector3Tools<Real>::UnitCrossProduct(edge2, edge1);
        if (w == Vector3<Real>::GetZero())
        {
            continue;
        }
        const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(w);
        const auto u = vector3OrthonormalBasis.GetUVector();
        const auto v = vector3OrthonormalBasis.GetVVector();

        auto minHeight = Math<Real>::GetValue(0);
        auto maxHeight = Math<Real>::GetValue(0);
        auto j = 0;
        auto iter = uniqueIndices.begin();
        while (iter != uniqueIndices.end())
        {
            auto index = *iter++;
            auto diff = points.at(index) - origin;
            points2.at(j).SetX(Vector3Tools<Real>::DotProduct(u, diff));
            points2.at(j).SetY(Vector3Tools<Real>::DotProduct(v, diff));
            auto height = Vector3Tools<Real>::DotProduct(w, diff);
            if (height > maxHeight)
            {
                maxHeight = height;
            }
            else if (height < minHeight)
            {
                minHeight = height;
            }

            j++;
        }
        if (-minHeight > maxHeight)
        {
            maxHeight = -minHeight;
        }

        box2 = ContMinBox2<Real>{ points2, epsilon, queryType, false };

        volume = maxHeight * box2.GetExtent0() * box2.GetExtent1();
        if (volume < minVolume)
        {
            minVolume = volume;

            auto extent0 = box2.GetExtent0();
            auto extent1 = box2.GetExtent1();
            auto extent2 = Math<Real>::GetRational(1, 2) * maxHeight;
            auto axis0 = box2.GetAxis0().GetX() * u + box2.GetAxis0().GetY() * v;
            auto axis1 = box2.GetAxis1().GetX() * u + box2.GetAxis1().GetY() * v;
            const auto axis2 = w;
            auto center = origin + box2.GetCenter().GetX() * u + box2.GetCenter().GetY() * v + minBox.GetExtent2() * w;

            minBox.Set(center, axis0, axis1, axis2, extent0, extent1, extent2);
        }
    }

    for (auto e2iter = edges.begin(); e2iter != edges.end(); e2iter++)
    {
        auto w = points.at(e2iter->GetKey(1)) - points.at(e2iter->GetKey(0));
        w.Normalize();

        auto e1iter = e2iter;
        for (++e1iter; e1iter != edges.end(); e1iter++)
        {
            auto v = points.at(e1iter->GetKey(1)) - points.at(e1iter->GetKey(0));
            v.Normalize();
            Real dot = Vector3Tools<Real>::DotProduct(v, w);
            if (Math<Real>::FAbs(dot) > Math<Real>::GetZeroTolerance())
            {
                continue;
            }

            auto e0iter = e1iter;
            for (++e0iter; e0iter != edges.end(); e0iter++)
            {
                auto u = points.at(e0iter->GetKey(1)) - points.at(e0iter->GetKey(0));
                u.Normalize();
                dot = Vector3Tools<Real>::DotProduct(u, v);
                if (Math<Real>::FAbs(dot) > Math<Real>::GetZeroTolerance())
                {
                    continue;
                }
                dot = Vector3Tools<Real>::DotProduct(u, w);
                if (Math<Real>::FAbs(dot) > Math<Real>::GetZeroTolerance())
                {
                    continue;
                }

                auto umin = Math<Real>::GetValue(0);
                auto umax = Math<Real>::GetValue(0);
                auto vmin = Math<Real>::GetValue(0);
                auto vmax = Math<Real>::GetValue(0);
                auto wmin = Math<Real>::GetValue(0);
                auto wmax = Math<Real>::GetValue(0);
                auto& origin = points.at(hullIndices.at(0));

                auto iter = uniqueIndices.begin();
                while (iter != uniqueIndices.end())
                {
                    auto index = *iter++;
                    auto diff = points.at(index) - origin;

                    auto fU = Vector3Tools<Real>::DotProduct(u, diff);
                    if (fU < umin)
                    {
                        umin = fU;
                    }
                    else if (fU > umax)
                    {
                        umax = fU;
                    }

                    auto fV = Vector3Tools<Real>::DotProduct(v, diff);
                    if (fV < vmin)
                    {
                        vmin = fV;
                    }
                    else if (fV > vmax)
                    {
                        vmax = fV;
                    }

                    auto fW = Vector3Tools<Real>::DotProduct(w, diff);
                    if (fW < wmin)
                    {
                        wmin = fW;
                    }
                    else if (fW > wmax)
                    {
                        wmax = fW;
                    }
                }

                auto uExtent = Math<Real>::GetRational(1, 2) * (umax - umin);
                auto vExtent = Math<Real>::GetRational(1, 2) * (vmax - vmin);
                auto wExtent = Math<Real>::GetRational(1, 2) * (wmax - wmin);

                volume = uExtent * vExtent * wExtent;
                if (volume < minVolume)
                {
                    minVolume = volume;

                    minBox.Set(origin + Math<Real>::GetRational(1, 2) * (umin + umax) * u +
                                   Math<Real>::GetRational(1, 2) * (vmin + vmax) * v +
                                   Math<Real>::GetRational(1, 2) * (wmin + wmax) * w,
                               u, v, w, uExtent, vExtent, wExtent);
                }
            }
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContMinBox3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::ContMinBox3<Real>::operator Mathematics::Box3<Real>() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minBox;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_DETAIL_H