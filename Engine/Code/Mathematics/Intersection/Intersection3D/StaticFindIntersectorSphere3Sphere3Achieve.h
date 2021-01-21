///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/21 11:22)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects3D/Circle3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::StaticFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, const Real epsilon)
    : ParentType{ epsilon }, m_Sphere0{ sphere0 }, m_Sphere1{ sphere1 }, m_Circle{ Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Math::GetValue(0) }, m_ContactPoint{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::Find()
{
    // �ཻƽ�������NΪ���ߡ�
    auto center1MinusCenter0 = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
    auto sqrLen = Vector3DTools::VectorMagnitudeSquared(center1MinusCenter0);
    auto radius0 = m_Sphere0.GetRadius();
    auto radius1 = m_Sphere1.GetRadius();

    auto radiusSum = radius0 + radius1;
    auto radiusSumSqr = radiusSum * radiusSum;
    if (radiusSumSqr < sqrLen)
    {
        // �����ǲ��ཻ��/����ġ�
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (Math::Approximate(sqrLen, radiusSumSqr))
    {
        // ����ոսӴ��� �����߱������GetIntersectionType() ��ȷ���������������͵��ཻ��
        // ����������£�Ӧ�õ��� GetContactPoint()��������GetCircle()�� ���ڵ����߲����Խ�������͵����������Բ�β�����
        center1MinusCenter0.Normalize();
        m_ContactPoint = m_Sphere0.GetCenter() + radius0 * center1MinusCenter0;
        m_Circle = Circle3{ m_ContactPoint, Vector3D::GetZero(), Vector3D::GetZero(), center1MinusCenter0, Math::GetValue(0) };
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    auto radiusDiff = radius0 - radius1;
    auto radiusDiffSqr = radiusDiff * radiusDiff;
    if (sqrLen < radiusDiffSqr)
    {
        /// һ�������ϸ��������һ�������С� �����߱������ GetIntersectionType()��ȷ���������������͵��ཻ��
        /// ����������£���Ӧ����GetCircle()��GetContactPoint()��
        ///  ���ڵ����߲����Խ�������͵����������Բ�κͽӴ���������ѡ��������ġ�
        center1MinusCenter0.Normalize();
        m_ContactPoint = Math::GetRational(1, 2) * (m_Sphere0.GetCenter() + m_Sphere1.GetCenter());
        m_Circle = Circle3{ m_ContactPoint, Vector3D::GetZero(), Vector3D::GetZero(), center1MinusCenter0, Math::GetValue(0) };

        this->SetIntersectionType(radiusDiff <= Math::GetValue(0) ? IntersectionType::Sphere0 : IntersectionType::Sphere1);
        return;
    }

    if (Math::Approximate(sqrLen, radiusDiffSqr))
    {
        /// һ�����������һ�����У���ֻ��һ���Ӵ��㡣
        /// �����߱������GetIntersectionType()��ȷ���������������͵��ཻ��
        /// ����������£�Ӧ����GetContactPoint()��
        /// ���ڵ����߲����Խ�������͵����������Բ�β�����
        center1MinusCenter0.Normalize();

        if (radiusDiff <= Math::GetValue(0))
        {
            m_ContactPoint = m_Sphere1.GetCenter() + radius1 * center1MinusCenter0;
            this->SetIntersectionType(IntersectionType::Sphere0Point);
        }
        else
        {
            m_ContactPoint = m_Sphere0.GetCenter() + radius0 * center1MinusCenter0;
            this->SetIntersectionType(IntersectionType::Sphere1Point);
        }

        m_Circle = Circle3(m_ContactPoint, Vector3D::GetZero(), Vector3D::GetZero(), center1MinusCenter0, Math::GetValue(0));

        return;
    }

    // �����ཻԲ�������ĵ�t��K = C0 + t*(C1 - C0)��
    auto t = Math::GetRational(1, 2) * (Math::GetValue(1) + radiusDiff * radiusSum / sqrLen);

    // �ཻԲ�����ĺͰ뾶��

    // ����Բƽ���N��U��V��
    center1MinusCenter0.Normalize();

    const auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(center1MinusCenter0);
    m_Circle = Circle3{ m_Sphere0.GetCenter() + t * center1MinusCenter0, vector3DOrthonormalBasis.GetUVector(),
                        vector3DOrthonormalBasis.GetVVector(), center1MinusCenter0,
                        Math::Sqrt(Math::FAbs(radius0 * radius0 - t * t * sqrLen)) };

    // �ཻ��һ��Բ��
    this->SetIntersectionType(IntersectionType::Circle);
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ContactPoint;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H