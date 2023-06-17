///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Plane3.h"
#include "StaticFindIntersectorSegment3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Plane3<Real>::StaticFindIntersectorSegment3Plane3(const Segment3& segment, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, segment{ segment }, plane{ plane }, segmentParameter{}
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
Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Plane3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorSegment3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Plane3<Real>::Find() noexcept
{
    const Line3<Real> line{ segment.GetCenterPoint(), segment.GetDirection() };
    StaticFindIntersectorLine3Plane3<Real> intr{ line, plane };
    if (intr.IsIntersection())
    {
        // ����ƽ���ཻ���������ڲ�λ���߶��ϵĵ㴦��
        this->SetIntersectionType(intr.GetIntersectionType());
        segmentParameter = intr.GetLineParameter();
        if (!(Math::FAbs(segmentParameter) <= segment.GetExtent()))
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

    return segmentParameter;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_ACHIEVE_H