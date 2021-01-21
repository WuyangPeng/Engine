///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 15:48)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H

#include "DynamicTestIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::DynamicTestIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Sphere0{ sphere0 }, m_Sphere1{ sphere1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::Test()
{
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relVelocitySquared = Vector3DTools::VectorMagnitudeSquared(relVelocity);
    auto diff = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
    auto diffSquared = Vector3DTools::VectorMagnitudeSquared(diff);
    auto radiuSum = m_Sphere0.GetRadius() + m_Sphere1.GetRadius();
    auto radiuSumSqr = radiuSum * radiuSum;

    auto result = false;
    if (Math::GetValue(0) < relVelocitySquared)
    {
        auto dot = Vector3DTools::DotProduct(diff, relVelocity);
        if (dot <= Math::GetValue(0))
        {
            if (-this->GetTMax() * relVelocitySquared <= dot)
            {
                result = relVelocitySquared * diffSquared - dot * dot <= relVelocitySquared * radiuSumSqr;
            }
            else
            {
                result = this->GetTMax() * (this->GetTMax() * relVelocitySquared + (Math::GetValue(2)) * dot) + diffSquared <= radiuSumSqr;
            }
        }
    }

    result = (diffSquared <= radiuSumSqr);
    if (result)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H