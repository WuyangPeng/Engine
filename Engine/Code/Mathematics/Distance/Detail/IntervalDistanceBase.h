///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:42)

#ifndef MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H
#define MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H

#include "Mathematics/Distance/DistanceFwd.h"
#include "Mathematics/Distance/DistanceResult.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class IntervalDistanceBase : private boost::noncopyable
    {
    public:
        using ClassType = IntervalDistanceBase<Real, Vector>;

        using DistanceBaseType = DistanceBase<Real, Vector>;
        using DistanceResultType = DistanceResult<Real, Vector>;
        using MathType = Math<Real>;

    public:
        IntervalDistanceBase(const DistanceBaseType& distance, Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity);
        virtual ~IntervalDistanceBase() noexcept = default;

        IntervalDistanceBase(const IntervalDistanceBase& rhs) = default;
        virtual IntervalDistanceBase& operator=(const IntervalDistanceBase& rhs) = default;
        IntervalDistanceBase(IntervalDistanceBase&& rhs) noexcept = default;
        virtual IntervalDistanceBase& operator=(IntervalDistanceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD DistanceResultType GetResult() const noexcept;

    protected:
        void Solve();
        NODISCARD DistanceResultType GetDistanceResultSquared(Real t) const;
        NODISCARD Real GetDerivativeDistanceResultSquared(Real t) const;
        NODISCARD DistanceResultType GetDistanceResult(Real t) const;
        NODISCARD Real GetDerivativeDistanceResult(Real t) const;

    private:
        NODISCARD bool CheckBeginMonotonicFunction();
        NODISCARD bool CheckEndMonotonicFunction();
        NODISCARD bool Iteration();
        void BisectionMethod();
        NODISCARD virtual DistanceResultType Get(Real t) const = 0;
        NODISCARD virtual Real GetDerivative(Real t) const = 0;

    private:
        const DistanceBaseType& distance;
        Real tMin;
        Real tMax;
        Vector lhsVelocity;
        Vector rhsVelocity;
        DistanceResultType distanceResult;

        Real beginT;
        Real endT;
        DistanceResultType beginDistanceResult;
        Real beginDerivativeDistanceResult;
        DistanceResultType endDistanceResult;
        Real endDerivativeDistanceResult;
    };
}

#endif  // MATHEMATICS_DISTANCE_INTERVAL_DISTANCE_BASE_H
