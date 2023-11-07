///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:04)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class FindContactSet final
    {
    public:
        using ClassType = FindContactSet<Real>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;
        using SegmentType = std::array<Vector3, 2>;
        using TriangleType = std::array<Vector3, 3>;
        using RectangleType = std::array<Vector3, 4>;
        using PointType = std::vector<Vector3>;

    public:
        FindContactSet(const SegmentType& segment,
                       const Triangle3& triangle,
                       ContactSide side,
                       const IntersectorConfiguration& segmentCfg,
                       const IntersectorConfiguration& triangleCfg,
                       const Vector3& segmentVelocity,
                       const Vector3& triangleVelocity,
                       Real tFirst);

        FindContactSet(const SegmentType& segment,
                       const Box3& box,
                       ContactSide side,
                       const IntersectorConfiguration& segmentCfg,
                       const IntersectorConfiguration& boxCfg,
                       const Vector3& segmentVelocity,
                       const Vector3& boxVelocity,
                       Real tFirst);

        FindContactSet(const Triangle3& triangle,
                       const Box3& box,
                       ContactSide side,
                       const IntersectorConfiguration& triangleCfg,
                       const IntersectorConfiguration& boxCfg,
                       const Vector3& triangleVelocity,
                       const Vector3& boxVelocity,
                       Real tFirst);

        FindContactSet(const Box3& box0,
                       const Box3& box1,
                       ContactSide side,
                       const IntersectorConfiguration& box0Cfg,
                       const IntersectorConfiguration& box1Cfg,
                       const Vector3& box0Velocity,
                       const Vector3& box1Velocity,
                       Real tFirst);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PointType GetPoint() const;

    private:
        // 当已知特征相交时，将调用这些函数。 因此，它们是对象-对象相交算法的专用版本。

        void ColinearSegments(const SegmentType& segment0, const SegmentType& segment1);

        void SegmentThroughPlane(const SegmentType& segment, const Vector3& planeOrigin, const Vector3& planeNormal);

        void SegmentSegment(const SegmentType& segment0, const SegmentType& segment1);

        void ColinearSegmentTriangle(const SegmentType& segment, const TriangleType& triangle);

        void CoplanarSegmentRectangle(const SegmentType& segment, const RectangleType& rectangle);

        void CoplanarTriangleRectangle(const TriangleType& triangle, const RectangleType& rectangle);

        void CoplanarRectangleRectangle(const RectangleType& rectangle0, const RectangleType& rectangle1);

    private:
        PointType points;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H
