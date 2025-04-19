///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:48)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Cone3<Real>::StaticFindIntersectorLine3Cone3(const Line3Type& line, const Cone3Type& cone, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, cone{ cone }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Cone3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Cone3<Real>::Find()
{
    /// ���ö�Ӧ��Բ׶�Ķ���Q(t) = c2 * t^2 + 2 * c1 * t + c0��
    /// �趥��ΪV����λ���ȷ�������ΪA����׶�ᵽ׶�ڵĽǶ�ΪTheta������ g = cos(Theta)��
    /// ÿ��Dot(A,(X - V)/|X - V|) = gʱ����X�ͻ���׶���ϡ�
    /// ���÷���ʽ������ƽ�����õ�(X - V)^T * (A * A^T - g^2 * I) * (X - V) = 0�������ϱ�T��ʾת�������
    /// �ⶨ����һ��˫��׶�塣 ����L(t) = P + t * D������P���ߵ�ԭ�㣬D�ǵ�λ���ȷ����������
    /// ��X = L(t)��������Բ׶����ʽ�����ó� Q(t) = 0��
    /// ��������ֻϣ������Բ׶�ϵĽ���λ��Aָ��İ�ռ��У��������� L(t) ,��Q(t) = 0�ĸ����ɵģ��������Dot(A,L(t) - V) >= 0��
    auto axisDotDirection = Vector3ToolsType::DotProduct(cone.GetAxis(), line.GetDirection());
    auto cosSqr = cone.GetCosAngle() * cone.GetCosAngle();
    auto edge = line.GetOrigin() - cone.GetVertex();
    auto axisDotEdge = Vector3ToolsType::DotProduct(cone.GetVertex(), edge);
    auto directionDotEdge = Vector3ToolsType::DotProduct(line.GetDirection(), edge);
    auto edgeDotEdge = Vector3ToolsType::DotProduct(edge, edge);
    auto c2 = axisDotDirection * axisDotDirection - cosSqr;
    auto c1 = axisDotDirection * axisDotEdge - cosSqr * directionDotEdge;
    auto c0 = axisDotEdge * axisDotEdge - cosSqr * edgeDotEdge;

    // ����η��� ������ Dot(A,X - V) >= 0����ЩX��
    if (MathType::GetZeroTolerance() <= MathType::FAbs(c2))
    {
        // c2 != 0
        auto discr = c1 * c1 - c0 * c2;
        if (discr < MathType::GetValue(0))
        {
            // Q(t) = 0 û��ʵֵ���� ���߲���˫��Բ׶�ཻ��
            this->SetIntersectionType(IntersectionType::Empty);
            quantity = 0;
        }
        else if (discr > MathType::GetZeroTolerance())
        {
            // Q(t) = 0����������ͬ��ʵֵ���� ���ǣ������е�һ���������������붥�㡰�󡱵�˫��Բ׶�岿���ཻ��
            // ���ǽ��Զ��㡰ǰ�桱����Щ�������Ȥ��
            auto root = MathType::Sqrt(discr);

            quantity = 0;

            auto t = (-c1 - root) / c2;
            point0 = line.GetOrigin() + t * line.GetDirection();
            edge = point0 - cone.GetVertex();
            auto dot = Vector3ToolsType::DotProduct(edge, cone.GetAxis());
            if (MathType::GetValue(0) < dot)
            {
                ++quantity;
            }

            t = (-c1 + root) / c2;

            if (quantity == 0)
            {
                point0 = line.GetOrigin() + t * line.GetDirection();
                edge = point0 - cone.GetVertex();
            }
            else
            {
                point1 = line.GetOrigin() + t * line.GetDirection();
                edge = point1 - cone.GetVertex();
            }

            dot = Vector3ToolsType::DotProduct(edge, cone.GetAxis());
            if (MathType::GetValue(0) < dot)
            {
                ++quantity;
            }

            if (quantity == 2)
            {
                // �����붥��ǰ��ĵ���Բ׶�ཻ���Ρ�
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (quantity == 1)
            {
                // �����붥��ǰ��ĵ���Բ׶�ཻһ�Ρ� ��һ�������Ƕ������ĵ���Բ׶��
                this->SetIntersectionType(IntersectionType::Ray);
                ++quantity;
                point1 = line.GetDirection();
            }
            else
            {
                // �����붥���ĵ���Բ׶�ཻ���Ρ�
                this->SetIntersectionType(IntersectionType::Empty);
            }
        }
        else
        {
            // һ���ظ���ʵ��������Բ׶���У���
            point0 = line.GetOrigin() - (c1 / c2) * line.GetDirection();
            edge = point0 - cone.GetVertex();
            if (MathType::GetValue(0) < Vector3ToolsType::DotProduct(edge, cone.GetAxis()))
            {
                this->SetIntersectionType(IntersectionType::Point);
                quantity = 1;
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
                quantity = 0;
            }
        }
    }
    else if (MathType::GetZeroTolerance() <= MathType::FAbs(c1))
    {
        // c2 = 0, c1 != 0 ��D��Բ׶�߽��ϵķ���������
        point0 = line.GetOrigin() - (MathType::GetRational(1, 2) * c0 / c1) * line.GetDirection();
        edge = point0 - cone.GetVertex();
        auto dot = Vector3ToolsType::DotProduct(edge, cone.GetAxis());
        if (MathType::GetValue(0) < dot)
        {
            this->SetIntersectionType(IntersectionType::Ray);
            quantity = 2;
            point1 = line.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
            quantity = 0;
        }
    }
    else if (MathType::GetZeroTolerance() <= MathType::FAbs(c0))
    {
        // c2 = c1 = 0, c0 != 0
        this->SetIntersectionType(IntersectionType::Empty);
        quantity = 0;
    }
    else
    {
        // c2 = c1 = c0 = 0��Բ׶��������V + t * D������V��Բ׶���㣬D���߷���
        this->SetIntersectionType(IntersectionType::Ray);
        quantity = 2;
        point0 = cone.GetVertex();
        point1 = line.GetDirection();
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H