///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/04 18:34)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceResultImpl
    {
    public:
        using ClassType = DistanceResultImpl<Real, Vector>;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using Math = Math<Real>;

    public:
        explicit DistanceResultImpl(Real distance) noexcept;
        virtual ~DistanceResultImpl() noexcept = default;

        DistanceResultImpl(const DistanceResultImpl& rhs) = default;
        DistanceResultImpl& operator=(const DistanceResultImpl& rhs) = default;
        DistanceResultImpl(DistanceResultImpl&& rhs) noexcept = default;
        DistanceResultImpl& operator=(DistanceResultImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] Real GetDistance() const noexcept;
        [[nodiscard]] const Vector GetLhsClosestPoint() const;
        [[nodiscard]] const Vector GetRhsClosestPoint() const;

        void SetDistance(Real distance) noexcept;
        void SetSqrtDistance() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] virtual Real GetContactTime() const noexcept;
        [[nodiscard]] virtual const Vector GetLhsClosestPoint(int index) const;
        [[nodiscard]] virtual const Vector GetRhsClosestPoint(int index) const;
        [[nodiscard]] virtual int GetLhsClosestPointSize() const;
        [[nodiscard]] virtual int GetRhsClosestPointSize() const;
        [[nodiscard]] virtual ImplTypePtr Clone() const;
        [[nodiscard]] virtual bool isHaveContactTime() const noexcept;

        virtual void SetContactTime(Real contactTime);

        [[nodiscard]] virtual Real GetLhsParameter() const;
        [[nodiscard]] virtual Real GetRhsParameter() const;

    private:
        static constexpr auto sm_ClosestPointZeroSize = 0;

    private:
        Real m_Distance;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_IMPL_H
