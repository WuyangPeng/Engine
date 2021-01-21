///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/21 11:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Cone3<Real>::StaticFindIntersectorSphere3Cone3(const Sphere3& sphere, const Cone3& cone, const Real epsilon)
    : ParentType{ epsilon }, m_Sphere{ sphere }, m_Cone{ cone }, m_Point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSphere3Cone3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Cone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Cone3<Real>::Find()
{
    // ����Բ׶�����Ƿ��������С�
    auto diff = m_Sphere.GetCenter() - m_Cone.GetVertex();
    auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto lengthSqr = Vector3DTools::VectorMagnitudeSquared(diff);
    if (lengthSqr <= radiusSqr)
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // ���������Ƿ���Բ׶��
    auto dot = Vector3DTools::DotProduct(diff, m_Cone.GetAxis());
    auto dotSqr = dot * dot;
    auto cosSqr = m_Cone.GetCosAngle() * m_Cone.GetCosAngle();
    if (lengthSqr * cosSqr <= dotSqr && Math::GetValue(0) < dot)
    {
        // ����������Բ׶���ڲ�����������Բ׶���ཻ��
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    /// ����������Բ׶���ⲿ�� ���ڵ������Ϊ�ڰ���Բ׶���㲢��Բ׶��ʹӶ��㵽�������ĵ�������Խ��ƽ����Ѱ��Բ������֮��Ľ��㡣

    /// ������ t * D + V (t >= 0)������|D| = 1��dot(A,D) = cos(angle)��
    /// ͬ����D = e * A + f * (C - V)�� �����߷���ʽ�������淽��ʽ�����Real^2 = |t * D + V - C|^2��
    /// ��˽���Ķ��η�Ϊt^2 - 2 * dot(D,C - V) * t + |C - V|^2 - Real^2 = 0��
    /// ���ҽ����б�ʽΪ�Ǹ�ʱ���ŷ��������� ������Ա��
    /// dot(D,C - V)^2 >= dot(C - V,C - V) - Real^2
    /// ע�⣬����Ҳ�Ϊ�������򲻵�ʽΪtrue���������V���� ���Ѿ��ڴ˺����ĵ�һ�δ������ų�����һ��

    auto uLength = Math::Sqrt(Math::FAbs(lengthSqr - dotSqr));
    auto test = m_Cone.GetCosAngle() * dot + m_Cone.GetSinAngle() * uLength;
    auto discr = test * test - lengthSqr + radiusSqr;

    // ������ӽ�����V�Ľ���
    auto t = test - Math::Sqrt(discr);
    auto value0 = diff - dot * m_Cone.GetAxis();
    auto value1 = m_Cone.GetSinAngle() / uLength;
    m_Point = t * (m_Cone.GetCosAngle() * m_Cone.GetAxis() + value1 * value0);

    if (Math::GetValue(0) <= discr && Math::GetValue(0) <= test)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H