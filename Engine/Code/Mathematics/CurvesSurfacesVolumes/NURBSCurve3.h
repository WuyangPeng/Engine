///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineBasis.h"
#include "SingleCurve3.h"

namespace Mathematics
{
    template <typename Real>
    class NURBSCurve3 : public SingleCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NURBSCurve3<Real>;
        using ParentType = SingleCurve3<Real>;

    public:
        NURBSCurve3(int numCtrlPoints, const std::vector<Vector3<Real>>& ctrlPoint, const std::vector<Real>& ctrlWeight, int degree, bool loop, bool open);

        NURBSCurve3(int numCtrlPoints, const std::vector<Vector3<Real>>& ctrlPoint, const std::vector<Real>& ctrlWeight, int degree, bool loop, const std::vector<Real>& knot);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumCtrlPoints() const noexcept;
        NODISCARD int GetDegree() const noexcept;
        NODISCARD bool IsOpen() const noexcept;
        NODISCARD bool IsUniform() const noexcept;
        NODISCARD bool IsLoop() const noexcept;

        void SetControlPoint(int i, const Vector3<Real>& ctrl);
        NODISCARD Vector3<Real> GetControlPoint(int i) const;
        void SetControlWeight(int i, Real weight);
        NODISCARD Real GetControlWeight(int i) const;

        void SetKnot(int i, Real knot);
        NODISCARD Real GetKnot(int i) const;

        NODISCARD Vector3<Real> GetPosition(Real t) const override;
        NODISCARD Vector3<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetThirdDerivative(Real t) const override;

        void Get(Real t, Vector3<Real>* pos, Vector3<Real>* der1, Vector3<Real>* der2, Vector3<Real>* der3) const;

        NODISCARD BSplineBasis<Real>& GetBasis() noexcept;

    protected:
        void CreateControl(const std::vector<Vector3<Real>>& newCtrlPoint, const std::vector<Real>& newCtrlWeight);

    private:
        int numCtrlPoints;
        std::vector<Vector3<Real>> ctrlPoint;
        std::vector<Real> ctrlWeight;
        bool loop;
        BSplineBasis<Real> basis;
        int replicate;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE3_H
