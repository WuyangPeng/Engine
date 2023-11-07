///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:28)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorRay3Triangle3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Triangle3<Real>::StaticTestIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Triangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorRay3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Triangle3<Real>::Test()
{
    const auto diff = ray.GetOrigin() - triangle.GetVertex(0);
    const auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    const auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    const auto normal = Vector3Tools::CrossProduct(edge1, edge2);

    auto ddn = Vector3Tools::DotProduct(ray.GetDirection(), normal);
    Real sign{};
    if (Math::GetZeroTolerance() < ddn)
    {
        sign = Math::GetValue(1);
    }
    else if (ddn < -Math::GetZeroTolerance())
    {
        sign = Math::GetValue(-1);
        ddn = -ddn;
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto ddqxe2 = sign * Vector3Tools::DotProduct(ray.GetDirection(), Vector3Tools::CrossProduct(diff, edge2));
    if (Math::GetValue(0) <= ddqxe2)
    {
        auto dde1xq = sign * Vector3Tools::DotProduct(ray.GetDirection(), Vector3Tools::CrossProduct(edge1, diff));
        if (Math::GetValue(0) <= dde1xq)
        {
            if (ddqxe2 + dde1xq <= ddn)
            {
                auto qdn = -sign * Vector3Tools::DotProduct(diff, normal);
                if (Math::GetValue(0) <= qdn)
                {
                    this->SetIntersectionType(IntersectionType::Point);
                    return;
                }
            }
        }
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H