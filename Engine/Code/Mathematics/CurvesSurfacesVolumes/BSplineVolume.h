///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 16:37)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineBasis.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineVolume
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineVolume<Real>;

    public:
        BSplineVolume(int numUCtrlPoints, int numVCtrlPoints, int numWCtrlPoints, int uDegree, int vDegree, int wDegree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumCtrlPoints(int dim) const noexcept;
        NODISCARD int GetDegree(int dim) const noexcept;

        void SetControlPoint(int uIndex, int vIndex, int wIndex, const Vector3<Real>& newCtrlPoint);
        NODISCARD Vector3<Real> GetControlPoint(int uIndex, int vIndex, int wIndex) const;

        NODISCARD Vector3<Real> GetPosition(Real u, Real v, Real w) const;
        NODISCARD Vector3<Real> GetDerivativeU(Real u, Real v, Real w) const;
        NODISCARD Vector3<Real> GetDerivativeV(Real u, Real v, Real w) const;
        NODISCARD Vector3<Real> GetDerivativeW(Real u, Real v, Real w) const;

        NODISCARD Vector3<Real> GetPosition(const std::array<Real, 3>& pos) const;
        NODISCARD Vector3<Real> GetDerivative(int i, const std::array<Real, 3>& pos) const;

    private:
        std::vector<std::vector<std::vector<Vector3<Real>>>> ctrlPoint;
        std::array<BSplineBasis<Real>, 3> basis;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_H
