///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 10:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Plane3.h"
#include "StaticFindIntersectorSegment3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Plane3<Real>::StaticFindIntersectorSegment3Plane3(const Segment3& segment, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, m_Segment{ segment }, m_Plane{ plane }, m_SegmentParameter{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Plane3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorSegment3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Plane3<Real>::Find() noexcept
{
    const Line3<Real> line{ m_Segment.GetCenterPoint(), m_Segment.GetDirection() };
    StaticFindIntersectorLine3Plane3<Real> intr{ line, m_Plane };
    if (intr.IsIntersection())
    {
        // 线与平面相交，但可能在不位于线段上的点处。
        this->SetIntersectionType(intr.GetIntersectionType());
        m_SegmentParameter = intr.GetLineParameter();
        if (!(Math::FAbs(m_SegmentParameter) <= m_Segment.GetExtent()))
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Plane3<Real>::GetSegmentParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_ACHIEVE_H