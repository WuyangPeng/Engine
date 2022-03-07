///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/20 15:53)

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
        using ImplTypeSharedPtr = ParentType::ImplTypeSharedPtr;

    public:
        DistanceContactTimeResult(Real distance, Real contactTime) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �����ڶ�̬��ѯ����С�����ʱ�䡣
        NODISCARD Real GetContactTime() const noexcept override;
        NODISCARD void SetContactTime(Real newContactTime) noexcept override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

        NODISCARD bool isHaveContactTime() const noexcept override;

    private:
        Real contactTime;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_H
