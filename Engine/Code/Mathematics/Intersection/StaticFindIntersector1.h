///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:04)

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
        StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool IsIntersection() const noexcept override;

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
