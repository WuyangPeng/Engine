///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_DETAIL_H

#include "StaticTestIntersectorSphere3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSphere3Cone3<Real>::StaticTestIntersectorSphere3Cone3(const Sphere3Type& sphere, const Cone3Type& cone, const Real epsilon)
    : ParentType{ epsilon }, sphere{ sphere }, cone{ cone }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSphere3Cone3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Cone3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
Mathematics::Cone3<Real> Mathematics::StaticTestIntersectorSphere3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cone;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSphere3Cone3<Real>::Test()
{
    auto invSin = MathType::GetValue(1) / cone.GetSinAngle();
    auto cosSqr = cone.GetCosAngle() * cone.GetCosAngle();

    auto cmv = sphere.GetCenter() - cone.GetVertex();
    auto d = cmv + (sphere.GetRadius() * invSin) * cone.GetAxis();
    auto dSqrLen = Vector3ToolsType::GetLengthSquared(d);
    auto e = Vector3ToolsType::DotProduct(d, cone.GetAxis());
    if (MathType ::GetValue(0) < e && e * e >= dSqrLen * cosSqr)
    {
        auto sinSqr = cone.GetSinAngle() * cone.GetSinAngle();
        dSqrLen = Vector3ToolsType::GetLengthSquared(cmv);
        e = -Vector3ToolsType::DotProduct(cmv, cone.GetAxis());
        if (MathType ::GetValue(0) < e && dSqrLen * sinSqr <= e * e)
        {
            auto rSqr = sphere.GetRadius() * sphere.GetRadius();
            if (dSqrLen <= rSqr)
            {
                this->SetIntersectionType(IntersectionType::Other);
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
            }
        }

        this->SetIntersectionType(IntersectionType::Other);
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_DETAIL_H