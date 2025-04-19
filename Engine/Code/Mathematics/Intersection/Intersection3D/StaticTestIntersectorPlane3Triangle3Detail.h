///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorPlane3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Triangle3<Real>::StaticTestIntersectorPlane3Triangle3(const Plane3Type& plane, const Triangle3Type& triangle, Real epsilon)
    : ParentType{ MathType::GetValue(0) <= epsilon ? epsilon : MathType::GetValue(0) }, plane{ plane }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Triangle3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorPlane3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Triangle3<Real>::Test()
{
    constexpr auto zero = MathType::GetValue(0);
    std::array<Real, 3> sd{};
    for (auto i = 0; i < 3; ++i)
    {
        sd.at(i) = plane.DistanceTo(triangle.GetVertex(i));
        if (MathType::FAbs(sd.at(i)) <= this->GetEpsilon())
        {
            sd.at(i) = zero;
        }
    };

    if (!(zero < sd.at(0) && zero < sd.at(1) && zero < sd.at(2)) && !(sd.at(0) < zero && sd.at(1) < zero && sd.at(2) < zero))
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H