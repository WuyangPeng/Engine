///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:41)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SPHERE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SPHERE3_DETAIL_H

#include "ContSphere3.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContSphere3<Real>::ContSphereOfAABB(const std::vector<Vector3<Real>>& points)
{
    const auto aabb = Vector3Tools<Real>::ComputeExtremes(points);
    const auto minExtreme = aabb.GetMinPoint();
    const auto maxExtreme = aabb.GetMaxPoint();

    auto halfDiagonal = Math<Real>::GetRational(1, 2) * (maxExtreme - minExtreme);
    Sphere3<Real> sphere{ Math<Real>::GetRational(1, 2) * (maxExtreme + minExtreme), Vector3Tools<Real>::GetLength(halfDiagonal) };

    return sphere;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContSphere3<Real>::ContSphereAverage(const std::vector<Vector3<Real>>& points)
{
    const auto numPoints = points.size();
    auto center = points.at(0);

    for (auto i = 1u; i < numPoints; ++i)
    {
        center += points.at(i);
    }
    center /= boost::numeric_cast<Real>(numPoints);

    Real radius{};
    for (auto i = 0u; i < numPoints; ++i)
    {
        auto diff = points.at(i) - center;
        auto radiusSqr = Vector3Tools<Real>::GetLengthSquared(diff);
        if (radiusSqr > radius)
        {
            radius = radiusSqr;
        }
    }
    radius = Math<Real>::Sqrt(radius);
    Sphere3<Real> sphere{ center, radius };

    return sphere;
}

template <typename Real>
bool Mathematics::ContSphere3<Real>::InSphere(const Vector3<Real>& point, const Sphere3<Real>& sphere)
{
    auto diff = point - sphere.GetCenter();
    return Vector3Tools<Real>::GetLength(diff) <= sphere.GetRadius();
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::ContSphere3<Real>::MergeSpheres(const Sphere3<Real>& sphere0, const Sphere3<Real>& sphere1)
{
    auto cenDiff = sphere1.GetCenter() - sphere0.GetCenter();
    auto lenSqr = Vector3Tools<Real>::GetLengthSquared(cenDiff);
    auto rDiff = sphere1.GetRadius() - sphere0.GetRadius();
    auto rDiffSqr = rDiff * rDiff;

    if (rDiffSqr >= lenSqr)
    {
        return (rDiff >= Math<Real>::GetValue(0) ? sphere1 : sphere0);
    }

    auto length = Math<Real>::Sqrt(lenSqr);

    Vector3<Real> center;
    if (length > Math<Real>::GetZeroTolerance())
    {
        Real coeff = (length + rDiff) / ((Math<Real>::GetValue(2)) * length);
        center = sphere0.GetCenter() + coeff * cenDiff;
    }
    else
    {
        center = sphere0.GetCenter();
    }

    auto radius = Math<Real>::GetRational(1, 2) * (length + sphere0.GetRadius() + sphere1.GetRadius());
    Sphere3<Real> sphere{ center, radius };
    return sphere;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SPHERE3_DETAIL_H