///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/10 14:31)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_DETAIL_H

#include "ContCylinder3.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3.h"

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics::ContCylinder3<Real>::ContCylinder(const std::vector<Vector3<Real>>& points)
{
    const auto line = OrthogonalLineFit3<Real>(points).GetLine3();

    auto maxRadiusSqr = Math<Real>::GetValue(0);

    for (auto i = 0u; i < points.size(); ++i)
    {
        auto radiusSqr = DistancePoint3Line3<Real>(points.at(i), line).GetSquared().GetDistance();
        if (radiusSqr > maxRadiusSqr)
        {
            maxRadiusSqr = radiusSqr;
        }
    }

    auto diff = points.at(0) - line.GetOrigin();
    auto wMin = Vector3Tools<Real>::DotProduct(line.GetDirection(), diff);
    auto wMax = wMin;
    for (auto i = 1u; i < points.size(); ++i)
    {
        diff = points.at(i) - line.GetOrigin();
        auto w = Vector3Tools<Real>::DotProduct(line.GetDirection(), diff);
        if (w < wMin)
        {
            wMin = w;
        }
        else if (w > wMax)
        {
            wMax = w;
        }
    }

    auto origin = line.GetOrigin() + Math<Real>::GetRational(1, 2) * (wMax + wMin) * line.GetDirection();
    const auto direction = line.GetDirection();

    const Line3<Real> axis{ origin, direction };

    auto radius = Math<Real>::Sqrt(maxRadiusSqr);
    auto height = wMax - wMin;

    Cylinder3<Real> cylinder{ axis, radius, height };

    return cylinder;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_DETAIL_H