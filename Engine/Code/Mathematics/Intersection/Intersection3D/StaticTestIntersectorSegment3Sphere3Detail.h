///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorSegment3Capsule3.h"
#include "StaticTestIntersectorSegment3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::StaticTestIntersectorSegment3Sphere3(const Segment3Type& segment, const Sphere3Type& sphere, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, sphere{ sphere }, zeroThreshold{ MathType::GetZeroTolerance() }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Sphere3<Real>::Test()
{
    auto diff = segment.GetCenterPoint() - sphere.GetCenter();
    auto a0 = Vector3ToolsType::DotProduct(diff, diff) - sphere.GetRadius() * sphere.GetRadius();
    auto a1 = Vector3ToolsType::DotProduct(segment.GetDirection(), diff);
    auto discr = a1 * a1 - a0;
    if (discr < MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto tmp0 = segment.GetExtent() * segment.GetExtent() + a0;
    auto tmp1 = MathType::GetValue(2) * a1 * segment.GetExtent();
    auto qm = tmp0 - tmp1;
    auto qp = tmp0 + tmp1;
    if (qm * qp <= MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    if (qm > MathType::GetValue(0) && MathType::FAbs(a1) < segment.GetExtent())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H