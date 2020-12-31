///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/21 18:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_ACHIEVE_H

#include "StaticFindIntersectorLine2Line2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Line2<Real>::StaticFindIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_LhsLine{ lhsLine }, m_RhsLine{ rhsLine }, m_Quantity{ 0 }, m_Point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine2Line2<Real>::Find()
{
    StaticTestIntersectorLine2Classify<Real> classify{ m_LhsLine.GetOrigin(), m_LhsLine.GetDirection(), m_RhsLine.GetOrigin(), m_RhsLine.GetDirection(), true, this->GetEpsilon() };

    const auto intersectionType = classify.GetIntersectionType();
    this->SetIntersectionType(intersectionType);

    switch (intersectionType)
    {
        case IntersectionType::Empty:
        {
            m_Quantity = 0;
            break;
        }
        case IntersectionType::Point:
        {
            m_Quantity = 1;
            m_Point = m_LhsLine.GetOrigin() + classify.GetParameter0() * m_LhsLine.GetDirection();
            break;
        }
        case IntersectionType::Line:
        {
            m_Quantity = std::numeric_limits<int>::max();
            break;
        }
        default:
            MATHEMATICS_ASSERTION_3(false, "�ཻ���ͼ������\n");
            break;
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Line2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Line2<Real>::GetLhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsLine;
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Line2<Real>::GetRhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsLine;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Line2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorLine2Line2<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (m_Quantity == 1)
    {
        return m_Point;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("������Ψһ�Ľ��㡣\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_ACHIEVE_H
