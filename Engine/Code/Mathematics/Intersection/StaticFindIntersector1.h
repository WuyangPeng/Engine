///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 14:02)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersector1 final : public Intersector1<Real>
    {
    public:
        using ClassType = StaticFindIntersector1<Real>;
        using ParentType = Intersector1<Real>;
        using Math = typename ParentType::Math;
        using IntersectionsType = std::vector<Real>;

    public:
        StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool IsIntersection() const noexcept final;

        // 有关交集的信息。
        // 相交数为0（区间不重叠），
        // 1（区间边界相交）或2（区间与区间相交）。
        NODISCARD int GetNumIntersections() const;
        NODISCARD Real GetIntersection(int index) const;

    private:
        void Find();

    private:
        IntersectionsType intersections;
    };

    using StaticFindIntersector1F = StaticFindIntersector1<float>;
    using StaticFindIntersector1D = StaticFindIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H
