///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:03)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersector1 final : public Intersector1<Real>
    {
    public:
        using ClassType = DynamicFindIntersector1<Real>;
        using ParentType = Intersector1<Real>;

        using Math = typename ParentType::Math;
        using IntersectionsType = std::vector<Real>;

    public:
        DynamicFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool IsIntersection() const noexcept final;

        // 动态相交查询的两个区间处于第一次/最后一次接触的时间。
        NODISCARD Real GetFirstTime() const;
        NODISCARD Real GetLastTime() const;

        // 有关交集的信息。
        // 相交数为0（区间不重叠），
        // 1（区间边界相交）或2（区间与区间相交）。
        NODISCARD int GetNumIntersections() const;
        NODISCARD Real GetIntersection(int index) const;

    private:
        void Find(Real tMax, Real speedU, Real speedV);

    private:
        // 有关相交的信息。
        Real firstTime;
        Real lastTime;

        IntersectionsType intersections;
    };

    using DynamicFindIntersector1F = DynamicFindIntersector1<float>;
    using DynamicFindIntersector1D = DynamicFindIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
