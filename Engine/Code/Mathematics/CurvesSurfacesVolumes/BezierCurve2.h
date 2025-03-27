///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve2.h"

namespace Mathematics
{
    template <typename Real>
    class BezierCurve2 : public SingleCurve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BezierCurve2<Real>;
        using ParentType = SingleCurve2<Real>;
        using MathType = typename ParentType::MathType;

    public:
        BezierCurve2(int degree, const std::vector<Vector2<Real>>& ctrlPoint);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetDegree() const noexcept;
        NODISCARD std::vector<Vector2<Real>> GetControlPoints() const;

        NODISCARD Vector2<Real> GetPosition(Real t) const override;
        NODISCARD Vector2<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetThirdDerivative(Real t) const override;

    private:
        int degree;
        int numCtrlPoints;
        std::vector<Vector2<Real>> ctrlPoint;
        std::vector<Vector2<Real>> der1CtrlPoint;
        std::vector<Vector2<Real>> der2CtrlPoint;
        std::vector<Vector2<Real>> der3CtrlPoint;
        std::vector<std::vector<Real>> choose;
    };

    using BezierCurve2F = BezierCurve2<float>;
    using BezierCurve2D = BezierCurve2<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_H
