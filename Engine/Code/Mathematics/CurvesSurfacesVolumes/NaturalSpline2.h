///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/16 21:26)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve2.h"

namespace Mathematics
{
    template <typename Real>
    class NaturalSpline2 : public MultipleCurve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NaturalSpline2<Real>;
        using ParentType = MultipleCurve2<Real>;

    public:
        enum class BoundaryType
        {
            Free,
            Clamped,
            Closed
        };

        NaturalSpline2(BoundaryType type, int numSegments, const std::vector<Real>& times, const std::vector<Vector2<Real>>& points);

        NaturalSpline2(int numSegments, const std::vector<Real>& times, const std::vector<Vector2<Real>>& points, const Vector2<Real>& derivativeStart, const Vector2<Real>& derivativeFinal);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD std::vector<Vector2<Real>> GetPoints() const;

        NODISCARD Vector2<Real> GetPosition(Real t) const override;
        NODISCARD Vector2<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetThirdDerivative(Real t) const override;

    protected:
        void CreateFreeSpline();

        void CreateClampedSpline(const Vector2<Real>& derivativeStart, const Vector2<Real>& derivativeFinal);

        void CreateClosedSpline();

        NODISCARD Real GetSpeedKey(int key, Real t) const override;
        NODISCARD Real GetLengthKey(int key, Real t0, Real t1) const override;

    private:
        class SplineKey
        {
        public:
            SplineKey(const NaturalSpline2* spline, int key) noexcept;

            const NaturalSpline2* spline;
            int key;
        };

        NODISCARD static Real GetSpeedWithDataKey(Real t, const SplineKey* data);

    private:
        std::vector<Vector2<Real>> a;
        std::vector<Vector2<Real>> b;
        std::vector<Vector2<Real>> c;
        std::vector<Vector2<Real>> d;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_H
