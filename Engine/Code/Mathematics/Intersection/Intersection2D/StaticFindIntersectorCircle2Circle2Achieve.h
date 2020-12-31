///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 16:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorCircle2Circle2.h"
#include "Detail/StaticFindIntersectorCircle2Circle2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorCircle2Circle2<Real>::StaticFindIntersectorCircle2Circle2(const Circle2& lhsCircle, const Circle2& rhsCircle, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(lhsCircle, rhsCircle) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorCircle2Circle2<Real>::Find()
{
    const auto lhsCircle = GetLhsCircle();
    const auto rhsCircle = GetRhsCircle();

    // 两个圆是|X - C0| = R0和|X - C1| = R1。
    // 定义U = C1 - C0和V = Perp(U)其中PerpPerp(x,y) = (y,-x)。
    // 注意Dot(U,V) = 0和|V|^2 = |U|^2。
    // 交叉点X可以是X = C0 + s * U + t * V和X = C1 + (s - 1) * U + t * V的形式写入。
    // 对圆方程进行平方，并将这些公式代入
    //   R0^2 = (s^2 + t^2)*|U|^2
    //   R1^2 = ((s-1)^2 + t^2) * |U|^2.
    // 相减和求解s的值
    //   s = ((R0^2-R1^2)/|U|^2 + 1)/2
    // 然后在第一个方程中替换并求解t^2
    //   t^2 = (R0^2/|U|^2) - s^2.
    // 为了有解，右侧必须是非负的。 一些代数导致解的存在的条件，
    //   (|U|^2 - (R0+R1)^2)*(|U|^2 - (R0-R1)^2) <= 0.
    // 这减少到
    //   |R0-R1| <= |U| <= |R0+R1|.
    // 如果 |U| = |R0 - R1|, 那么这些圆是并排的并且恰好相切。
    // 如果 |U| = |R0 + R1|, 那么圆是嵌套的，并且恰好相切。
    // 如果 |R0-R1| < |U| < |R0+R1|，那么两个圆相交有两个交点

    auto centerDifference = rhsCircle.GetCenter() - lhsCircle.GetCenter();
    auto centerDifferenceSquaredLength = Vector2DTools::VectorMagnitudeSquared(centerDifference);
    auto lhsRadius = lhsCircle.GetRadius();
    auto rhsRadius = rhsCircle.GetRadius();
    auto lhsAdiusMinusRhsAdius = lhsRadius - rhsRadius;
    auto epsilon = ParentType::GetEpsilon();
    if (centerDifferenceSquaredLength < epsilon && Math::FAbs(lhsAdiusMinusRhsAdius) < epsilon)
    {
        // 圆基本相同。
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    auto lhsAdiusMinusRhsAdiusSquared = lhsAdiusMinusRhsAdius * lhsAdiusMinusRhsAdius;
    if (centerDifferenceSquaredLength + epsilon < lhsAdiusMinusRhsAdiusSquared)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto lhsRadiusPlusRhsRadius = lhsRadius + rhsRadius;
    auto lhsRadiusPlusRhsRadiusSquared = lhsRadiusPlusRhsRadius * lhsRadiusPlusRhsRadius;
    if (lhsRadiusPlusRhsRadiusSquared + epsilon < centerDifferenceSquaredLength)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (centerDifferenceSquaredLength + epsilon < lhsRadiusPlusRhsRadiusSquared)
    {
        if (lhsAdiusMinusRhsAdiusSquared + epsilon < centerDifferenceSquaredLength)
        {
            auto ordinal = Math::GetRational(1, 2) * ((lhsRadius * lhsRadius - rhsRadius * rhsRadius) / centerDifferenceSquaredLength + Math::GetValue(1));
            auto amendmentCenter = lhsCircle.GetCenter() + ordinal * centerDifference;

            // 理论上，discriminant是非负的。
            // 然而，数值四舍五入误差可能使其略负。将其截断为零。
            auto discriminant = lhsRadius * lhsRadius / centerDifferenceSquaredLength - ordinal * ordinal;
            if (discriminant < Math::GetValue(0))
            {
                discriminant = Math::GetValue(0);
            }
            auto discriminantSqrt = Math::Sqrt(discriminant);
            const auto perp = Vector2DTools::GetPerp(centerDifference);

            auto lhsPoint = amendmentCenter - discriminantSqrt * perp;
            auto rhsPoint = amendmentCenter + discriminantSqrt * perp;

            if (Vector2DTools::Approximate(lhsPoint, rhsPoint, epsilon))
            {
                m_Impl->AddIntersection((lhsPoint + rhsPoint) / Math::GetValue(2));
            }
            else
            {
                m_Impl->AddIntersection(lhsPoint);
                m_Impl->AddIntersection(rhsPoint);
            }
        }
        else
        {
            // |U| = |R0 - R1|,圆是相切的。
            auto point = lhsCircle.GetCenter() + (lhsRadius / lhsAdiusMinusRhsAdius) * centerDifference;
            m_Impl->AddIntersection(point);
        }
    }
    else
    {
        // |U| = |R0 + R1|, 圆是相切的。
        auto point = lhsCircle.GetCenter() + (lhsRadius / lhsRadiusPlusRhsRadius) * centerDifference;
        m_Impl->AddIntersection(point);
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorCircle2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetLhsCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsCircle();
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetRhsCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsCircle();
}

template <typename Real>
int Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetIntersectionCircle() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (this->GetIntersectionType() == IntersectionType::Other)
    {
        return m_Impl->GetIntersectionCircle();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("要查询的圆并不是重叠的。\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_ACHIEVE_H
