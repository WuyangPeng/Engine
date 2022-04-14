///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/16 11:21)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_H

#include "Mathematics/MathematicsDll.h"

#include "RiemannianGeodesic.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class EllipsoidGeodesic : public RiemannianGeodesic<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = EllipsoidGeodesic<Real>;
        using ParentType = RiemannianGeodesic<Real>;
        using Math = Math<Real>;

    public:
        EllipsoidGeodesic(Real xExtent, Real yExtent, Real zExtent);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3<Real> ComputePosition(const VariableLengthVector<Real>& point);
        void ComputeMetric(const VariableLengthVector<Real>& point) override;
        void ComputeChristoffel1(const VariableLengthVector<Real>& point) override;

    private:
        Real xExtent;
        Real yExtent;
        Real zExtent;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_H
