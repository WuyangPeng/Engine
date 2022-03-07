///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/01 15:51)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "DynamicTestIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::DynamicTestIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, sphere0{ sphere0 }, sphere1{ sphere1 }
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
Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere0;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSphere3Sphere3<Real>::Test()
{
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relVelocitySquared = Vector3Tools::GetLengthSquared(relVelocity);
    auto diff = sphere1.GetCenter() - sphere0.GetCenter();
    auto diffSquared = Vector3Tools::GetLengthSquared(diff);
    auto radiuSum = sphere0.GetRadius() + sphere1.GetRadius();
    auto radiuSumSqr = radiuSum * radiuSum;

    auto result = false;
    if (Math::GetValue(0) < relVelocitySquared)
    {
        auto dot = Vector3Tools::DotProduct(diff, relVelocity);
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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H