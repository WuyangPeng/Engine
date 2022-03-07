///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 15:48)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_DETAIL_H

#include "StaticTestIntersectorLine3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Plane3<Real>::StaticTestIntersectorLine3Plane3(const Line3& line, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, line{ line }, plane{ plane }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Plane3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorLine3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine3Plane3<Real>::Test() noexcept
{
    const auto ddn = Vector3Tools::DotProduct(line.GetDirection(), plane.GetNormal());

    if (Math::GetZeroTolerance() < Math::FAbs(ddn))
    {
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    const auto signedDistance = plane.DistanceTo(line.GetOrigin());
    if (Math::FAbs(signedDistance) <= Math::GetZeroTolerance())
    {
        this->SetIntersectionType(IntersectionType::Line);
        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_LINE3_PLANE3_DETAIL_H