///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/17 10:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve3.h"

namespace Mathematics
{
    template <typename Real>
    class NaturalSpline3 : public MultipleCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NaturalSpline3<Real>;
        using ParentType = MultipleCurve3<Real>;

    public:
        enum class BoundaryType
        {
            Free,
            Clamped,
            Closed
        };

        NaturalSpline3(BoundaryType type, int numSegments, const std::vector<Real>& times, const std::vector<Vector3<Real>>& points);

        NaturalSpline3(int numSegments, const std::vector<Real>& times, const std::vector<Vector3<Real>>& points, const Vector3<Real>& derivativeStart, const Vector3<Real>& derivativeFinal);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::vector<Vector3<Real>> GetPoints() const;

        NODISCARD Vector3<Real> GetPosition(Real t) const override;
        NODISCARD Vector3<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetThirdDerivative(Real t) const override;

    protected:
        void CreateFreeSpline();

        void CreateClampedSpline(const Vector3<Real>& derivativeStart, const Vector3<Real>& derivativeFinal);

        void CreateClosedSpline();

        NODISCARD Real GetSpeedKey(int key, Real t) const override;
        NODISCARD Real GetLengthKey(int key, Real t0, Real t1) const override;

    private:
        class SplineKey
        {
        public:
            SplineKey(const NaturalSpline3* spline, int key) noexcept;

            const NaturalSpline3* spline;
            int key;
        };

        NODISCARD static Real GetSpeedWithDataKey(Real t, const SplineKey* data);

    private:
        std::vector<Vector3<Real>> a;
        std::vector<Vector3<Real>> b;
        std::vector<Vector3<Real>> c;
        std::vector<Vector3<Real>> d;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_H
