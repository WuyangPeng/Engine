///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 14:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Capsule3Detail.h"
#include "StaticFindIntersectorSegment3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::StaticFindIntersectorSegment3Capsule3(const Segment3& segment, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ segment }, m_Capsule{ capsule }, m_Quantity{}, m_Point0{}, m_Point1{}, m_Parameter0{}, m_Parameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Capsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::Find()
{
    const auto quantity = StaticFindIntersectorLine3Capsule3<Real>::Find(m_Segment.GetCenterPoint(), m_Segment.GetDirection(), m_Capsule);

    m_Quantity = 0;
    for (auto i = 0; i < quantity.m_Quantity; ++i)
    {
        auto parameter = (i == 0) ? quantity.m_Parameter0 : quantity.m_Parameter1;
        if (Math::FAbs(parameter) <= m_Segment.GetExtent())
        {
            if (m_Quantity == 0)
            {
                m_Point0 = m_Segment.GetCenterPoint() + parameter * m_Segment.GetDirection();
            }
            else if (m_Quantity == 1)
            {
                m_Point1 = m_Segment.GetCenterPoint() + parameter * m_Segment.GetDirection();
            }
        }

        ++m_Quantity;
    }

    m_Parameter0 = quantity.m_Parameter0;
    m_Parameter1 = quantity.m_Parameter1;

    if (m_Quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (m_Quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetPoint(int index) const
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
Real Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetParameter0() const noexcept
{
    return m_Parameter0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetParameter1() const noexcept
{
    return m_Parameter1;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_ACHIEVE_H