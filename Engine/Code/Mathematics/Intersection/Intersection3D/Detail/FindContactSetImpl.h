///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 15:12)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_IMPL_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE FindContactSetImpl final
    {
    public:
        using ClassType = FindContactSetImpl<Real>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;
        using SegmentType = std::array<Vector3D, 2>;
        using TriangleType = std::array<Vector3D, 3>;
        using RectangleType = std::array<Vector3D, 4>;
        using PointType = std::vector<Vector3D>;

    public:
        FindContactSetImpl(const SegmentType& segment,
                           const Triangle3& triangle,
                           ContactSide side,
                           const IntersectorConfiguration& segmentCfg,
                           const IntersectorConfiguration& triangleCfg,
                           const Vector3D& segmentVelocity,
                           const Vector3D& triangleVelocity,
                           Real tFirst);

        FindContactSetImpl(const SegmentType& segment,
                           const Box3& box,
                           ContactSide side,
                           const IntersectorConfiguration& segmentCfg,
                           const IntersectorConfiguration& boxCfg,
                           const Vector3D& segmentVelocity,
                           const Vector3D& boxVelocity,
                           Real tFirst);

        FindContactSetImpl(const Triangle3& triangle,
                           const Box3& box,
                           ContactSide side,
                           const IntersectorConfiguration& triangleCfg,
                           const IntersectorConfiguration& boxCfg,
                           const Vector3D& triangleVelocity,
                           const Vector3D& boxVelocity,
                           Real tFirst);

        FindContactSetImpl(const Box3& box0,
                           const Box3& box1,
                           ContactSide side,
                           const IntersectorConfiguration& box0Cfg,
                           const IntersectorConfiguration& box1Cfg,
                           const Vector3D& box0Velocity,
                           const Vector3D& box1Velocity,
                           Real tFirst);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] PointType GetPoint() const;

    private:
        // 当已知特征相交时，将调用这些函数。 因此，它们是对象-对象相交算法的专用版本。

        void ColinearSegments(const SegmentType& segment0, const SegmentType& segment1);

        void SegmentThroughPlane(const SegmentType& segment, const Vector3D& planeOrigin, const Vector3D& planeNormal);

        void SegmentSegment(const SegmentType& segment0, const SegmentType& segment1);

        void ColinearSegmentTriangle(const SegmentType& segment, const TriangleType& triangle);

        void CoplanarSegmentRectangle(const SegmentType& segment, const RectangleType& rectangle);

        void CoplanarTriangleRectangle(const TriangleType& triangle, const RectangleType& rectangle);

        void CoplanarRectangleRectangle(const RectangleType& rectangle0, const RectangleType& rectangle1);

    private:
        PointType m_Points;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_IMPL_H
