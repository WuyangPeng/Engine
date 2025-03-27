///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorPlane3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::StaticTestIntersectorPlane3Ellipsoid3(const Plane3& plane, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, plane{ plane }, ellipsoid{ ellipsoid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::Test()
{
    const auto mInverse = ellipsoid.GetMatrixInverse();
    const auto discr = mInverse.QuadraticForm(plane.GetNormal(), plane.GetNormal());
    const auto root = MathType::Sqrt(MathType::FAbs(discr));
    const auto sDist = plane.DistanceTo(ellipsoid.GetCenter());

    if (MathType::FAbs(sDist) <= root)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Ellipsoid3<Real>::EllipsoidIsCulled() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrixInverse = ellipsoid.GetMatrixInverse();

    const auto discr = matrixInverse.QuadraticForm(plane.GetNormal(), plane.GetNormal());
    const auto root = MathType::Sqrt(MathType::FAbs(discr));
    const auto sDist = plane.DistanceTo(ellipsoid.GetCenter());

    return sDist <= -root;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_DETAIL_H