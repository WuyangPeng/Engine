/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 14:04)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_CONTROL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_CONTROL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3EllipseAndPointsControl
    {
    public:
        using ClassType = ApproximationCone3EllipseAndPointsControl<Real>;

        using MathType = Math<Real>;

    public:
        ApproximationCone3EllipseAndPointsControl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool ValidParameters() const noexcept;

        NODISCARD Real GetPenalty() const noexcept;
        NODISCARD int GetMaxSubdivisions() const noexcept;
        NODISCARD int GetMaxBisections() const noexcept;
        NODISCARD Real GetEpsilon() const noexcept;
        NODISCARD Real GetTolerance() const noexcept;
        NODISCARD Real GetPadding() const noexcept;

        void SetPenalty(Real aPenalty) noexcept;
        void SetMaxSubdivisions(int aMaxSubdivisions) noexcept;
        void SetMaxBisections(int aMaxBisections) noexcept;
        void SetEpsilon(Real aEpsilon) noexcept;
        void SetTolerance(Real aTolerance) noexcept;
        void SetPadding(Real aPadding) noexcept;

    private:
        /// 用位于支撑圆锥体的平面下方的points[i]的罚值来更新最小二乘误差函数；
        /// 即当点积Dot(coneDirection, points[i] - coneVertex) < 0时。
        Real penalty;

        /// Minimizer1<T>的参数
        int maxSubdivisions;
        int maxBisections = 64;
        Real epsilon = MathType::GetValue(1e-08);
        Real tolerance = MathType::GetValue(1e-04);

        /// 在[0 + padding, pi/2 - padding]上搜索最小值，
        /// 以避免在[0,pi/2]的端点处被最小二乘误差函数的零除。
        Real padding;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_ELLIPSE_AND_POINTS_CONTROL_H
