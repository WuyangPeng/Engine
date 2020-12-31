///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/28 14:03)

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

    // 查找顶点到潜在分离轴上的投影。
    auto d0 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(0));
    auto d1 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(1));
    auto d2 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(2));

    // 显式的排序顶点的构建IntersectorConfiguration。
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
    // IntersectorConfiguration.mIndex的坐标排序方案的说明。
    // 顶点数（向上/向下）与范围的符号（仅在向后映射中很重要）
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
    // 当它在“相交配置”中返回排序时，也保证它是有序的。
    // （如果有4个顶点，则将按照将创建一个框（例如0,1,3,2）的顺序进行保证）

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
            // 面——面
            cfg.SetMap(VertexProjectionMap::M44);

            maxProjectedExtent = absAxes[2] * box.GetExtent(2);

            // 面沿axes[2]具有法线。
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
            // 面——面
            cfg.SetMap(VertexProjectionMap::M44);

            maxProjectedExtent = absAxes[1] * box.GetExtent(1);

            // 面沿axes[1]具有法线。
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
        else  // 仅axes[0]等于0
        {
            // 线段——线段
            cfg.SetMap(VertexProjectionMap::M2_2);

            maxProjectedExtent = absAxes[1] * box.GetExtent(1) + absAxes[2] * box.GetExtent(2);

            // axis0垂直于轴
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
            // 面——面
            cfg.SetMap(VertexProjectionMap::M44);

            maxProjectedExtent = absAxes[0] * box.GetExtent(0);

            // 面沿axes[0]具有法线
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
        else  // 仅axes[1]等于0
        {
            // 线段——线段
            cfg.SetMap(VertexProjectionMap::M2_2);

            maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[2] * box.GetExtent(2);

            // axis1垂直于轴
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
        // 仅axis2小于零
        // 线段——线段
        cfg.SetMap(VertexProjectionMap::M2_2);

        maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[1] * box.GetExtent(1);

        // axis2垂直于轴
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

    else  // 没有轴等于零
    {
        // 点对点（唯一最大和最小顶点）
        cfg.SetMap(VertexProjectionMap::M1_1);

        maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[1] * box.GetExtent(1) + absAxes[2] * box.GetExtent(2);

        // 只有这两个顶点很重要，其余的都没有关系
        cfg.SetIndex(0, (Math<Real>::GetValue(0) < axes[0] ? 0 : 1) + (Math<Real>::GetValue(0) < axes[1] ? 0 : 2) + (Math<Real>::GetValue(0) < axes[2] ? 0 : 4));
        // 通过这样排列顶点，对角共计7个
        cfg.SetIndex(7, 7 - cfg.GetIndex(0));
    }

#include STSTEM_WARNING_POP

    // 查找线上的投影
    auto origin = Vector3DTools<Real>::DotProduct(axis, box.GetCenter());
    cfg.SetMin(origin - maxProjectedExtent);
    cfg.SetMax(origin + maxProjectedExtent);

    return cfg;
}

template <typename Real>
void Mathematics::FindIntersectorAxisImpl<Real>::Find(const Vector3D& axis, const Vector3D& velocity, const IntersectorConfiguration& cfg0Start, const IntersectorConfiguration& cfg1Start, Real tmax)
{
    // 等速分离轴测试。 配置cfg0Start和cfg1Start是当前的潜在联系配置，而cfg0Final和cfg1Final是改进的配置。
    auto t = Math<Real>::GetValue(0);
    auto speed = Vector3DTools<Real>::DotProduct(axis, velocity);

    if (cfg1Start.GetMax() < cfg0Start.GetMin())  // object1在object0的左侧
    {
        if (speed <= Math<Real>::GetValue(0))  // object1远离object0
        {
            m_Result = false;
            return;
        }

        // 查找该轴上的首次接触
        t = (cfg0Start.GetMin() - cfg1Start.GetMax()) / speed;

        // 如果这是新的最大首次接触时间，请进行设置和配置。
        if (m_TFirst < t)
        {
            m_TFirst = t;
            m_Side = ContactSide::Left;
            m_CfgFinal0 = cfg0Start;
            m_CfgFinal1 = cfg1Start;
        }

        // 快速退出：所需间隔后的交点
        if (tmax < m_TFirst)
        {
            m_Result = false;
            return;
        }

        // 查找该轴上的最后一次接触时间
        t = (cfg0Start.GetMax() - cfg1Start.GetMin()) / speed;
        if (t < m_TLast)
        {
            m_TLast = t;
        }

        // 快速退出：所需间隔前的交点
        if (m_TLast < m_TFirst)
        {
            m_Result = false;
            return;
        }
    }
    else if (cfg0Start.GetMax() < cfg1Start.GetMin())  // obj1在obj0的右侧
    {
        if (Math<Real>::GetValue(0) <= speed)  // object1远离object0
        {
            m_Result = false;
            return;
        }

        // 查找该轴上的首次接触
        t = (cfg0Start.GetMax() - cfg1Start.GetMin()) / speed;

        // 如果这是新的最大首次接触时间，请进行设置和配置。
        if (m_TFirst < t)
        {
            m_TFirst = t;
            m_Side = ContactSide::Right;
            m_CfgFinal0 = cfg0Start;
            m_CfgFinal1 = cfg1Start;
        }

        // 快速退出：所需间隔后的交点
        if (tmax < m_TFirst)
        {
            m_Result = false;
            return;
        }

        // 查找该轴上的最后一次接触时间
        t = (cfg0Start.GetMin() - cfg1Start.GetMax()) / speed;
        if (t < m_TLast)
        {
            m_TLast = t;
        }

        // 快速退出：所需间隔前的交点
        if (m_TLast < m_TFirst)
        {
            m_Result = false;
            return;
        }
    }
    else  // 重叠间隔上的object1和object0
    {
        if (Math<Real>::GetValue(0) < speed)
        {
            // 查找该轴上的最后一次接触时间
            t = (cfg0Start.GetMax() - cfg1Start.GetMin()) / speed;
            if (t < m_TLast)
            {
                m_TLast = t;
            }

            // 快速退出：所需间隔前的交点
            if (m_TLast < m_TFirst)
            {
                m_Result = false;
                return;
            }
        }
        else if (speed < Math<Real>::GetValue(0))
        {
            // 查找该轴上的最后一次接触时间
            t = (cfg0Start.GetMin() - cfg1Start.GetMax()) / speed;
            if (t < m_TLast)
            {
                m_TLast = t;
            }

            // 快速退出：所需间隔前的交点
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
