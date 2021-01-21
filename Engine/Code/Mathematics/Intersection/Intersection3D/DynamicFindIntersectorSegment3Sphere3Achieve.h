///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/06 11:21)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H

#include "DynamicFindIntersectorSegment3Sphere3.h"
#include "StaticFindIntersectorSegment3Capsule3Detail.h"
#include "StaticFindIntersectorSegment3Sphere3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::DynamicFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Segment{ segment }, m_Sphere{ sphere }, m_Quantity{}, m_Point0{}, m_Point1{}, m_SegmentParameter0{}, m_SegmentParameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::Find()
{
    // �������Ƿ��ཻ��
    StaticFindIntersectorSegment3Sphere3<Real> intersector{ m_Segment, m_Sphere };
    if (intersector.IsIntersection())
    {
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Other);
        if (intersector.GetQuantity() == 1)
        {
            m_Point0 = intersector.GetPoint(0);
        }
        else if (intersector.GetQuantity() == 2)
        {
            m_Point0 = intersector.GetPoint(0);
            m_Point1 = intersector.GetPoint(1);
        }

        m_SegmentParameter0 = intersector.GetSegmentParameter0();
        m_SegmentParameter1 = intersector.GetSegmentParameter1();

        return;
    }

    /// �������ٶ��м�ȥ�߶��ٶȣ��Ա��������߶ε�����ϵ��
    /// �ڸ�ϵͳ�У��߶ε�Ȼ�ǹ̶��ġ�
    /// �����Խһ�����ң�����ȡ����֮���ǣ����ǽ���������뾶�������߶Σ��������������������ġ�
    /// ���ڵ������Ǽ���ƶ����ĵ�һ�������߶κ���뾶�γɵĽ����ཻ��
    const Capsule3<Real> capsule{ m_Segment, m_Sphere.GetRadius() };

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relSpeed = Vector3DTools::VectorMagnitude(relVelocity);
    // ��λ��������
    relVelocity.Normalize();
    const Segment3 path{ (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed, m_Sphere.GetCenter() + (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed * relVelocity, relVelocity };

    StaticFindIntersectorSegment3Capsule3<Real> staticFindIntersectorSegment3Capsule3{ path, capsule };
    if (!staticFindIntersectorSegment3Capsule3.IsIntersection())
    {
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    m_SegmentParameter0 = staticFindIntersectorSegment3Capsule3.GetParameter0();
    m_SegmentParameter1 = staticFindIntersectorSegment3Capsule3.GetParameter1();

    // ��������֪�����彫���߶��ཻ�� ������ڶζ˵����ڲ��㷢���� ������Ҫȷ���ĸ���
    this->SetContactTime((staticFindIntersectorSegment3Capsule3.GetParameter0() + path.GetExtent()) / relSpeed);
    m_Quantity = 1;
    this->SetIntersectionType(IntersectionType::Point);

    auto moveCenter = m_Sphere.GetCenter() + this->GetContactTime() * this->GetRhsVelocity();
    auto moveOrigin = m_Segment.GetCenterPoint() + this->GetContactTime() * this->GetLhsVelocity();
    auto origin = Vector3DTools::DotProduct(m_Segment.GetDirection(), moveOrigin);
    auto negEnd = origin - m_Segment.GetExtent();
    auto posEnd = origin + m_Segment.GetExtent();
    auto center = Vector3DTools::DotProduct(m_Segment.GetDirection(), moveCenter);

    if (center < negEnd)
    {
        // �߶��յ�P - e * D���Ľ��㡣
        m_Point0 = moveOrigin - m_Segment.GetExtent() * m_Segment.GetDirection();
    }
    else if (center > posEnd)
    {
        // �߶��յ�P + e * D���Ľ��㡣
        m_Point0 = moveOrigin + m_Segment.GetExtent() * m_Segment.GetDirection();
    }
    else
    {
        // ���Ե�ϵ��ڲ����ཻ�� ʹ���ط������ͶӰ���ҵ��Ǹ��㡣
        m_Point0 = moveOrigin + (center - origin) * m_Segment.GetDirection();
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetPoint(int index) const
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
Real Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter0;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter1;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H