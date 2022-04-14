///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/17 20:38)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve2.h"

namespace Mathematics
{
    template <typename Real>
    class TCBSpline2 : public MultipleCurve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = TCBSpline2<Real>;
        using ParentType = MultipleCurve2<Real>;

    public:
        TCBSpline2(int numSegments,
                   const std::vector<Real>& times,
                   const std::vector<Vector2<Real>>& points,
                   const std::vector<Real>& tension,
                   const std::vector<Real>& continuity,
                   const std::vector<Real>& bias);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::vector<Vector2<Real>> GetPoints() const;
        NODISCARD std::vector<Real> GetTensions() const;
        NODISCARD std::vector<Real> GetContinuities() const;
        NODISCARD std::vector<Real> GetBiases() const;

        NODISCARD Vector2<Real> GetPosition(Real t) const override;
        NODISCARD Vector2<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetThirdDerivative(Real t) const override;

    protected:
        void ComputePoly(int i0, int i1, int i2, int i3);

        NODISCARD Real GetSpeedKey(int key, Real t) const override;
        NODISCARD Real GetLengthKey(int key, Real t0, Real t1) const override;

    private:
        class SplineKey
        {
        public:
            SplineKey(const TCBSpline2* spline, int key) noexcept;

            const TCBSpline2* spline;
            int key;
        };

        static Real GetSpeedWithDataKey(Real t, const SplineKey* data);

    private:
        std::vector<Vector2<Real>> points;
        std::vector<Real> tension;
        std::vector<Real> continuity;
        std::vector<Real> bias;
        std::vector<Vector2<Real>> a;
        std::vector<Vector2<Real>> b;
        std::vector<Vector2<Real>> c;
        std::vector<Vector2<Real>> d;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_H
