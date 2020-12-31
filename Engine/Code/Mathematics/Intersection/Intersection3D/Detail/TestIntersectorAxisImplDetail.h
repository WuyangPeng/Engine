///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/28 10:05)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_IMPL_DETAIL_H

#include "TestIntersectorAxisImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects3D/Box3Detail.h"

template <typename Real>
Mathematics::TestIntersectorAxisImpl<Real>::TestIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{}
{
    const auto projection0 = GetProjection(axis, segment);

    const auto projection1 = GetProjection(axis, triangle);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxisImpl<Real>::TestIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{}
{
    const auto projection0 = GetProjection(axis, segment);

    const auto projection1 = GetProjection(axis, box);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxisImpl<Real>::TestIntersectorAxisImpl(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{}
{
    const auto projection0 = GetProjection(axis, triangle);

    const auto projection1 = GetProjection(axis, box);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxisImpl<Real>::TestIntersectorAxisImpl(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax)
    : m_Result{ false }, m_TFirst{}, m_TLast{}
{
    const auto projection0 = GetProjection(axis, box0);

    const auto projection1 = GetProjection(axis, box1);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxisImpl<Real>::TestIntersectorAxisImpl(const Vector3D& axis, const Vector3D& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept
    : m_Result{ false }, m_TFirst{}, m_TLast{}
{
    Test(axis, velocity, min0, max0, min1, max1, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::TestIntersectorAxisImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TestIntersectorAxisImpl<Real>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Result;
}

template <typename Real>
Real Mathematics::TestIntersectorAxisImpl<Real>::GetTFirst() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_TFirst;
}

template <typename Real>
Real Mathematics::TestIntersectorAxisImpl<Real>::GetTLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_TLast;
}

template <typename Real>
typename Mathematics::TestIntersectorAxisImpl<Real>::Projections Mathematics::TestIntersectorAxisImpl<Real>::GetProjection(const Vector3D& axis, const SegmentType& segment) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto min = Vector3DTools<Real>::DotProduct(axis, segment[0]);
    auto max = Vector3DTools<Real>::DotProduct(axis, segment[1]);
#include STSTEM_WARNING_POP

    if (max < min)
    {
        std::swap(min, max);
    }

    return Projections{ min, max };
}

template <typename Real>
typename Mathematics::TestIntersectorAxisImpl<Real>::Projections Mathematics::TestIntersectorAxisImpl<Real>::GetProjection(const Vector3D& axis, const Triangle3& triangle)
{
    auto min = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(0));
    auto max = min;

    std::array<Real, 3> dot{ min,
                             Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(1)),
                             Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(2)) };

    const auto iter = std::minmax_element(dot.begin(), dot.end());

    if (iter.first != dot.end())
    {
        min = *iter.first;
    }

    if (iter.second != dot.end())
    {
        max = *iter.second;
    }

    return Projections{ min, max };
}

template <typename Real>
typename Mathematics::TestIntersectorAxisImpl<Real>::Projections Mathematics::TestIntersectorAxisImpl<Real>::GetProjection(const Vector3D& axis, const Box3& box)
{
    auto origin = Vector3DTools<Real>::DotProduct(axis, box.GetCenter());
    auto maximumExtent = Math<Real>::FAbs(box.GetExtent(0) * Vector3DTools<Real>::DotProduct(axis, box.GetAxis(0))) +
                         Math<Real>::FAbs(box.GetExtent(1) * Vector3DTools<Real>::DotProduct(axis, box.GetAxis(1))) +
                         Math<Real>::FAbs(box.GetExtent(2) * Vector3DTools<Real>::DotProduct(axis, box.GetAxis(2)));

    return Projections{ origin - maximumExtent, origin + maximumExtent };
}

template <typename Real>
void Mathematics::TestIntersectorAxisImpl<Real>::Test(const Vector3D& axis, const Vector3D& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept
{
    /// ��̬��������ԡ� �����ʱ�������������˳�����object0��object1û�����κηָ���( TFirst > TLast || TFirst > TMax )�ϵļ��[0��TMax]���ཻ���򷵻�false�� ���򷵻�true��
    //  min0��max0��min1��max1�ǽ�����object0��object1ͶӰ���������ϵ���С�����㡣
    // �ٶ�ΪVelocity1-Velocity0

    auto t = Math<Real>::GetValue(0);
    auto speed = Vector3DTools<Real>::DotProduct(axis, velocity);

    if (max1 < min0)  // object1λ��object0�����
    {
        if (speed <= Math<Real>::GetValue(0))  // object1Զ��object0
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ��״νӴ�
        t = (min0 - max1) / speed;
        if (m_TFirst < t)
        {
            m_TFirst = t;
        }

        // �����˳�����������Ľ���
        if (tmax < m_TFirst)
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ��
        t = (max0 - min1) / speed;
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
    else if (max0 < min1)  // object1λ��object0���Ҳ�
    {
        if (Math<Real>::GetValue(0) <= speed)  // object1Զ��object0
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ��״νӴ�
        t = (max0 - min1) / speed;
        if (m_TFirst < t)
        {
            m_TFirst = t;
        }

        // �����˳�����������Ľ���
        if (tmax < m_TFirst)
        {
            m_Result = false;
            return;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ��
        t = (min0 - max1) / speed;
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
            t = (max0 - min1) / speed;
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
            //  ���Ҹ����ϵ����һ�νӴ�ʱ��
            t = (min0 - max1) / speed;
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

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_IMPL_DETAIL_H
