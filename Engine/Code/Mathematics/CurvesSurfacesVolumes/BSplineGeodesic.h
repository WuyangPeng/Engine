///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/15 10:22)

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
