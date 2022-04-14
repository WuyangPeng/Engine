///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/11 22:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_DETAIL_H

#include "ContSeparatePoints2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/ComputationalGeometry/ConvexHull2.h"

template <typename Real>
Mathematics::ContSeparatePoints2<Real>::ContSeparatePoints2(const std::vector<Vector2<Real>>& points0, const std::vector<Vector2<Real>>& points1, Line2<Real>& separatingLine)
    : separated{}
{
    ConvexHull2<Real> hull0{ points0, Math<Real>::GetRational(1, 1000), QueryType::Int64 };
    MATHEMATICS_ASSERTION_0(hull0.GetDimension() == 2, "代码目前仅支持非共线点\n");
    const auto numEdges0 = hull0.GetNumSimplices();
    auto edges0 = hull0.GetIndices();

    ConvexHull2<Real> hull1{ points1, Math<Real>::GetRational(1, 1000), QueryType::Int64 };
    MATHEMATICS_ASSERTION_0(hull1.GetDimension() == 2, "代码目前仅支持非共线点\n");
    const auto numEdges1 = hull1.GetNumSimplices();
    auto edges1 = hull1.GetIndices();

    Vector2<Real> lineNormal{};
    Real lineConstant{};
    for (auto j1 = 0, j0 = numEdges0 - 1; j1 < numEdges0; j0 = j1++)
    {
        auto i0 = edges0.at(j0);
        auto i1 = edges0.at(j1);

        const auto& origin = points0.at(i0);
        auto direction = points0.at(i1) - points0.at(i0);
        direction.Normalize();

        separatingLine = Line2<Real>(origin, direction);
        lineNormal = Vector2Tools<Real>::GetPerp(direction);
        lineConstant = Vector2Tools<Real>::DotProduct(lineNormal, separatingLine.GetOrigin());

        const auto side1 = OnSameSide(lineNormal, lineConstant, edges1, points1);

        if (side1)
        {
            const auto side0 = WhichSide(lineNormal, lineConstant, edges0, points0);

            if (side0 * side1 <= 0)
            {
                separated = true;
                return;
            }
        }
    }

    for (auto j1 = 0, j0 = numEdges1 - 1; j1 < numEdges1; j0 = j1++)
    {
        auto i0 = edges1.at(j0);
        auto i1 = edges1.at(j1);

        const auto& origin = points1.at(i0);
        auto direction = points1.at(i1) - points1.at(i0);
        direction.Normalize();

        separatingLine = Line2<Real>(origin, direction);

        lineNormal = Vector2Tools<Real>::GetPerp(direction);
        lineConstant = Vector2Tools<Real>::DotProduct(lineNormal, separatingLine.GetOrigin());

        const auto side0 = OnSameSide(lineNormal, lineConstant, edges0, points0);

        if (side0)
        {
            const auto side1 = WhichSide(lineNormal, lineConstant, edges1, points1);

            if (side0 * side1 <= 0)
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
bool Mathematics::ContSeparatePoints2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::ContSeparatePoints2<Real>::operator bool() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return separated;
}

template <typename Real>
int Mathematics::ContSeparatePoints2<Real>::OnSameSide(const Vector2<Real>& lineNormal, Real lineConstant, const std::vector<int>& edges, const std::vector<Vector2<Real>>& points)
{
    const auto numEdges = boost::numeric_cast<int>(edges.size());

    auto posSide = 0;
    auto negSide = 0;

    for (auto i1 = 0, i0 = numEdges - 1; i1 < numEdges; i0 = i1++)
    {
        auto c0 = Vector2Tools<Real>::DotProduct(lineNormal, points.at(edges.at(i0)));
        if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            ++posSide;
        }
        else if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            ++negSide;
        }

        if (posSide && negSide)
        {
            return 0;
        }

        c0 = Vector2Tools<Real>::DotProduct(lineNormal, points.at(edges.at(i1)));
        if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            ++posSide;
        }
        else if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            ++negSide;
        }

        if (posSide && negSide)
        {
            return 0;
        }
    }

    return (posSide ? +1 : -1);
}

template <typename Real>
int Mathematics::ContSeparatePoints2<Real>::WhichSide(const Vector2<Real>& lineNormal, Real lineConstant, const std::vector<int>& edges, const std::vector<Vector2<Real>>& points)
{
    const auto numEdges = boost::numeric_cast<int>(edges.size());

    for (auto i1 = 0, i0 = numEdges - 1; i1 < numEdges; i0 = i1++)
    {
        auto c0 = Vector2Tools<Real>::DotProduct(lineNormal, points.at(edges.at(i0)));
        if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            return +1;
        }
        if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            return -1;
        }

        c0 = Vector2Tools<Real>::DotProduct(lineNormal, points.at(edges.at(i1)));
        if (c0 > lineConstant + Math<Real>::GetZeroTolerance())
        {
            return +1;
        }
        if (c0 < lineConstant - Math<Real>::GetZeroTolerance())
        {
            return -1;
        }
    }

    return 0;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_DETAIL_H