///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 14:09)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_DETAIL_H

#include "BSplineGeodesic.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::BSplineGeodesic<Real>::BSplineGeodesic(const BSplineRectangle<Real>& spline)
    : RiemannianGeodesic<Real>{ 2 }, spline{ spline }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineGeodesic<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::BSplineGeodesic<Real>::ComputeMetric(const VariableLengthVector<Real>& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto der0 = spline.PU(point[0], point[1]);
    const auto der1 = spline.PV(point[0], point[1]);

    this->SetMetric(0, 0, Vector3Tools<Real>::DotProduct(der0, der0));
    this->SetMetric(0, 1, Vector3Tools<Real>::DotProduct(der0, der1));
    this->SetMetric(1, 0, this->GetMetric(0, 1));
    this->SetMetric(1, 1, Vector3Tools<Real>::DotProduct(der1, der1));
}

template <typename Real>
void Mathematics::BSplineGeodesic<Real>::ComputeChristoffel1(const VariableLengthVector<Real>& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto der0 = spline.PU(point[0], point[1]);
    const auto der1 = spline.PV(point[0], point[1]);
    const auto der00 = spline.PUU(point[0], point[1]);
    const auto der01 = spline.PUV(point[0], point[1]);
    const auto der11 = spline.PVV(point[0], point[1]);

    this->SetChristoffel1(0, 0, 0, Vector3Tools<Real>::DotProduct(der00, der0));
    this->SetChristoffel1(0, 0, 1, Vector3Tools<Real>::DotProduct(der01, der0));
    this->SetChristoffel1(0, 1, 0, this->GeChristoffel1(0, 0, 1));
    this->SetChristoffel1(0, 1, 1, Vector3Tools<Real>::DotProduct(der11, der0));

    this->SetChristoffel1(1, 0, 0, Vector3Tools<Real>::DotProduct(der00, der1));
    this->SetChristoffel1(1, 0, 1, Vector3Tools<Real>::DotProduct(der01, der1));
    this->SetChristoffel1(1, 1, 0, this->GeChristoffel1(1, 0, 1));
    this->SetChristoffel1(1, 1, 1, Vector3Tools<Real>::DotProduct(der11, der1));
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_DETAIL_H