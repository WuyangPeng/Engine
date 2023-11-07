///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_ACHIEVE_H

#include "StaticTestIntersectorLine2Classify.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Classify<Real>::StaticTestIntersectorLine2Classify(const Vector2& lhsOrigin,
                                                                                          const Vector2& lhsDirection,
                                                                                          const Vector2& rhsOrigin,
                                                                                          const Vector2& rhsDirection,
                                                                                          bool isCalculateParameter,
                                                                                          const Real epsilon)
    : ParentType{ epsilon },
      parameter0{ Math::GetValue(0) },
      parameter1{ Math::GetValue(0) }
{
    Test(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection, isCalculateParameter);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Classify<Real>::Test(const Vector2& lhsOrigin, const Vector2& lhsDirection, const Vector2& rhsOrigin, const Vector2& rhsDirection, bool isCalculateParameter)
{
    auto dotThreshold = this->GetEpsilon();

    /// 两条线的交点是P0 + s0 * D0 = P1 + s1 * D1的解。
    /// 将其重写为s0 * D0 - s1 * D1 = P1 - P0 = Q。
    /// 如果D0.Dot(Perp(D1)) = 0，则这些线是平行的。
    /// 此外，如果Q.Dot(Perp(D1)) = 0，则行是相同的。
    /// 如果D0.Dot(Perp(D1))不为零，则s0 = Q.Dot(Perp(D1)) / D0.Dot(Perp(D1))产生交点。
    /// 同样，s1 = Q.Dot(Perp(D0)) / D0.Dot(Perp(D1))
    auto difference = rhsOrigin - lhsOrigin;
    auto lhsDirectionDotPerpRhsDirection = Vector2Tools::DotPerp(lhsDirection, rhsDirection);
    if (dotThreshold < Math::FAbs(lhsDirectionDotPerpRhsDirection))
    {
        // 线在单个点相交。
        if (isCalculateParameter)
        {
            auto differenceDotPerpLhsDirection = Vector2Tools::DotPerp(difference, lhsDirection);
            auto differenceDotPerpRhsDirection = Vector2Tools::DotPerp(difference, rhsDirection);
            parameter0 = differenceDotPerpRhsDirection / lhsDirectionDotPerpRhsDirection;
            parameter1 = differenceDotPerpLhsDirection / lhsDirectionDotPerpRhsDirection;
        }

        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // 线是平行的。
    if (difference.IsZero(dotThreshold))
    {
        // 线是共线的.
        this->SetIntersectionType(IntersectionType::Line);
        return;
    }

    difference.Normalize(dotThreshold);
    auto differenceDotPerpRhsDirection = Vector2Tools::DotPerp(difference, rhsDirection);
    if (Math::FAbs(differenceDotPerpRhsDirection) <= dotThreshold)
    {
        // 线是共线的.
        this->SetIntersectionType(IntersectionType::Line);
    }
    else
    {
        // 线是平行的，但是不相同。
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine2Classify<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::StaticTestIntersectorLine2Classify<Real>::GetParameter0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return parameter0;
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine2Classify<Real>::GetParameter1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return parameter1;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_ACHIEVE_H
