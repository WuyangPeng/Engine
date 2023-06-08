///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 18:06)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_DETAIL_H

#include "DistancePoint3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Triangle3<Real>::DistancePoint3Triangle3(const Vector3& point, const Triangle3& triangle) noexcept
    : ParentType{}, point{ point }, triangle{ triangle }, triangleBary{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Triangle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistancePoint3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
typename Mathematics::DistancePoint3Triangle3<Real>::DistanceResult Mathematics::DistancePoint3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = triangle.GetVertex(0) - point;
    auto edge0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge1 = triangle.GetVertex(2) - triangle.GetVertex(0);
    auto edge0LengthSquared = Vector3Tools::GetLengthSquared(edge0);
    auto edge0DotEdge1 = Vector3Tools::DotProduct(edge0, edge1);
    auto edge1LengthSquared = Vector3Tools::GetLengthSquared(edge1);
    auto diffDotEdge0 = Vector3Tools::DotProduct(diff, edge0);
    auto diffDotEdge1 = Vector3Tools::DotProduct(diff, edge1);
    auto diffLengthSquared = Vector3Tools::GetLengthSquared(diff);
    auto det = Math::FAbs(edge0LengthSquared * edge1LengthSquared - edge0DotEdge1 * edge0DotEdge1);
    auto s = edge0DotEdge1 * diffDotEdge1 - edge1LengthSquared * diffDotEdge0;
    auto t = edge0DotEdge1 * diffDotEdge0 - edge0LengthSquared * diffDotEdge1;
    auto sqrDistance = Math::GetValue(0);

    if (s + t <= det)
    {
        if (s < Math::GetValue(0))
        {
            if (t < Math::GetValue(0))  // 区域 4
            {
                if (diffDotEdge0 < Math::GetValue(0))
                {
                    t = Math::GetValue(0);
                    if (edge0LengthSquared <= -diffDotEdge0)
                    {
                        s = Math::GetValue(1);
                        sqrDistance = edge0LengthSquared + (Math::GetValue(2)) * diffDotEdge0 + diffLengthSquared;
                    }
                    else
                    {
                        s = -diffDotEdge0 / edge0LengthSquared;
                        sqrDistance = diffDotEdge0 * s + diffLengthSquared;
                    }
                }
                else
                {
                    s = Math::GetValue(0);
                    if (Math::GetValue(0) <= diffDotEdge1)
                    {
                        t = Math::GetValue(0);
                        sqrDistance = diffLengthSquared;
                    }
                    else if (edge1LengthSquared <= -diffDotEdge1)
                    {
                        t = Math::GetValue(1);
                        sqrDistance = edge1LengthSquared + (Math::GetValue(2)) * diffDotEdge1 + diffLengthSquared;
                    }
                    else
                    {
                        t = -diffDotEdge1 / edge1LengthSquared;
                        sqrDistance = diffDotEdge1 * t + diffLengthSquared;
                    }
                }
            }
            else  // 区域 3
            {
                s = Math::GetValue(0);
                if (Math::GetValue(0) <= diffDotEdge1)
                {
                    t = Math::GetValue(0);
                    sqrDistance = diffLengthSquared;
                }
                else if (edge1LengthSquared <= -diffDotEdge1)
                {
                    t = Math::GetValue(1);
                    sqrDistance = edge1LengthSquared + (Math::GetValue(2)) * diffDotEdge1 + diffLengthSquared;
                }
                else
                {
                    t = -diffDotEdge1 / edge1LengthSquared;
                    sqrDistance = diffDotEdge1 * t + diffLengthSquared;
                }
            }
        }
        else if (t < Math::GetValue(0))  // 区域 5
        {
            t = Math::GetValue(0);
            if (diffDotEdge0 >= Math::GetValue(0))
            {
                s = Math::GetValue(0);
                sqrDistance = diffLengthSquared;
            }
            else if (edge0LengthSquared <= -diffDotEdge0)
            {
                s = Math::GetValue(1);
                sqrDistance = edge0LengthSquared + (Math::GetValue(2)) * diffDotEdge0 + diffLengthSquared;
            }
            else
            {
                s = -diffDotEdge0 / edge0LengthSquared;
                sqrDistance = diffDotEdge0 * s + diffLengthSquared;
            }
        }
        else  // 区域 0
        {
            // 内部点的最小值

            s /= det;
            t /= det;
            sqrDistance = s * (edge0LengthSquared * s + edge0DotEdge1 * t + (Math::GetValue(2)) * diffDotEdge0) + t * (edge0DotEdge1 * s + edge1LengthSquared * t + (Math::GetValue(2)) * diffDotEdge1) + diffLengthSquared;
        }
    }
    else
    {
        if (s < Math::GetValue(0))  // 区域 2
        {
            auto value0 = edge0DotEdge1 + diffDotEdge0;
            auto value1 = edge1LengthSquared + diffDotEdge1;
            if (value0 < value1)
            {
                auto numer = value1 - value0;
                auto denom = edge0LengthSquared - (Math::GetValue(2)) * edge0DotEdge1 + edge1LengthSquared;
                if (denom <= numer)
                {
                    s = Math::GetValue(1);
                    t = Math::GetValue(0);
                    sqrDistance = edge0LengthSquared + (Math::GetValue(2)) * diffDotEdge0 + diffLengthSquared;
                }
                else
                {
                    s = numer / denom;
                    t = Math::GetValue(1) - s;
                    sqrDistance = s * (edge0LengthSquared * s + edge0DotEdge1 * t + (Math::GetValue(2)) * diffDotEdge0) + t * (edge0DotEdge1 * s + edge1LengthSquared * t + (Math::GetValue(2)) * diffDotEdge1) + diffLengthSquared;
                }
            }
            else
            {
                s = Math::GetValue(0);
                if (value1 <= Math::GetValue(0))
                {
                    t = Math::GetValue(1);
                    sqrDistance = edge1LengthSquared + (Math::GetValue(2)) * diffDotEdge1 + diffLengthSquared;
                }
                else if (Math::GetValue(0) <= diffDotEdge1)
                {
                    t = Math::GetValue(0);
                    sqrDistance = diffLengthSquared;
                }
                else
                {
                    t = -diffDotEdge1 / edge1LengthSquared;
                    sqrDistance = diffDotEdge1 * t + diffLengthSquared;
                }
            }
        }
        else if (t < Math::GetValue(0))  // 区域 6
        {
            auto value0 = edge0DotEdge1 + diffDotEdge1;
            auto value1 = edge0LengthSquared + diffDotEdge0;
            if (value1 > value0)
            {
                auto numer = value1 - value0;
                auto denom = edge0LengthSquared - (Math::GetValue(2)) * edge0DotEdge1 + edge1LengthSquared;
                if (denom <= numer)
                {
                    t = Math::GetValue(1);
                    s = Math::GetValue(0);
                    sqrDistance = edge1LengthSquared + (Math::GetValue(2)) * diffDotEdge1 + diffLengthSquared;
                }
                else
                {
                    t = numer / denom;
                    s = Math::GetValue(1) - t;
                    sqrDistance = s * (edge0LengthSquared * s + edge0DotEdge1 * t + (Math::GetValue(2)) * diffDotEdge0) + t * (edge0DotEdge1 * s + edge1LengthSquared * t + (Math::GetValue(2)) * diffDotEdge1) + diffLengthSquared;
                }
            }
            else
            {
                t = Math::GetValue(0);
                if (value1 <= Math::GetValue(0))
                {
                    s = Math::GetValue(1);
                    sqrDistance = edge0LengthSquared + (Math::GetValue(2)) * diffDotEdge0 + diffLengthSquared;
                }
                else if (Math::GetValue(0) <= diffDotEdge0)
                {
                    s = Math::GetValue(0);
                    sqrDistance = diffLengthSquared;
                }
                else
                {
                    s = -diffDotEdge0 / edge0LengthSquared;
                    sqrDistance = diffDotEdge0 * s + diffLengthSquared;
                }
            }
        }
        else  // 区域 1
        {
            auto numer = edge1LengthSquared + diffDotEdge1 - edge0DotEdge1 - diffDotEdge0;
            if (numer <= Math::GetValue(0))
            {
                s = Math::GetValue(0);
                t = Math::GetValue(1);
                sqrDistance = edge1LengthSquared + (Math::GetValue(2)) * diffDotEdge1 + diffLengthSquared;
            }
            else
            {
                auto denom = edge0LengthSquared - (Math::GetValue(2)) * edge0DotEdge1 + edge1LengthSquared;
                if (denom <= numer)
                {
                    s = Math::GetValue(1);
                    t = Math::GetValue(0);
                    sqrDistance = edge0LengthSquared + (Math::GetValue(2)) * diffDotEdge0 + diffLengthSquared;
                }
                else
                {
                    s = numer / denom;
                    t = Math::GetValue(1) - s;
                    sqrDistance = s * (edge0LengthSquared * s + edge0DotEdge1 * t + (Math::GetValue(2)) * diffDotEdge0) + t * (edge0DotEdge1 * s + edge1LengthSquared * t + (Math::GetValue(2)) * diffDotEdge1) + diffLengthSquared;
                }
            }
        }
    }

    // 解决数字舍入误差。
    if (sqrDistance < Math::GetValue(0))
    {
        sqrDistance = Math::GetValue(0);
    }

    const auto closestPoint = triangle.GetVertex(0) + s * edge0 + t * edge1;

    triangleBary[1] = s;
    triangleBary[2] = t;
    triangleBary[0] = Math::GetValue(1) - s - t;

    return DistanceResult{ sqrDistance, Math::GetValue(0), point, closestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint3Triangle3<Real>::DistanceResult Mathematics::DistancePoint3Triangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedTriangle = triangle.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistancePoint3Triangle3<Real>::GetTriangleBary(int index) const
{
    return triangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_DETAIL_H