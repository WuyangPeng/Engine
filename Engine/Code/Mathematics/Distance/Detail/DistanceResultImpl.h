///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:42)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceResultImpl
    {
    public:
        using ClassType = DistanceResultImpl<Real, Vector>;
        using FactoryType = DistanceResultFactory<Real, Vector>;

        using ImplTypeSharedPtr = std::shared_ptr<ClassType>;
        using MathType = Math<Real>;

    public:
        explicit DistanceResultImpl(Real distance) noexcept;
        virtual ~DistanceResultImpl() noexcept = default;

        DistanceResultImpl(const DistanceResultImpl& rhs) noexcept = default;
        DistanceResultImpl& operator=(const DistanceResultImpl& rhs) noexcept = default;
        DistanceResultImpl(DistanceResultImpl&& rhs) noexcept = default;
        DistanceResultImpl& operator=(DistanceResultImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD Real GetDistance() const noexcept;
        NODISCARD Vector GetLhsClosestPoint() const;
        NODISCARD Vector GetRhsClosestPoint() const;

        void SetDistance(Real newDistance) noexcept;
        void SetSqrtDistance(Real newDistance) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD virtual Real GetContactTime() const noexcept;
        NODISCARD virtual Vector GetLhsClosestPoint(int index) const;
        NODISCARD virtual Vector GetRhsClosestPoint(int index) const;
        NODISCARD virtual int GetLhsClosestPointSize() const;
        NODISCARD virtual int GetRhsClosestPointSize() const;
        NODISCARD virtual ImplTypeSharedPtr Clone() const;
        NODISCARD virtual bool IsHaveContactTime() const noexcept;

        virtual void SetContactTime(Real contactTime);

        NODISCARD virtual Real GetLhsParameter() const;
        NODISCARD virtual Real GetRhsParameter() const;

    private:
        static constexpr auto closestPointZeroSize = 0;

    private:
        Real distance;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H
