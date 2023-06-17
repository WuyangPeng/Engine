///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:31)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorRay3Lozenge3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Rectangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Lozenge3<Real>::StaticTestIntersectorRay3Lozenge3(const Ray3& ray, const Lozenge3& lozenge, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, lozenge{ lozenge }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Lozenge3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Lozenge3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorRay3Lozenge3<Real>::GetLozenge() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Lozenge3<Real>::Test()
{
    const auto distance = DistanceRay3Rectangle3<Real>(ray, lozenge.GetRectangle()).Get().GetDistance();

    if (distance <= lozenge.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_LOZENGE3_DETAIL_H