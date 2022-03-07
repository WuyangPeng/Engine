///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/25 21:24)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H

#include "TestIntersectorAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, segment);

    const auto projection1 = GetProjection(axis, triangle);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Box3& box, const Vector3& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, segment);

    const auto projection1 = GetProjection(axis, box);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3& axis, const Triangle3& triangle, const Box3& box, const Vector3& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, triangle);

    const auto projection1 = GetProjection(axis, box);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}
template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3& axis, const Box3& box0, const Box3& box1, const Vector3& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, box0);

    const auto projection1 = GetProjection(axis, box1);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3& axis, const Vector3& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept
    : result{ false }, tFirst{}, tLast{}
{
    Test(axis, velocity, min0, max0, min1, max1, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::TestIntersectorAxis<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TestIntersectorAxis<Real>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return result;
}

template <typename Real>
Real Mathematics::TestIntersectorAxis<Real>::GetTFirst() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tFirst;
}

template <typename Real>
Real Mathematics::TestIntersectorAxis<Real>::GetTLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tLast;
}

template <typename Real>
typename Mathematics::TestIntersectorAxis<Real>::Projections Mathematics::TestIntersectorAxis<Real>::GetProjection(const Vector3& axis, const SegmentType& segment) noexcept
{
    auto min = Vector3Tools<Real>::DotProduct(axis, segment.at(0));
    auto max = Vector3Tools<Real>::DotProduct(axis, segment.at(1));

    if (max < min)
    {
        std::swap(min, max);
    }

    return Projections{ min, max };
}

template <typename Real>
typename Mathematics::TestIntersectorAxis<Real>::Projections Mathematics::TestIntersectorAxis<Real>::GetProjection(const Vector3& axis, const Triangle3& triangle)
{
    auto min = Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(0));
    auto max = min;

    std::array<Real, 3> dot{ min,
                             Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(1)),
                             Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(2)) };

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
typename Mathematics::TestIntersectorAxis<Real>::Projections Mathematics::TestIntersectorAxis<Real>::GetProjection(const Vector3& axis, const Box3& box)
{
    const auto origin = Vector3Tools<Real>::DotProduct(axis, box.GetCenter());
    const auto maximumExtent = Math<Real>::FAbs(box.GetExtent(0) * Vector3Tools<Real>::DotProduct(axis, box.GetAxis(0))) +
                               Math<Real>::FAbs(box.GetExtent(1) * Vector3Tools<Real>::DotProduct(axis, box.GetAxis(1))) +
                               Math<Real>::FAbs(box.GetExtent(2) * Vector3Tools<Real>::DotProduct(axis, box.GetAxis(2)));

    return Projections{ origin - maximumExtent, origin + maximumExtent };
}

template <typename Real>
void Mathematics::TestIntersectorAxis<Real>::Test(const Vector3& axis, const Vector3& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept
{
    /// ��̬��������ԡ� �����ʱ�������������˳�����object0��object1û�����κηָ���( TFirst > TLast || TFirst > TMax )�ϵļ��[0��TMax]���ཻ���򷵻�false�� ���򷵻�true��
    //  min0��max0��min1��max1�ǽ�����object0��object1ͶӰ���������ϵ���С�����㡣
    // �ٶ�ΪVelocity1-Velocity0

    auto t = Math<Real>::GetValue(0);
    auto speed = Vector3Tools<Real>::DotProduct(axis, velocity);

    if (max1 < min0)  // object1λ��object0�����
    {
        if (speed <= Math<Real>::GetValue(0))  // object1Զ��object0
        {
            result = false;
            return;
        }

        // ���Ҹ����ϵ��״νӴ�
        t = (min0 - max1) / speed;
        if (tFirst < t)
        {
            tFirst = t;
        }

        // �����˳�����������Ľ���
        if (tmax < tFirst)
        {
            result = false;
            return;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ��
        t = (max0 - min1) / speed;
        if (t < tLast)
        {
            tLast = t;
        }

        // �����˳���������ǰ�Ľ���
        if (tLast < tFirst)
        {
            result = false;
            return;
        }
    }
    else if (max0 < min1)  // object1λ��object0���Ҳ�
    {
        if (Math<Real>::GetValue(0) <= speed)  // object1Զ��object0
        {
            result = false;
            return;
        }

        // ���Ҹ����ϵ��״νӴ�
        t = (max0 - min1) / speed;
        if (tFirst < t)
        {
            tFirst = t;
        }

        // �����˳�����������Ľ���
        if (tmax < tFirst)
        {
            result = false;
            return;
        }

        // ���Ҹ����ϵ����һ�νӴ�ʱ��
        t = (min0 - max1) / speed;
        if (t < tLast)
        {
            tLast = t;
        }

        // �����˳���������ǰ�Ľ���
        if (tLast < tFirst)
        {
            result = false;
            return;
        }
    }
    else  // �ص�����ϵ�object1��object0
    {
        if (Math<Real>::GetValue(0) < speed)
        {
            // ���Ҹ����ϵ����һ�νӴ�ʱ��
            t = (max0 - min1) / speed;
            if (t < tLast)
            {
                tLast = t;
            }

            // �����˳���������ǰ�Ľ���
            if (tLast < tFirst)
            {
                result = false;
                return;
            }
        }
        else if (speed < Math<Real>::GetValue(0))
        {
            //  ���Ҹ����ϵ����һ�νӴ�ʱ��
            t = (min0 - max1) / speed;
            if (t < tLast)
            {
                tLast = t;
            }

            // �����˳���������ǰ�Ľ���
            if (tLast < tFirst)
            {
                result = false;
                return;
            }
        }
    }

    result = true;
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H
