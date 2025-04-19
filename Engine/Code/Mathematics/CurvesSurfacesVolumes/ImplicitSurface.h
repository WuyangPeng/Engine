///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include "Surface.h"
#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class ImplicitSurface : public Surface<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ImplicitSurface<Real>;
        using ParentType = Surface<Real>; 

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual Real F(const Vector3<Real>& pos) const = 0;

        NODISCARD virtual Real FX(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FY(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FZ(const Vector3<Real>& pos) const = 0;

        NODISCARD virtual Real FXX(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FXY(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FXZ(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FYY(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FYZ(const Vector3<Real>& pos) const = 0;
        NODISCARD virtual Real FZZ(const Vector3<Real>& pos) const = 0;

        NODISCARD bool IsOnSurface(const Vector3<Real>& pos, Real epsilon) const;

        NODISCARD Vector3<Real> GetGradient(const Vector3<Real>& pos) const;

        NODISCARD Matrix3<Real> GetHessian(const Vector3<Real>& pos) const;

        void GetFrame(const Vector3<Real>& pos, Vector3<Real>& tangent0, Vector3<Real>& tangent1, Vector3<Real>& normal) const;

        NODISCARD bool ComputePrincipalCurvatureInfo(const Vector3<Real>& pos, Real& curv0, Real& curv1, Vector3<Real>& dir0, Vector3<Real>& dir1);

    protected:
        ImplicitSurface() noexcept = default;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_H
