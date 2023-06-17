///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:39)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_DETAIL_H

#include "ContCapsule3.h"
#include "Mathematics/Approximation/OrthogonalLineFit3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Segment3Detail.h"

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::ContCapsule3<Real>::ContCapsule(const std::vector<Vector3<Real>>& points)
{
    const auto line = OrthogonalLineFit3<Real>(points).GetLine3();

    auto maxRadiusSqr = Math<Real>::GetValue(0);

    for (auto i = 0u; i < points.size(); ++i)
    {
        auto rSqr = DistancePoint3Line3<Real>(points.at(i), line).GetSquared();
        if (rSqr.GetDistance() > maxRadiusSqr)
        {
            maxRadiusSqr = rSqr.GetDistance();
        }
    }

    const auto vector3OrthonormalBasis = Vector3Tools<Real>::GenerateComplementBasis(line.GetDirection());

    const auto u = vector3OrthonormalBasis.GetUVector();
    const auto v = vector3OrthonormalBasis.GetVVector();
    const auto w = line.GetDirection();

    auto minValue = Math<Real>::maxReal;
    auto maxValue = -Math<Real>::maxReal;
    for (auto i = 0u; i < points.size(); ++i)
    {
        auto diff = points.at(i) - line.GetOrigin();
        auto uDotDiff = Vector3Tools<Real>::DotProduct(u, diff);
        auto vDotDiff = Vector3Tools<Real>::DotProduct(v, diff);
        auto wDotDiff = Vector3Tools<Real>::DotProduct(w, diff);
        auto discr = maxRadiusSqr - (uDotDiff * uDotDiff + vDotDiff * vDotDiff);
        auto radical = Math<Real>::Sqrt(Math<Real>::FAbs(discr));

        auto test = wDotDiff + radical;
        if (test < minValue)
        {
            minValue = test;
        }

        test = wDotDiff - radical;
        if (test > maxValue)
        {
            maxValue = test;
        }
    }

    Real extent{};
    if (maxValue > minValue)
    {
        extent = Math<Real>::GetRational(1, 2) * (maxValue - minValue);
    }
    else
    {
        extent = Math<Real>::GetValue(0);
    }

    auto center = line.GetOrigin() + Math<Real>::GetRational(1, 2) * (minValue + maxValue) * line.GetDirection();
    const auto direction = line.GetDirection();
    const Segment3<Real> segment{ extent, center, direction };

    auto radius = Math<Real>::Sqrt(maxRadiusSqr);

    Capsule3<Real> capsule{ segment, radius };

    return capsule;
}

template <typename Real>
bool Mathematics::ContCapsule3<Real>::InCapsule(const Vector3<Real>& point, const Capsule3<Real>& capsule)
{
    const auto distance = DistancePoint3Segment3<Real>(point, capsule.GetSegment()).Get();

    return distance.GetDistance() <= capsule.GetRadius();
}

template <typename Real>
bool Mathematics::ContCapsule3<Real>::InCapsule(const Sphere3<Real>& sphere, const Capsule3<Real>& capsule)
{
    const auto rDiff = capsule.GetRadius() - sphere.GetRadius();
    if (rDiff >= Math<Real>::GetValue(0))
    {
        const auto distance = DistancePoint3Segment3<Real>(sphere.GetCenter(), capsule.GetSegment()).Get();
        return distance.GetDistance() <= rDiff;
    }
    return false;
}

template <typename Real>
bool Mathematics::ContCapsule3<Real>::InCapsule(const Capsule3<Real>& testCapsule, const Capsule3<Real>& capsule)
{
    const Sphere3<Real> spherePosEnd{ testCapsule.GetSegment().GetEndPoint(), testCapsule.GetRadius() };
    const Sphere3<Real> sphereNegEnd{ testCapsule.GetSegment().GetBeginPoint(), testCapsule.GetRadius() };

    return InCapsule(spherePosEnd, capsule) && InCapsule(sphereNegEnd, capsule);
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::ContCapsule3<Real>::MergeCapsules(const Capsule3<Real>& capsule0, const Capsule3<Real>& capsule1)
{
    if (InCapsule(capsule0, capsule1))
    {
        return capsule1;
    }

    if (InCapsule(capsule1, capsule0))
    {
        return capsule0;
    }

    const auto& p0 = capsule0.GetSegment().GetCenterPoint();
    const auto& p1 = capsule1.GetSegment().GetCenterPoint();
    const auto& d0 = capsule0.GetSegment().GetDirection();
    const auto& d1 = capsule1.GetSegment().GetDirection();

    auto origin = Math<Real>::GetRational(1, 2) * (p0 + p1);
    Vector3<Real> direction;

    if (Vector3Tools<Real>::DotProduct(d0, d1) >= Math<Real>::GetValue(0))
    {
        direction = d0 + d1;
    }
    else
    {
        direction = d0 - d1;
    }
    direction.Normalize();

    const Line3<Real> line{ origin, direction };

    const auto posEnd0 = capsule0.GetSegment().GetEndPoint();
    auto radius = DistancePoint3Line3<Real>(posEnd0, line).Get().GetDistance() + capsule0.GetRadius();

    const auto negEnd0 = capsule0.GetSegment().GetBeginPoint();
    auto tmp = DistancePoint3Line3<Real>(negEnd0, line).Get().GetDistance() + capsule0.GetRadius();
    if (tmp > radius)
    {
        radius = tmp;
    }

    const auto posEnd1 = capsule1.GetSegment().GetEndPoint();
    tmp = DistancePoint3Line3<Real>(posEnd1, line).Get().GetDistance() + capsule1.GetRadius();
    if (tmp > radius)
    {
        radius = tmp;
    }

    const auto negEnd1 = capsule1.GetSegment().GetBeginPoint();
    tmp = DistancePoint3Line3<Real>(negEnd1, line).Get().GetDistance() + capsule1.GetRadius();
    if (tmp > radius)
    {
        radius = tmp;
    }

    auto rDiff = radius - capsule0.GetRadius();
    auto rDiffSqr = rDiff * rDiff;
    auto diff = line.GetOrigin() - posEnd0;
    auto k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
    auto k1 = Vector3Tools<Real>::DotProduct(diff, line.GetDirection());
    auto discr = k1 * k1 - k0;
    auto root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    auto tPos = -k1 - root;
    auto tNeg = -k1 + root;

    diff = line.GetOrigin() - negEnd0;
    k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
    k1 = Vector3Tools<Real>::DotProduct(diff, line.GetDirection());
    discr = k1 * k1 - k0;
    root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    tmp = -k1 - root;
    if (tmp > tPos)
    {
        tPos = tmp;
    }
    tmp = -k1 + root;
    if (tmp < tNeg)
    {
        tNeg = tmp;
    }

    rDiff = radius - capsule1.GetRadius();
    rDiffSqr = rDiff * rDiff;
    diff = line.GetOrigin() - posEnd1;
    k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
    k1 = Vector3Tools<Real>::DotProduct(diff, line.GetDirection());
    discr = k1 * k1 - k0;
    root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    tmp = -k1 - root;
    if (tmp > tPos)
    {
        tPos = tmp;
    }
    tmp = -k1 + root;
    if (tmp < tNeg)
    {
        tNeg = tmp;
    }

    diff = line.GetOrigin() - negEnd1;
    k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
    k1 = Vector3Tools<Real>::DotProduct(diff, line.GetDirection());
    discr = k1 * k1 - k0;
    root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    tmp = -k1 - root;
    if (tmp > tPos)
    {
        tPos = tmp;
    }
    tmp = -k1 + root;
    if (tmp < tNeg)
    {
        tNeg = tmp;
    }

    auto center = line.GetOrigin() + Math<Real>::GetRational(1, 2) * (tPos + tNeg) * line.GetDirection();
    direction = line.GetDirection();

    Real extent{};
    if (tPos > tNeg)
    {
        extent = Math<Real>::GetRational(1, 2) * (tPos - tNeg);
    }
    else
    {
        extent = Math<Real>::GetValue(0);
    }

    const Segment3<Real> segment{ extent, center, direction };

    Capsule3<Real> capsule{ segment, radius };

    return capsule;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_DETAIL_H