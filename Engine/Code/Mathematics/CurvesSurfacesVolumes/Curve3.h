///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/13 15:17)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Curve3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Curve3<Real>;

    public:
        Curve3(Real tmin, Real tmax) noexcept;
        virtual ~Curve3() noexcept = default;
        Curve3(const Curve3& rhs) = default;
        Curve3& operator=(const Curve3& rhs) = default;
        Curve3(Curve3&& rhs) = default;
        Curve3& operator=(Curve3&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD Real GetMinTime() const noexcept;
        NODISCARD Real GetMaxTime() const noexcept;
        void SetTimeInterval(Real tmin, Real tmax);

        NODISCARD virtual Vector3<Real> GetPosition(Real t) const = 0;
        NODISCARD virtual Vector3<Real> GetFirstDerivative(Real t) const = 0;
        NODISCARD virtual Vector3<Real> GetSecondDerivative(Real t) const = 0;
        NODISCARD virtual Vector3<Real> GetThirdDerivative(Real t) const = 0;

        NODISCARD Real GetSpeed(Real t) const;
        NODISCARD virtual Real GetLength(Real t0, Real t1) const = 0;
        NODISCARD Real GetTotalLength() const;
        NODISCARD Vector3<Real> GetTangent(Real t) const;
        NODISCARD Vector3<Real> GetNormal(Real t) const;
        NODISCARD Vector3<Real> GetBinormal(Real t) const;
        void GetFrame(Real t, Vector3<Real>& position, Vector3<Real>& tangent, Vector3<Real>& normal, Vector3<Real>& binormal) const;
        NODISCARD Real GetCurvature(Real t) const;
        NODISCARD Real GetTorsion(Real t) const;

        NODISCARD virtual Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const = 0;

        NODISCARD std::vector<Vector3<Real>> SubdivideByTime(int numPoints) const;
        NODISCARD std::vector<Vector3<Real>> SubdivideByLength(int numPoints) const;

    private:
        Real tMin;
        Real tMax;
    };

    using Curve3F = Curve3<float>;
    using Curve3D = Curve3<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_H
