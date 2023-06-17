///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:57)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "Curve3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingleCurve3 : public Curve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingleCurve3<Real>;
        using ParentType = Curve3<Real>;
        using Math = Math<Real>;

    public:
        SingleCurve3(Real tmin, Real tmax) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Real GetLength(Real t0, Real t1) const override;
        NODISCARD Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const override;

    protected:
        NODISCARD static Real GetSpeedWithData(Real t, const SingleCurve3<Real>* data);
    };

    using SingleCurve3F = SingleCurve3<float>;
    using SingleCurve3D = SingleCurve3<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE3_H
