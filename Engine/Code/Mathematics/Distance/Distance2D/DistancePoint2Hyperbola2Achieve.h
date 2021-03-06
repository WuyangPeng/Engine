///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 15:13)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H

#include "DistancePoint2Hyperbola2.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Hyperbola2<Real>::DistancePoint2Hyperbola2(const Vector2D& point, const Vector2D& extent) noexcept
    : ParentType{}, m_Point{ point }, m_Extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Hyperbola2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && Math::GetValue(0) < m_Extent.GetX() && Math::GetValue(0) < m_Extent.GetY())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::DistancePoint2Hyperbola2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::DistancePoint2Hyperbola2<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent;
}

template <typename Real>
const typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector2D extentSquared{ m_Extent.GetX() * m_Extent.GetX(), m_Extent.GetY() * m_Extent.GetY() };
    const Vector2D reciprocalExtentSquared{ Math::GetValue(1) / extentSquared[0], Math::GetValue(1) / extentSquared[1] };

    // 初始化二分法。 与H(-a^2)= +无穷大和H(b^2)= -infinity不相关，
    // 因此我们只需要用相应的有符号数字初始化函数值。
    auto t0 = -extentSquared.GetX();
    auto t1 = extentSquared.GetY();
    auto tRoot = Math::GetRational(1, 2) * (t0 + t1);
    auto hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

    // 迭代直到 H(troot)正好为零或直到一个浮点端点不再改变。
    // 后一条件利用IEEE浮点数的性质，因此循环必须以有限数量的步骤终止。
    const auto maximumIterations = this->GetMaximumIterations();
    for (auto loop = 0; loop < maximumIterations; ++loop)
    {
        if (!Math::Approximate(hyperbolaRoot, Math::GetValue(0), this->GetZeroThreshold()) &&
            !Math::Approximate(tRoot, t0, this->GetZeroThreshold()) &&
            !Math::Approximate(tRoot, t1, this->GetZeroThreshold()))
        {
            break;
        }

        if (Math::GetValue(0) < hyperbolaRoot)
        {
            t0 = tRoot;
            tRoot = Math::GetRational(1, 2) * (t0 + t1);
        }
        else  // hyperbolaRoot < Math<Real>::sm_Zero
        {
            t1 = tRoot;
        }

        tRoot = Math::GetRational(1, 2) * (t0 + t1);
        hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

        if (loop + 1 == maximumIterations)
        {
            MATHEMATICS_ASSERTION_2(false, "未能迭代所需次数内收敛");
        }
    }

    const Vector2D closest{ m_Point.GetX() / (Math::GetValue(1) + tRoot * reciprocalExtentSquared.GetX()),
                            m_Point.GetY() / (Math::GetValue(1) - tRoot * reciprocalExtentSquared.GetY()) };

    auto diff = m_Point - closest;

    return DistanceResult{ Vector2DTools::VectorMagnitudeSquared(diff), Math::GetValue(0), m_Point, closest };
}

// private
template <typename Real>
Real Mathematics::DistancePoint2Hyperbola2<Real>::GetHyperbola(Real t, const Vector2D& reciprocalExtentSquared) const
{
    auto ratio0 = m_Point.GetX() / (Math::GetValue(1) + t * reciprocalExtentSquared[0]);
    auto ratio1 = m_Point.GetY() / (Math::GetValue(1) - t * reciprocalExtentSquared[1]);

    return ratio0 * ratio0 - ratio1 * ratio1 - Math::GetValue(1);
}

template <typename Real>
const typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, [[maybe_unused]] const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);

    ClassType distance{ movePoint, m_Extent };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H
