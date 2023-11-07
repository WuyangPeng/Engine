///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:40)

#ifndef MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_DETAIL_H

#include "ContLozenge3.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Rectangle3.h"

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::ContLozenge3<Real>::ContLozenge(const std::vector<Vector3<Real>>& points)
{
    auto box = GaussPointsFit3<Real>(points).GetBox3();

    auto diff = points.at(0) - box.GetCenter();
    auto wMin = Vector3Tools<Real>::DotProduct(box.GetAxis(0), diff);
    auto wMax = wMin;

    for (auto i = 1u; i < points.size(); ++i)
    {
        diff = points.at(i) - box.GetCenter();
        auto w = Vector3Tools<Real>::DotProduct(box.GetAxis(0), diff);
        if (w < wMin)
        {
            wMin = w;
        }
        else if (w > wMax)
        {
            wMax = w;
        }
    }

    auto radius = Math<Real>::GetRational(1, 2) * (wMax - wMin);
    auto rSqr = radius * radius;
    auto newCenter = box.GetCenter() + (Math<Real>::GetRational(1, 2) * (wMax + wMin)) * box.GetAxis(0);
    box = Box3<Real>{ newCenter,
                      box.GetAxis0(),
                      box.GetAxis1(),
                      box.GetAxis2(),
                      box.GetExtent0(),
                      box.GetExtent1(),
                      box.GetExtent2() };

    auto aMin = Math<Real>::maxReal;
    auto aMax = -aMin;
    auto bMin = Math<Real>::maxReal;
    auto bMax = -bMin;

    for (auto i = 0u; i < points.size(); ++i)
    {
        diff = points.at(i) - box.GetCenter();
        auto u = Vector3Tools<Real>::DotProduct(box.GetAxis(2), diff);
        auto v = Vector3Tools<Real>::DotProduct(box.GetAxis(1), diff);
        auto w = Vector3Tools<Real>::DotProduct(box.GetAxis(0), diff);
        auto discr = rSqr - w * w;
        auto radical = Math<Real>::Sqrt(Math<Real>::FAbs(discr));

        auto test = u + radical;
        if (test < aMin)
        {
            aMin = test;
        }

        test = u - radical;
        if (test > aMax)
        {
            aMax = test;
        }

        test = v + radical;
        if (test < bMin)
        {
            bMin = test;
        }

        test = v - radical;
        if (test > bMax)
        {
            bMax = test;
        }
    }

    if (aMin >= aMax)
    {
        auto test = Math<Real>::GetRational(1, 2) * (aMin + aMax);
        aMin = test;
        aMax = test;
    }
    if (bMin >= bMax)
    {
        auto test = Math<Real>::GetRational(1, 2) * (bMin + bMax);
        bMin = test;
        bMax = test;
    }

    for (auto i = 0u; i < points.size(); ++i)
    {
        diff = points.at(i) - box.GetCenter();
        auto u = Vector3Tools<Real>::DotProduct(box.GetAxis(2), diff);
        auto v = Vector3Tools<Real>::DotProduct(box.GetAxis(1), diff);

        Real* aExtreme{ nullptr };
        Real* bExtreme{ nullptr };

        if (u > aMax)
        {
            if (v > bMax)
            {
                aExtreme = &aMax;
                bExtreme = &bMax;
            }
            else if (v < bMin)
            {
                aExtreme = &aMax;
                bExtreme = &bMin;
            }
        }
        else if (u < aMin)
        {
            if (v > bMax)
            {
                aExtreme = &aMin;
                bExtreme = &bMax;
            }
            else if (v < bMin)
            {
                aExtreme = &aMin;
                bExtreme = &bMin;
            }
        }

        if (aExtreme && bExtreme)
        {
            auto deltaU = u - *aExtreme;
            auto deltaV = v - *bExtreme;
            auto deltaSumSqr = deltaU * deltaU + deltaV * deltaV;
            auto w = Vector3Tools<Real>::DotProduct(box.GetAxis(0), diff);
            auto wSqr = w * w;
            auto test = deltaSumSqr + wSqr;
            if (test > rSqr)
            {
                auto discr = (rSqr - wSqr) / deltaSumSqr;
                Real t = -Math<Real>::Sqrt(Math<Real>::FAbs(discr));
                *aExtreme = u + t * deltaU;
                *bExtreme = v + t * deltaV;
            }
        }
    }

    Vector3<Real> center;
    std::array<Vector3<Real>, 2> axis{ box.GetAxis(2), box.GetAxis(1) };
    Vector2<Real> extent{};

    if (aMin < aMax)
    {
        if (bMin < bMax)
        {
            center = box.GetCenter() + aMin * box.GetAxis(2) + bMin * box.GetAxis(1);
            extent[0] = Math<Real>::GetRational(1, 2) * (aMax - aMin);
            extent[1] = Math<Real>::GetRational(1, 2) * (bMax - bMin);
        }
        else
        {
            center = box.GetCenter() + aMin * box.GetAxis(2) + (Math<Real>::GetRational(1, 2) * (bMin + bMax)) * box.GetAxis(1);
            extent[0] = Math<Real>::GetRational(1, 2) * (aMax - aMin);
            extent[1] = Math<Real>::GetValue(0);
        }
    }
    else
    {
        if (bMin < bMax)
        {
            center = box.GetCenter() + bMin * box.GetAxis(1) + (Math<Real>::GetRational(1, 2) * (aMin + aMax)) * box.GetAxis(2);
            extent[0] = Math<Real>::GetValue(0);
            extent[1] = Math<Real>::GetRational(1, 2) * (bMax - bMin);
        }
        else
        {
            center = box.GetCenter() +
                     (Math<Real>::GetRational(1, 2) * (aMin + aMax)) * box.GetAxis(2) +
                     (Math<Real>::GetRational(1, 2) * (bMin + bMax)) * box.GetAxis(1);
            extent[0] = Math<Real>::GetValue(0);
            extent[1] = Math<Real>::GetValue(0);
        }
    }

    const Rectangle3<Real> rectangle{ center, axis.at(0), axis.at(1), extent[0], extent[1] };
    Lozenge3<Real> lozenge{ rectangle, radius };

    return lozenge;
}

template <typename Real>
bool Mathematics::ContLozenge3<Real>::InLozenge(const Vector3<Real>& point, const Lozenge3<Real>& lozenge)
{
    auto dist = DistancePoint3Rectangle3<Real>(point, lozenge.GetRectangle()).Get().GetDistance();

    return dist <= lozenge.GetRadius();
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_DETAIL_H