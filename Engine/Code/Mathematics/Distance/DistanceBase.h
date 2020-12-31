///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 14:40)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_H
#define MATHEMATICS_DISTANCE_DISTANCE_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResult.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceBase
    {
    public:
        using ClassType = DistanceBase<Real, Vector>;
        using DistanceResult = DistanceResult<Real, Vector>;
        using Math = Math<Real>;

    public:
        DistanceBase() noexcept;
        virtual ~DistanceBase() noexcept = default;

        DistanceBase(const DistanceBase& rhs) = default;
        DistanceBase& operator=(const DistanceBase& rhs) = default;
        DistanceBase(DistanceBase&& rhs) noexcept = default;
        DistanceBase& operator=(DistanceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 对于导数逼近。
        void SetDifferenceStep(Real differenceStep) noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        [[nodiscard]] Real GetDifferenceStep() const noexcept;

        void SetMaximumIterations(int maximumIterations) noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        [[nodiscard]] int GetMaximumIterations() const noexcept;

        void SetZeroThreshold(Real zeroThreshold) noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        [[nodiscard]] Real GetZeroThreshold() const noexcept;

        // 静态距离查询。
        // 距离（默认实现为调用GetSquared，对DistanceResult中的距离值进行开方）
        [[nodiscard]] virtual const DistanceResult Get() const;
        // 距离平方
        [[nodiscard]] virtual const DistanceResult GetSquared() const = 0;

        // 函数计算动态距离查询。
        // （默认实现为调用GetSquared，对DistanceResult中的距离值进行开方）
        [[nodiscard]] virtual const DistanceResult Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        [[nodiscard]] virtual const DistanceResult GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const = 0;

        // 微分计算动态距离查询。默认使用有限差分估计f'(t) = (f(t + h) - f(t - h)) / (2 * h)，其中h = m_DifferenceStep。
        // 派生类可以覆盖这些，并提供不要求h的精确公式的实现。
        [[nodiscard]] virtual Real GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        [[nodiscard]] virtual Real GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

        // 动态距离查询。函数计算在时间间隔[tmin,tmax]两个对象之间的最小距离。
        // 默认实现假设是，距离f(t)是一个凸函数。
        [[nodiscard]] virtual const DistanceResult GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        [[nodiscard]] virtual const DistanceResult GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

    private:
        static constexpr auto sm_DefaultMaximumIterations = 8;
        static constexpr Real sm_DefaultZeroThreshold = Math::GetZeroTolerance();
        static constexpr Real sm_DefaultDifferenceStep = Math::GetRational(1, 1000);
    
    private:
        // 对于牛顿法和逆抛物线插值。
        // 默认 = 8
        int m_MaximumIterations;
        // 默认 = Math<Real>::GetZeroTolerance()
        Real m_ZeroThreshold;

        // 默认 = 1e-03
        Real m_DifferenceStep;
        Real m_InverseTwoDifferenceStep;
    };

    using Distance2f = DistanceBase<float, FloatVector2D>;
    using Distance3f = DistanceBase<float, FloatVector3D>;
    using Distance2d = DistanceBase<double, DoubleVector2D>;
    using Distance3d = DistanceBase<double, DoubleVector3D>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_H
