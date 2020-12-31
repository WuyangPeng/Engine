///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 13:08)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_IMPL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DynamicIntersectorImpl final
    {
    public:
        using ClassType = DynamicIntersectorImpl<Real, Vector>;
        using Math = Math<Real>;
        using VectorType = Vector<Real>;

    public:
        explicit DynamicIntersectorImpl(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ���������ڵ�һ�νӴ�ʱ��̬�ཻ��ѯ��ʱ�䡣
        [[nodiscard]] Real GetContactTime() const noexcept;
        [[nodiscard]] Real GetTMax() const noexcept;
        [[nodiscard]] const VectorType GetLhsVelocity() const noexcept;
        [[nodiscard]] const VectorType GetRhsVelocity() const noexcept;
        void SetContactTime(Real contactTime) noexcept;

    private:
        Real m_ContactTime;
        Real m_TMax;
        VectorType m_LhsVelocity;
        VectorType m_RhsVelocity;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_IMPL_H
