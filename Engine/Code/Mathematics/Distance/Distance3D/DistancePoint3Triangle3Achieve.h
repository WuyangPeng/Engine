///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/14 18:32)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_ACHIEVE_H

#include "DistancePoint3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Triangle3<Real>::DistancePoint3Triangle3(const Vector3D& point, const Triangle3& triangle) noexcept
    : ParentType{}, m_Point{ point }, m_Triangle{ triangle }, m_TriangleBary{}
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
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Triangle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DistancePoint3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
typename const Mathematics::DistancePoint3Triangle3<Real>::DistanceResult Mathematics::DistancePoint3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = m_Triangle.GetVertex(0) - m_Point;
    auto edge0 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);
    auto edge0LengthSquared = Vector3DTools::VectorMagnitudeSquared(edge0);
    auto edge0DotEdge1 = Vector3DTools::DotProduct(edge0, edge1);
    auto edge1LengthSquared = Vector3DTools::VectorMagnitudeSquared(edge1);
    auto diffDotEdge0 = Vector3DTools::DotProduct(diff, edge0);
    auto diffDotEdge1 = Vector3DTools::DotProduct(diff, edge1);
    auto diffLengthSquared = Vector3DTools::VectorMagnitudeSquared(diff);
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

    const auto closestPoint = m_Triangle.GetVertex(0) + s * edge0 + t * edge1;

    m_TriangleBary[1] = s;
    m_TriangleBary[2] = t;
    m_TriangleBary[0] = Math::GetValue(1) - s - t;

    return DistanceResult{ sqrDistance, Math::GetValue(0), m_Point, closestPoint };
}

template <typename Real>
typename const Mathematics::DistancePoint3Triangle3<Real>::DistanceResult Mathematics::DistancePoint3Triangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedTriangle = m_Triangle.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistancePoint3Triangle3<Real>::GetTriangleBary(int index) const
{
    return m_TriangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_ACHIEVE_H