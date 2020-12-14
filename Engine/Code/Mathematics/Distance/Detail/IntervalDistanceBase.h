///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 15:11)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H

#include "Mathematics/Distance/DistanceFwd.h"
#include "Mathematics/Distance/DistanceResult.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE IntervalDistanceBase : private boost::noncopyable
    {
    public:
        using ClassType = IntervalDistanceBase<Real, Vector>;
        using DistanceBase = DistanceBase<Real, Vector>;
        using DistanceResult = DistanceResult<Real, Vector>;
        using Math = Math<Real>;

    public:
        IntervalDistanceBase(const DistanceBase& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);
        virtual ~IntervalDistanceBase() noexcept = default;

        IntervalDistanceBase(const IntervalDistanceBase& rhs) = default;
        virtual IntervalDistanceBase& operator=(const IntervalDistanceBase& rhs) = default;
        IntervalDistanceBase(IntervalDistanceBase&& rhs) noexcept = default;
        virtual IntervalDistanceBase& operator=(IntervalDistanceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] const DistanceResult GetResult() const noexcept;

    protected:
        void Solve();
        [[nodiscard]] const DistanceResult GetDistanceResultSquared(Real t) const;
        [[nodiscard]] Real GetDerivativeDistanceResultSquared(Real t) const;
        [[nodiscard]] const DistanceResult GetDistanceResult(Real t) const;
        [[nodiscard]] Real GetDerivativeDistanceResult(Real t) const;

    private:
        [[nodiscard]] bool CheckBeginMonotonicFunction();
        [[nodiscard]] bool CheckEndMonotonicFunction();
        [[nodiscard]] bool Iteration();
        void BisectionMethod();
        [[nodiscard]] virtual const DistanceResult Get(Real t) const = 0;
        [[nodiscard]] virtual Real GetDerivative(Real t) const = 0;

    private:
        const DistanceBase& m_Distance;
        Real m_TMin;
        Real m_TMax;
        Vector m_LhsVelocity;
        Vector m_RhsVelocity;
        DistanceResult m_DistanceResult;

        Real m_BeginT;
        Real m_EndT;
        DistanceResult m_BeginDistanceResult;
        Real m_BeginDerivativeDistanceResult;
        DistanceResult m_EndDistanceResult;
        Real m_EndDerivativeDistanceResult;
    };
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H
