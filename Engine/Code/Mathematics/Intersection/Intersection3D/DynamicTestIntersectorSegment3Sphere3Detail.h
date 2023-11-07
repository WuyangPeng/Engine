///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "DynamicTestIntersectorSegment3Sphere3.h"
#include "StaticTestIntersectorSegment3Capsule3Detail.h"
#include "StaticTestIntersectorSegment3Sphere3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::DynamicTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tMax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, segment{ segment }, sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::Test()
{
    // �������Ƿ��ཻ��
    StaticTestIntersectorSegment3Sphere3<Real> inte{ segment, sphere };
    this->SetIntersectionType(inte.GetIntersectionType());
    if (inte.IsIntersection())
    {
        return;
    }

    /// �������ٶ��м�ȥ�߶��ٶȣ��Ա��������߶ε�����ϵ��
    /// �ڸ�ϵͳ�У���·��Ȼ�ǹ̶��ġ� �����Խһ�����ң�����ȡ����֮���ǣ����ǽ���������뾶�������߶Σ��������������������ġ�
    /// ���ڵ������Ǽ���ƶ����ĵ�һ�������߶κ�����뾶�γɵĽ����ཻ��

    const Capsule3<Real> capsule{ segment, sphere.GetRadius() };

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relSpeed = Vector3Tools::GetLength(relVelocity);
    relVelocity.Normalize();
    const Segment3 path{ (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed, sphere.GetCenter() + (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed * relVelocity, relVelocity };

    StaticTestIntersectorSegment3Capsule3<Real> intersector{ path, capsule };
    this->SetIntersectionType(intersector.GetIntersectionType());
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H