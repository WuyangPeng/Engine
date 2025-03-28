///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:14)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects3D/Circle3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::StaticFindIntersectorSphere3Sphere3(const Sphere3Type& sphere0, const Sphere3Type& sphere1, const Real epsilon)
    : ParentType{ epsilon }, sphere0{ sphere0 }, sphere1{ sphere1 }, circle{ Vector3Type::GetZero(), Vector3Type::GetZero(), Vector3Type::GetZero(), Vector3Type::GetZero(), MathType::GetValue(0) }, contactPoint{}
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
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere0;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::Find()
{
    // �ཻƽ�������NΪ���ߡ�
    auto center1MinusCenter0 = sphere1.GetCenter() - sphere0.GetCenter();
    auto sqrLen = Vector3ToolsType::GetLengthSquared(center1MinusCenter0);
    auto radius0 = sphere0.GetRadius();
    auto radius1 = sphere1.GetRadius();

    auto radiusSum = radius0 + radius1;
    auto radiusSumSqr = radiusSum * radiusSum;
    if (radiusSumSqr < sqrLen)
    {
        // �����ǲ��ཻ��/����ġ�
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (MathType::Approximate(sqrLen, radiusSumSqr))
    {
        // ����ոսӴ��� �����߱������GetIntersectionType() ��ȷ���������������͵��ཻ��
        // ����������£�Ӧ�õ��� GetContactPoint()��������GetCircle()�� ���ڵ����߲����Խ�������͵����������Բ�β�����
        center1MinusCenter0.Normalize();
        contactPoint = sphere0.GetCenter() + radius0 * center1MinusCenter0;
        circle = Circle3Type{ contactPoint, Vector3Type::GetZero(), Vector3Type::GetZero(), center1MinusCenter0, MathType::GetValue(0) };
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
        contactPoint = MathType::GetRational(1, 2) * (sphere0.GetCenter() + sphere1.GetCenter());
        circle = Circle3Type{ contactPoint, Vector3Type::GetZero(), Vector3Type::GetZero(), center1MinusCenter0, MathType::GetValue(0) };

        this->SetIntersectionType(radiusDiff <= MathType::GetValue(0) ? IntersectionType::Sphere0 : IntersectionType::Sphere1);
        return;
    }

    if (MathType::Approximate(sqrLen, radiusDiffSqr))
    {
        /// һ�����������һ�����У���ֻ��һ���Ӵ��㡣
        /// �����߱������GetIntersectionType()��ȷ���������������͵��ཻ��
        /// ����������£�Ӧ����GetContactPoint()��
        /// ���ڵ����߲����Խ�������͵����������Բ�β�����
        center1MinusCenter0.Normalize();

        if (radiusDiff <= MathType::GetValue(0))
        {
            contactPoint = sphere1.GetCenter() + radius1 * center1MinusCenter0;
            this->SetIntersectionType(IntersectionType::Sphere0Point);
        }
        else
        {
            contactPoint = sphere0.GetCenter() + radius0 * center1MinusCenter0;
            this->SetIntersectionType(IntersectionType::Sphere1Point);
        }

        circle = Circle3Type(contactPoint, Vector3Type::GetZero(), Vector3Type::GetZero(), center1MinusCenter0, MathType::GetValue(0));

        return;
    }

    // �����ཻԲ�������ĵ�t��K = C0 + t*(C1 - C0)��
    auto t = MathType::GetRational(1, 2) * (MathType::GetValue(1) + radiusDiff * radiusSum / sqrLen);

    // �ཻԲ�����ĺͰ뾶��

    // ����Բƽ���N��U��V��
    center1MinusCenter0.Normalize();

    const auto Vector3OrthonormalBasis = Vector3ToolsType::GenerateComplementBasis(center1MinusCenter0);
    circle = Circle3Type{ sphere0.GetCenter() + t * center1MinusCenter0, Vector3OrthonormalBasis.GetUVector(),
                      Vector3OrthonormalBasis.GetVVector(),
                      center1MinusCenter0,
                      MathType::Sqrt(MathType::FAbs(radius0 * radius0 - t * t * sqrLen)) };

    // �ཻ��һ��Բ��
    this->SetIntersectionType(IntersectionType::Circle);
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactPoint;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H