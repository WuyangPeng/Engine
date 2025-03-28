///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:59)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorSegment3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorSegment3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorSegment3Sphere3(const Segment3& segment,
                                              const Sphere3& sphere,
                                              Real tMax,
                                              const Vector3Type& lhsVelocity,
                                              const Vector3Type& rhsVelocity,
                                              const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Sphere3 GetSphere() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;
        NODISCARD Real GetSegmentParameter0() const noexcept;
        NODISCARD Real GetSegmentParameter1() const noexcept;

    private:
        /// 动态查找交叉点查询。 GetPoint(0)访问第一个交点。 第一次联系是通过GetContactTime()访问的。
        void Find();

    private:
        Segment3 segment;
        Sphere3 sphere;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;
        Real segmentParameter0;
        Real segmentParameter1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
