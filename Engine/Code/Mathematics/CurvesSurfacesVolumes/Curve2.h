///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Curve2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Curve2<Real>;

    public:
        Curve2(Real tmin, Real tmax) noexcept;
        virtual ~Curve2() noexcept = default;
        Curve2(const Curve2& rhs) = default;
        Curve2& operator=(const Curve2& rhs) = default;
        Curve2(Curve2&& rhs) = default;
        Curve2& operator=(Curve2&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD Real GetMinTime() const noexcept;
        NODISCARD Real GetMaxTime() const noexcept;
        void SetTimeInterval(Real tmin, Real tmax);

        NODISCARD virtual Vector2<Real> GetPosition(Real t) const = 0;
        NODISCARD virtual Vector2<Real> GetFirstDerivative(Real t) const = 0;
        NODISCARD virtual Vector2<Real> GetSecondDerivative(Real t) const = 0;
        NODISCARD virtual Vector2<Real> GetThirdDerivative(Real t) const = 0;

        NODISCARD Real GetSpeed(Real t) const;
        NODISCARD virtual Real GetLength(Real t0, Real t1) const = 0;
        NODISCARD Real GetTotalLength() const;
        NODISCARD Vector2<Real> GetTangent(Real t) const;
        NODISCARD Vector2<Real> GetNormal(Real t) const;
        void GetFrame(Real t, Vector2<Real>& position, Vector2<Real>& tangent, Vector2<Real>& normal) const;
        NODISCARD Real GetCurvature(Real t) const;

        NODISCARD virtual Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const = 0;

        NODISCARD std::vector<Vector2<Real>> SubdivideByTime(int numPoints) const;
        NODISCARD std::vector<Vector2<Real>> SubdivideByLength(int numPoints) const;

    private:
        Real tMin;
        Real tMax;
    };

    using Curve2F = Curve2<float>;
    using Curve2D = Curve2<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_H
