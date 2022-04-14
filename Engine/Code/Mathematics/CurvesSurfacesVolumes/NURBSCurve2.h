///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/17 14:29)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineBasis.h"
#include "SingleCurve2.h"

namespace Mathematics
{
    template <typename Real>
    class NURBSCurve2 : public SingleCurve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NURBSCurve2<Real>;
        using ParentType = SingleCurve2<Real>;

    public:
        NURBSCurve2(int numCtrlPoints, const std::vector<Vector2<Real>>& ctrlPoint, const std::vector<Real>& ctrlWeight, int degree, bool loop, bool open);

        NURBSCurve2(int numCtrlPoints, const std::vector<Vector2<Real>>& ctrlPoint, const std::vector<Real>& ctrlWeight, int degree, bool loop, const std::vector<Real>& knot);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumCtrlPoints() const noexcept;
        NODISCARD int GetDegree() const noexcept;
        NODISCARD bool IsOpen() const noexcept;
        NODISCARD bool IsUniform() const noexcept;
        NODISCARD bool IsLoop() const noexcept;

        void SetControlPoint(int i, const Vector2<Real>& ctrl);
        NODISCARD Vector2<Real> GetControlPoint(int i) const;
        void SetControlWeight(int i, Real weight);
        NODISCARD Real GetControlWeight(int i) const;

        void SetKnot(int i, Real knot);
        NODISCARD Real GetKnot(int i) const;

        NODISCARD Vector2<Real> GetPosition(Real t) const override;
        NODISCARD Vector2<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetThirdDerivative(Real t) const override;

        void Get(Real t, Vector2<Real>* pos, Vector2<Real>* der1, Vector2<Real>* der2, Vector2<Real>* der3) const;

        NODISCARD BSplineBasis<Real>& GetBasis() noexcept;

    protected:
        void CreateControl(const std::vector<Vector2<Real>>& newCtrlPoint, const std::vector<Real>& newCtrlWeight);

    private:
        int numCtrlPoints;
        std::vector<Vector2<Real>> ctrlPoint;
        std::vector<Real> ctrlWeight;
        bool loop;
        BSplineBasis<Real> basis;
        int replicate;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_H
