///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineRectangle.h"
#include "RiemannianGeodesic.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineGeodesic : public RiemannianGeodesic<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineGeodesic<Real>;
        using Math = Math<Real>;

    public:
        BSplineGeodesic(const BSplineRectangle<Real>& spline);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void ComputeMetric(const VariableLengthVector<Real>& point) override;
        void ComputeChristoffel1(const VariableLengthVector<Real>& point) override;

    private:
        BSplineRectangle<Real> spline;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_GEODESIC_H
