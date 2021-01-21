///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/20 17:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Plane3<Real>::StaticFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, const Real epsilon)
    : ParentType{ epsilon }, m_Plane0{ plane0 }, m_Plane1{ plane1 }, m_IntrLine{ Vector3D::GetZero(), Vector3D::GetZero() }, m_IntrPlane{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Plane3<Real>::Find()
{
    /// ���N0��N1ƽ�У�������ƽ��ƽ���ҷֿ�����ͬһƽ���ϡ�
    /// ������������£������ء� false���� ���򣬽���Ϊ L(t) = t * Cross(N0,N1) / |Cross(N0,N1)| + c0 * N0 + c1 * N1
    /// ����ĳЩϵ��c0��c1������t����ʵ�����в�������
    /// �뷨��һ��ȡ�����
    ///   d0 = Dot(N0,L) = c0 * Dot(N0,N0) + c1 * Dot(N0,N1) = c0 + c1 * d
    ///   d1 = Dot(N1,L) = c0 * Dot(N0,N1) + c1 * Dot(N1,N1) = c0 * d + c1
    /// ����d = Dot(N0,N1)�� ��������δ֪���е��������̡� ���������
    ///   c0 = (d0 - d * d1) / det
    ///   c1 = (d1 - d * d0) / det
    /// ����det = 1 - d^2��

    auto dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal());
    if (Math::GetValue(1) - Math::GetZeroTolerance() <= Math::FAbs(dot))
    {
        // ��Щƽ����ƽ�еġ� ��������Ƿ��档
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
            // ƽ�湲�档
            this->SetIntersectionType(IntersectionType::Plane);
            m_IntrPlane = m_Plane0;
            return;
        }

        // ƽ����ƽ�еģ�����Ȼ��ͬ��
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto invDet = (Math::GetValue(1)) / (Math::GetValue(1) - dot * dot);
    auto c0 = (m_Plane0.GetConstant() - dot * m_Plane1.GetConstant()) * invDet;
    auto c1 = (m_Plane1.GetConstant() - dot * m_Plane0.GetConstant()) * invDet;
    this->SetIntersectionType(IntersectionType::Line);
    m_IntrLine = Line3{ c0 * m_Plane0.GetNormal() + c1 * m_Plane1.GetNormal(), Vector3DTools::UnitCrossProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal()) };
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetIntersectionLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntrLine;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetIntersectionPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntrPlane;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H