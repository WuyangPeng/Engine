///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/01 15:18)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "DynamicTestIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::DynamicTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, plane0{ plane0 }, plane1{ plane1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane0;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::Test()
{
    auto dot = Vector3Tools::DotProduct(plane0.GetNormal(), plane1.GetNormal());
    if (Math::FAbs(dot) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        /// ƽ��������ཻ�ġ� ���ٶȲ���ı������ཻ����ʵ��
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Line);
        return;
    }

    // ���ƽ���Ƿ��Ѿ����档
    auto diff = Math::GetValue(0);
    if (Math::GetValue(0) <= dot)
    {
        // ���߷�����ͬ����Ҫ�鿴c0 - c1��
        diff = plane0.GetConstant() - plane1.GetConstant();
    }
    else
    {
        // ���߷����෴����Ҫ�鿴c0 + c1��
        diff = plane0.GetConstant() + plane1.GetConstant();
    }

    if (Math::FAbs(diff) < Math::GetZeroTolerance())
    {
        // ƽ���������ͬ�ġ�
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Plane);
        return;
    }

    // ��Щƽ����ƽ���ҷֿ��ġ� ȷ����ʱ���ǽ���Ϊ����ġ�
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    dot = Vector3Tools::DotProduct(plane0.GetNormal(), relVelocity);
    if (Math::FAbs(dot) < Math::GetZeroTolerance())
    {
        // ƽ�������˶�ʹ���Ǳ���ƽ�С�
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetContactTime(diff / dot);
    if (Math::GetValue(0) <= this->GetContactTime() && this->GetContactTime() <= this->GetTMax())
    {
        // ƽ��˴����򣬲�����ָ����ʱ������������
        this->SetIntersectionType(IntersectionType::Plane);
        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H