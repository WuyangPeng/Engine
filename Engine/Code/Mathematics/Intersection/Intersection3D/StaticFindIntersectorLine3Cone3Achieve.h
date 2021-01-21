///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/18 14:33)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Cone3<Real>::StaticFindIntersectorLine3Cone3(const Line3& line, const Cone3& cone, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Cone{ cone }, m_Quantity{}, m_Point0{}, m_Point1{}
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
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Cone;
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
    auto axisDotDirection = Vector3DTools::DotProduct(m_Cone.GetAxis(), m_Line.GetDirection());
    auto cosSqr = m_Cone.GetCosAngle() * m_Cone.GetCosAngle();
    auto edge = m_Line.GetOrigin() - m_Cone.GetVertex();
    auto axisDotEdge = Vector3DTools::DotProduct(m_Cone.GetVertex(), edge);
    auto directionDotEdge = Vector3DTools::DotProduct(m_Line.GetDirection(), edge);
    auto edgeDotEdge = Vector3DTools::DotProduct(edge, edge);
    auto c2 = axisDotDirection * axisDotDirection - cosSqr;
    auto c1 = axisDotDirection * axisDotEdge - cosSqr * directionDotEdge;
    auto c0 = axisDotEdge * axisDotEdge - cosSqr * edgeDotEdge;

    // ����η��� ������ Dot(A,X - V) >= 0����ЩX��
    if (Math::GetZeroTolerance() <= Math::FAbs(c2))
    {
        // c2 != 0
        auto discr = c1 * c1 - c0 * c2;
        if (discr < Math::GetValue(0))
        {
            // Q(t) = 0 û��ʵֵ���� ���߲���˫��Բ׶�ཻ��
            this->SetIntersectionType(IntersectionType::Empty);
            m_Quantity = 0;
        }
        else if (discr > Math::GetZeroTolerance())
        {
            // Q(t) = 0����������ͬ��ʵֵ���� ���ǣ������е�һ���������������붥�㡰�󡱵�˫��Բ׶�岿���ཻ��
            // ���ǽ��Զ��㡰ǰ�桱����Щ�������Ȥ��
            auto root = Math::Sqrt(discr);

            m_Quantity = 0;

            auto t = (-c1 - root) / c2;
            m_Point0 = m_Line.GetOrigin() + t * m_Line.GetDirection();
            edge = m_Point0 - m_Cone.GetVertex();
            auto dot = Vector3DTools::DotProduct(edge, m_Cone.GetAxis());
            if (Math::GetValue(0) < dot)
            {
                ++m_Quantity;
            }

            t = (-c1 + root) / c2;

            if (m_Quantity == 0)
            {
                m_Point0 = m_Line.GetOrigin() + t * m_Line.GetDirection();
                edge = m_Point0 - m_Cone.GetVertex();
            }
            else
            {
                m_Point1 = m_Line.GetOrigin() + t * m_Line.GetDirection();
                edge = m_Point1 - m_Cone.GetVertex();
            }

            dot = Vector3DTools::DotProduct(edge, m_Cone.GetAxis());
            if (Math::GetValue(0) < dot)
            {
                ++m_Quantity;
            }

            if (m_Quantity == 2)
            {
                // �����붥��ǰ��ĵ���Բ׶�ཻ���Ρ�
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (m_Quantity == 1)
            {
                // �����붥��ǰ��ĵ���Բ׶�ཻһ�Ρ� ��һ�������Ƕ������ĵ���Բ׶��
                this->SetIntersectionType(IntersectionType::Ray);
                ++m_Quantity;
                m_Point1 = m_Line.GetDirection();
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
            m_Point0 = m_Line.GetOrigin() - (c1 / c2) * m_Line.GetDirection();
            edge = m_Point0 - m_Cone.GetVertex();
            if (Math::GetValue(0) < Vector3DTools::DotProduct(edge, m_Cone.GetAxis()))
            {
                this->SetIntersectionType(IntersectionType::Point);
                m_Quantity = 1;
            }
            else
            {
                this->SetIntersectionType(IntersectionType::Empty);
                m_Quantity = 0;
            }
        }
    }
    else if (Math::GetZeroTolerance() <= Math::FAbs(c1))
    {
        // c2 = 0, c1 != 0 ��D��Բ׶�߽��ϵķ���������
        m_Point0 = m_Line.GetOrigin() - (Math::GetRational(1, 2) * c0 / c1) * m_Line.GetDirection();
        edge = m_Point0 - m_Cone.GetVertex();
        auto dot = Vector3DTools::DotProduct(edge, m_Cone.GetAxis());
        if (Math::GetValue(0) < dot)
        {
            this->SetIntersectionType(IntersectionType::Ray);
            m_Quantity = 2;
            m_Point1 = m_Line.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
            m_Quantity = 0;
        }
    }
    else if (Math::GetZeroTolerance() <= Math::FAbs(c0))
    {
        // c2 = c1 = 0, c0 != 0
        this->SetIntersectionType(IntersectionType::Empty);
        m_Quantity = 0;
    }
    else
    {
        // c2 = c1 = c0 = 0��Բ׶��������V + t * D������V��Բ׶���㣬D���߷���
        this->SetIntersectionType(IntersectionType::Ray);
        m_Quantity = 2;
        m_Point0 = m_Cone.GetVertex();
        m_Point1 = m_Line.GetDirection();
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Cone3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H