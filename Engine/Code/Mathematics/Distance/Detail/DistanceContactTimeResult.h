///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 18:51)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResultImpl.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceContactTimeResult : public DistanceResultImpl<Real, Vector>
    {
    public:
        using ClassType = DistanceContactTimeResult<Real, Vector>;
        using ParentType = DistanceResultImpl<Real, Vector>;
        using ImplTypePtr = ParentType::ImplTypePtr;

    public:
        DistanceContactTimeResult(Real distance, Real contactTime) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 发生在动态查询其最小距离的时间。
        [[nodiscard]] Real GetContactTime() const noexcept override;
        [[nodiscard]] void SetContactTime(Real contactTime) noexcept override;

        [[nodiscard]] ImplTypePtr Clone() const override;

        [[nodiscard]] bool isHaveContactTime() const noexcept override;

    private:
        Real m_ContactTime;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
