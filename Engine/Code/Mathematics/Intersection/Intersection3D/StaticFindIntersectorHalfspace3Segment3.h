///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:05)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Segment3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 这里的查询用于线段和半角的交集。
/// 在动态查找查询中，如果线段已经与半空间相交，则返回值为'false'。 这个想法是寻找第一次接触。

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorHalfspace3Segment3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorHalfspace3Segment3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Segment3 GetSegment() const noexcept;

        // 相交集为空，点或线段。 函数GetQuantity()返回0、1或2。
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        void Find();

    private:
        Plane3 halfspace;
        Segment3 segment;

        int quantity;
        Vector3 point0;
        Vector3 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H
