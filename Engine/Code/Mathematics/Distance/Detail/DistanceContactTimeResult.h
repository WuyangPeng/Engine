///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:41)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResultImpl.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceContactTimeResult : public DistanceResultImpl<Real, Vector>
    {
    public:
        using ClassType = DistanceContactTimeResult<Real, Vector>;
        using ParentType = DistanceResultImpl<Real, Vector>;

        using ImplTypeSharedPtr = typename ParentType::ImplTypeSharedPtr;

    public:
        DistanceContactTimeResult(Real distance, Real contactTime) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 发生在动态查询其最小距离的时间。
        NODISCARD Real GetContactTime() const noexcept override;
        void SetContactTime(Real newContactTime) noexcept override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

        NODISCARD bool IsHaveContactTime() const noexcept override;

    private:
        Real contactTime;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
