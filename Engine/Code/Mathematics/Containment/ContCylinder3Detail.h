// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:29)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_DETAIL_H

#include "ContCylinder3.h"
#include "Mathematics/Approximation/OrthogonalLineFit3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3.h" 

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics
	::ContCylinder (const std::vector<Vector3<Real> >& points)
{
	auto line = OrthogonalLineFit3<Real>(points).GetLine3();

	auto maxRadiusSqr = Math<Real>::GetValue(0);
 
    for (auto i = 0u; i < points.size(); ++i)
    {
		auto radiusSqr = DistancePoint3Line3<Real>(points[i], line).GetSquared().GetDistance();
        if (radiusSqr > maxRadiusSqr)
        {
            maxRadiusSqr = radiusSqr;
        }
    }

	auto diff = points[0] - line.GetOrigin();
	auto wMin = Vector3Tools<Real>::DotProduct(line.GetDirection(),diff);
	auto wMax = wMin;
    for (auto i = 1u; i < points.size(); ++i)
    {
        diff = points[i] - line.GetOrigin();
		auto w = Vector3Tools<Real>::DotProduct(line.GetDirection(),diff);
        if (w < wMin)
        {
            wMin = w;
        }
        else if (w > wMax)
        {
            wMax = w;
        }
    }

	auto origin = line.GetOrigin() + ((Real{0.5})*(wMax + wMin))*line.GetDirection();
	auto direction = line.GetDirection();

	Line3<Real> axis{ origin,direction };
	
	auto radius = Math<Real>::Sqrt(maxRadiusSqr);
	auto height = wMax - wMin;

	Cylinder3<Real> cylinder{ axis,radius,height };

    return cylinder;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_DETAIL_H