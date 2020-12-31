///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 18:16)

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
        // 有关相交的信息。
        Real m_FirstTime;
        Real m_LastTime;

        IntersectionsType m_Intersections;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_IMPL_H
