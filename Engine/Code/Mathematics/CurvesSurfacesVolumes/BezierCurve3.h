///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/14 13:37)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve3.h"

namespace Mathematics
{
    template <typename Real>
    class BezierCurve3 : public SingleCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BezierCurve3<Real>;
        using ParentType = SingleCurve3<Real>;
        using Math = ParentType::Math;

    public:
        BezierCurve3(int degree, const std::vector<Vector3<Real>>& ctrlPoint);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetDegree() const noexcept;
        NODISCARD std::vector<Vector3<Real>> GetControlPoints() const;

        NODISCARD Vector3<Real> GetPosition(Real t) const override;
        NODISCARD Vector3<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector3<Real> GetThirdDerivative(Real t) const override;

    private:
        int degree;
        int numCtrlPoints;
        std::vector<Vector3<Real>> ctrlPoint;
        std::vector<Vector3<Real>> der1CtrlPoint;
        std::vector<Vector3<Real>> der2CtrlPoint;
        std::vector<Vector3<Real>> der3CtrlPoint;
        std::vector<std::vector<Real>> choose;
    };

    using BezierCurve3F = BezierCurve3<float>;
    using BezierCurve3D = BezierCurve3<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H
