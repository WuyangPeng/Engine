///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:21)

#ifndef RENDERING_DATA_TYPES_BOUND_DETAIL_H
#define RENDERING_DATA_TYPES_BOUND_DETAIL_H

#include "Bound.h"

#if !defined(RENDERING_EXPORT_TEMPLATE) || defined(RENDERING_INCLUDED_BOUND_ACHIEVE)

    #include "BoundAchieve.h"

#endif  // !defined(RENDERING_EXPORT_TEMPLATE) || defined(RENDERING_INCLUDED_BOUND_ACHIEVE)

template <typename T>
bool Rendering::TestIntersection(const Bound<T>& lhsBound, const Bound<T>& rhsBound) noexcept
{
    if (lhsBound.GetRadius() <= Mathematics::Math<T>::GetZeroTolerance() || rhsBound.GetRadius() <= Mathematics::Math<T>::GetZeroTolerance())
    {
        // 其中一个边界是无效的，不相交。
        return false;
    }

    // 测试静态球和静态球的相交。
    const auto difference = lhsBound.GetCenter() - rhsBound.GetCenter();
    const auto radiusSum = lhsBound.GetRadius() + rhsBound.GetRadius();

    return difference.SquaredLength() <= radiusSum * radiusSum;
}

template <typename T>
bool Rendering::TestIntersection(const Bound<T>& lhsBound,
                                 const Mathematics::AVector<T>& lhsVelocity,
                                 const Bound<T>& rhsBound,
                                 const Mathematics::AVector<T>& rhsVelocity,
                                 float tMax)
{
    if (lhsBound.GetRadius() <= Mathematics::Math<T>::GetZeroTolerance() || rhsBound.GetRadius() <= Mathematics::Math<T>::GetZeroTolerance())
    {
        // 其中一个边界是无效的，不相交。
        return false;
    }

    // 测试动态球和动态球的相交。
    auto realVelocity = rhsVelocity - lhsVelocity;
    const auto centerDifference = rhsBound.GetCenter() - lhsBound.GetCenter();

    auto realVelocitySquaredLength = realVelocity.SquaredLength();
    auto centerDifferenceSquaredLength = centerDifference.SquaredLength();
    const auto radiusSum = lhsBound.GetRadius() + rhsBound.GetRadius();
    const auto radiusSumSquared = radiusSum * radiusSum;

    if (Mathematics::Math<T>::GetZeroTolerance() < realVelocitySquaredLength)
    {
        auto dot = Dot(centerDifference, realVelocity);
        if (dot <= Mathematics::Math<T>::GetZeroTolerance())
        {
            if (-tMax * realVelocitySquaredLength <= dot)
            {
                return realVelocitySquaredLength * centerDifferenceSquaredLength - dot * dot <= realVelocitySquaredLength * radiusSumSquared;
            }
            else
            {
                return tMax * (tMax * realVelocitySquaredLength + Mathematics::Math<T>::GetValue(2) * dot) + centerDifferenceSquaredLength <= radiusSumSquared;
            }
        }
    }

    return centerDifferenceSquaredLength <= radiusSumSquared;
}

template <typename T>
bool Rendering::Approximate(const Bound<T>& lhs, const Bound<T>& rhs, const float epsilon) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    if (Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) && Mathematics::Math<T>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon))
        return true;
    else
        return false;
}

#endif  // RENDERING_DATA_TYPES_BOUND_DETAIL_H
