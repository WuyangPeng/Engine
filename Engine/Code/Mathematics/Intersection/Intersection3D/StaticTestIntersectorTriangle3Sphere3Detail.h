///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorSegment3Sphere3.h"
#include "StaticTestIntersectorTriangle3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Triangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>::StaticTestIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, triangle{ triangle }, sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Sphere3<Real>::Test()
{
    DistancePoint3Triangle3<Real> calc{ sphere.GetCenter(), triangle };
    const auto sqrDistance = calc.GetSquared().GetDistance();
    const auto rSqr = sphere.GetRadius() * sphere.GetRadius();
    if (sqrDistance <= rSqr)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H