///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 22:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorSegment3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>::StaticTestIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, ellipsoid{ ellipsoid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Ellipsoid3<Real>::Test()
{
    const auto matrix = ellipsoid.GetMatrix();

    const auto diff = segment.GetCenterPoint() - ellipsoid.GetCenter();
    const auto matDir = matrix * segment.GetDirection();
    const auto matDiff = matrix * diff;
    const auto a2 = Vector3Tools::DotProduct(segment.GetDirection(), matDir);
    const auto a1 = Vector3Tools::DotProduct(segment.GetDirection(), matDiff);
    const auto a0 = Vector3Tools::DotProduct(diff, matDiff) - Math::GetValue(1);

    const auto discr = a1 * a1 - a0 * a2;
    if (discr < Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (a0 <= Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    auto e = segment.GetExtent();

    if (Math::GetValue(0) <= a1)
    {
        auto q = a0 + e * (Math::GetValue(-2) * a1 + a2 * e);
        if (q <= Math::GetValue(0))
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }

        auto qder = a1 - a2 * e;
        if (qder < Math::GetValue(0))
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
    }
    else
    {
        auto q = a0 + e * (Math::GetValue(2) * a1 + a2 * e);
        if (q <= Math::GetValue(0))
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }

        auto qder = a1 + a2 * e;
        if (qder < Math::GetValue(0))
        {
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H