///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:03)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve3.h"

namespace Mathematics
{
    template <typename Real>
    class TCBSpline3 : public MultipleCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = TCBSpline3<Real>;
        using ParentType = MultipleCurve3<Real>;

    public:
        TCBSpline3(int numSegments,
                   const std::vector<Real>& times,
                   const std::vector<Vector3<Real>>& points,
                   const std::vector<Real>& tension,
                   const std::vector<Real>& continuity,
                   const std::vector<Real>& bias);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::vector<Vector3<Real>> GetPoints() const;
        NODISCARD std::vector<Real> GetTensions() const;
        NODISCARD std::vector<Real> GetContinuities() const;
        NODISCARD std::vector<Real> GetBiases() const;

        NODISCARD Vector3<Real> GetPosition(Real t) const override;
        NODISCARD Vector3<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetThirdDerivative(Real t) const override;

    protected:
        void ComputePoly(int i0, int i1, int i2, int i3);

        NODISCARD Real GetSpeedKey(int key, Real t) const override;
        NODISCARD Real GetLengthKey(int key, Real t0, Real t1) const override;

    private:
        class SplineKey
        {
        public:
            SplineKey(const TCBSpline3* spline, int key) noexcept;

            const TCBSpline3* spline;
            int key;
        };

        static Real GetSpeedWithDataKey(Real t, const SplineKey* data);

    private:
        std::vector<Vector3<Real>> points;
        std::vector<Real> tension;
        std::vector<Real> continuity;
        std::vector<Real> bias;
        std::vector<Vector3<Real>> a;
        std::vector<Vector3<Real>> b;
        std::vector<Vector3<Real>> c;
        std::vector<Vector3<Real>> d;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_H
