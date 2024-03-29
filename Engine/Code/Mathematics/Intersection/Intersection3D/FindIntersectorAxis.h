///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:04)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "IntersectorConfiguration.h"
#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class FindIntersectorAxis final
    {
    public:
        using ClassType = FindIntersectorAxis<Real>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using SegmentType = std::array<Vector3, 2>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;

    public:
        /// 查找查询投影区间的交集。 输入的速度是objectVelocity1 - objectVelocity0之差。
        /// 计算接触的第一次和最后一次，以及关于接触结构和投影（接触侧）顺序的信息。
        FindIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3& velocity, Real tmax);

        FindIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Box3& box, const Vector3& velocity, Real tmax);

        FindIntersectorAxis(const Vector3& axis, const Triangle3& triangle, const Box3& box, const Vector3& velocity, Real tmax);

        FindIntersectorAxis(const Vector3& axis, const Box3& box0, const Box3& box1, const Vector3& velocity, Real tmax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool GetResult() const noexcept;
        NODISCARD Real GetTFirst() const noexcept;
        NODISCARD Real GetTLast() const noexcept;

        NODISCARD ContactSide Getside() const noexcept;
        NODISCARD IntersectorConfiguration GetCfgFinal0() const noexcept;
        NODISCARD IntersectorConfiguration GetCfgFinal1() const noexcept;

        // Configurations.
        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3& axis, const SegmentType& segment);

        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3& axis, const Triangle3& triangle);

        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3& axis, const Box3& box);

    private:
        // 投影的低级查找查询。
        void Find(const Vector3& axis, const Vector3& velocity, const IntersectorConfiguration& cfg0Start, const IntersectorConfiguration& cfg1Start, Real tmax) noexcept;

    private:
        bool result;
        Real tFirst;
        Real tLast;
        ContactSide side;
        IntersectorConfiguration cfgFinal0;
        IntersectorConfiguration cfgFinal1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_H
