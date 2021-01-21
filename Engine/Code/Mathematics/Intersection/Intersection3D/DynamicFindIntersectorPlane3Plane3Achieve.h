///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/04 16:55)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H

#include "DynamicFindIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::DynamicFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Plane0{ plane0 }, m_Plane1{ plane1 }, m_IntersectionLine{ Vector3D::GetZero(), Vector3D::GetZero() }, m_IntersectionPlane{}
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
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane1;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::Find()
{
    auto dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal());
    if (Math::FAbs(dot) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        // ��������ཻ�ġ� ���ٶȲ���ı������ཻ����ʵ��
        this->SetContactTime(Math::GetValue(0));

        auto invDet = (Math::GetValue(1)) / (Math::GetValue(1) - dot * dot);
        auto c0 = (m_Plane0.GetConstant() - dot * m_Plane1.GetConstant()) * invDet;
        auto c1 = (m_Plane1.GetConstant() - dot * m_Plane0.GetConstant()) * invDet;
        this->SetIntersectionType(IntersectionType::Line);
        m_IntersectionLine = Line3{ c0 * m_Plane0.GetNormal() + c1 * m_Plane1.GetNormal(), Vector3DTools::UnitCrossProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal()) };

        return;
    }

    // ���ƽ���Ƿ��Ѿ����档
    auto diff = Math::GetValue(0);
    if (Math::GetValue(0) <= dot)
    {
        // ���߷�����ͬ����Ҫ�鿴c0 - c1��
        diff = m_Plane0.GetConstant() - m_Plane1.GetConstant();
    }
    else
    {
        // ���߷����෴����Ҫ�鿴c0 + c1��
        diff = m_Plane0.GetConstant() + m_Plane1.GetConstant();
    }

    if (Math::FAbs(diff) < Math::GetZeroTolerance())
    {
        // ƽ���������ͬ�ġ�
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Plane);

        m_IntersectionPlane = m_Plane0;
        return;
    }

    // ��Щƽ����ƽ���ҷֿ��ġ� ȷ����ʱ���ǽ���Ϊ����ġ�
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), relVelocity);
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
        m_IntersectionPlane = Plane3{ m_Plane0.GetNormal(), m_Plane0.GetConstant() + this->GetContactTime() * (Vector3DTools::DotProduct(m_Plane0.GetNormal(), this->GetLhsVelocity())) };

        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetIntersectionLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntersectionLine;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorPlane3Plane3<Real>::GetIntersectionPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntersectionPlane;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H