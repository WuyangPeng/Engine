///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:15)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_DETAIL_H

#include "SortPointsOnCircle.h"
#include "Mathematics/Base/Math.h"

template <typename T>
Mathematics::SortPointsOnCircle<T>::SortObject::SortObject(const Vector2& w, int index)
    : w{ w }, index{ index }
{
}

template <typename T>
Mathematics::SortPointsOnCircle<T>::SortObject::SortObject()
    : w{}, index{}
{
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::SortPointsOnCircle<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename Mathematics::SortPointsOnCircle<T>::Indices Mathematics::SortPointsOnCircle<T>::ByAngle(const Points& point,
                                                                                                 const Vector2& center,
                                                                                                 const Vector2& direction,
                                                                                                 bool sortCcw)
{
    const auto directionPerp = (sortCcw ? Vector2{ -direction[1], direction[0] } : Vector2{ direction[1], -direction[0] });
    std::vector<SortObject> object{};
    for (auto i = 0u; i < point.size(); ++i)
    {
        Vector2 vertex{ point[i][0] - center[0], point[i][1] - center[1] };
        object.emplace_back({ direction[0] * vertex[0] + direction[1] * vertex[1], directionPerp[0] * vertex[0] + directionPerp[1] * vertex[1] }, i);
    }
    std::ranges::sort(object, LessThanByAngle);

    Indices indices{};
    for (size_t i = 0; i < point.size(); ++i)
    {
        indices.emplace_back(object[i].index);
    }

    return indices;
}

template <typename T>
typename Mathematics::SortPointsOnCircle<T>::Indices Mathematics::SortPointsOnCircle<T>::ByGeometry(const Points& point,
                                                                                                    const Vector2& center,
                                                                                                    const Vector2& direction,
                                                                                                    bool sortCcw)
{
    const auto directionPerp = (sortCcw ? Vector2{ -direction[1], direction[0] } : Vector2{ direction[1], -direction[0] });
    std::vector<SortObject> object{};
    for (size_t i = 0; i < point.size(); ++i)
    {
        Vector2 vertex{ point[i][0] - center[0], point[i][1] - center[1] };
        object.emplace_back({ direction[0] * vertex[0] + direction[1] * vertex[1], directionPerp[0] * vertex[0] + directionPerp[1] * vertex[1] }, i);
    }
    std::ranges::sort(object, LessThanByGeometry);

    Indices indices{};
    for (size_t i = 0; i < point.size(); ++i)
    {
        indices.emplace_back(object[i].index);
    }

    return indices;
}

template <typename T>
bool Mathematics::SortPointsOnCircle<T>::LessThanByAngle(const SortObject& lhs, const SortObject& rhs)
{
    const T& x0 = lhs.w[0];
    const T& y0 = lhs.w[1];
    const T& x1 = rhs.w[0];
    const T& y1 = rhs.w[1];

    const auto angle0 = Math<T>::ATan(y0, x0);
    const auto angle1 = Math<T>::ATan(y1, x1);
    if (angle0 < angle1)
    {
        return true;
    }
    if (angle1 < angle0)
    {
        return false;
    }

    // c == 0, s0 < s1
    return (x0 - x1) * (x0 + x1) < (y1 - y0) * (y1 + y0);
}

template <typename T>
bool Mathematics::SortPointsOnCircle<T>::LessThanByGeometry(const SortObject& object0, const SortObject& object1)
{
    const T& x0 = object0.w[0];
    const T& y0 = object0.w[1];
    const T& x1 = object1.w[0];
    const T& y1 = object1.w[1];
    const T zero{};

    if (y0 < zero && zero <= y1)
    {
        return true;
    }

    if (y1 < zero && zero <= y0)
    {
        return false;
    }

    if (zero < y0 && Math<T>::Approximate(y1, zero))
    {
        return x1 < zero;
    }

    if (zero < y1 && Math<T>::Approximate(y0, zero))
    {
        return zero < x0;
    }

    if (y0 == zero && Math<T>::Approximate(y1, zero))
    {
        return (x1 < zero && x1 < x0) || (zero < x0 && x0 < x1);
    }

    const auto c = x0 * y1 - x1 * y0;
    if (zero < c)
    {
        return true;
    }

    if (c < zero)
    {
        return false;
    }

    // c == 0, s0 < s1
    return (x0 - x1) * (x0 + x1) < (y1 - y0) * (y1 + y0);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_DETAIL_H