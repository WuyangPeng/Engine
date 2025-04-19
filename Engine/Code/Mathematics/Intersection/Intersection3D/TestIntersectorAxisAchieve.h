///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:30)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H

#include "TestIntersectorAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3Type& axis, const SegmentType& segment, const Triangle3Type& triangle, const Vector3Type& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, segment);

    const auto projection1 = GetProjection(axis, triangle);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3Type& axis, const SegmentType& segment, const Box3Type& box, const Vector3Type& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, segment);

    const auto projection1 = GetProjection(axis, box);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3Type& axis, const Triangle3Type& triangle, const Box3Type& box, const Vector3Type& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, triangle);

    const auto projection1 = GetProjection(axis, box);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}
template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3Type& axis, const Box3Type& box0, const Box3Type& box1, const Vector3Type& velocity, Real tmax)
    : result{ false }, tFirst{}, tLast{}
{
    const auto projection0 = GetProjection(axis, box0);

    const auto projection1 = GetProjection(axis, box1);

    Test(axis, velocity, projection0.first, projection0.second, projection1.first, projection1.second, tmax);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3Type& axis, const Vector3Type& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept
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
typename Mathematics::TestIntersectorAxis<Real>::Projections Mathematics::TestIntersectorAxis<Real>::GetProjection(const Vector3Type& axis, const SegmentType& segment) noexcept
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
typename Mathematics::TestIntersectorAxis<Real>::Projections Mathematics::TestIntersectorAxis<Real>::GetProjection(const Vector3Type& axis, const Triangle3Type& triangle)
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
typename Mathematics::TestIntersectorAxis<Real>::Projections Mathematics::TestIntersectorAxis<Real>::GetProjection(const Vector3Type& axis, const Box3Type& box)
{
    const auto origin = Vector3Tools<Real>::DotProduct(axis, box.GetCenter());
    const auto maximumExtent = Math<Real>::FAbs(box.GetExtent(0) * Vector3Tools<Real>::DotProduct(axis, box.GetAxis(0))) +
                               Math<Real>::FAbs(box.GetExtent(1) * Vector3Tools<Real>::DotProduct(axis, box.GetAxis(1))) +
                               Math<Real>::FAbs(box.GetExtent(2) * Vector3Tools<Real>::DotProduct(axis, box.GetAxis(2)));

    return Projections{ origin - maximumExtent, origin + maximumExtent };
}

template <typename Real>
void Mathematics::TestIntersectorAxis<Real>::Test(const Vector3Type& axis, const Vector3Type& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept
{
    /// 静态分离轴测试。 如果在时间间隔（即快速退出）中object0和object1没有在任何分隔轴( TFirst > TLast || TFirst > TMax )上的间隔[0，TMax]中相交，则返回false。 否则返回true。
    //  min0，max0，min1和max1是将对象object0和object1投影到测试轴上的最小和最大点。
    // 速度为Velocity1-Velocity0

    auto t = Math<Real>::GetValue(0);
    auto speed = Vector3Tools<Real>::DotProduct(axis, velocity);

    if (max1 < min0)  // object1位于object0的左侧
    {
        if (speed <= Math<Real>::GetValue(0))  // object1远离object0
        {
            result = false;
            return;
        }

        // 查找该轴上的首次接触
        t = (min0 - max1) / speed;
        if (tFirst < t)
        {
            tFirst = t;
        }

        // 快速退出：所需间隔后的交点
        if (tmax < tFirst)
        {
            result = false;
            return;
        }

        // 查找该轴上的最后一次接触时间
        t = (max0 - min1) / speed;
        if (t < tLast)
        {
            tLast = t;
        }

        // 快速退出：所需间隔前的交点
        if (tLast < tFirst)
        {
            result = false;
            return;
        }
    }
    else if (max0 < min1)  // object1位于object0的右侧
    {
        if (Math<Real>::GetValue(0) <= speed)  // object1远离object0
        {
            result = false;
            return;
        }

        // 查找该轴上的首次接触
        t = (max0 - min1) / speed;
        if (tFirst < t)
        {
            tFirst = t;
        }

        // 快速退出：所需间隔后的交点
        if (tmax < tFirst)
        {
            result = false;
            return;
        }

        // 查找该轴上的最后一次接触时间
        t = (min0 - max1) / speed;
        if (t < tLast)
        {
            tLast = t;
        }

        // 快速退出：所需间隔前的交点
        if (tLast < tFirst)
        {
            result = false;
            return;
        }
    }
    else  // 重叠间隔上的object1和object0
    {
        if (Math<Real>::GetValue(0) < speed)
        {
            // 查找该轴上的最后一次接触时间
            t = (max0 - min1) / speed;
            if (t < tLast)
            {
                tLast = t;
            }

            // 快速退出：所需间隔前的交点
            if (tLast < tFirst)
            {
                result = false;
                return;
            }
        }
        else if (speed < Math<Real>::GetValue(0))
        {
            //  查找该轴上的最后一次接触时间
            t = (min0 - max1) / speed;
            if (t < tLast)
            {
                tLast = t;
            }

            // 快速退出：所需间隔前的交点
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
