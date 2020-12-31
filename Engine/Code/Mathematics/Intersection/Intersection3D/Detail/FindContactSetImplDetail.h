///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/25 15:41)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_IMPL_DETAIL_H

#include "FindContactSetImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorConfigurationDetail.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorUtility3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"

template <typename Real>
Mathematics::FindContactSetImpl<Real>::FindContactSetImpl(
    const SegmentType& segment,
    const Triangle3& triangle,
    ContactSide side,
    const IntersectorConfiguration& segmentCfg,
    const IntersectorConfiguration& triangleCfg,
    const Vector3D& segmentVelocity,
    const Vector3D& triangleVelocity,
    Real tFirst)
    : m_Points{}
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    // ���߶��Ƶ���λ�á�
    SegmentType segmentFinal{ segment[0] + tFirst * segmentVelocity, segment[1] + tFirst * segmentVelocity };
#include STSTEM_WARNING_POP

    // ���������ƶ�����λ�á�
    TriangleType triangleFinal{ triangle.GetVertex(0) + tFirst * triangleVelocity,
                                triangle.GetVertex(1) + tFirst * triangleVelocity,
                                triangle.GetVertex(2) + tFirst * triangleVelocity };

    if (side == ContactSide::Left)  // ���������߶ε����
    {
        if (segmentCfg.GetMap() == VertexProjectionMap::M11)
        {
            m_Points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(0)));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M11 || triangleCfg.GetMap() == VertexProjectionMap::M21)
        {
            m_Points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(2)));
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
            m_Points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(1)));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M111 || triangleCfg.GetMap() == VertexProjectionMap::M12)
        {
            m_Points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(0)));
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
Mathematics::FindContactSetImpl<Real>::FindContactSetImpl(
    const SegmentType& segment,
    const Box3& box,
    ContactSide side,
    const IntersectorConfiguration& segmentCfg,
    const IntersectorConfiguration& boxCfg,
    const Vector3D& segmentVelocity,
    const Vector3D& boxVelocity,
    Real tFirst)
    : m_Points{}
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    // ���߶��Ƶ���λ�á�
    SegmentType segmentFinal{ segment[0] + tFirst * segmentVelocity, segment[1] + tFirst * segmentVelocity };
#include STSTEM_WARNING_POP

    // �������Ƶ���λ�á�
    const auto boxFinal = box.GetMove(tFirst, boxVelocity);

    if (side == ContactSide::Left)
    {
        // �������߶ε����
        if (segmentCfg.GetMap() == VertexProjectionMap::M11)
        {
            m_Points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(0)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
        {
            // �߶��߶��ཻ
            SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                    IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

            SegmentSegment(segmentFinal, boxSegment);
        }
        else  // boxCfg.GetMap() == VertexProjectionMap::M44
        {
            // �߶�-�����ཻ
            RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(4), boxFinal),
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
            m_Points.emplace_back(segmentFinal.at(segmentCfg.GetIndex(1)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
        {
            // �߶��߶��ཻ
            SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                    IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal) };

            SegmentSegment(segmentFinal, boxSegment);
        }
        else  // boxCfg.GetMap() == VertexProjectionMap::M44
        {
            // �߶�-�����ཻ
            RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                   IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal),
                                   IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(2), boxFinal),
                                   IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(3), boxFinal) };

            CoplanarSegmentRectangle(segmentFinal, boxFace);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindContactSetImpl<Real>::FindContactSetImpl(
    const Triangle3& triangle,
    const Box3& box,
    ContactSide side,
    const IntersectorConfiguration& triangleCfg,
    const IntersectorConfiguration& boxCfg,
    const Vector3D& triangleVelocity,
    const Vector3D& boxVelocity,
    Real tFirst)
    : m_Points{}
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
            m_Points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(0)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M21)
        {
            if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // �������߶Ρ��������߶��ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(0)),
                                                   triangleFinal.at(triangleCfg.GetIndex(1)) };

                SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                        IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

                SegmentSegment(triangleSegment, boxSegment);
            }
            else  // boxCfg.GetMap() == VertexProjectionMap::M44
            {
                // �������߶Ρ����������ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(0)),
                                                   triangleFinal.at(triangleCfg.GetIndex(1)) };

                RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(4), boxFinal),
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
                SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(6), boxFinal),
                                        IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(7), boxFinal) };

                ColinearSegmentTriangle(boxSegment, triangleFinal);
            }
            else
            {
                // �������桪���������ཻ
                RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(4), boxFinal),
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
            m_Points.emplace_back(triangleFinal.at(triangleCfg.GetIndex(2)));
        }
        else if (boxCfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal));
        }
        else if (triangleCfg.GetMap() == VertexProjectionMap::M12)
        {
            if (boxCfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // �߶Ρ����߶��ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(1)),
                                                   triangleFinal.at(triangleCfg.GetIndex(2)) };

                SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                        IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal) };

                SegmentSegment(triangleSegment, boxSegment);
            }
            else  // boxCfg.GetMap() == VertexProjectionMap::M44
            {
                // �������߶Ρ����������ཻ
                const SegmentType triangleSegment{ triangleFinal.at(triangleCfg.GetIndex(1)),
                                                   triangleFinal.at(triangleCfg.GetIndex(2)) };

                RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
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
                SegmentType boxSegment{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
                                        IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(1), boxFinal) };

                ColinearSegmentTriangle(boxSegment, triangleFinal);
            }
            else
            {
                // �������桪���������ཻ
                RectangleType boxFace{ IntersectorUtility3<Real>::GetPointFromIndex(boxCfg.GetIndex(0), boxFinal),
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
Mathematics::FindContactSetImpl<Real>::FindContactSetImpl(
    const Box3& box0,
    const Box3& box1,
    ContactSide side,
    const IntersectorConfiguration& box0Cfg,
    const IntersectorConfiguration& box1Cfg,
    const Vector3D& box0Velocity,
    const Vector3D& box1Velocity,
    Real tFirst)
{
    // �������Ƶ���λ�á�
    const auto box0Final = box0.GetMove(tFirst, box0Velocity);
    const auto box1Final = box1.GetMove(tFirst, box1Velocity);

    if (side == ContactSide::Left)
    {
        // box1��box0���
        if (box0Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final));
        }
        else if (box1Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final));
        }
        else if (box0Cfg.GetMap() == VertexProjectionMap::M2_2)
        {
            if (box1Cfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // box0�ߡ���box1���ཻ
                SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final) };

                SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(6), box1Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final) };

                SegmentSegment(edge0, edge1);
            }
            else  // box1Cfg.mMap == VertexProjectionMap::M44
            {
                // box0�ߡ���box1���ཻ
                SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final) };

                RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(4), box1Final),
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
                RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(2), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(3), box0Final) };

                SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(6), box1Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(7), box1Final) };

                CoplanarSegmentRectangle(edge1, face0);
            }
            else
            {
                // box0�桪��box1���ཻ
                RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(0), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(1), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(2), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(3), box0Final) };

                RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(4), box1Final),
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
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final));
        }
        else if (box1Cfg.GetMap() == VertexProjectionMap::M1_1)
        {
            m_Points.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final));
        }
        else if (box0Cfg.GetMap() == VertexProjectionMap::M2_2)
        {
            if (box1Cfg.GetMap() == VertexProjectionMap::M2_2)
            {
                // box0�ߡ���box1���ཻ
                SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(1), box1Final) };

                SegmentSegment(edge0, edge1);
            }
            else  // box1Cfg.GetMap() == VertexProjectionMap::M44
            {
                // box0�ߡ���box1���ཻ
                SegmentType edge0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
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
                RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(4), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(5), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                SegmentType edge1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
                                   IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(1), box1Final) };

                CoplanarSegmentRectangle(edge1, face0);
            }
            else  // box1Cfg.GetMap() == VertexProjectionMap::M44
            {
                // box0�桪��box1���ཻ
                RectangleType face0{ IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(4), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(5), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(6), box0Final),
                                     IntersectorUtility3<Real>::GetPointFromIndex(box0Cfg.GetIndex(7), box0Final) };

                RectangleType face1{ IntersectorUtility3<Real>::GetPointFromIndex(box1Cfg.GetIndex(0), box1Final),
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
bool Mathematics::FindContactSetImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::FindContactSetImpl<Real>::PointType Mathematics::FindContactSetImpl<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Points;
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::ColinearSegments(const SegmentType& segment0, const SegmentType& segment1)
{
    // Ǳ�ڵĽ�������ʼ��Ϊsegment0�����segment1���вü���
    m_Points.assign(segment0.begin(), segment0.end());

    // �� 0
    auto diff = segment1[1] - segment1[0];
    auto dot = Vector3DTools<Real>::DotProduct(diff, segment1[0]);
    m_Points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(diff, dot, m_Points);

    // �� 1
    diff = -diff;
    dot = Vector3DTools<Real>::DotProduct(diff, segment1[1]);
    m_Points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(diff, dot, m_Points);
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::SegmentThroughPlane(const SegmentType& segment, const Vector3D& planeOrigin, const Vector3D& planeNormal)
{
    auto u = Vector3DTools<Real>::DotProduct(planeNormal, planeOrigin);
    auto v0 = Vector3DTools<Real>::DotProduct(planeNormal, segment[0]);
    auto v1 = Vector3DTools<Real>::DotProduct(planeNormal, segment[1]);

    // ���ڣ�ͨ��ͶӰ�ѽ����Ϊһά���⣬���ں������ҵ�V��U�ཻ����V�ı��ʡ�
    auto ratio = (u - v0) / (v1 - v0);
    m_Points.clear();
    m_Points.emplace_back(segment[0] + ratio * (segment[1] - segment[0]));
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::SegmentSegment(const SegmentType& segment0, const SegmentType& segment1)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto dir0 = segment0[1] - segment0[0];
    auto dir1 = segment1[1] - segment1[0];

    const auto normal = Vector3DTools<Real>::CrossProduct(dir0, dir1);

    // �Ƚ�Ϊsin(kDir0,kDir1) < epsilon��
    auto dir0LengthSquared = Vector3DTools<Real>::VectorMagnitudeSquared(dir0);
    auto dir1LengthSquared = Vector3DTools<Real>::VectorMagnitudeSquared(dir1);
    auto normalLengthSquared = Vector3DTools<Real>::VectorMagnitudeSquared(normal);
    if (normalLengthSquared < Math<Real>::GetZeroTolerance() * dir0LengthSquared * dir1LengthSquared)
    {
        ColinearSegments(segment0, segment1);
    }
    else
    {
        SegmentThroughPlane(segment1, segment0[0], Vector3DTools<Real>::CrossProduct(normal, segment0[1] - segment0[0]));
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::ColinearSegmentTriangle(const SegmentType& segment, const TriangleType& triangle)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    // ��λ���㱻��ʼ��Ϊ�߶Σ�Ȼ���������ε����������޼���
    m_Points.assign(segment.begin(), segment.end());

    TriangleType side{ triangle[1] - triangle[0], triangle[2] - triangle[1], triangle[0] - triangle[2] };

    const auto normal = Vector3DTools<Real>::CrossProduct(side[0], side[1]);
    for (auto i = 0; i < 3; ++i)
    {
        // ����ָ���������ڡ�
        const auto sideCross = Vector3DTools<Real>::CrossProduct(normal, side[i]);
        auto constant = Vector3DTools<Real>::DotProduct(sideCross, triangle[i]);
        m_Points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(sideCross, constant, m_Points);
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::CoplanarSegmentRectangle(const SegmentType& segment, const RectangleType& rectangle)
{
    // ��λ���㱻��ʼ��Ϊ�߶Σ�Ȼ���ھ��ε��ĸ������޼���
    m_Points.assign(segment.begin(), segment.end());

    for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        auto normal = rectangle[i1] - rectangle[i0];
        auto constant = Vector3DTools<Real>::DotProduct(normal, rectangle[i0]);
        m_Points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(normal, constant, m_Points);

#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::CoplanarTriangleRectangle(const TriangleType& triangle, const RectangleType& rectangle)
{
    // ��λ���㱻��ʼ��Ϊ�����Σ�Ȼ���޼������ӵĲ���
    m_Points.assign(triangle.begin(), triangle.end());

    for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        auto normal = rectangle[i1] - rectangle[i0];
        auto constant = Vector3DTools<Real>::DotProduct(normal, rectangle[i0]);
        m_Points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(normal, constant, m_Points);

#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::FindContactSetImpl<Real>::CoplanarRectangleRectangle(const RectangleType& rectangle0, const RectangleType& rectangle1)
{
    // �����ʼ��Ϊ��0��Ȼ������1���ĸ������޼���

    m_Points.assign(rectangle0.begin(), rectangle0.end());

    for (auto i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        auto normal = rectangle1[i1] - rectangle1[i0];
        auto constant = Vector3DTools<Real>::DotProduct(normal, rectangle1[i0]);
        m_Points = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(normal, constant, m_Points);

#include STSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_IMPL_DETAIL_H
