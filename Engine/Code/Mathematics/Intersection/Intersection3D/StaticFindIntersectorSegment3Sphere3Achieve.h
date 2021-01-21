///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 10:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorSegment3Capsule3.h"
#include "StaticFindIntersectorSegment3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::StaticFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ segment }, m_Sphere{ sphere }, m_Quantity{}, m_Point0{}, m_Point1{}, m_SegmentParameter0{}, m_SegmentParameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::Find()
{
    auto diff = m_Segment.GetCenterPoint() - m_Sphere.GetCenter();
    auto a0 = Vector3DTools::DotProduct(diff, diff) - m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto a1 = Vector3DTools::DotProduct(m_Segment.GetDirection(), diff);
    auto discr = a1 * a1 - a0;
    if (discr < Math::GetValue(0))
    {
        m_Quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto extent0 = m_Segment.GetExtent() * m_Segment.GetExtent() + a0;
    auto extent1 = (Math::GetValue(2)) * a1 * m_Segment.GetExtent();
    auto minus = extent0 - extent1;
    auto plus = extent0 + extent1;

    if (minus * plus <= Math::GetValue(0))
    {
        auto root = Math::Sqrt(discr);
        m_SegmentParameter0 = (minus > Math::GetValue(0) ? -a1 - root : -a1 + root);
        m_Point0 = m_Segment.GetCenterPoint() + m_SegmentParameter0 * m_Segment.GetDirection();
        m_Quantity = 1;
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (Math::GetValue(0) < minus && Math::FAbs(a1) < m_Segment.GetExtent())
    {
        if (this->GetEpsilon() <= discr)
        {
            auto root = Math::Sqrt(discr);
            m_SegmentParameter0 = -a1 - root;
            m_SegmentParameter1 = -a1 + root;
            m_Point0 = m_Segment.GetCenterPoint() + m_SegmentParameter0 * m_Segment.GetDirection();
            m_Point1 = m_Segment.GetCenterPoint() + m_SegmentParameter1 * m_Segment.GetDirection();
            m_Quantity = 2;
            this->SetIntersectionType(IntersectionType::Segment);
        }
        else
        {
            m_SegmentParameter0 = -a1;
            m_Point0 = m_Segment.GetCenterPoint() + m_SegmentParameter0 * m_Segment.GetDirection();
            m_Quantity = 1;
            this->SetIntersectionType(IntersectionType::Point);
        }
    }
    else
    {
        m_Quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter1;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H