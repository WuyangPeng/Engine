///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:24)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorCircle3Plane3.h"
#include "StaticFindIntersectorPlane3Plane3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorCircle3Plane3<Real>::StaticFindIntersectorCircle3Plane3(const Circle3& circle, const Plane3& plane, const Real epsilon)
    : ParentType{ epsilon }, circle{ circle }, plane{ plane }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorCircle3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

template <typename Real>
void Mathematics::StaticFindIntersectorCircle3Plane3<Real>::Find()
{
    quantity = 0;

    // ����Բ��ƽ�档
    const Plane3 CPlane{ circle.GetNormal(), circle.GetCenter() };

    // �����ƽ��������ƽ��Ľ��㡣
    StaticFindIntersectorPlane3Plane3<Real> intersector{ plane, CPlane };
    if (!intersector.IsIntersection())
    {
        // ƽ����ƽ���Ҳ��ཻ�ġ�
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (intersector.GetIntersectionType() == IntersectionType::Plane)
    {
        // ƽ����ͬ��Բ�ǹ�ͬ�Ľ�����
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // ƽ���ཻ��һ���ߡ�
    const auto line = intersector.GetIntersectionLine();

    /// �ҵ�Բ��ֱ���ϵ�һ�����㡣 �����Ϊt * D + P��Բ��ΪC��Բ�뾶Ϊr��
    /// ��r^2 = |t * D + P - C|^2 = |D|^2 * t^2 + 2 * Dot(D,P - C) * t + |P - C|^2��
    /// ������ʽΪa2 * t^2 + 2 * a1 * t + a0 = 0�Ķ��η��̡�
    auto diff = line.GetOrigin() - circle.GetCenter();
    auto directionSquared = Vector3Tools::GetLengthSquared(line.GetDirection());
    auto dotProduct = Vector3Tools::DotProduct(diff, line.GetDirection());
    auto a0 = Vector3Tools::GetLengthSquared(diff) - circle.GetRadius() * circle.GetRadius();

    auto discr = dotProduct * dotProduct - a0 * directionSquared;
    if (discr < Math::GetValue(0))
    {
        // û��ʵ���ĸ���Բ����ƽ���ཻ��
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Point);

    auto inv = (Math::GetValue(1)) / directionSquared;
    if (discr < Math::GetZeroTolerance())
    {
        // һ���ظ��ĸ���Բ������ƽ�档
        quantity = 1;
        point0 = line.GetOrigin() - (dotProduct * inv) * line.GetDirection();
        return;
    }

    // Բ��������ͬ��ʵ���ĸ�����ƽ�������������ཻ��
    auto root = Math::Sqrt(discr);
    quantity = 2;
    point0 = line.GetOrigin() - ((dotProduct + root) * inv) * line.GetDirection();
    point1 = line.GetOrigin() - ((dotProduct - root) * inv) * line.GetDirection();
}

template <typename Real>
int Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetIntersectionCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H