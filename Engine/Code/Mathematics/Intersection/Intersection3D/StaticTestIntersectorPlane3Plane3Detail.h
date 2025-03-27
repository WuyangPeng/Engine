///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "StaticTestIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Plane3<Real>::StaticTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, const Real epsilon) noexcept
    : ParentType{ epsilon }, plane0{ plane0 }, plane1{ plane1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane0;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Plane3<Real>::Test() noexcept
{
    if (const auto dot = Vector3Tools::DotProduct(plane0.GetNormal(), plane1.GetNormal());
        MathType::FAbs(dot) < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
