// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.2 (2019/07/17 18:27)

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
        using Math = Math<Real>;

    public:
        // Abstract base class.
        SingleCurve3(Real tmin, Real tmax) noexcept;

        // Length-from-time and time-from-length.
        Real GetLength(Real t0, Real t1) const override;
        Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const override;

    protected:
        using Curve3<Real>::GetSpeed;
        using Curve3<Real>::GetTotalLength;

        static Real GetSpeedWithData(Real t, const SingleCurve3<Real>* data);
    };

    using SingleCurve3f = SingleCurve3<float>;
    using SingleCurve3d = SingleCurve3<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE3_H
