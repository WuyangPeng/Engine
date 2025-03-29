///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:18)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_DETAIL_H

#include "FindContactSet.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorConfigurationDetail.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorUtility3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(const SegmentType& segment,
                                                  const Triangle3Type& triangle,
                                                  ContactSide side,
                                                  const IntersectorConfigurationType& segmentCfg,
                                                  const IntersectorConfigurationType& triangleCfg,
                                                  const Vector3Type& segmentVelocity,
                                                  const Vector3Type& triangleVelocity,
                                                  Real tFirst)
    : points{}
{
    // ���߶��Ƶ���λ�á�
    SegmentType segmentFinal{ segment.at(0) + tFirst * segmentVelocity, segment.at(1) + tFirst * segmentVelocity };

    // ���������ƶ�����λ�á�
    TriangleType triangleFinal{ triangle.GetVertex(0) + tFirst * triangleVelocity,
                                triangle.GetVertex(1) + tFirst * triangleVelocity,
                                triangle.GetVertex(2) + tFirst * triangleVelocity };

    if (side == ContactSide::Left)  // ���������߶ε����
    {
        if (segmentCfg.GetMap() == VertexProjectionMap::M11)
        {
            points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(0)));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M11 || triangleCfg.GetMap() == VertexProjectionMap::M21)
        {
            points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(2)));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M12)
        {
            const SegmentType value{ triangleFinal.at(triangleCfg.GetIndex(1)), triangleFinal.at(triangleCfg.GetIndex(2)) };

            SegmentSegment(segmentFinal, value);
        }
        else  // �߶��� m2, �������� m3
        {
            ColinearSegmentTriangle(segmentFinal, triangleFinal);
        }
    }
    else  // �߶��������ε����
    {
        if (segmentCfg.GetMap() == VertexProjectionMap::M11)
        {
            points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(1)));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M111 || triangleCfg.GetMap() == VertexProjectionMap::M12)
        {
            points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(0)));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M21)
        {
            const SegmentType value{ triangleFinal.at(triangleCfg.GetIndex(0)), triangleFinal.at(triangleCfg.GetIndex(1)) };

            SegmentSegment(segmentFinal, value);
        }
        else  // �߶��� m2,�������� m3
        {
            ColinearSegmentTriangle(segmentFinal, triangleFinal);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(const SegmentType& segment,
                                                  const Box3Type& box,
                                                  ContactSide side,
                                                  const IntersectorConfigurationType& segmentCfg,
                                                  const IntersectorConfigurationType& boxCfg,
                                                  const Vector3Type& segmentVelocity,
                                                  const Vector3Type& boxVelocity,
                                                  Real tFirst)
    : points{}
{
    // ���߶��Ƶ���λ�á�
    SegmentType segmentFinal{ segment.at(0) + tFirst * segmentVelocity, segment.at(1) + tFirst * segmentVelocity };

    // �������Ƶ���λ�á�
    const auto boxFinal = box.GetMove(tFirst, boxVelocity);

    if (side == ContactSide::Left)
    {
        // �������߶ε����
        if (segmentCfg.GetMap() == VertexProjectionMap::M11)
        {
            points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(0)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
        {
            // �߶��߶��ཻ
            const SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                          IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

            SegmentSegment(segmentFinal, boxSegment);
        }
        else  // boxCfg.GetMap() == VertexProjectionMap::M44
        {
            // �߶�-�����ཻ
            const RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(4), boxFinal),
                                         IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(5), boxFinal),
                                         IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                         IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

            CoplanarSegmentRectangle(segmentFinal, boxFace);
        }
    }
    else  // side == Right
    {
        // �������߶ε��Ҳ�
        if (segmentCfg.GetMap() == VertexProjectionMap::M11)
        {
            points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(1)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
        {
            // �߶��߶��ཻ
            const SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                          IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal) };

            SegmentSegment(segmentFinal, boxSegment);
        }
        else  // boxCfg.GetMap() == VertexProjectionMap::M44
        {
            // �߶�-�����ཻ
            const RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                         IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal),
                                         IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(2), boxFinal),
                                         IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(3), boxFinal) };

            CoplanarSegmentRectangle(segmentFinal, boxFace);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(const Triangle3Type& triangle,
                                                  const Box3Type& box,
                                                  ContactSide side,
                                                  const IntersectorConfigurationType& triangleCfg,
                                                  const IntersectorConfigurationType& boxCfg,
                                                  const Vector3Type& triangleVelocity,
                                                  const Vector3Type& boxVelocity,
                                                  Real tFirst)
    : points{}
{
    // ���������ƶ�����λ�á�
    TriangleType triangleFinal{ triangle.GetVertex(0) + tFirst * triangleVelocity,
                                triangle.GetVertex(1) + tFirst * triangleVelocity,
                                triangle.GetVertex(2) + tFirst * triangleVelocity };

    // �������Ƶ���λ�á�
    const auto boxFinal = box.GetMove(tFirst, boxVelocity);

    if (side == ContactSide::Left)
    {
        // ���������������
        if (triangleCfg.GetMap() == VertexProjectionMap::M111 || triangleCfg.GetMap() == VertexProjectionMap::M12)
        {
            points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(0)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M21)
        {
            if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // �������߶Ρ��������߶��ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(0)),
                                                   triangleFinal.at(triangleCfg.GetIndex(1)) };

                const SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                              IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

                SegmentSegment(triangleSegment, boxSegment);
            }
            else  // boxCfg.GetMap() == VertexProjectionMap::M44
            {
                // �������߶Ρ����������ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(0)),
                                                   triangleFinal.at(triangleCfg.GetIndex(1)) };

                const RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(4), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(5), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

                CoplanarSegmentRectangle(triangleSegment, boxFace);
            }
        }
        else  // triangleCfg.GetMap() == VertexProjectionMap::M3
        {
            if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // �����߶Ρ������������ཻ
                const SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                              IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

                ColinearSegmentTriangle(boxSegment, triangleFinal);
            }
            else
            {
                // �������桪���������ཻ
                const RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(4), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(5), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

                CoplanarTriangleRectangle(triangleFinal, boxFace);
            }
        }
    }
    else  // side == Right
    {
        // �������������Ҳ�
        if (triangleCfg.GetMap() == VertexProjectionMap::M111 || triangleCfg.GetMap() == VertexProjectionMap::M21)
        {
            points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(2)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M12)
        {
            if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // �߶Ρ����߶��ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(1)),
                                                   triangleFinal.at(triangleCfg.GetIndex(2)) };

                const SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                              IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal) };

                SegmentSegment(triangleSegment, boxSegment);
            }
            else  // boxCfg.GetMap() == VertexProjectionMap::M44
            {
                // �������߶Ρ����������ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(1)),
                                                   triangleFinal.at(triangleCfg.GetIndex(2)) };

                const RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(2), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(3), boxFinal) };

                CoplanarSegmentRectangle(triangleSegment, boxFace);
            }
        }
        else  // triangleCfg.GetMap() == VertexProjectionMap::M3
        {
            if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
            {
                //  �����߶Ρ������������ཻ
                const SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                              IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal) };

                ColinearSegmentTriangle(boxSegment, triangleFinal);
            }
            else
            {
                // �������桪���������ཻ
                const RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(2), boxFinal),
                                             IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(3), boxFinal) };

                CoplanarTriangleRectangle(triangleFinal, boxFace);
            }
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(const Box3Type& box0,
                                                  const Box3Type& box1,
                                                  ContactSide side,
                                                  const IntersectorConfigurationType& box0Cfg,
                                                  const IntersectorConfigurationType& box1Cfg,
                                                  const Vector3Type& box0Velocity,
                                                  const Vector3Type& box1Velocity,
                                                  Real tFirst)
    : points{}
{
    // �������Ƶ���λ�á�
    const auto box0Final = box0.GetMove(tFirst, box0Velocity);
    const auto box1Final = box1.GetMove(tFirst, box1Velocity);

    if (side == ContactSide::Left)
    {
        // box1��box0���
        if (box0Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final));
        }
        else if (box1Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final));
        }
        else if (box0Cfg.GetMap() == VertexProjectionMap::M2_2)
        {
            if (box1Cfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // box0�ߡ���box1���ཻ
                const SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final) };

                const SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(6), box1Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final) };

                SegmentSegment(edge0, edge1);
            }
            else  // box1Cfg.mMap == VertexProjectionMap::M44
            {
                // box0�ߡ���box1���ཻ
                const SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final) };

                const RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(4), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(5), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(6), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final) };

                CoplanarSegmentRectangle(edge0, face1);
            }
        }
        else  // box0Cfg.GetMap() == VertexProjectionMap::M44
        {
            if (box1Cfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // box0�桪��box1���ཻ
                const RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(2), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(3), box0Final) };

                const SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(6), box1Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final) };

                CoplanarSegmentRectangle(edge1, face0);
            }
            else
            {
                // box0�桪��box1���ཻ
                const RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(2), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(3), box0Final) };

                const RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(4), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(5), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(6), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final) };

                CoplanarRectangleRectangle(face0, face1);
            }
        }
    }
    else  // side == Right
    {
        // box1��box0�Ҳ�
        if (box0Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final));
        }
        else if (box1Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final));
        }
        else if (box0Cfg.GetMap() == VertexProjectionMap::M2_2)
        {
            if (box1Cfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // box0�ߡ���box1���ཻ
                const SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                const SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(1), box1Final) };

                SegmentSegment(edge0, edge1);
            }
            else  // box1Cfg.GetMap() == VertexProjectionMap::M44
            {
                // box0�ߡ���box1���ཻ
                const SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                const RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(1), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(2), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(3), box1Final) };

                CoplanarSegmentRectangle(edge0, face1);
            }
        }
        else  // box0Cfg.GetMap() == VertexProjectionMap::M44
        {
            if (box1Cfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // box0�桪��box1���ཻ
                const RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(4), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(5), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                const SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
                                         IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(1), box1Final) };

                CoplanarSegmentRectangle(edge1, face0);
            }
            else  // box1Cfg.GetMap() == VertexProjectionMap::M44
            {
                // box0�桪��box1���ཻ
                const RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(4), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(5), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                const RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(1), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(2), box1Final),
                                           IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(3), box1Final) };

                CoplanarRectangleRectangle(face0, face1);
            }
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::FindContactSet<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::FindContactSet<Real>::PointType Mathematics::FindContactSet<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return points;
}

template <typename Real>
void Mathematics::FindContactSet<Real>::ColinearSegments(const SegmentType& segment0, const SegmentType& segment1)
{
    // Ǳ�ڵĽ�������ʼ��Ϊsegment0�����segment1���вü���
    points.assign(segment0.begin(), segment0.end());

    // �� 0
    auto diff = segment1.at(1) - segment1.at(0);
    auto dot = Vector3Tools<Real>::DotProduct(diff, segment1.at(0));
    points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(diff, dot, points);

    // �� 1
    diff = -diff;
    dot = Vector3Tools<Real>::DotProduct(diff, segment1.at(1));
    points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(diff, dot, points);
}

template <typename Real>
void Mathematics::FindContactSet<Real>::SegmentThroughPlane(const SegmentType& segment, const Vector3Type& planeOrigin, const Vector3Type& planeNormal)
{
    auto u = Vector3Tools<Real>::DotProduct(planeNormal, planeOrigin);
    auto v0 = Vector3Tools<Real>::DotProduct(planeNormal, segment.at(0));
    auto v1 = Vector3Tools<Real>::DotProduct(planeNormal, segment.at(1));

    // ���ڣ�ͨ��ͶӰ�ѽ����Ϊһά���⣬���ں������ҵ�V��U�ཻ����V�ı��ʡ�
    auto ratio = (u - v0) / (v1 - v0);
    points.clear();
    points.emplace_back(segment.at(0) + ratio * (segment.at(1) - segment.at(0)));
}

template <typename Real>
void Mathematics::FindContactSet<Real>::SegmentSegment(const SegmentType& segment0, const SegmentType& segment1)
{
    auto dir0 = segment0.at(1) - segment0.at(0);
    auto dir1 = segment1.at(0) - segment1.at(0);

    const auto normal = Vector3Tools<Real>::CrossProduct(dir0, dir1);

    // �Ƚ�Ϊsin(kDir0,kDir1) < epsilon��
    auto dir0LengthSquared = Vector3Tools<Real>::GetLengthSquared(dir0);
    auto dir1LengthSquared = Vector3Tools<Real>::GetLengthSquared(dir1);
    auto normalLengthSquared = Vector3Tools<Real>::GetLengthSquared(normal);
    if (normalLengthSquared < Math<Real>::GetZeroTolerance() * dir0LengthSquared * dir1LengthSquared)
    {
        ColinearSegments(segment0, segment1);
    }
    else
    {
        SegmentThroughPlane(segment1, segment0.at(0), Vector3Tools<Real>::CrossProduct(normal, segment0.at(1) - segment0.at(0)));
    }
}

template <typename Real>
void Mathematics::FindContactSet<Real>::ColinearSegmentTriangle(const SegmentType& segment, const TriangleType& triangle)
{
    // ��λ���㱻��ʼ��Ϊ�߶Σ�Ȼ���������ε����������޼���
    points.assign(segment.begin(), segment.end());

    TriangleType side{ triangle.at(1) - triangle.at(0), triangle.at(2) - triangle.at(1), triangle.at(0) - triangle.at(2) };

    const auto normal = Vector3Tools<Real>::CrossProduct(side.at(0), side.at(1));
    for (auto i = 0; i < 3; ++i)
    {
        // ����ָ���������ڡ�
        const auto sideCross = Vector3Tools<Real>::CrossProduct(normal, side.at(i));
        auto constant = Vector3Tools<Real>::DotProduct(sideCross, triangle.at(i));
        points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(sideCross, constant, points);
    }
}

template <typename Real>
void Mathematics::FindContactSet<Real>::CoplanarSegmentRectangle(const SegmentType& segment, const RectangleType& rectangle)
{
    // ��λ���㱻��ʼ��Ϊ�߶Σ�Ȼ���ھ��ε��ĸ������޼���
    points.assign(segment.begin(), segment.end());

    for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
        auto normal = rectangle.at(i1) - rectangle.at(i0);
        auto constant = Vector3Tools<Real>::DotProduct(normal, rectangle.at(i0));
        points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(normal, constant, points);
    }
}

template <typename Real>
void Mathematics::FindContactSet<Real>::CoplanarTriangleRectangle(const TriangleType& triangle, const RectangleType& rectangle)
{
    // ��λ���㱻��ʼ��Ϊ�����Σ�Ȼ���޼������ӵĲ���
    points.assign(triangle.begin(), triangle.end());

    for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
        auto normal = rectangle.at(i1) - rectangle.at(i0);
        auto constant = Vector3Tools<Real>::DotProduct(normal, rectangle.at(i0));
        points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(normal, constant, points);
    }
}

template <typename Real>
void Mathematics::FindContactSet<Real>::CoplanarRectangleRectangle(const RectangleType& rectangle0, const RectangleType& rectangle1)
{
    // �����ʼ��Ϊ��0��Ȼ������1���ĸ������޼���

    points.assign(rectangle0.begin(), rectangle0.end());

    for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
        auto normal = rectangle1.at(i1) - rectangle1.at(i0);
        auto constant = Vector3Tools<Real>::DotProduct(normal, rectangle1.at(i0));
        points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(normal, constant, points);
    }
}

#endif  // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_DETAIL_H
