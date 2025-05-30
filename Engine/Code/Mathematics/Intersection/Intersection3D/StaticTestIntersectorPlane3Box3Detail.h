///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_DETAIL_H

#include "StaticTestIntersectorPlane3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Box3<Real>::StaticTestIntersectorPlane3Box3(const Plane3Type& plane, const Box3Type& box, const Real epsilon)
    : ParentType{ epsilon }, plane{ plane }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Box3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorPlane3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Box3<Real>::Test()
{
    std::array<Real, 3> tmp{ box.GetExtent(0) * (Vector3ToolsType::DotProduct(plane.GetNormal(), box.GetAxis(0))),
                             box.GetExtent(1) * (Vector3ToolsType::DotProduct(plane.GetNormal(), box.GetAxis(1))),
                             box.GetExtent(2) * (Vector3ToolsType::DotProduct(plane.GetNormal(), box.GetAxis(2))) };

    auto radius = MathType::FAbs(tmp.at(0)) + MathType::FAbs(tmp.at(1)) + MathType::FAbs(tmp.at(2));

    auto signedDistance = plane.DistanceTo(box.GetCenter());
    if (MathType::FAbs(signedDistance) <= radius)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Box3<Real>::BoxIsCulled() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    std::array<Real, 3> tmp{ box.GetExtent(0) * (Vector3ToolsType::DotProduct(plane.GetNormal(), box.GetAxis(0))),
                             box.GetExtent(1) * (Vector3ToolsType::DotProduct(plane.GetNormal(), box.GetAxis(1))),
                             box.GetExtent(2) * (Vector3ToolsType::DotProduct(plane.GetNormal(), box.GetAxis(2))) };

    auto radius = MathType::FAbs(tmp.at(0)) + MathType::FAbs(tmp.at(1)) + MathType::FAbs(tmp.at(2));

    auto signedDistance = plane.DistanceTo(box.GetCenter());

    return signedDistance <= -radius;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_BOX3_DETAIL_H