///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:56)

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
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingleCurve2<Real>;
        using ParentType = Curve2<Real>;
        using Math = Math<Real>;

    public:
        SingleCurve2(Real tmin, Real tmax) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Real GetLength(Real t0, Real t1) const override;
        NODISCARD Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const override;

    protected:
        NODISCARD static Real GetSpeedWithData(Real t, const SingleCurve2<Real>* data);
    };

    using SingleCurve2F = SingleCurve2<float>;
    using SingleCurve2D = SingleCurve2<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_H
