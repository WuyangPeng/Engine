///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineBasis.h"
#include "SingleCurve3.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineCurve3 : public SingleCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BSplineCurve3<Real>;
        using ParentType = SingleCurve3<Real>;
        using Math = ParentType::MathType;

    public:
        BSplineCurve3(const std::vector<Vector3<Real>>& ctrlPoint, int degree, bool loop, bool open);
        BSplineCurve3(const std::vector<Vector3<Real>>& ctrlPoint, int degree, bool loop, const std::vector<Real>& knot);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumCtrlPoints() const noexcept;
        NODISCARD int GetDegree() const noexcept;
        NODISCARD bool IsOpen() const noexcept;
        NODISCARD bool IsUniform() const noexcept;
        NODISCARD bool IsLoop() const noexcept;

        void SetControlPoint(int i, const Vector3<Real>& ctrl);
        NODISCARD Vector3<Real> GetControlPoint(int i) const;

        void SetKnot(int i, Real knot);
        NODISCARD Real GetKnot(int i) const;

        NODISCARD Vector3<Real> GetPosition(Real t) const override;
        NODISCARD Vector3<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetThirdDerivative(Real t) const override;

        void Get(Real t, Vector3<Real>* pos, Vector3<Real>* der1, Vector3<Real>* der2, Vector3<Real>* der3) const;

        NODISCARD BSplineBasis<Real>& GetBasis() noexcept;

    protected:
        void CreateControl(const std::vector<Vector3<Real>>& newCtrlPoint);

    private:
        int numCtrlPoints;
        std::vector<Vector3<Real>> ctrlPoint;
        bool loop;
        BSplineBasis<Real> basis;
        int replicate;
    };

    using BSplineCurve3F = BSplineCurve3<float>;
    using BSplineCurve3D = BSplineCurve3<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_H
