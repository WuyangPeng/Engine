/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/24 16:57)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_DETAIL_H

#include "CircleSortObjectDetail.h"
#include "SortPointsOnCircle.h"
#include "Mathematics/Base/MathDetail.h"

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
    return Sort(point, center, direction, sortCcw, LessThanByAngle);
}

template <typename T>
typename Mathematics::SortPointsOnCircle<T>::Indices Mathematics::SortPointsOnCircle<T>::ByGeometry(const Points& point,
                                                                                                    const Vector2& center,
                                                                                                    const Vector2& direction,
                                                                                                    bool sortCcw)
{
    return Sort(point, center, direction, sortCcw, LessThanByGeometry);
}

template <typename T>
typename Mathematics::SortPointsOnCircle<T>::Indices Mathematics::SortPointsOnCircle<T>::Sort(const Points& point, const Vector2& center, const Vector2& direction, bool sortCcw, SortFunction sortFunction)
{
    const auto directionPerp = (sortCcw ? Vector2{ -direction.at(1), direction.at(0) } : Vector2{ direction.at(1), -direction.at(0) });
    CircleSortObjectContainer object{};
    for (auto i = 0u; i < point.size(); ++i)
    {
        Vector2 vertex{ point.at(i).at(0) - center.at(0), point.at(i).at(1) - center.at(1) };
        object.emplace_back(Vector2{ direction.at(0) * vertex.at(0) + direction.at(1) * vertex.at(1),
                                     directionPerp.at(0) * vertex.at(0) + directionPerp.at(1) * vertex.at(1) },
                            i);
    }
    std::ranges::sort(object, sortFunction);

    Indices indices{};
    for (const auto& element : object)
    {
        indices.emplace_back(element.GetIndex());
    }

    return indices;
}

template <typename T>
bool Mathematics::SortPointsOnCircle<T>::LessThanByAngle(const CircleSortObjectType& lhs, const CircleSortObjectType& rhs)
{
    const auto x0 = lhs.GetW(0);
    const auto y0 = lhs.GetW(1);
    const auto x1 = rhs.GetW(0);
    const auto y1 = rhs.GetW(1);

    const auto angle0 = Math<T>::ATan2(y0, x0);
    const auto angle1 = Math<T>::ATan2(y1, x1);
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
bool Mathematics::SortPointsOnCircle<T>::LessThanByGeometry(const CircleSortObjectType& lhs, const CircleSortObjectType& rhs)
{
    const auto x0 = lhs.GetW(0);
    const auto y0 = lhs.GetW(1);
    const auto x1 = rhs.GetW(0);
    const auto y1 = rhs.GetW(1);
    constexpr T zero{};

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

    if (Math<T>::Approximate(y0, zero) && Math<T>::Approximate(y1, zero))
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