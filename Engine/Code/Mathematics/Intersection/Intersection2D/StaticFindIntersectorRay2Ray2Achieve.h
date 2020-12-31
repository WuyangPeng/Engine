///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/22 16:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_ACHIEVE_H

#include "StaticFindIntersectorRay2Ray2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Ray2<Real>::StaticFindIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_LhsRay{ lhsRay }, m_RhsRay{ rhsRay }, m_Quantity{ 0 }, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorRay2Ray2<Real>::Find()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ m_LhsRay.GetOrigin(), m_LhsRay.GetDirection(), m_RhsRay.GetOrigin(), m_RhsRay.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // ����ֱ�߽����Ƿ��������ϡ�
        if (Math::GetValue(0) <= classify.GetParameter0() && Math::GetValue(0) <= classify.GetParameter1())
        {
            m_Quantity = 1;
            intersectionType = IntersectionType::Point;
            m_Point0 = m_LhsRay.GetOrigin() + classify.GetParameter0() * m_LhsRay.GetDirection();
        }
        else
        {
            m_Quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        auto dotProduct = Vector2DTools::DotProduct(m_LhsRay.GetDirection(), m_RhsRay.GetOrigin() - m_LhsRay.GetOrigin());

        if (Math::GetValue(0) < Vector2DTools::DotProduct(m_LhsRay.GetDirection(), m_RhsRay.GetDirection()))
        {
            // �����ǹ��ߵĲ�������ͬ�ķ����������Ǳ������ص��ġ�
            m_Quantity = std::numeric_limits<int>::max();
            intersectionType = IntersectionType::Ray;
            m_Point0 = (Math::GetValue(0) < dotProduct ? m_RhsRay.GetOrigin() : m_LhsRay.GetOrigin());
        }
        else
        {
            // �����ǹ��ߵģ��ҷ����෴�� ���������Ƿ��ص���
            // m_LhsRay���м��[0��+����󣩣�
            // m_RhsRay���������ray0����ļ����-infinity��dotProduct] ��
            if (dotThreshold < dotProduct)
            {
                m_Quantity = 2;
                intersectionType = IntersectionType::Segment;
                m_Point0 = m_LhsRay.GetOrigin();
                m_Point1 = m_RhsRay.GetOrigin();
            }
            else if (dotProduct < -dotThreshold)
            {
                m_Quantity = 0;
                intersectionType = IntersectionType::Empty;
            }
            else  // dotProduct == 0
            {
                m_Quantity = 1;
                intersectionType = IntersectionType::Point;
                m_Point0 = m_LhsRay.GetOrigin();
            }
        }
    }
    else
    {
        m_Quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    ParentType::SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsRay;
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsRay;
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index == 0)
    {
        return m_Point0;
    }
    else if (index == 1)
    {
        return m_Point1;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Խ��"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
