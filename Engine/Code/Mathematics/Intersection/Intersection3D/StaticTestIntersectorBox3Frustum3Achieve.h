///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 14:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_ACHIEVE_H

#include "StaticTestIntersectorBox3Frustum3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Frustum3<Real>::StaticTestIntersectorBox3Frustum3(const Box3& box, const Frustum3& frustum, const Real epsilon)
    : ParentType{ epsilon }, m_Box{ box }, m_Frustum{ frustum }
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
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Frustum3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
const Mathematics::Frustum3<Real> Mathematics::StaticTestIntersectorBox3Frustum3<Real>::GetFrustum() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Frustum;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Frustum3<Real>::Test()
{
    using Vector3 = std::array<Real, 3>;
    const std::array<Vector3D, 3> axes{ m_Box.GetAxis0(), m_Box.GetAxis1(), m_Box.GetAxis2() };
    const Vector3 extents{ m_Box.GetExtent0(), m_Box.GetExtent1(), m_Box.GetExtent2() };

    auto diff = m_Box.GetCenter() - m_Frustum.GetOrigin();  // C-E

    Vector3 rightDot{};  // Dot(R,A[i])
    Vector3 upDot{};  // Dot(U,A[i])
    Vector3 directionDot{};  // Dot(D,A[i])
    Vector3 diffDot{};  // (Dot(R,C-E),Dot(U,C-E),Dot(D,C-E))
    Vector3 rightDotMin{};  // dmin*Dot(R,A[i])
    Vector3 upDotMin{};  // dmin*Dot(U,A[i])
    Vector3 directionDotMin{};  // dmin*Dot(D,A[i])
    Vector3 diffDotMin{};  // dmin*(Dot(R,C-E),Dot(U,C-E),?)
    Vector3 rightDotMax{};  // rmax*Dot(D,A[i])
    Vector3 upDotMax{};  // rmax*(?,?,Dot(D,C-E))
    Vector3 directionDotMax{};  // umax*Dot(D,A[i])
    Vector3 diffDotMax{};  // umax*(?,?,Dot(D,C-E))
    Vector3 rightDotMinPlusDirectionDotMax{};  // dmin*Dot(R,A[i]) + rmax*Dot(D,A[i])
    Vector3 rightDotMinMinusDirectionDotMax{};  // dmin*Dot(R,A[i]) - rmax*Dot(D,A[i])
    Vector3 upDotMinPlusDirectionDotMax{};  // dmin*Dot(U,A[i]) + umax*Dot(D,A[i])
    Vector3 upDotMinMinusDirectionDotMax{};  // dmin*Dot(U,A[i]) - umax*Dot(D,A[i])
    Vector3 upDotMaxPlusRightDotMax{};  // rmax*Dot(U,A[i]) + umax*Dot(R,A[i])
    Vector3 upDotMaxMinusRightDotMax{};  // rmax*Dot(U,A[i]) - umax*Dot(R,A[i])

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    // M = D
    diffDot[2] = Vector3DTools::DotProduct(diff, m_Frustum.GetDirectionVector());
    for (auto i = 0; i < 3; ++i)
    {
        directionDot[i] = Vector3DTools::DotProduct(axes[i], m_Frustum.GetDirectionVector());
    }
    auto radius = extents[0] * Math::FAbs(directionDot[0]) + extents[1] * Math::FAbs(directionDot[1]) + extents[2] * Math::FAbs(directionDot[2]);
    if (diffDot[2] + radius < m_Frustum.GetDirectionMin() || m_Frustum.GetDirectionMax() < diffDot[2] - radius)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = n * Real - r * D
    for (auto i = 0; i < 3; ++i)
    {
        rightDot[i] = Vector3DTools::DotProduct(axes[i], m_Frustum.GetRightVector());
        rightDotMax[i] = m_Frustum.GetRightBound() * directionDot[i];
        rightDotMin[i] = m_Frustum.GetDirectionMin() * rightDot[i];
        rightDotMinMinusDirectionDotMax[i] = rightDotMin[i] - rightDotMax[i];
    }
    diffDot[0] = Vector3DTools::DotProduct(diff, m_Frustum.GetRightVector());
    radius = extents[0] * Math::FAbs(rightDotMinMinusDirectionDotMax[0]) + extents[1] * Math::FAbs(rightDotMinMinusDirectionDotMax[1]) + extents[2] * Math::FAbs(rightDotMinMinusDirectionDotMax[2]);
    diffDotMin[0] = m_Frustum.GetDirectionMin() * diffDot[0];
    upDotMax[2] = m_Frustum.GetRightBound() * diffDot[2];
    auto value0 = diffDotMin[0] - upDotMax[2];
    auto mTwoRF = m_Frustum.GetMTwoRF();
    if (value0 + radius < mTwoRF || value0 > radius)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = -n * Real - r * D
    for (auto i = 0; i < 3; ++i)
    {
        rightDotMinPlusDirectionDotMax[i] = rightDotMin[i] + rightDotMax[i];
    }
    radius = extents[0] * Math::FAbs(rightDotMinPlusDirectionDotMax[0]) + extents[1] * Math::FAbs(rightDotMinPlusDirectionDotMax[1]) + extents[2] * Math::FAbs(rightDotMinPlusDirectionDotMax[2]);
    value0 = -(diffDotMin[0] + upDotMax[2]);
    if (value0 + radius < mTwoRF || radius < value0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = n*U - u*D
    for (auto i = 0; i < 3; ++i)
    {
        upDot[i] = Vector3DTools::DotProduct(axes[i], m_Frustum.GetUpVector());
        directionDotMax[i] = m_Frustum.GetUpBound() * directionDot[i];
        upDotMin[i] = m_Frustum.GetDirectionMin() * upDot[i];
        upDotMinMinusDirectionDotMax[i] = upDotMin[i] - directionDotMax[i];
    }
    diffDot[1] = Vector3DTools::DotProduct(diff, m_Frustum.GetUpVector());
    radius = extents[0] * Math::FAbs(upDotMinMinusDirectionDotMax[0]) + extents[1] * Math::FAbs(upDotMinMinusDirectionDotMax[1]) + extents[2] * Math::FAbs(upDotMinMinusDirectionDotMax[2]);
    diffDotMin[1] = m_Frustum.GetDirectionMin() * diffDot[1];
    diffDotMax[2] = m_Frustum.GetUpBound() * diffDot[2];
    value0 = diffDotMin[1] - diffDotMax[2];
    auto MTwoUF = m_Frustum.GetMTwoUF();
    if (value0 + radius < MTwoUF || radius < value0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = -n*U - u*D
    for (auto i = 0; i < 3; ++i)
    {
        upDotMinPlusDirectionDotMax[i] = upDotMin[i] + directionDotMax[i];
    }
    radius = extents[0] * Math::FAbs(upDotMinPlusDirectionDotMax[0]) + extents[1] * Math::FAbs(upDotMinPlusDirectionDotMax[1]) + extents[2] * Math::FAbs(upDotMinPlusDirectionDotMax[2]);
    value0 = -(diffDotMin[1] + diffDotMax[2]);
    if (value0 + radius < MTwoUF || radius < value0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // M = A[i]
    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetRightBound() * Math::FAbs(rightDot[i]) + m_Frustum.GetUpBound() * Math::FAbs(upDot[i]);
        directionDotMin[i] = m_Frustum.GetDirectionMin() * directionDot[i];
        auto fmin = directionDotMin[i] - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = directionDotMin[i] + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = rightDot[i] * diffDot[0] + upDot[i] * diffDot[1] + directionDot[i] * diffDot[2];
        if (value0 + extents[i] < fmin || fmax < value0 - extents[i])
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(Real,A[i])
    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetUpBound() * Math::FAbs(directionDot[i]);
        auto fmin = -upDotMin[i] - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = -upDotMin[i] + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = directionDot[i] * diffDot[1] - upDot[i] * diffDot[2];
        radius = extents[0] * Math::FAbs(upDot[i] * directionDot[0] - upDot[0] * directionDot[i]) + extents[1] * Math::FAbs(upDot[i] * directionDot[1] - upDot[1] * directionDot[i]) + extents[2] * Math::FAbs(upDot[i] * directionDot[2] - upDot[2] * directionDot[i]);
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(U,A[i])
    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetRightBound() * Math::FAbs(directionDot[i]);
        auto fmin = rightDotMin[i] - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = rightDotMin[i] + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = -directionDot[i] * diffDot[0] + rightDot[i] * diffDot[2];
        radius = extents[0] * Math::FAbs(rightDot[i] * directionDot[0] - rightDot[0] * directionDot[i]) + extents[1] * Math::FAbs(rightDot[i] * directionDot[1] - rightDot[1] * directionDot[i]) + extents[2] * Math::FAbs(rightDot[i] * directionDot[2] - rightDot[2] * directionDot[i]);
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D+r*Real+u*U,A[i])
    for (auto i = 0; i < 3; ++i)
    {
        auto right = m_Frustum.GetRightBound() * upDot[i];
        auto up = m_Frustum.GetUpBound() * rightDot[i];
        upDotMaxPlusRightDotMax[i] = right + up;
        upDotMaxMinusRightDotMax[i] = right - up;
    }

    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetRightBound() * Math::FAbs(upDotMinMinusDirectionDotMax[i]) + m_Frustum.GetUpBound() * Math::FAbs(rightDotMinMinusDirectionDotMax[i]);
        auto value2 = -m_Frustum.GetDirectionMin() * upDotMaxMinusRightDotMax[i];
        auto fmin = value2 - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = value2 + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = diffDot[0] * upDotMinMinusDirectionDotMax[i] - diffDot[1] * rightDotMinMinusDirectionDotMax[i] - diffDot[2] * upDotMaxMinusRightDotMax[i];
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; j++)
        {
            radius += extents[j] * Math::FAbs(rightDot[j] * upDotMinMinusDirectionDotMax[i] - upDot[j] * rightDotMinMinusDirectionDotMax[i] - directionDot[j] * upDotMaxMinusRightDotMax[i]);
        }

        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D+r*Real-u*U,A[i])
    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetRightBound() * Math::FAbs(upDotMinPlusDirectionDotMax[i]) + m_Frustum.GetUpBound() * Math::FAbs(rightDotMinMinusDirectionDotMax[i]);
        auto value2 = -m_Frustum.GetDirectionMin() * upDotMaxPlusRightDotMax[i];
        auto fmin = value2 - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = value2 + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = diffDot[0] * upDotMinPlusDirectionDotMax[i] - diffDot[1] * rightDotMinMinusDirectionDotMax[i] - diffDot[2] * upDotMaxPlusRightDotMax[i];
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; ++j)
        {
            radius += extents[j] * Math::FAbs(rightDot[j] * upDotMinPlusDirectionDotMax[i] - upDot[j] * rightDotMinMinusDirectionDotMax[i] - directionDot[j] * upDotMaxPlusRightDotMax[i]);
        }
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D-r*Real+u*U,A[i])
    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetRightBound() * Math::FAbs(upDotMinMinusDirectionDotMax[i]) + m_Frustum.GetUpBound() * Math::FAbs(rightDotMinPlusDirectionDotMax[i]);
        auto value = m_Frustum.GetDirectionMin() * upDotMaxPlusRightDotMax[i];
        auto fmin = value - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = value + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = diffDot[0] * upDotMinMinusDirectionDotMax[i] - diffDot[1] * rightDotMinPlusDirectionDotMax[i] + diffDot[2] * upDotMaxPlusRightDotMax[i];
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; ++j)
        {
            radius += extents[j] * Math::FAbs(rightDot[j] * upDotMinMinusDirectionDotMax[i] - upDot[j] * rightDotMinPlusDirectionDotMax[i] + directionDot[j] * upDotMaxPlusRightDotMax[i]);
        }
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // M = Cross(n*D-r*Real-u*U,A[i])
    for (auto i = 0; i < 3; ++i)
    {
        auto p = m_Frustum.GetRightBound() * Math::FAbs(upDotMinPlusDirectionDotMax[i]) + m_Frustum.GetUpBound() * Math::FAbs(rightDotMinPlusDirectionDotMax[i]);
        auto value = m_Frustum.GetDirectionMin() * upDotMaxMinusRightDotMax[i];
        auto fmin = value - p;
        if (fmin < Math::GetValue(0))
        {
            fmin *= m_Frustum.GetDirectionRatio();
        }
        auto fmax = value + p;
        if (Math::GetValue(0) < fmax)
        {
            fmax *= m_Frustum.GetDirectionRatio();
        }
        value0 = diffDot[0] * upDotMinPlusDirectionDotMax[i] - diffDot[1] * rightDotMinPlusDirectionDotMax[i] + diffDot[2] * upDotMaxMinusRightDotMax[i];
        radius = Math::GetValue(0);
        for (auto j = 0; j < 3; ++j)
        {
            radius += extents[j] * Math::FAbs(rightDot[j] * upDotMinPlusDirectionDotMax[i] - upDot[j] * rightDotMinPlusDirectionDotMax[i] + directionDot[j] * upDotMaxMinusRightDotMax[i]);
        }
        if (value0 + radius < fmin || fmax < value0 - radius)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

#include STSTEM_WARNING_POP

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_ACHIEVE_H