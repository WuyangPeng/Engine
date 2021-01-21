///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 10:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H

#include "IntersectorUtility3Detail.h"
#include "StaticFindIntersectorLine3Box3Detail.h"
#include "StaticFindIntersectorSegment3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Box3<Real>::StaticFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ segment }, m_Box{ box }, m_Solid{ solid }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Box3<Real>::Find()
{
    auto t0 = -m_Segment.GetExtent();
    auto t1 = m_Segment.GetExtent();

    const auto findShared = StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, m_Segment.GetCenterPoint(), m_Segment.GetDirection(), m_Box, m_Solid);
    this->SetIntersectionType(findShared.m_IntersectionType);
    m_Quantity = findShared.m_Quantity;
    m_Point0 = findShared.m_Point0;
    m_Point1 = findShared.m_Point1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H