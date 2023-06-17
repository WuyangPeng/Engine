///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:39)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_DETAIL_H

#include "ContEllipsoid3.h"
#include "Mathematics/Algebra/Quaternion.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3.h"

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::ContEllipsoid3<Real>::ContEllipsoid(const std::vector<Vector3<Real>>& points)
{
    const auto box = GaussPointsFit3<Real>(points).GetBox3();
    Vector3<Real> diag{ box.GetExtent(0), box.GetExtent(1), box.GetExtent(2) };
    std::array<Vector3<Real>, 3> axis{ box.GetAxis(0), box.GetAxis(1), box.GetAxis(2) };

    for (auto i = 0; i < 3; ++i)
    {
        if (diag[i] < Math<Real>::GetValue(0))
        {
            diag[i] = -diag[i];
        }
        if (diag[i] < Math<Real>::GetZeroTolerance())
        {
            diag[i] = Math<Real>::GetZeroTolerance();
        }
    }

    auto maxValue = Math<Real>::GetValue(0);
    for (auto i = 0u; i < points.size(); ++i)
    {
        auto diff = points.at(i) - box.GetCenter();
        Vector3<Real> dot{ Vector3Tools<Real>::DotProduct(axis.at(0), diff),
                           Vector3Tools<Real>::DotProduct(axis.at(1), diff),
                           Vector3Tools<Real>::DotProduct(axis.at(2), diff) };

        auto value = dot[0] * dot[0] / diag[0] + dot[1] * dot[1] / diag[1] + dot[2] * dot[2] / diag[2];

        if (value > maxValue)
        {
            maxValue = value;
        }
    }

    for (auto i = 0u; i < 3; ++i)
    {
        diag[i] *= maxValue;
    }

    Ellipsoid3<Real> ellipsoid{ box.GetCenter(),
                                axis.at(0),
                                axis.at(1),
                                axis.at(2),
                                Math<Real>::Sqrt(diag[0]),
                                Math<Real>::Sqrt(diag[1]),
                                Math<Real>::Sqrt(diag[2]) };

    return ellipsoid;
}

template <typename Real>
void Mathematics::ContEllipsoid3<Real>::ProjectEllipsoid(const Ellipsoid3<Real>& ellipsoid, const Line3<Real>& line, Real& smin, Real& smax)
{
    auto center = Vector3Tools<Real>::DotProduct(line.GetDirection(), ellipsoid.GetCenter() - line.GetOrigin());

    Vector3<Real> tmp{ ellipsoid.GetExtent0() * (Vector3Tools<Real>::DotProduct(line.GetDirection(), ellipsoid.GetAxis0())),
                       ellipsoid.GetExtent1() * (Vector3Tools<Real>::DotProduct(line.GetDirection(), ellipsoid.GetAxis1())),
                       ellipsoid.GetExtent2() * (Vector3Tools<Real>::DotProduct(line.GetDirection(), ellipsoid.GetAxis2())) };
    auto rSqr = tmp[0] * tmp[0] + tmp[1] * tmp[1] + tmp[2] * tmp[2];
    auto radius = Math<Real>::Sqrt(rSqr);

    smin = center - radius;
    smax = center + radius;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::ContEllipsoid3<Real>::MergeEllipsoids(const Ellipsoid3<Real>& ellipsoid0, const Ellipsoid3<Real>& ellipsoid1)
{
    auto center = Math<Real>::GetRational(1, 2) * (ellipsoid0.GetCenter() + ellipsoid1.GetCenter());

    std::vector<Vector3<Real>> rotationColumn0;
    rotationColumn0.emplace_back(ellipsoid0.GetAxis0());
    rotationColumn0.emplace_back(ellipsoid0.GetAxis1());
    rotationColumn0.emplace_back(ellipsoid0.GetAxis2());

    std::vector<Vector3<Real>> rotationColumn1;
    rotationColumn1.emplace_back(ellipsoid1.GetAxis0());
    rotationColumn1.emplace_back(ellipsoid1.GetAxis1());
    rotationColumn1.emplace_back(ellipsoid1.GetAxis2());

    const Quaternion<Real> q0{ rotationColumn0 };
    Quaternion<Real> q1{ rotationColumn1 };
    if (Dot(q0, q1) < Math<Real>::GetValue(0))
    {
        q1 = -q1;
    }
    auto q = q0 + q1;
    q = Math<Real>::InvSqrt(Dot(q, q)) * q;
    const auto matrix = q.ToRotationMatrix();

    std::array<Vector3<Real>, 3> axis{ Vector3<Real>{ matrix[0][0], matrix[0][1], matrix[0][2] },
                                       Vector3<Real>{ matrix[1][0], matrix[1][1], matrix[1][2] },
                                       Vector3<Real>{ matrix[2][0], matrix[2][1], matrix[2][2] } };

    Vector3<Real> extent{};

    for (auto i = 0; i < 3; ++i)
    {
        const Line3<Real> line{ center, axis.at(i) };

        Real min0{};
        Real max0{};
        Real min1{};
        Real max1{};
        ProjectEllipsoid(ellipsoid0, line, min0, max0);
        ProjectEllipsoid(ellipsoid1, line, min1, max1);

        auto maxIntr = (max0 >= max1 ? max0 : max1);
        auto minIntr = (min0 <= min1 ? min0 : min1);

        center += line.GetDirection() * Math<Real>::GetRational(1, 2) * (minIntr + maxIntr);

        extent[i] = Math<Real>::GetRational(1, 2) * (maxIntr - minIntr);
    }

    Ellipsoid3<Real> merge{ center, axis.at(0), axis.at(1), axis.at(2), extent[0], extent[1], extent[2] };

    return merge;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_DETAIL_H