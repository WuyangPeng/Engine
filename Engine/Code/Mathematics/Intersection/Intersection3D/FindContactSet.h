///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:04)

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

        using Vector3Type = Vector3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Box3Type = Box3<Real>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;
        using SegmentType = std::array<Vector3Type, 2>;
        using TriangleType = std::array<Vector3Type, 3>;
        using RectangleType = std::array<Vector3Type, 4>;
        using PointType = std::vector<Vector3Type>;

    public:
        FindContactSet(const SegmentType& segment,
                       const Triangle3Type& triangle,
                       ContactSide side,
                       const IntersectorConfiguration& segmentCfg,
                       const IntersectorConfiguration& triangleCfg,
                       const Vector3Type& segmentVelocity,
                       const Vector3Type& triangleVelocity,
                       Real tFirst);

        FindContactSet(const SegmentType& segment,
                       const Box3Type& box,
                       ContactSide side,
                       const IntersectorConfiguration& segmentCfg,
                       const IntersectorConfiguration& boxCfg,
                       const Vector3Type& segmentVelocity,
                       const Vector3Type& boxVelocity,
                       Real tFirst);

        FindContactSet(const Triangle3Type& triangle,
                       const Box3Type& box,
                       ContactSide side,
                       const IntersectorConfiguration& triangleCfg,
                       const IntersectorConfiguration& boxCfg,
                       const Vector3Type& triangleVelocity,
                       const Vector3Type& boxVelocity,
                       Real tFirst);

        FindContactSet(const Box3Type& box0,
                       const Box3Type& box1,
                       ContactSide side,
                       const IntersectorConfiguration& box0Cfg,
                       const IntersectorConfiguration& box1Cfg,
                       const Vector3Type& box0Velocity,
                       const Vector3Type& box1Velocity,
                       Real tFirst);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PointType GetPoint() const;

    private:
        // ����֪�����ཻʱ����������Щ������ ��ˣ������Ƕ���-�����ཻ�㷨��ר�ð汾��

        void ColinearSegments(const SegmentType& segment0, const SegmentType& segment1);

        void SegmentThroughPlane(const SegmentType& segment, const Vector3Type& planeOrigin, const Vector3Type& planeNormal);

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
