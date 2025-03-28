///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:14)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Cone3<Real>::StaticFindIntersectorSphere3Cone3(const Sphere3Type& sphere, const Cone3Type& cone, const Real epsilon)
    : ParentType{ epsilon }, sphere{ sphere }, cone{ cone }, point{}
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
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Cone3<Real>::Find()
{
    // ����Բ׶�����Ƿ��������С�
    auto diff = sphere.GetCenter() - cone.GetVertex();
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto lengthSqr = Vector3ToolsType::GetLengthSquared(diff);
    if (lengthSqr <= radiusSqr)
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // ���������Ƿ���Բ׶��
    auto dot = Vector3ToolsType::DotProduct(diff, cone.GetAxis());
    auto dotSqr = dot * dot;
    auto cosSqr = cone.GetCosAngle() * cone.GetCosAngle();
    if (lengthSqr * cosSqr <= dotSqr && MathType::GetValue(0) < dot)
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

    auto length = MathType::Sqrt(MathType::FAbs(lengthSqr - dotSqr));
    auto test = cone.GetCosAngle() * dot + cone.GetSinAngle() * length;
    auto discr = test * test - lengthSqr + radiusSqr;

    // ������ӽ�����V�Ľ���
    auto t = test - MathType::Sqrt(discr);
    auto value0 = diff - dot * cone.GetAxis();
    auto value1 = cone.GetSinAngle() / length;
    point = t * (cone.GetCosAngle() * cone.GetAxis() + value1 * value0);

    if (MathType::GetValue(0) <= discr && MathType::GetValue(0) <= test)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H