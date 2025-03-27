///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:55)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineBasis.h"
#include "ParametricSurface.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineRectangle : public ParametricSurface<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineRectangle<Real>;
        using ParentType = ParametricSurface<Real>;
        using Math = ParentType::MathType;

    public:
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen);
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, Real* vKnot);
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, bool vOpen);
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, const std::vector<std::vector<Vector3<Real>>>& ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, Real* vKnot);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumCtrlPoints(int dim) const noexcept;
        NODISCARD int GetDegree(int dim) const noexcept;
        NODISCARD bool IsOpen(int dim) const noexcept;
        NODISCARD bool IsUniform(int dim) const;
        NODISCARD bool IsLoop(int dim) const noexcept;

        void SetControlPoint(int uIndex, int vIndex, const Vector3<Real>& ctrl);
        NODISCARD Vector3<Real> GetControlPoint(int uIndex, int vIndex) const;

        void SetKnot(int dim, int i, Real knot);
        NODISCARD Real GetKnot(int dim, int i) const;

        NODISCARD Vector3<Real> P(Real u, Real v) const override;
        NODISCARD Vector3<Real> PU(Real u, Real v) const override;
        NODISCARD Vector3<Real> PV(Real u, Real v) const override;
        NODISCARD Vector3<Real> PUU(Real u, Real v) const override;
        NODISCARD Vector3<Real> PUV(Real u, Real v) const override;
        NODISCARD Vector3<Real> PVV(Real u, Real v) const override;

        void Get(Real u, Real v, Vector3<Real>* pos, Vector3<Real>* derU, Vector3<Real>* derV, Vector3<Real>* derUU, Vector3<Real>* derUV, Vector3<Real>* derVV) const;

    private:
        int numUCtrlPoints;
        int numVCtrlPoints;
        std::vector<std::vector<Vector3<Real>>> ctrlPoint;
        std::array<bool, 2> loop;
        std::array<BSplineBasis<Real>, 2> basis;
        int uReplicate;
        int vReplicate;
    };

    using BSplineRectangleF = BSplineRectangle<float>;
    using BSplineRectangleD = BSplineRectangle<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_H
