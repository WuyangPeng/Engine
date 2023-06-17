///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_DETAIL_H

#include "StaticTestIntersectorBox3Frustum3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Frustum3<Real>::StaticTestIntersectorBox3Frustum3(const Box3& box, const Frustum3& frustum, const Real epsilon)
    : ParentType{ epsilon }, box{ box }, frustum{ frustum }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorBox3Frustum3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Frustum3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
Mathematics::Frustum3<Real> Mathematics::StaticTestIntersectorBox3Frustum3<Real>::GetFrustum() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return frustum;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Frustum3<Real>::Test()
{
    using Vector = std::array<Real, 3>;

    const std::array<Vector3, 3> axes{ box.GetAxis0(), box.GetAxis1(), box.GetAxis2() };
    const Vector extents{ box.GetExtent0(), box.GetExtent1(), box.GetExtent2() };

    auto diff = box.GetCenter() - frustum.GetOrigin();  // C-E

    Vector rightDot{};  // Dot(R,A.at(i))
    Vector upDot{};  // Dot(U,A.at(i))
    Vector directionDot{};  // Dot(D,A.at(i))
    Vector diffDot{};  // (Dot(R,C-E),Dot(U,C-E),Dot(D,C-E))
    Vector rightDotMin{};  // dmin*Dot(R,A.at(i))
    Vector upDotMin{};  // dmin*Dot(U,A.at(i))
    Vector directionDotMin{};  // dmin*Dot(D,A.at(i))
    Vector diffDotMin{};  // dmin*(Dot(R,C-E),Dot(U,C-E),?)
    Vector rightDotMax{};  // rmax*Dot(D,A.at(i))
    Vector upDotMax{};  // rmax*(?,?,Dot(D,C-E))
    Vector directionDotMax{};  // umax*Dot(D,A.at(i))
    Vector diffDotMax{};  // umax*(?,?,Dot(D,C-E))
    Vector rightDotMinPlusDirectionDotMax{};  // dmin*Dot(R,A.at(i)) + rmax*Dot(D,A.at(i))
    Vector rightDotMinMinusDirectionDotMax{};  // dmin*Dot(R,A.at(i)) - rmax*Dot(D,A.at(i))
    Vector upDotMinPlusDirectionDotMax{};  // dmin*Dot(U,A.at(i)) + umax*Dot(D,A.at(i))
    Vector upDotMinMinusDirectionDotMax{};  // dmin*Dot(U,A.at(i)) - umax*Dot(D,A.at(i))
    Vector upDotMaxPlusRightDotMax{};  // rmax*Dot(U,A.at(i)) + umax*Dot(R,A.at(i))
    Vector upDotMaxMinusRightDotMax{};  // rmax*Dot(U,A.at(i)) - umax*Dot(R,A.at(i))

    // M = D
    diffDot.at(2) = Vector3Tools::DotProduct(diff, frustum.GetDirectionVector());
    for (auto i = 0; i < 3; ++i)
    {
        directionDot.at(i) = Vector3Tools::DotProduct(axes.at(i), frustum.GetDirectionVector());
    }
    auto radius = extents.at(0) * Math::FAbs(directionDot.at(0)) + extents.at(1) * Math::FAbs(directionDot.at(1)) + extents.at(2) * Math::FAbs(directionDot.at(2));
    if (diffDot.at(2) + radius < frustum.GetDirectionMin() || frustum.GetDirectionMax() < diffDot.at(2) - radius)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = n * Real - r * D
    for (auto i = 0; i < 3; ++i)
    {
        rightDot.at(i) = Vector3Tools::DotProduct(axes.at(i), frustum.GetRightVector());
        rightDotMax.at(i) = frustum.GetRightBound() * directionDot.at(i);
        rightDotMin.at(i) = frustum.GetDirectionMin() * rightDot.at(i);
        rightDotMinMinusDirectionDotMax.at(i) = rightDotMin.at(i) - rightDotMax.at(i);
    }
    diffDot.at(0) = Vector3Tools::DotProduct(diff, frustum.GetRightVector());
    radius = extents.at(0) * Math::FAbs(rightDotMinMinusDirectionDotMax.at(0)) + extents.at(1) * Math::FAbs(rightDotMinMinusDirectionDotMax.at(1)) + extents.at(2) * Math::FAbs(rightDotMinMinusDirectionDotMax.at(2));
    diffDotMin.at(0) = frustum.GetDirectionMin() * diffDot.at(0);
    upDotMax.at(2) = frustum.GetRightBound() * diffDot.at(2);
    auto value0 = diffDotMin.at(0) - upDotMax.at(2);
    auto mTwoRF = frustum.GetMTwoRF();
    if (value0 + radius < mTwoRF || value0 > radius)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = -n * Real - r * D
    for (auto i = 0; i < 3; ++i)
    {
        rightDotMinPlusDirectionDotMax.at(i) = rightDotMin.at(i) + rightDotMax.at(i);
    }
    radius = extents.at(0) * Math::FAbs(rightDotMinPlusDirectionDotMax.at(0)) + extents.at(1) * Math::FAbs(rightDotMinPlusDirectionDotMax.at(1)) + extents.at(2) * Math::FAbs(rightDotMinPlusDirectionDotMax.at(2));
    value0 = -(diffDotMin.at(0) + upDotMax.at(2));
    if (value0 + radius < mTwoRF || radius < value0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = n*U - u*D
    for (auto i = 0; i < 3; ++i)
    {
        upDot.at(i) = Vector3Tools::DotProduct(axes.at(i), frustum.GetUpVector());
        directionDotMax.at(i) = frustum.GetUpBound() * directionDot.at(i);
        upDotMin.at(i) = frustum.GetDirectionMin() * upDot.at(i);
        upDotMinMinusDirectionDotMax.at(i) = upDotMin.at(i) - directionDotMax.at(i);
    }
    diffDot.at(1) = Vector3Tools::DotProduct(diff, frustum.GetUpVector());
    radius = extents.at(0) * Math::FAbs(upDotMinMinusDirectionDotMax.at(0)) + extents.at(1) * Math::FAbs(upDotMinMinusDirectionDotMax.at(1)) + extents.at(2) * Math::FAbs(upDotMinMinusDirectionDotMax.at(2));
    diffDotMin.at(1) = frustum.GetDirectionMin() * diffDot.at(1);
    diffDotMax.at(2) = frustum.GetUpBound() * diffDot.at(2);
    value0 = diffDotMin.at(1) - diffDotMax.at(2);
    auto MTwoUF = frustum.GetMTwoUF();
    if (value0 + radius < MTwoUF || radius < value0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = -n*U - u*D
    for (auto i = 0; i < 3; ++i)
    {
        upDotMinPlusDirectionDotMax.at(i) = upDotMin.at(i) + directionDotMax.at(i);
    }
    radius = extents.at(0) * Math::FAbs(upDotMinPlusDirectionDotMax.at(0)) + extents.at(1) * Math::FAbs(upDotMinPlusDirectionDotMax.at(1)) + extents.at(2) * Math::FAbs(upDotMinPlusDirectionDotMax.at(2));
    value0 = -(diffDotMin.at(1) + diffDotMax.at(2));
    if (value0 + radius < MTwoUF || radius < value0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = A.at(i)
    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetRightBound() * Math::FAbs(rightDot.at(i)) + frustum.GetUpBound() * Math::FAbs(upDot.at(i));
        directionDotMin.at(i) = frustum.GetDirectionMin() * directionDot.at(i);
        auto fmin = directionDotMin.at(i) - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = directionDotMin.at(i) + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = rightDot.at(i) * diffDot.at(0) + upDot.at(i) * diffDot.at(1) + directionDot.at(i) * diffDot.at(2);
        if (value0 + extents.at(i) < fmin || fmax < value0 - extents.at(i))
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(Real,A.at(i))
    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetUpBound() * Math::FAbs(directionDot.at(i));
        auto fmin = -upDotMin.at(i) - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = -upDotMin.at(i) + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = directionDot.at(i) * diffDot.at(1) - upDot.at(i) * diffDot.at(2);
        radius = extents.at(0) * Math::FAbs(upDot.at(i) * directionDot.at(0) - upDot.at(0) * directionDot.at(i)) + extents.at(1) * Math::FAbs(upDot.at(i) * directionDot.at(1) - upDot.at(1) * directionDot.at(i)) + extents.at(2) * Math::FAbs(upDot.at(i) * directionDot.at(2) - upDot.at(2) * directionDot.at(i));
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(U,A.at(i))
    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetRightBound() * Math::FAbs(directionDot.at(i));
        auto fmin = rightDotMin.at(i) - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = rightDotMin.at(i) + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = -directionDot.at(i) * diffDot.at(0) + rightDot.at(i) * diffDot.at(2);
        radius = extents.at(0) * Math::FAbs(rightDot.at(i) * directionDot.at(0) - rightDot.at(0) * directionDot.at(i)) + extents.at(1) * Math::FAbs(rightDot.at(i) * directionDot.at(1) - rightDot.at(1) * directionDot.at(i)) + extents.at(2) * Math::FAbs(rightDot.at(i) * directionDot.at(2) - rightDot.at(2) * directionDot.at(i));
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D+r*Real+u*U,A.at(i))
    for (auto i = 0; i < 3; ++i)
    {
        auto right = frustum.GetRightBound() * upDot.at(i);
        auto up = frustum.GetUpBound() * rightDot.at(i);
        upDotMaxPlusRightDotMax.at(i) = right + up;
        upDotMaxMinusRightDotMax.at(i) = right - up;
    }

    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetRightBound() * Math::FAbs(upDotMinMinusDirectionDotMax.at(i)) + frustum.GetUpBound() * Math::FAbs(rightDotMinMinusDirectionDotMax.at(i));
        auto value2 = -frustum.GetDirectionMin() * upDotMaxMinusRightDotMax.at(i);
        auto fmin = value2 - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = value2 + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = diffDot.at(0) * upDotMinMinusDirectionDotMax.at(i) - diffDot.at(1) * rightDotMinMinusDirectionDotMax.at(i) - diffDot.at(2) * upDotMaxMinusRightDotMax.at(i);
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; j++)
        {
            radius += extents.at(j) * Math::FAbs(rightDot.at(j) * upDotMinMinusDirectionDotMax.at(i) - upDot.at(j) * rightDotMinMinusDirectionDotMax.at(i) - directionDot.at(j) * upDotMaxMinusRightDotMax.at(i));
        }

        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D+r*Real-u*U,A.at(i))
    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetRightBound() * Math::FAbs(upDotMinPlusDirectionDotMax.at(i)) + frustum.GetUpBound() * Math::FAbs(rightDotMinMinusDirectionDotMax.at(i));
        auto value2 = -frustum.GetDirectionMin() * upDotMaxPlusRightDotMax.at(i);
        auto fmin = value2 - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = value2 + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = diffDot.at(0) * upDotMinPlusDirectionDotMax.at(i) - diffDot.at(1) * rightDotMinMinusDirectionDotMax.at(i) - diffDot.at(2) * upDotMaxPlusRightDotMax.at(i);
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; ++j)
        {
            radius += extents.at(j) * Math::FAbs(rightDot.at(j) * upDotMinPlusDirectionDotMax.at(i) - upDot.at(j) * rightDotMinMinusDirectionDotMax.at(i) - directionDot.at(j) * upDotMaxPlusRightDotMax.at(i));
        }
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D-r*Real+u*U,A.at(i))
    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetRightBound() * Math::FAbs(upDotMinMinusDirectionDotMax.at(i)) + frustum.GetUpBound() * Math::FAbs(rightDotMinPlusDirectionDotMax.at(i));
        auto value = frustum.GetDirectionMin() * upDotMaxPlusRightDotMax.at(i);
        auto fmin = value - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = value + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = diffDot.at(0) * upDotMinMinusDirectionDotMax.at(i) - diffDot.at(1) * rightDotMinPlusDirectionDotMax.at(i) + diffDot.at(2) * upDotMaxPlusRightDotMax.at(i);
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; ++j)
        {
            radius += extents.at(j) * Math::FAbs(rightDot.at(j) * upDotMinMinusDirectionDotMax.at(i) - upDot.at(j) * rightDotMinPlusDirectionDotMax.at(i) + directionDot.at(j) * upDotMaxPlusRightDotMax.at(i));
        }
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D-r*Real-u*U,A.at(i))
    for (auto i = 0; i < 3; ++i)
    {
        auto p = frustum.GetRightBound() * Math::FAbs(upDotMinPlusDirectionDotMax.at(i)) + frustum.GetUpBound() * Math::FAbs(rightDotMinPlusDirectionDotMax.at(i));
        auto value = frustum.GetDirectionMin() * upDotMaxMinusRightDotMax.at(i);
        auto fmin = value - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= frustum.GetDirectionRatio();
        }
        auto fmax = value + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= frustum.GetDirectionRatio();
        }
        value0 = diffDot.at(0) * upDotMinPlusDirectionDotMax.at(i) - diffDot.at(1) * rightDotMinPlusDirectionDotMax.at(i) + diffDot.at(2) * upDotMaxMinusRightDotMax.at(i);
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; ++j)
        {
            radius += extents.at(j) * Math::FAbs(rightDot.at(j) * upDotMinPlusDirectionDotMax.at(i) - upDot.at(j) * rightDotMinPlusDirectionDotMax.at(i) + directionDot.at(j) * upDotMaxMinusRightDotMax.at(i));
        }
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_DETAIL_H