///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/15 10:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H

#include "DynamicTestIntersectorSegment3Sphere3.h"
#include "StaticTestIntersectorSegment3Capsule3Detail.h"
#include "StaticTestIntersectorSegment3Sphere3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::DynamicTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Segment{ segment }, m_Sphere{ sphere }
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
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::Test()
{
    // �������Ƿ��ཻ��
    StaticTestIntersectorSegment3Sphere3<Real> inte{ m_Segment, m_Sphere };
    this->SetIntersectionType(inte.GetIntersectionType());
    if (inte.IsIntersection())
    {
        return;
    }

    /// �������ٶ��м�ȥ�߶��ٶȣ��Ա��������߶ε�����ϵ��
    /// �ڸ�ϵͳ�У���·��Ȼ�ǹ̶��ġ� �����Խһ�����ң�����ȡ����֮���ǣ����ǽ���������뾶�������߶Σ��������������������ġ�
    /// ���ڵ������Ǽ���ƶ����ĵ�һ�������߶κ�����뾶�γɵĽ����ཻ��

    const Capsule3<Real> capsule{ m_Segment, m_Sphere.GetRadius() };

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relSpeed = Vector3DTools::VectorMagnitude(relVelocity);
    relVelocity.Normalize();
    const Segment3 path{ (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed, m_Sphere.GetCenter() + (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed * relVelocity, relVelocity };

    StaticTestIntersectorSegment3Capsule3<Real> intersector{ path, capsule };
    this->SetIntersectionType(intersector.GetIntersectionType());
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H