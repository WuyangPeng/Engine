///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 21:20)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_DETAIL_H

#include "ContMinBox2.h"
#include "Mathematics/ComputationalGeometry/ConvexHull2.h"
#include "Mathematics/ComputationalGeometry/ConvexHull2Detail.h"

template <typename Real>
Mathematics::ContMinBox2<Real>::ContMinBox2(const std::vector<Vector2<Real>>& points, Real epsilon, QueryType queryType, bool isConvexPolygon)
{
    std::vector<Vector2<Real>> hullPoints{};
    if (isConvexPolygon)
    {
        hullPoints = points;
    }
    else
    {
        ConvexHull2<Real> hull{ points, epsilon, queryType };
        const auto hullDim = hull.GetDimension();
        const auto hullNumSimplices = hull.GetNumSimplices();
        auto hullIndices = hull.GetIndices();

        if (hullDim == 0)
        {
            minBox = Box2<Real>{ points.at(0), Vector2<Real>::GetUnitX(), Vector2<Real>::GetUnitY(), Math<Real>::GetValue(0), Math<Real>::GetValue(0) };
            return;
        }

        if (hullDim == 1)
        {
            auto hull1 = hull.GetConvexHull1();
            hullIndices = hull1.GetIndices();

            auto center = Math<Real>::GetRational(1, 2) * (points.at(hullIndices.at(0)) + points.at(hullIndices.at(1)));
            auto diff = points.at(hullIndices.at(1)) - points.at(hullIndices.at(0));

            auto length = Vector2Tools<Real>::GetLength(diff);
            diff.Normalize();

            minBox = Box2<Real>{ center, diff, Vector2Tools<Real>::GetPerp(minBox.GetAxis0()), Math<Real>::GetRational(1, 2) * length, Math<Real>::GetValue(0) };

            return;
        }

        hullPoints.resize(hullNumSimplices);
        for (auto i = 0; i < hullNumSimplices; ++i)
        {
            hullPoints.at(i) = points.at(hullIndices.at(i));
        }
    }
    const auto numPoints = boost::numeric_cast<int>(hullPoints.size());

    const auto numPointsM1 = boost::numeric_cast<int>(hullPoints.size()) - 1;
    std::vector<Vector2<Real>> edges(numPoints);
    std::vector<bool> visited(numPoints);

    for (auto i = 0; i < numPointsM1; ++i)
    {
        const auto next = i + 1;
        edges.at(i) = hullPoints.at(next) - hullPoints.at(i);
        edges.at(i).Normalize();
        visited.at(i) = false;
    }
    edges.at(numPointsM1) = hullPoints.at(0) - hullPoints.at(numPointsM1);
    edges.at(numPointsM1).Normalize();
    visited.at(numPointsM1) = false;

    auto xmin = hullPoints.at(0).GetX();
    auto xmax = xmin;
    auto ymin = hullPoints.at(0).GetY();
    auto ymax = ymin;
    auto lIndex = 0;
    auto rIndex = 0;
    auto bIndex = 0;
    auto tIndex = 0;
    for (auto i = 1; i < numPoints; ++i)
    {
        if (hullPoints.at(i).GetX() <= xmin)
        {
            xmin = hullPoints.at(i).GetX();
            lIndex = i;
        }
        if (hullPoints.at(i).GetX() >= xmax)
        {
            xmax = hullPoints.at(i).GetX();
            rIndex = i;
        }

        if (hullPoints.at(i).GetY() <= ymin)
        {
            ymin = hullPoints.at(i).GetY();
            bIndex = i;
        }
        if (hullPoints.at(i).GetY() >= ymax)
        {
            ymax = hullPoints.at(i).GetY();
            tIndex = i;
        }
    }

    if (lIndex == numPointsM1)
    {
        if (hullPoints.at(0).GetX() <= xmin)
        {
            xmin = hullPoints.at(0).GetX();
            lIndex = 0;
        }
    }

    if (rIndex == numPointsM1)
    {
        if (hullPoints.at(0).GetX() >= xmax)
        {
            xmax = hullPoints.at(0).GetX();
            rIndex = 0;
        }
    }

    if (bIndex == numPointsM1)
    {
        if (hullPoints.at(0).GetY() <= ymin)
        {
            ymin = hullPoints.at(0).GetY();
            bIndex = 0;
        }
    }

    if (tIndex == numPointsM1)
    {
        if (hullPoints.at(0).GetY() >= ymax)
        {
            ymax = hullPoints.at(0).GetY();
            tIndex = 0;
        }
    }

    const Vector2<Real> center{ Math<Real>::GetRational(1, 2) * (xmin + xmax), Math<Real>::GetRational(1, 2) * (ymin + ymax) };

    minBox = Box2<Real>{ center, Vector2<Real>::GetUnitX(), Vector2<Real>::GetUnitY(), Math<Real>::GetRational(1, 2) * (xmax - xmin), Math<Real>::GetRational(1, 2) * (ymax - ymin) };

    auto minAreaDiv4 = minBox.GetExtent0() * minBox.GetExtent1();

    auto u = Vector2<Real>::GetUnitX();
    auto v = Vector2<Real>::GetUnitY();

    auto done = false;
    while (!done)
    {
        auto flag = MinBox2Flag::None;
        auto maxDot = Math<Real>::GetValue(0);

        auto dot = Vector2Tools<Real>::DotProduct(u, edges.at(bIndex));
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = MinBox2Flag::Bottom;
        }

        dot = Vector2Tools<Real>::DotProduct(v, edges.at(rIndex));
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = MinBox2Flag::Right;
        }

        dot = -Vector2Tools<Real>::DotProduct(u, edges.at(tIndex));
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = MinBox2Flag::Top;
        }

        dot = -Vector2Tools<Real>::DotProduct(v, edges.at(lIndex));
        if (dot > maxDot)
        {
            maxDot = dot;
            flag = MinBox2Flag::Left;
        }

        switch (flag)
        {
            case MinBox2Flag::Bottom:
                if (visited.at(bIndex))
                {
                    done = true;
                }
                else
                {
                    u = edges.at(bIndex);
                    v = -Vector2Tools<Real>::GetPerp(u);
                    UpdateBox(hullPoints.at(lIndex), hullPoints.at(rIndex), hullPoints.at(bIndex), hullPoints.at(tIndex), u, v, minAreaDiv4);

                    visited.at(bIndex) = true;
                    if (++bIndex == numPoints)
                    {
                        bIndex = 0;
                    }
                }
                break;
            case MinBox2Flag::Right:
                if (visited.at(rIndex))
                {
                    done = true;
                }
                else
                {
                    v = edges.at(rIndex);
                    u = Vector2Tools<Real>::GetPerp(v);
                    UpdateBox(hullPoints.at(lIndex), hullPoints.at(rIndex), hullPoints.at(bIndex), hullPoints.at(tIndex), u, v, minAreaDiv4);

                    visited.at(rIndex) = true;
                    if (++rIndex == numPoints)
                    {
                        rIndex = 0;
                    }
                }
                break;
            case MinBox2Flag::Top:
                if (visited.at(tIndex))
                {
                    done = true;
                }
                else
                {
                    u = -edges.at(tIndex);
                    v = -Vector2Tools<Real>::GetPerp(u);
                    UpdateBox(hullPoints.at(lIndex), hullPoints.at(rIndex), hullPoints.at(bIndex), hullPoints.at(tIndex), u, v, minAreaDiv4);

                    visited.at(tIndex) = true;
                    if (++tIndex == numPoints)
                    {
                        tIndex = 0;
                    }
                }
                break;
            case MinBox2Flag::Left:
                if (visited.at(lIndex))
                {
                    done = true;
                }
                else
                {
                    v = -edges.at(lIndex);
                    u = Vector2Tools<Real>::GetPerp(v);
                    UpdateBox(hullPoints.at(lIndex), hullPoints.at(rIndex), hullPoints.at(bIndex), hullPoints.at(tIndex), u, v, minAreaDiv4);

                    visited.at(lIndex) = true;
                    if (++lIndex == numPoints)
                    {
                        lIndex = 0;
                    }
                }
                break;
            case MinBox2Flag::None:

                done = true;
                break;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContMinBox2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::ContMinBox2<Real>::operator Mathematics::Box2<Real>() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minBox;
}

template <typename Real>
void Mathematics::ContMinBox2<Real>::UpdateBox(const Vector2<Real>& lPoint, const Vector2<Real>& rPoint, const Vector2<Real>& bPoint, const Vector2<Real>& tPoint, const Vector2<Real>& u, const Vector2<Real>& v, Real& minAreaDiv4)
{
    auto RLDiff = rPoint - lPoint;
    auto TBDiff = tPoint - bPoint;
    auto extent0 = Math<Real>::GetRational(1, 2) * (Vector2Tools<Real>::DotProduct(u, RLDiff));
    auto extent1 = Math<Real>::GetRational(1, 2) * (Vector2Tools<Real>::DotProduct(v, TBDiff));
    auto areaDiv4 = extent0 * extent1;
    if (areaDiv4 < minAreaDiv4)
    {
        minAreaDiv4 = areaDiv4;

        auto LBDiff = lPoint - bPoint;

        minBox = Box2<Real>{ lPoint + u * extent0 + v * (extent1 - Vector2Tools<Real>::DotProduct(v, LBDiff)), u, v, extent0, extent1 };
    }
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_DETAIL_H