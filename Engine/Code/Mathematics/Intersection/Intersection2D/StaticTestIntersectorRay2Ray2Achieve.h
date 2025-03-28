///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_ACHIEVE_H

#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "StaticTestIntersectorRay2Ray2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Ray2<Real>::StaticTestIntersectorRay2Ray2(const Ray2Type& lhsRay, const Ray2Type& rhsRay, const Real dotThreshold)
    : ParentType{ dotThreshold }, lhsRay{ lhsRay }, rhsRay{ rhsRay }, quantity{ 0 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Ray2<Real>::Test()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ lhsRay.GetOrigin(), lhsRay.GetDirection(), rhsRay.GetOrigin(), rhsRay.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // ����ֱ�߽����Ƿ��������ϡ�
        if (MathType::GetValue(0) <= classify.GetParameter0() && MathType::GetValue(0) <= classify.GetParameter1())
        {
            quantity = 1;
            intersectionType = IntersectionType::Point;
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        if (MathType::GetValue(0) < Vector2ToolsType::DotProduct(lhsRay.GetDirection(), rhsRay.GetDirection()))
        {
            // �����ǹ��ߵĲ�������ͬ�ķ����������Ǳ������ص��ġ�
            quantity = std::numeric_limits<int>::max();
            intersectionType = IntersectionType::Ray;
        }
        else
        {
            // �����ǹ��ߵģ��ҷ����෴�� ���������Ƿ��ص���
            // lhsRay���м��[0��+����󣩣�
            // rhsRay���������ray0����ļ����-infinity��dotProduct] ��
            auto dotProduct = Vector2ToolsType::DotProduct(lhsRay.GetDirection(), rhsRay.GetOrigin() - lhsRay.GetOrigin());
            if (dotThreshold < dotProduct)
            {
                quantity = 2;
                intersectionType = IntersectionType::Segment;
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
            }
        }
    }
    else
    {
        quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    ParentType::SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Ray2<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsRay;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Ray2<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsRay;
}

template <typename Real>
int Mathematics::StaticTestIntersectorRay2Ray2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
