///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 18:16)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DynamicFindIntersector1Impl final
    {
    public:
        using ClassType = DynamicFindIntersector1Impl<Real>;
        using Math = Math<Real>;
        using IntersectionsType = std::vector<Real>;

    public:
        DynamicFindIntersector1Impl(Real firstTime, Real lastTime, const IntersectionsType& intersections);
        DynamicFindIntersector1Impl() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsIntersection() const noexcept;

        [[nodiscard]] Real GetFirstTime() const;
        [[nodiscard]] Real GetLastTime() const;

        [[nodiscard]] int GetNumIntersections() const;
        [[nodiscard]] Real GetIntersection(int index) const;

    private:
        // �й��ཻ����Ϣ��
        Real m_FirstTime;
        Real m_LastTime;

        IntersectionsType m_Intersections;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_H
