/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/05 10:29)

#ifndef MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_DETAIL_H
#define MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_DETAIL_H

#include "BoundingSphere.h"
#include "Mathematics/Algebra/TransformDetail.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BOUNDING_SPHERE_ACHIEVE)

    #include "BoundingSphereAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BOUNDING_SPHERE_ACHIEVE)

template <typename T>
bool Mathematics::TestIntersection(const BoundingSphere<T>& lhsBound, const BoundingSphere<T>& rhsBound, T epsilon) noexcept
{
    if (lhsBound.GetRadius() <= epsilon || rhsBound.GetRadius() <= epsilon)
    {
        // ����һ���߽�����Ч�ģ����ཻ��
        return false;
    }

    // ���Ծ�̬��;�̬����ཻ��
    const auto difference = lhsBound.GetCenter() - rhsBound.GetCenter();
    const auto radiusSum = lhsBound.GetRadius() + rhsBound.GetRadius();

    return difference.SquaredLength() <= radiusSum * radiusSum + epsilon;
}

template <typename T>
bool Mathematics::TestIntersection(const BoundingSphere<T>& lhsBound,
                                   const AVector<T>& lhsVelocity,
                                   const BoundingSphere<T>& rhsBound,
                                   const AVector<T>& rhsVelocity,
                                   T tMax)
{
    if (lhsBound.GetRadius() <= Math<T>::GetZeroTolerance() || rhsBound.GetRadius() <= Math<T>::GetZeroTolerance())
    {
        // ����һ���߽�����Ч�ģ����ཻ��
        return false;
    }

    // ���Զ�̬��Ͷ�̬����ཻ��
    auto realVelocity = rhsVelocity - lhsVelocity;
    const auto centerDifference = rhsBound.GetCenter() - lhsBound.GetCenter();

    auto realVelocitySquaredLength = realVelocity.SquaredLength();
    auto centerDifferenceSquaredLength = centerDifference.SquaredLength();
    const auto radiusSum = lhsBound.GetRadius() + rhsBound.GetRadius();
    const auto radiusSumSquared = radiusSum * radiusSum;

    if (Math<T>::GetZeroTolerance() < realVelocitySquaredLength)
    {
        auto dot = Dot(centerDifference, realVelocity);
        if (dot <= Math<T>::GetZeroTolerance())
        {
            if (-tMax * realVelocitySquaredLength <= dot)
            {
                return realVelocitySquaredLength * centerDifferenceSquaredLength - dot * dot <= realVelocitySquaredLength * radiusSumSquared;
            }
            else
            {
                return tMax * (tMax * realVelocitySquaredLength + Math<T>::GetValue(2) * dot) + centerDifferenceSquaredLength <= radiusSumSquared;
            }
        }
    }

    return centerDifferenceSquaredLength <= radiusSumSquared;
}

template <typename T>
bool Mathematics::Approximate(const BoundingSphere<T>& lhs, const BoundingSphere<T>& rhs, T epsilon)
{
    MATHEMATICS_ASSERTION_0(T{} <= epsilon, "epsilon�������0��");

    if (Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) && Math<T>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon))
        return true;
    else
        return false;
}

#endif  // MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_DETAIL_H
