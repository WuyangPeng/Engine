///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H

#include "DistancePoint2Hyperbola2.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Hyperbola2<Real>::DistancePoint2Hyperbola2(const Vector2Type& point, const Vector2Type& extent) noexcept
    : ParentType{}, point{ point }, extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Hyperbola2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && MathType::GetValue(0) < extent.GetX() && MathType::GetValue(0) < extent.GetY())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Hyperbola2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Hyperbola2<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent;
}

template <typename Real>
typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector2Type extentSquared{ extent.GetX() * extent.GetX(), extent.GetY() * extent.GetY() };
    const Vector2Type reciprocalExtentSquared{ MathType::GetValue(1) / extentSquared[0], MathType::GetValue(1) / extentSquared[1] };

    // 初始化二分法。 与H(-a^2)= +无穷大和H(b^2)= -infinity不相关，
    // 因此我们只需要用相应的有符号数字初始化函数值。
    auto t0 = -extentSquared.GetX();
    auto t1 = extentSquared.GetY();
    auto tRoot = MathType::GetRational(1, 2) * (t0 + t1);
    auto hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

    // 迭代直到 H(troot)正好为零或直到一个浮点端点不再改变。
    // 后一条件利用IEEE浮点数的性质，因此循环必须以有限数量的步骤终止。
    const auto maximumIterations = this->GetMaximumIterations();
    for (auto loop = 0; loop < maximumIterations; ++loop)
    {
        if (!MathType::Approximate(hyperbolaRoot, MathType::GetValue(0), this->GetZeroThreshold()) &&
            !MathType::Approximate(tRoot, t0, this->GetZeroThreshold()) &&
            !MathType::Approximate(tRoot, t1, this->GetZeroThreshold()))
        {
            break;
        }

        if (MathType::GetValue(0) < hyperbolaRoot)
        {
            t0 = tRoot;
            tRoot = MathType::GetRational(1, 2) * (t0 + t1);
        }
        else  // hyperbolaRoot < MathType<Real>::sm_Zero
        {
            t1 = tRoot;
        }

        tRoot = MathType::GetRational(1, 2) * (t0 + t1);
        hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

        if (loop + 1 == maximumIterations)
        {
            MATHEMATICS_ASSERTION_2(false, "未能迭代所需次数内收敛");
        }
    }

    const Vector2Type closest{ point.GetX() / (MathType::GetValue(1) + tRoot * reciprocalExtentSquared.GetX()),
                           point.GetY() / (MathType::GetValue(1) - tRoot * reciprocalExtentSquared.GetY()) };

    const auto diff = point - closest;

    return DistanceResult{ Vector2ToolsType::GetLengthSquared(diff), MathType::GetValue(0), point, closest };
}

template <typename Real>
Real Mathematics::DistancePoint2Hyperbola2<Real>::GetHyperbola(Real t, const Vector2Type& reciprocalExtentSquared) const
{
    const auto ratio0 = point.GetX() / (MathType::GetValue(1) + t * reciprocalExtentSquared[0]);
    const auto ratio1 = point.GetY() / (MathType::GetValue(1) - t * reciprocalExtentSquared[1]);

    return ratio0 * ratio0 - ratio1 * ratio1 - MathType::GetValue(1);
}

template <typename Real>
typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, [[maybe_unused]] const Vector2Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);

    ClassType distance{ movePoint, extent };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H
