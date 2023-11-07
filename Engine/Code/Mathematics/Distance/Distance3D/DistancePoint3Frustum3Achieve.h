///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:33)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_FRUSTUM3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_FRUSTUM3_ACHIEVE_H

#include "DistancePoint3Frustum3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Frustum3<Real>::DistancePoint3Frustum3(const Vector3& point, const Frustum3& frustum) noexcept
    : ParentType{}, point{ point }, frustum{ frustum }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Frustum3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Frustum3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Frustum3<Real> Mathematics::DistancePoint3Frustum3<Real>::GetFrustum() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return frustum;
}

template <typename Real>
typename Mathematics::DistancePoint3Frustum3<Real>::DistanceResult Mathematics::DistancePoint3Frustum3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 计算相对于视锥坐标系的点的坐标。
    auto diff = point - frustum.GetOrigin();
    Vector3 test{ Vector3Tools::DotProduct(diff, frustum.GetRightVector()),
                  Vector3Tools::DotProduct(diff, frustum.GetUpVector()),
                  Vector3Tools::DotProduct(diff, frustum.GetDirectionVector()) };

    // 在具有非负Real和U坐标的八分圆中执行计算。
    auto rSignChange = false;
    if (test.GetX() < Math::GetValue(0))
    {
        rSignChange = true;
        test.SetX(-test.GetX());
    }
    else
    {
        rSignChange = false;
    }

    auto uSignChange = false;
    if (test.GetY() < Math::GetValue(0))
    {
        uSignChange = true;
        test.SetY(-test.GetY());
    }
    else
    {
        uSignChange = false;
    }

    // 视锥导出参数。
    const auto rightMin = frustum.GetRightBound();
    const auto rightMax = frustum.GetDirectionRatio() * rightMin;
    const auto upMin = frustum.GetUpBound();
    const auto upMax = frustum.GetDirectionRatio() * upMin;
    const auto directionMin = frustum.GetDirectionMin();
    const auto directionMax = frustum.GetDirectionMax();
    const auto rightMinSqr = rightMin * rightMin;
    const auto upMinSqr = upMin * upMin;
    const auto directionMinSqr = directionMin * directionMin;

    const auto minRightDirectionDot = rightMinSqr + directionMinSqr;
    const auto minUpDirectionDot = upMinSqr + directionMinSqr;
    const auto minRightUpDirectionDot = rightMinSqr + minUpDirectionDot;
    const auto maxRightDirectionDot = frustum.GetDirectionRatio() * minRightDirectionDot;
    const auto maxUpDirectionDot = frustum.GetDirectionRatio() * minUpDirectionDot;
    const auto maxRightUpDirectionDot = frustum.GetDirectionRatio() * minRightUpDirectionDot;

    /// 在所有情况下，算法都会通过确定测试点所在的圆锥体的顶点，边缘和面的哪个Voronoi区域来计算最接近的点。
    Vector3 closest{};

    if (directionMax <= test.GetZ())
    {
        if (test.GetX() <= rightMax)
        {
            if (test.GetY() <= upMax)
            {
                // F-face
                closest.SetX(test.GetX());
                closest.SetY(test.GetY());
                closest.SetZ(directionMax);
            }
            else
            {
                // UF-edge
                closest.SetX(test.GetX());
                closest.SetY(upMax);
                closest.SetZ(directionMax);
            }
        }
        else
        {
            if (test.GetY() <= upMax)
            {
                // LF-edge
                closest.SetX(rightMax);
                closest.SetY(test.GetY());
                closest.SetZ(directionMax);
            }
            else
            {
                // LUF-vertex
                closest.SetX(rightMax);
                closest.SetY(upMax);
                closest.SetZ(directionMax);
            }
        }
    }
    else if (test.GetZ() <= directionMin)
    {
        if (test.GetX() <= rightMin)
        {
            if (test.GetY() <= upMin)
            {
                // N-face
                closest.SetX(test.GetX());
                closest.SetY(test.GetY());
                closest.SetZ(directionMin);
            }
            else
            {
                auto upDirectionDot = upMin * test.GetY() + directionMin * test.GetZ();
                if (maxUpDirectionDot <= upDirectionDot)
                {
                    // UF-edge
                    closest.SetX(test.GetX());
                    closest.SetY(upMax);
                    closest.SetZ(directionMax);
                }
                else if (upDirectionDot >= minUpDirectionDot)
                {
                    // U-face
                    auto upDot = directionMin * test.GetY() - upMin * test.GetZ();
                    auto t = upDot / minUpDirectionDot;
                    closest.SetX(test.GetX());
                    closest.SetY(test.GetY() - t * directionMin);
                    closest.SetZ(test.GetZ() + t * upMin);
                }
                else
                {
                    // UN-edge
                    closest.SetX(test.GetX());
                    closest.SetY(upMin);
                    closest.SetZ(directionMin);
                }
            }
        }
        else
        {
            if (test.GetY() <= upMin)
            {
                auto rightDirectionDot = rightMin * test.GetX() + directionMin * test.GetZ();
                if (maxRightDirectionDot <= rightDirectionDot)
                {
                    // LF-edge
                    closest.SetX(rightMax);
                    closest.SetY(test.GetY());
                    closest.SetZ(directionMax);
                }
                else if (minRightDirectionDot <= rightDirectionDot)
                {
                    // L-face
                    auto rightDot = directionMin * test.GetX() - rightMin * test.GetZ();
                    auto t = rightDot / minRightDirectionDot;
                    closest.SetX(test.GetX() - t * directionMin);
                    closest.SetY(test.GetY());
                    closest.SetZ(test.GetZ() + t * rightMin);
                }
                else
                {
                    // LN-edge
                    closest.SetX(rightMin);
                    closest.SetY(test.GetY());
                    closest.SetZ(directionMin);
                }
            }
            else
            {
                auto rightUpDirectionDot = rightMin * test.GetX() + upMin * test.GetY() + directionMin * test.GetZ();
                auto rightEdgeDot = upMin * rightUpDirectionDot - minRightUpDirectionDot * test.GetY();
                if (Math::GetValue(0) <= rightEdgeDot)
                {
                    auto rightDirectionDot = rightMin * test.GetX() + directionMin * test.GetZ();
                    if (maxRightDirectionDot <= rightDirectionDot)
                    {
                        // LF-edge
                        closest.SetX(rightMax);
                        closest.SetY(test.GetY());
                        closest.SetZ(directionMax);
                    }
                    else if (minRightDirectionDot <= rightDirectionDot)
                    {
                        // L-face
                        auto rightDot = directionMin * test.GetX() - rightMin * test.GetZ();
                        auto t = rightDot / minRightDirectionDot;
                        closest.SetX(test.GetX() - t * directionMin);
                        closest.SetY(test.GetY());
                        closest.SetZ(test.GetZ() + t * rightMin);
                    }
                    else
                    {
                        // LN-edge
                        closest.SetX(rightMin);
                        closest.SetY(test.GetY());
                        closest.SetZ(directionMin);
                    }
                }
                else
                {
                    auto upEdgeDot = rightMin * rightUpDirectionDot - minRightUpDirectionDot * test.GetX();
                    if (Math::GetValue(0) <= upEdgeDot)
                    {
                        auto upDirectionDot = upMin * test.GetY() + directionMin * test.GetZ();
                        if (maxUpDirectionDot <= upDirectionDot)
                        {
                            // UF-edge
                            closest.SetX(test.GetX());
                            closest.SetY(upMax);
                            closest.SetZ(directionMax);
                        }
                        else if (minUpDirectionDot <= upDirectionDot)
                        {
                            // U-face
                            auto upDot = directionMin * test.GetY() - upMin * test.GetZ();
                            auto t = upDot / minUpDirectionDot;
                            closest.SetX(test.GetX());
                            closest.SetY(test.GetY() - t * directionMin);
                            closest.SetZ(test.GetZ() + t * upMin);
                        }
                        else
                        {
                            // UN-edge
                            closest.SetX(test.GetX());
                            closest.SetY(upMin);
                            closest.SetZ(directionMin);
                        }
                    }
                    else
                    {
                        if (maxRightUpDirectionDot <= rightUpDirectionDot)
                        {
                            // LUF-vertex
                            closest.SetX(rightMax);
                            closest.SetY(upMax);
                            closest.SetZ(directionMax);
                        }
                        else if (minRightUpDirectionDot <= rightUpDirectionDot)
                        {
                            // LU-edge
                            auto t = rightUpDirectionDot / minRightUpDirectionDot;
                            closest.SetX(t * rightMin);
                            closest.SetY(t * upMin);
                            closest.SetZ(t * directionMin);
                        }
                        else
                        {
                            // LUN-vertex
                            closest.SetX(rightMin);
                            closest.SetY(upMin);
                            closest.SetZ(directionMin);
                        }
                    }
                }
            }
        }
    }
    else
    {
        auto rightDot = directionMin * test.GetX() - rightMin * test.GetZ();
        auto upDot = directionMin * test.GetY() - upMin * test.GetZ();
        if (rightDot <= Math::GetValue(0))
        {
            if (upDot <= Math::GetValue(0))
            {
                // 指向内部视锥
                closest = test;
            }
            else
            {
                auto upDirectionDot = upMin * test.GetY() + directionMin * test.GetZ();
                if (maxUpDirectionDot <= upDirectionDot)
                {
                    // UF-edge
                    closest.SetX(test.GetX());
                    closest.SetY(upMax);
                    closest.SetZ(directionMax);
                }
                else
                {
                    // U-face
                    auto t = upDot / minUpDirectionDot;
                    closest.SetX(test.GetX());
                    closest.SetY(test.GetY() - t * directionMin);
                    closest.SetZ(test.GetZ() + t * upMin);
                }
            }
        }
        else
        {
            if (upDot <= Math::GetValue(0))
            {
                auto rightDirectionDot = rightMin * test.GetX() + directionMin * test.GetZ();
                if (maxRightDirectionDot <= rightDirectionDot)
                {
                    // LF-edge
                    closest.SetX(rightMax);
                    closest.SetY(test.GetY());
                    closest.SetZ(directionMax);
                }
                else
                {
                    // L-face
                    auto t = rightDot / minRightDirectionDot;
                    closest.SetX(test.GetX() - t * directionMin);
                    closest.SetY(test.GetY());
                    closest.SetZ(test.GetZ() + t * rightMin);
                }
            }
            else
            {
                auto rightUpDirectionDot = rightMin * test.GetX() + upMin * test.GetY() + directionMin * test.GetZ();
                auto rightEdgeDot = upMin * rightUpDirectionDot - minRightUpDirectionDot * test.GetY();
                if (Math::GetValue(0) <= rightEdgeDot)
                {
                    auto rightDirectionDot = rightMin * test.GetX() + directionMin * test.GetZ();
                    if (maxRightDirectionDot <= rightDirectionDot)
                    {
                        // LF-edge
                        closest.SetX(rightMax);
                        closest.SetY(test.GetY());
                        closest.SetZ(directionMax);
                    }
                    else  // assert( rdDot >= minRDDot ) 从几何断言
                    {
                        // L-face
                        auto t = rightDot / minRightDirectionDot;
                        closest.SetX(test.GetX() - t * directionMin);
                        closest.SetY(test.GetY());
                        closest.SetZ(test.GetZ() + t * rightMin);
                    }
                }
                else
                {
                    auto upEdgeDot = rightMin * rightUpDirectionDot - minRightUpDirectionDot * test.GetX();
                    if (Math::GetValue(0) <= upEdgeDot)
                    {
                        auto upDirectionDot = upMin * test.GetY() + directionMin * test.GetZ();
                        if (maxUpDirectionDot <= upDirectionDot)
                        {
                            // UF-edge
                            closest.SetX(test.GetX());
                            closest.SetY(upMax);
                            closest.SetZ(directionMax);
                        }
                        else  // assert( udDot >= minUDDot ) 从几何断言
                        {
                            // U-face
                            auto t = upDot / minUpDirectionDot;
                            closest.SetX(test.GetX());
                            closest.SetY(test.GetY() - t * directionMin);
                            closest.SetZ(test.GetZ() + t * upMin);
                        }
                    }
                    else
                    {
                        if (maxRightUpDirectionDot <= rightUpDirectionDot)
                        {
                            // LUF-vertex
                            closest.SetX(rightMax);
                            closest.SetY(upMax);
                            closest.SetZ(directionMax);
                        }
                        else  // assert( rudDot >= minRUDDot ) 从几何断言
                        {
                            // LU-edge
                            auto t = rightUpDirectionDot / minRightUpDirectionDot;
                            closest.SetX(t * rightMin);
                            closest.SetY(t * upMin);
                            closest.SetZ(t * directionMin);
                        }
                    }
                }
            }
        }
    }

    diff = test - closest;

    // 转换回原始象限。
    if (rSignChange)
    {
        closest.SetX(-closest.GetX());
    }

    if (uSignChange)
    {
        closest.SetY(-closest.GetY());
    }

    // 转换回原始坐标。
    const auto closestPoint = frustum.GetOrigin() +
                              closest.GetX() * frustum.GetRightVector() +
                              closest.GetY() * frustum.GetUpVector() +
                              closest.GetZ() * frustum.GetDirectionVector();

    return DistanceResult{ Vector3Tools::GetLengthSquared(diff), Math::GetValue(0), point, closestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint3Frustum3<Real>::DistanceResult Mathematics::DistancePoint3Frustum3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedPoint = point.GetMove(t, lhsVelocity);
    const auto movedEllipsoid = frustum.GetMove(t, rhsVelocity);

    ClassType distance{ movedPoint, movedEllipsoid };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_FRUSTUM3_ACHIEVE_H