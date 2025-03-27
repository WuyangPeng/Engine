///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:12)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "DynamicFindIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::DynamicFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, plane0{ plane0 }, plane1{ plane1 }, intersectionLine{ Vector3::GetZero(), Vector3::GetZero() }, intersectionPlane{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane0;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane1;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::Find()
{
    auto dot = Vector3Tools::DotProduct(plane0.GetNormal(), plane1.GetNormal());
    if (MathType::FAbs(dot) < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        // ��������ཻ�ġ� ���ٶȲ���ı������ཻ����ʵ��
        this->SetContactTime(MathType::GetValue(0));

        auto invDet = (MathType::GetValue(1)) / (MathType::GetValue(1) - dot * dot);
        auto c0 = (plane0.GetConstant() - dot * plane1.GetConstant()) * invDet;
        auto c1 = (plane1.GetConstant() - dot * plane0.GetConstant()) * invDet;
        this->SetIntersectionType(IntersectionType::Line);
        intersectionLine = Line3{ c0 * plane0.GetNormal() + c1 * plane1.GetNormal(), Vector3Tools::UnitCrossProduct(plane0.GetNormal(), plane1.GetNormal()) };

        return;
    }

    // ���ƽ���Ƿ��Ѿ����档
    auto diff = MathType::GetValue(0);
    if (MathType::GetValue(0) <= dot)
    {
        // ���߷�����ͬ����Ҫ�鿴c0 - c1��
        diff = plane0.GetConstant() - plane1.GetConstant();
    }
    else
    {
        // ���߷����෴����Ҫ�鿴c0 + c1��
        diff = plane0.GetConstant() + plane1.GetConstant();
    }

    if (MathType::FAbs(diff) < MathType::GetZeroTolerance())
    {
        // ƽ���������ͬ�ġ�
        this->SetContactTime(MathType::GetValue(0));
        this->SetIntersectionType(IntersectionType::Plane);

        intersectionPlane = plane0;
        return;
    }

    // ��Щƽ����ƽ���ҷֿ��ġ� ȷ����ʱ���ǽ���Ϊ����ġ�
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    dot = Vector3Tools::DotProduct(plane0.GetNormal(), relVelocity);
    if (MathType::FAbs(dot) < MathType::GetZeroTolerance())
    {
        // ƽ�������˶�ʹ���Ǳ���ƽ�С�
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetContactTime(diff / dot);
    if (MathType::GetValue(0) <= this->GetContactTime() && this->GetContactTime() <= this->GetTMax())
    {
        // ƽ��˴����򣬲�����ָ����ʱ������������
        this->SetIntersectionType(IntersectionType::Plane);
        intersectionPlane = Plane3{ plane0.GetNormal(), plane0.GetConstant() + this->GetContactTime() * (Vector3Tools::DotProduct(plane0.GetNormal(), this->GetLhsVelocity())) };

        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetIntersectionLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersectionLine;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetIntersectionPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersectionPlane;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_DETAIL_H