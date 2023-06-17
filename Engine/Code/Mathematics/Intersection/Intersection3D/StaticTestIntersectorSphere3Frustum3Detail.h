///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:32)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_DETAIL_H

#include "StaticTestIntersectorSphere3Frustum3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Frustum3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSphere3Frustum3<Real>::StaticTestIntersectorSphere3Frustum3(const Sphere3& sphere, const Frustum3& frustum, const Real epsilon)
    : ParentType{ epsilon }, sphere{ sphere }, frustum{ frustum }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSphere3Frustum3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Frustum3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
Mathematics::Frustum3<Real> Mathematics::StaticTestIntersectorSphere3Frustum3<Real>::GetFrustum() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return frustum;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSphere3Frustum3<Real>::Test()
{
    const auto distance = DistancePoint3Frustum3<Real>(sphere.GetCenter(), frustum).Get().GetDistance();

    if (distance <= sphere.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_DETAIL_H