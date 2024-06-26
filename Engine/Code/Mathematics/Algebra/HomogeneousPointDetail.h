///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:26)

#ifndef MATHEMATICS_ALGEBRA_POINT_DETAIL_H
#define MATHEMATICS_ALGEBRA_POINT_DETAIL_H

#include "HomogeneousPoint.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_HOMOGENEOUS_POINT_ACHIEVE)

    #include "HomogeneousPointAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_HOMOGENEOUS_POINT_ACHIEVE)

template <typename T>
bool Mathematics::operator==(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename T>
bool Mathematics::operator<(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs) noexcept
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else if (lhs.GetY() < rhs.GetY())
        return true;
    else if (rhs.GetY() < lhs.GetY())
        return false;
    else if (lhs.GetZ() < rhs.GetZ())
        return true;
    else if (rhs.GetZ() < lhs.GetZ())
        return false;
    else
        return lhs.GetW() < rhs.GetW();
}

template <typename T>
bool Mathematics::Approximate(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs, const T epsilon) noexcept
{
    if (Math<T>::FAbs(lhs.GetX() - rhs.GetX()) <= epsilon &&
        Math<T>::FAbs(lhs.GetY() - rhs.GetY()) <= epsilon &&
        Math<T>::FAbs(lhs.GetZ() - rhs.GetZ()) <= epsilon &&
        Math<T>::FAbs(lhs.GetW() - rhs.GetW()) <= epsilon)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // MATHEMATICS_ALGEBRA_POINT_DETAIL_H