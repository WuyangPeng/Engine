///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 14:33)

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
    /// 设置对应于圆锥的二次Q(t) = c2 * t^2 + 2 * c1 * t + c0。
    /// 设顶点为V，单位长度方向向量为A，从锥轴到锥壁的角度为Theta，定义 g = cos(Theta)。
    /// 每当Dot(A,(X - V)/|X - V|) = g时，点X就会在锥壁上。
    /// 将该方程式和因子平方，得到(X - V)^T * (A * A^T - g^2 * I) * (X - V) = 0，其中上标T表示转置算符。
    /// 这定义了一个双面锥体。 线是L(t) = P + t * D，其中P是线的原点，D是单位长度方向的向量。
    /// 将X = L(t)代入上述圆锥方程式，将得出 Q(t) = 0。
    /// 由于我们只希望单面圆锥上的交点位于A指向的半空间中，因此任意点 L(t) ,由Q(t) = 0的根生成的，必须测试Dot(A,L(t) - V) >= 0。
    auto axisDotDirection = Vector3DTools::DotProduct(m_Cone.GetAxis(), m_Line.GetDirection());
    auto cosSqr = m_Cone.GetCosAngle() * m_Cone.GetCosAngle();
    auto edge = m_Line.GetOrigin() - m_Cone.GetVertex();
    auto axisDotEdge = Vector3DTools::DotProduct(m_Cone.GetVertex(), edge);
    auto directionDotEdge = Vector3DTools::DotProduct(m_Line.GetDirection(), edge);
    auto edgeDotEdge = Vector3DTools::DotProduct(edge, edge);
    auto c2 = axisDotDirection * axisDotDirection - cosSqr;
    auto c1 = axisDotDirection * axisDotEdge - cosSqr * directionDotEdge;
    auto c0 = axisDotEdge * axisDotEdge - cosSqr * edgeDotEdge;

    // 解二次方。 仅保留 Dot(A,X - V) >= 0的那些X。
    if (Math::GetZeroTolerance() <= Math::FAbs(c2))
    {
        // c2 != 0
        auto discr = c1 * c1 - c0 * c2;
        if (discr < Math::GetValue(0))
        {
            // Q(t) = 0 没有实值根。 该线不与双面圆锥相交。
            this->SetIntersectionType(IntersectionType::Empty);
            m_Quantity = 0;
        }
        else if (discr > Math::GetZeroTolerance())
        {
            // Q(t) = 0具有两个不同的实值根。 但是，它们中的一个或两个都可能与顶点“后”的双面圆锥体部分相交。
            // 我们仅对顶点“前面”的那些交点感兴趣。
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
                // 该线与顶点前面的单面圆锥相交两次。
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (m_Quantity == 1)
            {
                // 该线与顶点前面的单面圆锥相交一次。 另一个交点是顶点后面的单面圆锥。
                this->SetIntersectionType(IntersectionType::Ray);
                ++m_Quantity;
                m_Point1 = m_Line.GetDirection();
            }
            else
            {
                // 该线与顶点后的单面圆锥相交两次。
                this->SetIntersectionType(IntersectionType::Empty);
            }
        }
        else
        {
            // 一个重复的实根（线与圆锥相切）。
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
        // c2 = 0, c1 != 0 （D是圆锥边界上的方向向量）
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
        // c2 = c1 = c0 = 0，圆锥包含光线V + t * D，其中V是圆锥顶点，D是线方向。
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

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H