///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:42)

#ifndef MATHEMATICS_ALGEBRA_PLANE_DETAIL_H
#define MATHEMATICS_ALGEBRA_PLANE_DETAIL_H

#include "HomogeneousPointDetail.h"
#include "Plane.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_PLANE_ACHIEVE)

    #include "PlaneAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_PLANE_ACHIEVE)

template <typename T>
bool Mathematics::operator==(const Plane<T>& lhs, const Plane<T>& rhs)
{
    return lhs.GetHomogeneousPoint() == rhs.GetHomogeneousPoint();
}

template <typename T>
bool Mathematics::operator<(const Plane<T>& lhs, const Plane<T>& rhs)
{
    for (auto i = 0; i < Plane<T>::planeSize; ++i)
    {
        if (lhs[i] < rhs[i])
            return true;
        else if (rhs[i] < lhs[i])
            return false;
    }

    return false;
}

template <typename T>
bool Mathematics::Approximate(const Plane<T>& lhs, const Plane<T>& rhs, T epsilon)
{
    for (auto i = 0; i < Plane<T>::planeSize; ++i)
    {
        if (!Math<T>::Approximate(lhs[i], rhs[i], epsilon))
            return false;
    }

    return true;
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_DETAIL_H
