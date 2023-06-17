///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:31)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_DETAIL_H

#include "StaticTestIntersectorRay3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Box3<Real>::StaticTestIntersectorRay3Box3(const Ray3& ray, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Box3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorRay3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Box3<Real>::Test()
{
    Vector3 wdu{};
    Vector3 awdu{};
    Vector3 ddu{};
    Vector3 addu{};
    Vector3 awxddu{};

    auto diff = ray.GetOrigin() - box.GetCenter();

    wdu[0] = Vector3Tools::DotProduct(ray.GetDirection(), box.GetAxis(0));
    awdu[0] = Math::FAbs(wdu[0]);
    ddu[0] = Vector3Tools::DotProduct(diff, box.GetAxis(0));
    addu[0] = Math::FAbs(ddu[0]);
    if (box.GetExtent(0) < addu[0] && Math::GetValue(0) <= ddu[0] * wdu[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    wdu[1] = Vector3Tools::DotProduct(ray.GetDirection(), box.GetAxis(1));
    awdu[1] = Math::FAbs(wdu[1]);
    ddu[1] = Vector3Tools::DotProduct(diff, box.GetAxis(1));
    addu[1] = Math::FAbs(ddu[1]);
    if (box.GetExtent(1) < addu[1] && Math::GetValue(0) <= ddu[1] * wdu[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    wdu[2] = Vector3Tools::DotProduct(ray.GetDirection(), box.GetAxis(2));
    awdu[2] = Math::FAbs(wdu[2]);
    ddu[2] = Vector3Tools::DotProduct(diff, box.GetAxis(2));
    addu[2] = Math::FAbs(ddu[2]);
    if (box.GetExtent(2) < addu[2] && Math::GetValue(0) <= ddu[2] * wdu[2])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto wxd = Vector3Tools::CrossProduct(ray.GetDirection(), diff);

    awxddu[0] = Math::FAbs(Vector3Tools::DotProduct(wxd, box.GetAxis(0)));
    auto rhs = box.GetExtent(1) * awdu[2] + box.GetExtent(2) * awdu[1];
    if (rhs < awxddu[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awxddu[1] = Math::FAbs(Vector3Tools::DotProduct(wxd, box.GetAxis(1)));
    rhs = box.GetExtent(0) * awdu[2] + box.GetExtent(2) * awdu[0];
    if (rhs < awxddu[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awxddu[2] = Math::FAbs(Vector3Tools::DotProduct(wxd, box.GetAxis(2)));
    rhs = box.GetExtent(0) * awdu[1] + box.GetExtent(1) * awdu[0];
    if (rhs < awxddu[2])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_BOX3_DETAIL_H