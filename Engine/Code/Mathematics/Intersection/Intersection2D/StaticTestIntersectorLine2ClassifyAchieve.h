///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/23 15:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_ACHIEVE_H

#include "StaticTestIntersectorLine2Classify.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Classify<Real>::StaticTestIntersectorLine2Classify(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin,
                                                                                          const Vector2D& rhsDirection, bool isCalculateParameter, const Real epsilon)
    : ParentType{ epsilon }, m_Parameter0{ Math::GetValue(0) }, m_Parameter1{ Math::GetValue(0) }
{
    Test(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection, isCalculateParameter);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine2Classify<Real>::Test(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection, bool isCalculateParameter)
{
    auto dotThreshold = this->GetEpsilon();

    /// �����ߵĽ�����P0 + s0 * D0 = P1 + s1 * D1�Ľ⡣
    /// ������дΪs0 * D0 - s1 * D1 = P1 - P0 = Q��
    /// ���D0.Dot(Perp(D1)) = 0������Щ����ƽ�еġ�
    /// ���⣬���Q.Dot(Perp(D1)) = 0����������ͬ�ġ�
    /// ���D0.Dot(Perp(D1))��Ϊ�㣬��s0 = Q.Dot(Perp(D1)) / D0.Dot(Perp(D1))�������㡣
    /// ͬ����s1 = Q.Dot(Perp(D0)) / D0.Dot(Perp(D1))
    auto difference = rhsOrigin - lhsOrigin;
    auto lhsDirectionDotPerpRhsDirection = Vector2DTools::DotPerp(lhsDirection, rhsDirection);
    if (dotThreshold < Math::FAbs(lhsDirectionDotPerpRhsDirection))
    {
        // ���ڵ������ཻ��
        if (isCalculateParameter)
        {
            auto differenceDotPerpLhsDirection = Vector2DTools::DotPerp(difference, lhsDirection);
            auto differenceDotPerpRhsDirection = Vector2DTools::DotPerp(difference, rhsDirection);
            m_Parameter0 = differenceDotPerpRhsDirection / lhsDirectionDotPerpRhsDirection;
            m_Parameter1 = differenceDotPerpLhsDirection / lhsDirectionDotPerpRhsDirection;
        }

        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    // ����ƽ�еġ�
    if (difference.IsZero(dotThreshold))
    {
        // ���ǹ��ߵ�.
        this->SetIntersectionType(IntersectionType::Line);
        return;
    }

    difference.Normalize(dotThreshold);
    auto differenceDotPerpRhsDirection = Vector2DTools::DotPerp(difference, rhsDirection);
    if (Math::FAbs(differenceDotPerpRhsDirection) <= dotThreshold)
    {
        // ���ǹ��ߵ�.
        this->SetIntersectionType(IntersectionType::Line);
    }
    else
    {
        // ����ƽ�еģ����ǲ���ͬ��
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

    return m_Parameter0;
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine2Classify<Real>::GetParameter1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Parameter1;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_ACHIEVE_H