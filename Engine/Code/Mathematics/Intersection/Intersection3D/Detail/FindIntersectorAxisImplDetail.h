///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/28 14:03)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_IMPL_DETAIL_H

#include "FindIntersectorAxisImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Objects3D/Box3Detail.h"

template <typename Real>
Mathematics::FindIntersectorAxisImpl<Real>::FindIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{ Math<Real>::sm_MaxReal }, m_Side{}, m_CfgFinal0{}, m_CfgFinal1{}
{
    auto segmentCfgStart = GetConfiguration(axis, segment);

    auto triangleCfgStart = GetConfiguration(axis, triangle);

    Find(axis, velocity, segmentCfgStart, triangleCfgStart, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindIntersectorAxisImpl<Real>::FindIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{ Math<Real>::sm_MaxReal }, m_Side{}, m_CfgFinal0{}, m_CfgFinal1{}
{
    auto segmentCfgStart = GetConfiguration(axis, segment);

    auto boxCfgStart = GetConfiguration(axis, box);

    Find(axis, velocity, segmentCfgStart, boxCfgStart, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindIntersectorAxisImpl<Real>::FindIntersectorAxisImpl(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{ Math<Real>::sm_MaxReal }, m_Side{}, m_CfgFinal0{}, m_CfgFinal1{}
{
    auto triangleCfgStart = GetConfiguration(axis, triangle);

    auto boxCfgStart = GetConfiguration(axis, box);

    Find(axis, velocity, triangleCfgStart, boxCfgStart, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::FindIntersectorAxisImpl<Real>::FindIntersectorAxisImpl(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{ Math<Real>::sm_MaxReal }, m_Side{}, m_CfgFinal0{}, m_CfgFinal1{}
{
    auto box0CfgStart = GetConfiguration(axis, box0);

    auto box1CfgStart = GetConfiguration(axis, box1);

    Find(axis, velocity, box0CfgStart, box1CfgStart, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::FindIntersectorAxisImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::FindIntersectorAxisImpl<Real>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Result;
}

template <typename Real>
Real Mathematics::FindIntersectorAxisImpl<Real>::GetTFirst() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_TFirst;
}

template <typename Real>
Real Mathematics::FindIntersectorAxisImpl<Real>::GetTLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_TLast;
}

template <typename Real>
Mathematics::ContactSide Mathematics::FindIntersectorAxisImpl<Real>::Getside() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Side;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxisImpl<Real>::GetCfgFinal0() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_CfgFinal0;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxisImpl<Real>::GetCfgFinal1() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_CfgFinal1;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxisImpl<Real>::GetConfiguration(const Vector3D& axis, const SegmentType& segment)
{
    IntersectorConfiguration cfg{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    std::array<Real, 2> dot{ Vector3DTools<Real>::DotProduct(axis, segment[0]), Vector3DTools<Real>::DotProduct(axis, segment[1]) };

    if (Math<Real>::FAbs(dot[1] - dot[0]) < Math<Real>::GetZeroTolerance())
    {
        cfg.SetMap(VertexProjectionMap::M2);
    }
    else
    {
        cfg.SetMap(VertexProjectionMap::M11);
    }

    if (dot[0] < dot[1])
    {
        cfg.SetMin(dot[0]);
        cfg.SetMax(dot[1]);
        cfg.SetIndex(0, 0);
        cfg.SetIndex(1, 1);
    }
    else
    {
        cfg.SetMin(dot[1]);
        cfg.SetMax(dot[0]);
        cfg.SetIndex(0, 1);
        cfg.SetIndex(1, 0);
    }

#include STSTEM_WARNING_POP

    return cfg;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxisImpl<Real>::GetConfiguration(const Vector3D& axis, const Triangle3& triangle)
{
    IntersectorConfiguration cfg{};

    // ���Ҷ��㵽Ǳ�ڷ������ϵ�ͶӰ��
    auto d0 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(0));
    auto d1 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(1));
    auto d2 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(2));

    // ��ʽ�����򶥵�Ĺ���IntersectorConfiguration��
    if (d0 <= d1)
    {
        if (d1 <= d2)  // D0 <= D1 <= D2
        {
            if (Math<Real>::Approximate(d0, d1))
            {
                if (Math<Real>::Approximate(d1, d2))
                {
                    cfg.SetMap(VertexProjectionMap::M111);
                }
                else
                {
                    cfg.SetMap(VertexProjectionMap::M12);
                }
            }
            else  // ( D0 == D1 )
            {
                if (Math<Real>::Approximate(d1, d2))
                {
                    cfg.SetMap(VertexProjectionMap::M21);
                }
                else
                {
                    cfg.SetMap(VertexProjectionMap::M3);
                }
            }
            cfg.SetIndex(0, 0);
            cfg.SetIndex(1, 1);
            cfg.SetIndex(2, 2);
            cfg.SetMin(d0);
            cfg.SetMax(d2);
        }
        else if (d0 <= d2)  // D0 <= D2 < D1
        {
            if (Math<Real>::Approximate(d0, d2))
            {
                cfg.SetMap(VertexProjectionMap::M111);
                cfg.SetIndex(0, 0);
                cfg.SetIndex(1, 2);
                cfg.SetIndex(2, 1);
            }
            else
            {
                cfg.SetMap(VertexProjectionMap::M21);
                cfg.SetIndex(0, 2);
                cfg.SetIndex(1, 0);
                cfg.SetIndex(2, 1);
            }
            cfg.SetMin(d0);
            cfg.SetMax(d1);
        }
        else  // D2 < D0 <= D1
        {
            if (Math<Real>::Approximate(d0, d1))
            {
                cfg.SetMap(VertexProjectionMap::M111);
            }
            else
            {
                cfg.SetMap(VertexProjectionMap::M12);
            }
            cfg.SetIndex(0, 2);
            cfg.SetIndex(1, 0);
            cfg.SetIndex(2, 1);
            cfg.SetMin(d2);
            cfg.SetMax(d1);
        }
    }
    else if (d2 <= d1)  // D2 <= D1 < D0
    {
        if (Math<Real>::Approximate(d2, d1))
        {
            cfg.SetMap(VertexProjectionMap::M111);
            cfg.SetIndex(0, 2);
            cfg.SetIndex(1, 1);
            cfg.SetIndex(2, 0);
        }
        else
        {
            cfg.SetMap(VertexProjectionMap::M21);
            cfg.SetIndex(0, 1);
            cfg.SetIndex(1, 2);
            cfg.SetIndex(2, 0);
        }
        cfg.SetMin(d2);
        cfg.SetMax(d0);
    }
    else if (d2 <= d0)  // D1 < D2 <= D0
    {
        if (Math<Real>::Approximate(d2, d0))
        {
            cfg.SetMap(VertexProjectionMap::M111);
        }
        else
        {
            cfg.SetMap(VertexProjectionMap::M12);
        }

        cfg.SetIndex(0, 1);
        cfg.SetIndex(1, 2);
        cfg.SetIndex(2, 0);
        cfg.SetMin(d1);
        cfg.SetMax(d0);
    }
    else  // D1 < D0 < D2
    {
        cfg.SetMap(VertexProjectionMap::M111);
        cfg.SetIndex(0, 1);
        cfg.SetIndex(1, 0);
        cfg.SetIndex(2, 2);
        cfg.SetMin(d1);
        cfg.SetMax(d2);
    }

    return cfg;
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxisImpl<Real>::GetConfiguration(const Vector3D& axis, const Box3& box)
{
    // IntersectorConfiguration.mIndex���������򷽰���˵����
    // ������������/���£��뷶Χ�ķ��ţ��������ӳ���к���Ҫ��
    //   012
    // 0 ---
    // 1 +--
    // 2 -+-
    // 3 ++-
    // 4 --+
    // 5 +-+
    // 6 -++
    // 7 +++
    //
    // �����ڡ��ཻ���á��з�������ʱ��Ҳ��֤��������ġ�
    // �������4�����㣬�򽫰��ս�����һ��������0,1,3,2����˳����б�֤��

    IntersectorConfiguration cfg{};

    std::array<Real, 3> axes{ Vector3DTools<Real>::DotProduct(axis, box.GetAxis(0)),
                              Vector3DTools<Real>::DotProduct(axis, box.GetAxis(1)),
                              Vector3DTools<Real>::DotProduct(axis, box.GetAxis(2)) };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    std::array<Real, 3> absAxes{ Math<Real>::FAbs(axes[0]), Math<Real>::FAbs(axes[1]), Math<Real>::FAbs(axes[2]) };

    auto maxProjectedExtent = Math<Real>::GetValue(0);

    if (absAxes[0] < Math<Real>::GetZeroTolerance())
    {
        if (absAxes[1] < Math<Real>::GetZeroTolerance())
        {
            // �桪����
            cfg.SetMap(VertexProjectionMap::M44);

            maxProjectedExtent = absAxes[2] * box.GetExtent(2);

            // ����axes[2]���з��ߡ�
            if (Math<Real>::GetValue(0) < axes[2])
            {
                cfg.SetIndex(0, 0);
                cfg.SetIndex(1, 1);
                cfg.SetIndex(2, 3);
                cfg.SetIndex(3, 2);

                cfg.SetIndex(4, 6);
                cfg.SetIndex(5, 7);
                cfg.SetIndex(6, 5);
                cfg.SetIndex(7, 4);
            }
            else
            {
                cfg.SetIndex(0, 6);
                cfg.SetIndex(1, 7);
                cfg.SetIndex(2, 5);
                cfg.SetIndex(3, 4);

                cfg.SetIndex(4, 0);
                cfg.SetIndex(5, 1);
                cfg.SetIndex(6, 3);
                cfg.SetIndex(7, 2);
            }
        }
        else if (absAxes[2] < Math<Real>::GetZeroTolerance())
        {
            // �桪����
            cfg.SetMap(VertexProjectionMap::M44);

            maxProjectedExtent = absAxes[1] * box.GetExtent(1);

            // ����axes[1]���з��ߡ�
            if (Math<Real>::GetValue(0) < axes[1])
            {
                cfg.SetIndex(0, 4);
                cfg.SetIndex(1, 5);
                cfg.SetIndex(2, 1);
                cfg.SetIndex(3, 0);

                cfg.SetIndex(4, 2);
                cfg.SetIndex(5, 3);
                cfg.SetIndex(6, 7);
                cfg.SetIndex(7, 6);
            }
            else
            {
                cfg.SetIndex(0, 2);
                cfg.SetIndex(1, 3);
                cfg.SetIndex(2, 7);
                cfg.SetIndex(3, 6);

                cfg.SetIndex(4, 4);
                cfg.SetIndex(5, 5);
                cfg.SetIndex(6, 1);
                cfg.SetIndex(7, 0);
            }
        }
        else  // ��axes[0]����0
        {
            // �߶Ρ����߶�
            cfg.SetMap(VertexProjectionMap::M2_2);

            maxProjectedExtent = absAxes[1] * box.GetExtent(1) + absAxes[2] * box.GetExtent(2);

            // axis0��ֱ����
            if (Math<Real>::GetValue(0) < axes[1])
            {
                if (Math<Real>::GetValue(0) < axes[2])
                {
                    cfg.SetIndex(0, 0);
                    cfg.SetIndex(1, 1);

                    cfg.SetIndex(6, 6);
                    cfg.SetIndex(7, 7);
                }
                else
                {
                    cfg.SetIndex(0, 4);
                    cfg.SetIndex(1, 5);

                    cfg.SetIndex(6, 2);
                    cfg.SetIndex(7, 3);
                }
            }
            else  // axes[1] < 0
            {
                if (Math<Real>::GetValue(0) < axes[2])
                {
                    cfg.SetIndex(0, 2);
                    cfg.SetIndex(1, 3);

                    cfg.SetIndex(6, 4);
                    cfg.SetIndex(7, 5);
                }
                else
                {
                    cfg.SetIndex(0, 6);
                    cfg.SetIndex(1, 7);

                    cfg.SetIndex(6, 0);
                    cfg.SetIndex(7, 1);
                }
            }
        }
    }
    else if (absAxes[1] < Math<Real>::GetZeroTolerance())
    {
        if (absAxes[2] < Math<Real>::GetZeroTolerance())
        {
            // �桪����
            cfg.SetMap(VertexProjectionMap::M44);

            maxProjectedExtent = absAxes[0] * box.GetExtent(0);

            // ����axes[0]���з���
            if (Math<Real>::GetValue(0) < axes[0])
            {
                cfg.SetIndex(0, 0);
                cfg.SetIndex(1, 2);
                cfg.SetIndex(2, 6);
                cfg.SetIndex(3, 4);

                cfg.SetIndex(4, 5);
                cfg.SetIndex(5, 7);
                cfg.SetIndex(6, 3);
                cfg.SetIndex(7, 1);
            }
            else
            {
                cfg.SetIndex(4, 0);
                cfg.SetIndex(5, 2);
                cfg.SetIndex(6, 6);
                cfg.SetIndex(7, 4);

                cfg.SetIndex(0, 5);
                cfg.SetIndex(1, 7);
                cfg.SetIndex(2, 3);
                cfg.SetIndex(3, 1);
            }
        }
        else  // ��axes[1]����0
        {
            // �߶Ρ����߶�
            cfg.SetMap(VertexProjectionMap::M2_2);

            maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[2] * box.GetExtent(2);

            // axis1��ֱ����
            if (Math<Real>::GetValue(0) < axes[0])
            {
                if (Math<Real>::GetValue(0) < axes[2])
                {
                    cfg.SetIndex(0, 0);
                    cfg.SetIndex(1, 2);

                    cfg.SetIndex(6, 5);
                    cfg.SetIndex(7, 7);
                }
                else
                {
                    cfg.SetIndex(0, 4);
                    cfg.SetIndex(1, 6);

                    cfg.SetIndex(6, 1);
                    cfg.SetIndex(7, 3);
                }
            }
            else  // axes[0] < 0
            {
                if (Math<Real>::GetValue(0) < axes[2])
                {
                    cfg.SetIndex(0, 1);
                    cfg.SetIndex(1, 3);

                    cfg.SetIndex(6, 4);
                    cfg.SetIndex(7, 6);
                }
                else
                {
                    cfg.SetIndex(0, 5);
                    cfg.SetIndex(1, 7);

                    cfg.SetIndex(6, 0);
                    cfg.SetIndex(7, 2);
                }
            }
        }
    }

    else if (absAxes[2] < Math<Real>::GetZeroTolerance())
    {
        // ��axis2С����
        // �߶Ρ����߶�
        cfg.SetMap(VertexProjectionMap::M2_2);

        maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[1] * box.GetExtent(1);

        // axis2��ֱ����
        if (Math<Real>::GetValue(0) < axes[0])
        {
            if (Math<Real>::GetValue(0) < axes[1])
            {
                cfg.SetIndex(0, 0);
                cfg.SetIndex(1, 4);

                cfg.SetIndex(6, 3);
                cfg.SetIndex(7, 7);
            }
            else
            {
                cfg.SetIndex(0, 2);
                cfg.SetIndex(1, 6);

                cfg.SetIndex(6, 1);
                cfg.SetIndex(7, 5);
            }
        }
        else  // axes[0] < 0
        {
            if (Math<Real>::GetValue(0) < axes[1])
            {
                cfg.SetIndex(0, 1);
                cfg.SetIndex(1, 5);

                cfg.SetIndex(6, 2);
                cfg.SetIndex(7, 6);
            }
            else
            {
                cfg.SetIndex(0, 3);
                cfg.SetIndex(1, 7);

                cfg.SetIndex(6, 0);
                cfg.SetIndex(7, 4);
            }
        }
    }

    else  // û���������
    {
        // ��Ե㣨Ψһ������С���㣩
        cfg.SetMap(VertexProjectionMap::M1_1);

        maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[1] * box.GetExtent(1) + absAxes[2] * box.GetExtent(2);

        // ֻ���������������Ҫ������Ķ�û�й�ϵ
        cfg.SetIndex(0, (Math<Real>::GetValue(0) < axes[0] ? 0 : 1) + (Math<Real>::GetValue(0) < axes[1] ? 0 : 2) + (Math<Real>::GetValue(0) < axes[2] ? 0 : 4));
        // ͨ���������ж��㣬�Խǹ���7��
        cfg.SetIndex(7, 7 - cfg.GetIndex(0));
    }

#include STSTEM_WARNING_POP

    // �������ϵ�ͶӰ
    auto origin = Vector3DTools<Real>::DotProduct(axis, box.GetCenter());
    cfg.SetMin(origin - maxProjectedExtent);
    cfg.SetMax(origin + maxProjectedExtent);

    return cfg;
}

template <typename Real>
void Mathematics::FindIntersectorAxisImpl<Real>::Find(const Vector3D& axis, const Vector3D& velocity, const IntersectorConfiguration& cfg0Start, const IntersectorConfiguration& cfg1Start, Real tmax)
{
    // ���ٷ�������ԡ� ����cfg0Start��cfg1Start�ǵ�ǰ��Ǳ����ϵ���ã���cfg0Final��cfg1Final�ǸĽ������á�
    auto t = Math<Real>::GetValue(0);
    auto speed = Vector3DTools<Real>::DotProduct(axis, velocity);

    if (cfg1Start.GetMax() < cfg0Start.GetMin())  // object1��object0�����
    {
        if (speed <= Math<Real>::GetValue(0))  // object1Զ��object0
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ��״νӴ�
        t = (cfg0Start.GetMin() - cfg1Start.GetMax()) / speed;

        // ��������µ�����״νӴ�ʱ�䣬��������ú����á�
        if (m_TFirst < t)
        {
            m_TFirst = t;
            m_Side = ContactSide::Left;
            m_CfgFinal0 = cfg0Start;
            m_CfgFinal1 = cfg1Start;
        }

        // �����˳�����������Ľ���
        if (tmax < m_TFirst)
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ��
        t = (cfg0Start.GetMax() - cfg1Start.GetMin()) / speed;
        if (t < m_TLast)
        {
            m_TLast = t;
        }

        // �����˳���������ǰ�Ľ���
        if (m_TLast < m_TFirst)
        {
            m_Result = false;
            return;
        }
    }
    else if (cfg0Start.GetMax() < cfg1Start.GetMin())  // obj1��obj0���Ҳ�
    {
        if (Math<Real>::GetValue(0) <= speed)  // object1Զ��object0
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ��״νӴ�
        t = (cfg0Start.GetMax() - cfg1Start.GetMin()) / speed;

        // ��������µ�����״νӴ�ʱ�䣬��������ú����á�
        if (m_TFirst < t)
        {
            m_TFirst = t;
            m_Side = ContactSide::Right;
            m_CfgFinal0 = cfg0Start;
            m_CfgFinal1 = cfg1Start;
        }

        // �����˳�����������Ľ���
        if (tmax < m_TFirst)
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ��
        t = (cfg0Start.GetMin() - cfg1Start.GetMax()) / speed;
        if (t < m_TLast)
        {
            m_TLast = t;
        }

        // �����˳���������ǰ�Ľ���
        if (m_TLast < m_TFirst)
        {
            m_Result = false;
            return;
        }
    }
    else  // �ص�����ϵ�object1��object0
    {
        if (Math<Real>::GetValue(0) < speed)
        {
            // ���Ҹ����ϵ����һ�νӴ�ʱ��
            t = (cfg0Start.GetMax() - cfg1Start.GetMin()) / speed;
            if (t < m_TLast)
            {
                m_TLast = t;
            }

            // �����˳���������ǰ�Ľ���
            if (m_TLast < m_TFirst)
            {
                m_Result = false;
                return;
            }
        }
        else if (speed < Math<Real>::GetValue(0))
        {
            // ���Ҹ����ϵ����һ�νӴ�ʱ��
            t = (cfg0Start.GetMin() - cfg1Start.GetMax()) / speed;
            if (t < m_TLast)
            {
                m_TLast = t;
            }

            // �����˳���������ǰ�Ľ���
            if (m_TLast < m_TFirst)
            {
                m_Result = false;
                return;
            }
        }
    }
    m_Result = true;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_IMPL_DETAIL_H
