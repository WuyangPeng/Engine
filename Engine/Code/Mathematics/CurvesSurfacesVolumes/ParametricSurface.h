///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include "Surface.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class ParametricSurface : public Surface<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ParametricSurface<Real>;
        using ParentType = Surface<Real>;
        using MathType = Math<Real>;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Real GetUMin() const noexcept;
        NODISCARD Real GetUMax() const noexcept;
        NODISCARD Real GetVMin() const noexcept;
        NODISCARD Real GetVMax() const noexcept;
        NODISCARD bool IsRectangular() const noexcept;

        NODISCARD virtual Vector3<Real> P(Real u, Real v) const = 0;
        NODISCARD virtual Vector3<Real> PU(Real u, Real v) const = 0;
        NODISCARD virtual Vector3<Real> PV(Real u, Real v) const = 0;
        NODISCARD virtual Vector3<Real> PUU(Real u, Real v) const = 0;
        NODISCARD virtual Vector3<Real> PUV(Real u, Real v) const = 0;
        NODISCARD virtual Vector3<Real> PVV(Real u, Real v) const = 0;

        void GetFrame(Real u, Real v, Vector3<Real>& position, Vector3<Real>& tangent0, Vector3<Real>& tangent1, Vector3<Real>& normal) const;

        void ComputePrincipalCurvatureInfo(Real u, Real v, Real& curv0, Real& curv1, Vector3<Real>& dir0, Vector3<Real>& dir1);

    protected:
        ParametricSurface(Real umin, Real umax, Real vmin, Real vmax, bool rectangular);

    private:
        Real uMin;
        Real uMax;
        Real vMin;
        Real vMax;
        bool rectangular;
    };

    using ParametricSurfaceF = ParametricSurface<float>;
    using ParametricSurfaceD = ParametricSurface<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_H
