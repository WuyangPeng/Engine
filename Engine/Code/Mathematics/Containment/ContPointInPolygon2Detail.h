///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/11 16:54)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_DETAIL_H

#include "ContPointInPolygon2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ContPointInPolygon2<Real>::ContPointInPolygon2(const std::vector<Vector2<Real>>& points)
    : points{ points }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContPointInPolygon2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContPointInPolygon2<Real>::Contains(const Vector2<Real>& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto mNumPoints = boost::numeric_cast<int>(points.size());
    auto inside = false;
    for (auto i = 0, j = mNumPoints - 1; i < mNumPoints; j = i++)
    {
        const auto& u0 = points.at(i);
        const auto& u1 = points.at(j);

        if (p.GetY() < u1.GetY())
        {
            if (u0.GetY() <= p.GetY())
            {
                auto lhs = (p.GetY() - u0.GetY()) * (u1.GetX() - u0.GetX());
                auto rhs = (p.GetX() - u0.GetX()) * (u1.GetY() - u0.GetY());
                if (lhs > rhs)
                {
                    inside = !inside;
                }
            }
        }
        else if (p.GetY() < u0.GetY())
        {
            auto lhs = (p.GetY() - u0.GetY()) * (u1.GetX() - u0.GetX());
            auto rhs = (p.GetX() - u0.GetX()) * (u1.GetY() - u0.GetY());
            if (lhs < rhs)
            {
                inside = !inside;
            }
        }
    }
    return inside;
}

template <typename Real>
bool Mathematics::ContPointInPolygon2<Real>::ContainsConvexOrderN(const Vector2<Real>& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto mNumPoints = boost::numeric_cast<int>(points.size());
    for (int i1 = 0, i0 = mNumPoints - 1; i1 < mNumPoints; i0 = i1++)
    {
        auto nx = points.at(i1).GetY() - points.at(i0).GetY();
        auto ny = points.at(i0).GetX() - points.at(i1).GetX();
        auto dx = p.GetX() - points.at(i0).GetX();
        auto dy = p.GetY() - points.at(i0).GetY();
        if (nx * dx + ny * dy > Math<Real>::GetValue(0))
        {
            return false;
        }
    }
    return true;
}

template <typename Real>
bool Mathematics::ContPointInPolygon2<Real>::ContainsConvexOrderLogN(const Vector2<Real>& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return SubContainsPoint(p, 0, 0);
}

template <typename Real>
bool Mathematics::ContPointInPolygon2<Real>::ContainsQuadrilateral(const Vector2<Real>& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto mNumPoints = boost::numeric_cast<int>(points.size());
    if (mNumPoints != 4)
    {
        return false;
    }

    auto nx = points.at(2).GetY() - points.at(0).GetY();
    auto ny = points.at(0).GetX() - points.at(2).GetX();
    auto dx = p.GetX() - points.at(0).GetX();
    auto dy = p.GetY() - points.at(0).GetY();

    if (nx * dx + ny * dy > Math<Real>::GetValue(0))
    {
        nx = points.at(1).GetY() - points.at(0).GetY();
        ny = points.at(0).GetX() - points.at(1).GetX();
        if (nx * dx + ny * dy > Math<Real>::GetValue(0))
        {
            return false;
        }

        nx = points.at(2).GetY() - points.at(1).GetY();
        ny = points.at(1).GetX() - points.at(2).GetX();
        dx = p.GetX() - points.at(1).GetX();
        dy = p.GetY() - points.at(1).GetY();
        if (nx * dx + ny * dy > Math<Real>::GetValue(0))
        {
            return false;
        }
    }
    else
    {
        nx = points.at(0).GetY() - points.at(3).GetY();
        ny = points.at(3).GetX() - points.at(0).GetX();
        if (nx * dx + ny * dy > Math<Real>::GetValue(0))
        {
            return false;
        }

        nx = points.at(3).GetY() - points.at(2).GetY();
        ny = points.at(2).GetX() - points.at(3).GetX();
        dx = p.GetX() - points.at(3).GetX();
        dy = p.GetY() - points.at(3).GetY();
        if (nx * dx + ny * dy > Math<Real>::GetValue(0))
        {
            return false;
        }
    }
    return true;
}

template <typename Real>
bool Mathematics::ContPointInPolygon2<Real>::SubContainsPoint(const Vector2<Real>& p, int i0, int i1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto mNumPoints = boost::numeric_cast<int>(points.size());

    const auto diff = i1 - i0;
    if (diff == 1 || (diff < 0 && diff + mNumPoints == 1))
    {
        auto nx = points.at(i1).GetY() - points.at(i0).GetY();
        auto ny = points.at(i0).GetX() - points.at(i1).GetX();
        auto dx = p.GetX() - points.at(i0).GetX();
        auto dy = p.GetY() - points.at(i0).GetY();
        return nx * dx + ny * dy <= Math<Real>::GetValue(0);
    }

    auto mid = 0;
    if (i0 < i1)
    {
        mid = (i0 + i1) >> 1;
    }
    else
    {
        mid = ((i0 + i1 + mNumPoints) >> 1);
        if (mid >= mNumPoints)
        {
            mid -= mNumPoints;
        }
    }

    auto nx = points.at(mid).GetY() - points.at(i0).GetY();
    auto ny = points.at(i0).GetX() - points.at(mid).GetX();
    auto dx = p.GetX() - points.at(i0).GetX();
    auto dy = p.GetY() - points.at(i0).GetY();
    if (nx * dx + ny * dy > Math<Real>::GetValue(0))
    {
        return SubContainsPoint(p, i0, mid);
    }
    else
    {
        return SubContainsPoint(p, mid, i1);
    }
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_DETAIL_H