///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_H
#define MATHEMATICS_DISTANCE_DISTANCE_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResult.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"
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

        DistanceBase(const DistanceBase& rhs) noexcept = default;
        DistanceBase& operator=(const DistanceBase& rhs) noexcept = default;
        DistanceBase(DistanceBase&& rhs) noexcept = default;
        DistanceBase& operator=(DistanceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 对于导数逼近。
        void SetDifferenceStep(Real newDifferenceStep) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD Real GetDifferenceStep() const noexcept;

        void SetMaximumIterations(int newMaximumIterations) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD int GetMaximumIterations() const noexcept;

        void SetZeroThreshold(Real newZeroThreshold) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD Real GetZeroThreshold() const noexcept;

        // 静态距离查询。
        // 距离（默认实现为调用GetSquared，对DistanceResult中的距离值进行开方）
        NODISCARD virtual DistanceResult Get() const;
        // 距离平方
        NODISCARD virtual DistanceResult GetSquared() const = 0;

        // 函数计算动态距离查询。
        // （默认实现为调用GetSquared，对DistanceResult中的距离值进行开方）
        NODISCARD virtual DistanceResult Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        NODISCARD virtual DistanceResult GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const = 0;

        // 微分计算动态距离查询。默认使用有限差分估计f'(t) = (f(t + h) - f(t - h)) / (2 * h)，其中h = m_DifferenceStep。
        // 派生类可以覆盖这些，并提供不要求h的精确公式的实现。
        NODISCARD virtual Real GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        NODISCARD virtual Real GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

        // 动态距离查询。函数计算在时间间隔[tmin,tmax]两个对象之间的最小距离。
        // 默认实现假设是，距离f(t)是一个凸函数。
        NODISCARD virtual DistanceResult GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        NODISCARD virtual DistanceResult GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

    private:
        static constexpr auto defaultMaximumIterations = 8;
        static constexpr Real defaultZeroThreshold = Math::GetZeroTolerance();
        static constexpr Real defaultDifferenceStep = Math::GetRational(1, 1000);

    private:
        // 对于牛顿法和逆抛物线插值。
        // 默认 = 8
        int maximumIterations;
        // 默认 = Math<Real>::GetZeroTolerance()
        Real zeroThreshold;

        // 默认 = 1e-03
        Real differenceStep;
        Real inverseTwoDifferenceStep;
    };

    using Distance2F = DistanceBase<float, Vector2F>;
    using Distance3F = DistanceBase<float, Vector3F>;
    using Distance2D = DistanceBase<double, Vector2D>;
    using Distance3D = DistanceBase<double, Vector3D>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_H
