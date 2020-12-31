///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 15:05)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_IMPL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE StaticFindIntersector1Impl final
    {
    public:
        using ClassType = StaticFindIntersector1Impl<Real>;
        using Math = Math<Real>;
        using IntersectionsType = std::vector<Real>;

    public:
        explicit StaticFindIntersector1Impl(const IntersectionsType& intersections);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsIntersection() const noexcept;
        [[nodiscard]] int GetNumIntersections() const;
        [[nodiscard]] Real GetIntersection(int index) const;

    private:
        IntersectionsType m_Intersections;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_IMPL_H
