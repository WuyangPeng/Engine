///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "IntersectorUtility3.h"
#include "StaticTestIntersectorLine3Box3.h"
#include "StaticTestIntersectorSegment3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Box3<Real>::StaticTestIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, box{ box }, solid{ solid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Box3<Real>::Test()
{
    Vector3 awdu{};
    Vector3 addu{};
    Vector3 awxddu{};

    auto diff = segment.GetCenterPoint() - box.GetCenter();

    awdu[0] = Math::FAbs(Vector3Tools::DotProduct(segment.GetDirection(), box.GetAxis(0)));
    addu[0] = Math::FAbs(Vector3Tools::DotProduct(diff, box.GetAxis(0)));
    auto rhs = box.GetExtent(0) + segment.GetExtent() * awdu[0];
    if (rhs < addu[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awdu[1] = Math::FAbs(Vector3Tools::DotProduct(segment.GetDirection(), box.GetAxis(1)));
    addu[1] = Math::FAbs(Vector3Tools::DotProduct(diff, box.GetAxis(1)));
    rhs = box.GetExtent(1) + segment.GetExtent() * awdu[1];
    if (rhs < addu[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awdu[2] = Math::FAbs(Vector3Tools::DotProduct(segment.GetDirection(), box.GetAxis(2)));
    addu[2] = Math::FAbs(Vector3Tools::DotProduct(diff, box.GetAxis(2)));
    rhs = box.GetExtent(2) + segment.GetExtent() * awdu[2];
    if (rhs < addu[2])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto wxd = Vector3Tools::CrossProduct(segment.GetDirection(), diff);

    awxddu[0] = Math::FAbs(Vector3Tools::DotProduct(wxd, box.GetAxis(0)));
    rhs = box.GetExtent(1) * awdu[2] + box.GetExtent(2) * awdu[1];
    if (rhs < awxddu[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awxddu[1] = Math::FAbs(Vector3Tools::DotProduct(wxd, box.GetAxis(1)));
    rhs = box.GetExtent(0) * awdu[2] + box.GetExtent(2) * awdu[0];
    if (rhs < awxddu[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awxddu[2] = Math::FAbs(Vector3Tools::DotProduct(wxd, box.GetAxis(2)));
    rhs = box.GetExtent(0) * awdu[1] + box.GetExtent(1) * awdu[0];
    if (rhs < awxddu[2])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H