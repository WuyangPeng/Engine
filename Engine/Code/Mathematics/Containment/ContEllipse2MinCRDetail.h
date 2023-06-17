///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:39)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_DETAIL_H

#include "ContEllipse2MinCR.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

#include <deque>

template <typename Real>
Mathematics::ContEllipse2MinCR<Real>::ContEllipse2MinCR(const std::vector<Vector2<Real>>& points, const Vector2<Real>& c, const Matrix2<Real>& r, std::array<Real, 2>& d)
{
    std::vector<Vector2<Real>> a{ points.size() };
    for (auto i = 0u; i < points.size(); ++i)
    {
        auto diff = points.at(i) - c;
        const auto prod = diff * r;
        a.at(i).SetX(prod.GetX() * prod.GetX());
        a.at(i).SetY(prod.GetY() * prod.GetY());
    }

    std::sort(a.begin(), a.end(), XGreater);
    auto end = std::unique(a.begin(), a.end(), XEqual);
    a.erase(end, a.end());

    std::sort(a.begin(), a.end(), YGreater);
    end = std::unique(a.begin(), a.end(), YEqual);
    a.erase(end, a.end());

    MaxProduct(a, d);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContEllipse2MinCR<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContEllipse2MinCR<Real>::XGreater(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept
{
    if (p0.GetX() > p1.GetX())
    {
        return true;
    }

    if (p0.GetX() < p1.GetX())
    {
        return false;
    }

    return p0.GetY() > p1.GetY();
}

template <typename Real>
bool Mathematics::ContEllipse2MinCR<Real>::XEqual(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept
{
    return p0.GetX() == p1.GetX();
}

template <typename Real>
bool Mathematics::ContEllipse2MinCR<Real>::YGreater(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept
{
    if (p0.GetY() > p1.GetY())
    {
        return true;
    }

    if (p0.GetY() < p1.GetY())
    {
        return false;
    }

    return p0.GetX() > p1.GetX();
}

template <typename Real>
bool Mathematics::ContEllipse2MinCR<Real>::YEqual(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept
{
    return p0.GetY() == p1.GetY();
}

template <typename Real>
void Mathematics::ContEllipse2MinCR<Real>::MaxProduct(std::vector<Vector2<Real>>& a, std::array<Real, 2>& d)
{
    std::deque<bool> used(a.size());

    auto iYMin = -1;
    auto iXMin = -1;
    auto axMax = Math<Real>::GetValue(0);
    auto ayMax = Math<Real>::GetValue(0);
    for (auto i = 0u; i < a.size(); ++i)
    {
        if (a.at(i).GetX() > axMax)
        {
            axMax = a.at(i).GetX();
            iXMin = i;
        }

        if (a.at(i).GetY() > ayMax)
        {
            ayMax = a.at(i).GetY();
            iYMin = i;
        }
    }
    MATHEMATICS_ASSERTION_0(iXMin != -1 && iYMin != -1, "意外情况。\n");

    used.at(iYMin) = true;

    auto x0 = Math<Real>::GetValue(0);
    auto xMax = (Math<Real>::GetValue(1)) / axMax;

    for (auto j = 0u; j < a.size(); ++j)
    {
        auto x1 = xMax;
        auto line = -1;
        for (auto i = 0u; i < a.size(); ++i)
        {
            if (!used.at(i))
            {
                auto det = Vector2Tools<Real>::DotPerp(a.at(iYMin), a.at(i));
                if (det < Math<Real>::GetValue(0))
                {
                    d.at(0) = (a.at(i).GetY() - a.at(iYMin).GetY()) / det;
                    if (x0 < d.at(0) && d.at(0) <= x1)
                    {
                        line = i;
                        x1 = d.at(0);
                    }
                }
            }
        }

        if (Math<Real>::GetRational(1, 2) < a.at(iYMin).GetX() * x0)
        {
            d.at(0) = x0;
            d.at(1) = (Math<Real>::GetValue(1) - a.at(iYMin).GetX() * d.at(0)) / a.at(iYMin).GetY();
            break;
        }

        if (Math<Real>::GetRational(1, 2) < a.at(iYMin).GetX() * x1)
        {
            d.at(0) = Math<Real>::GetRational(1, 2) / a.at(iYMin).GetX();
            d.at(1) = Math<Real>::GetRational(1, 2) / a.at(iYMin).GetY();
            break;
        }

        MATHEMATICS_ASSERTION_0(line != -1, "意外情况。\n");
        x0 = x1;
        x1 = xMax;
        used.at(line) = true;
        iYMin = line;
    }
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_DETAIL_H
