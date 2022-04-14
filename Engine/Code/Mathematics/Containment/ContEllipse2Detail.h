///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 14:52)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_DETAIL_H

#include "ContEllipse2.h"
#include "Mathematics/Approximation/GaussPointsFit2.h"

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::ContEllipse2<Real>::ContEllipse(const std::vector<Vector2<Real>>& points)
{
    const auto box = GaussPointsFit2<Real>(points).GetBox2();
    std::array<Real, 2> diag{ box.GetExtent0(), box.GetExtent1() };
    std::array<Vector2<Real>, 2> axis{ box.GetAxis0(), box.GetAxis1() };

    for (auto i = 0; i < 2; ++i)
    {
        if (diag.at(i) < Math<Real>::GetValue(0))
        {
            diag.at(i) = -diag.at(i);
        }
        if (diag.at(i) < Math<Real>::GetZeroTolerance())
        {
            diag.at(i) = Math<Real>::GetZeroTolerance();
        }
    }

    auto maxValue = Math<Real>::GetValue(0);
    for (auto i = 0u; i < points.size(); ++i)
    {
        auto diff = points.at(i) - box.GetCenter();
        std::array<Real, 2> dot{ Vector2Tools<Real>::DotProduct(axis.at(0), diff), Vector2Tools<Real>::DotProduct(axis.at(1), diff) };
        auto value = dot.at(0) * dot.at(0) / diag.at(0) + dot.at(1) * dot.at(1) / diag.at(1);
        if (value > maxValue)
        {
            maxValue = value;
        }
    }

    for (auto i = 0u; i < 2; ++i)
    {
        diag.at(i) *= maxValue;
    }

    const auto center = box.GetCenter();
    std::array<Vector2<Real>, 2> ellipseAxis{};
    std::array<Real, 2> extent{};

    for (auto i = 0u; i < 2; ++i)
    {
        ellipseAxis.at(i) = axis.at(i);
        extent.at(i) = Math<Real>::Sqrt(diag.at(i));
    }

    Ellipse2<Real> ellipse{ center, ellipseAxis.at(0), ellipseAxis.at(1), extent.at(0), extent.at(1) };

    return ellipse;
}

template <typename Real>
void Mathematics::ContEllipse2<Real>::ProjectEllipse(const Ellipse2<Real>& ellipse, const Line2<Real>& line, Real& smin, Real& smax)
{
    auto center = Vector2Tools<Real>::DotProduct(line.GetDirection(), ellipse.GetCenter() - line.GetOrigin());

    std::array<Real, 2> tmp{ ellipse.GetExtent0() * (Vector2Tools<Real>::DotProduct(line.GetDirection(), ellipse.GetAxis0())),
                             ellipse.GetExtent1() * (Vector2Tools<Real>::DotProduct(line.GetDirection(), ellipse.GetAxis1())) };
    auto rSqr = tmp.at(0) * tmp.at(0) + tmp.at(1) * tmp.at(1);
    auto radius = Math<Real>::Sqrt(rSqr);

    smin = center - radius;
    smax = center + radius;
}

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::ContEllipse2<Real>::MergeEllipses(const Ellipse2<Real>& ellipse0, const Ellipse2<Real>& ellipse1)
{
    auto center = Math<Real>::GetRational(1, 2) * (ellipse0.GetCenter() + ellipse1.GetCenter());
    std::array<Vector2<Real>, 2> axis{};

    if (Vector2Tools<Real>::DotProduct(ellipse0.GetAxis0(), ellipse1.GetAxis0()) >= Math<Real>::GetValue(0))
    {
        axis.at(0) = Math<Real>::GetRational(1, 2) * (ellipse0.GetAxis0() + ellipse1.GetAxis0());
        axis.at(0).Normalize();
    }
    else
    {
        axis.at(0) = Math<Real>::GetRational(1, 2) * (ellipse0.GetAxis0() - ellipse1.GetAxis0());
        axis.at(0).Normalize();
    }
    axis.at(1) = -Vector2Tools<Real>::GetPerp(axis.at(0));

    std::array<Real, 2> extent{};

    for (auto i = 0; i < 2; ++i)
    {
        const Line2<Real> line{ center, axis.at(i) };

        Real min0{};
        Real max0{};
        Real min1{};
        Real max1{};
        ProjectEllipse(ellipse0, line, min0, max0);
        ProjectEllipse(ellipse1, line, min1, max1);

        auto maxIntr = (max0 >= max1 ? max0 : max1);
        auto minIntr = (min0 <= min1 ? min0 : min1);

        center += line.GetDirection() * Math<Real>::GetRational(1, 2) * (minIntr + maxIntr);

        extent.at(i) = Math<Real>::GetRational(1, 2) * (maxIntr - minIntr);
    }

    Ellipse2<Real> merge{ center, axis.at(0), axis.at(1), extent.at(0), extent.at(1) };

    return merge;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_DETAIL_H