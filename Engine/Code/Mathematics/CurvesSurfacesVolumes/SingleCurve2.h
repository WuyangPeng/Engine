// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.2 (2019/07/17 18:27)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "Curve2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingleCurve2 : public Curve2<Real>
    {
    public:
        using Math = Math<Real>;

    public:
        // Abstract base class.
        SingleCurve2(Real tmin, Real tmax) noexcept;

        // Length-from-time and time-from-length.
        Real GetLength(Real t0, Real t1) const override;
        Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const override;

    protected:
        using Curve2<Real>::GetSpeed;
        using Curve2<Real>::GetTotalLength;

        static Real GetSpeedWithData(Real t, const SingleCurve2<Real>* data);
    };

    using SingleCurve2f = SingleCurve2<float>;
    using SingleCurve2d = SingleCurve2<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_H
