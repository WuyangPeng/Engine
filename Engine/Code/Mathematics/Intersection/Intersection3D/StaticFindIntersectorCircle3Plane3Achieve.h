// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/24 17:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorCircle3Plane3.h"
#include "StaticFindIntersectorPlane3Plane3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorCircle3Plane3<Real>::StaticFindIntersectorCircle3Plane3(const Circle3& circle, const Plane3& plane, const Real epsilon)
    : ParentType{ epsilon }, m_Circle{ circle }, m_Plane{ plane }, m_Quantity{}, m_Point0{}, m_Point1{}
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
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
void Mathematics::StaticFindIntersectorCircle3Plane3<Real>::Find()
{
    m_Quantity = 0;

    // ����Բ��ƽ�档
    const Plane3 CPlane{ m_Circle.GetNormal(), m_Circle.GetCenter() };

    // �����ƽ��������ƽ��Ľ��㡣
    StaticFindIntersectorPlane3Plane3<Real> intersector{ m_Plane, CPlane };
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
    auto diff = line.GetOrigin() - m_Circle.GetCenter();
    auto directionSquared = Vector3DTools::VectorMagnitudeSquared(line.GetDirection());
    auto dotProduct = Vector3DTools::DotProduct(diff, line.GetDirection());
    auto a0 = Vector3DTools::VectorMagnitudeSquared(diff) - m_Circle.GetRadius() * m_Circle.GetRadius();

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
        m_Quantity = 1;
        m_Point0 = line.GetOrigin() - (dotProduct * inv) * line.GetDirection();
        return;
    }

    // Բ��������ͬ��ʵ���ĸ�����ƽ�������������ཻ��
    auto root = Math::Sqrt(discr);
    m_Quantity = 2;
    m_Point0 = line.GetOrigin() - ((dotProduct + root) * inv) * line.GetDirection();
    m_Point1 = line.GetOrigin() - ((dotProduct - root) * inv) * line.GetDirection();
}

template <typename Real>
int Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorCircle3Plane3<Real>::GetIntersectionCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H