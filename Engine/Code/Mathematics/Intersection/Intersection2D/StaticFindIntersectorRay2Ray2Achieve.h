///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_ACHIEVE_H

#include "StaticFindIntersectorRay2Ray2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Ray2<Real>::StaticFindIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold)
    : ParentType{ dotThreshold }, lhsRay{ lhsRay }, rhsRay{ rhsRay }, quantity{ 0 }, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorRay2Ray2<Real>::Find()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ lhsRay.GetOrigin(), lhsRay.GetDirection(), rhsRay.GetOrigin(), rhsRay.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // ����ֱ�߽����Ƿ��������ϡ�
        if (Math::GetValue(0) <= classify.GetParameter0() && Math::GetValue(0) <= classify.GetParameter1())
        {
            quantity = 1;
            intersectionType = IntersectionType::Point;
            point0 = lhsRay.GetOrigin() + classify.GetParameter0() * lhsRay.GetDirection();
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        auto dotProduct = Vector2Tools::DotProduct(lhsRay.GetDirection(), rhsRay.GetOrigin() - lhsRay.GetOrigin());

        if (Math::GetValue(0) < Vector2Tools::DotProduct(lhsRay.GetDirection(), rhsRay.GetDirection()))
        {
            // �����ǹ��ߵĲ�������ͬ�ķ����������Ǳ������ص��ġ�
            quantity = std::numeric_limits<int>::max();
            intersectionType = IntersectionType::Ray;
            point0 = (Math::GetValue(0) < dotProduct ? rhsRay.GetOrigin() : lhsRay.GetOrigin());
        }
        else
        {
            // �����ǹ��ߵģ��ҷ����෴�� ���������Ƿ��ص���
            // lhsRay���м��[0��+����󣩣�
            // rhsRay���������ray0����ļ����-infinity��dotProduct] ��
            if (dotThreshold < dotProduct)
            {
                quantity = 2;
                intersectionType = IntersectionType::Segment;
                point0 = lhsRay.GetOrigin();
                point1 = rhsRay.GetOrigin();
            }
            else if (dotProduct < -dotThreshold)
            {
                quantity = 0;
                intersectionType = IntersectionType::Empty;
            }
            else  // dotProduct == 0
            {
                quantity = 1;
                intersectionType = IntersectionType::Point;
                point0 = lhsRay.GetOrigin();
            }
        }
    }
    else
    {
        quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    this->SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsRay;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsRay;
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorRay2Ray2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index == 0)
    {
        return point0;
    }
    else if (index == 1)
    {
        return point1;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Խ��"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
