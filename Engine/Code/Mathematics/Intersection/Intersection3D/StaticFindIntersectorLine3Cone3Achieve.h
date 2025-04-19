///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:48)

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
    /// 设置对应于圆锥的二次Q(t) = c2 * t^2 + 2 * c1 * t + c0。
    /// 设顶点为V，单位长度方向向量为A，从锥轴到锥壁的角度为Theta，定义 g = cos(Theta)。
    /// 每当Dot(A,(X - V)/|X - V|) = g时，点X就会在锥壁上。
    /// 将该方程式和因子平方，得到(X - V)^T * (A * A^T - g^2 * I) * (X - V) = 0，其中上标T表示转置算符。
    /// 这定义了一个双面锥体。 线是L(t) = P + t * D，其中P是线的原点，D是单位长度方向的向量。
    /// 将X = L(t)代入上述圆锥方程式，将得出 Q(t) = 0。
    /// 由于我们只希望单面圆锥上的交点位于A指向的半空间中，因此任意点 L(t) ,由Q(t) = 0的根生成的，必须测试Dot(A,L(t) - V) >= 0。
    auto axisDotDirection = Vector3ToolsType::DotProduct(cone.GetAxis(), line.GetDirection());
    auto cosSqr = cone.GetCosAngle() * cone.GetCosAngle();
    auto edge = line.GetOrigin() - cone.GetVertex();
    auto axisDotEdge = Vector3ToolsType::DotProduct(cone.GetVertex(), edge);
    auto directionDotEdge = Vector3ToolsType::DotProduct(line.GetDirection(), edge);
    auto edgeDotEdge = Vector3ToolsType::DotProduct(edge, edge);
    auto c2 = axisDotDirection * axisDotDirection - cosSqr;
    auto c1 = axisDotDirection * axisDotEdge - cosSqr * directionDotEdge;
    auto c0 = axisDotEdge * axisDotEdge - cosSqr * edgeDotEdge;

    // 解二次方。 仅保留 Dot(A,X - V) >= 0的那些X。
    if (MathType::GetZeroTolerance() <= MathType::FAbs(c2))
    {
        // c2 != 0
        auto discr = c1 * c1 - c0 * c2;
        if (discr < MathType::GetValue(0))
        {
            // Q(t) = 0 没有实值根。 该线不与双面圆锥相交。
            this->SetIntersectionType(IntersectionType::Empty);
            quantity = 0;
        }
        else if (discr > MathType::GetZeroTolerance())
        {
            // Q(t) = 0具有两个不同的实值根。 但是，它们中的一个或两个都可能与顶点“后”的双面圆锥体部分相交。
            // 我们仅对顶点“前面”的那些交点感兴趣。
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
                // 该线与顶点前面的单面圆锥相交两次。
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (quantity == 1)
            {
                // 该线与顶点前面的单面圆锥相交一次。 另一个交点是顶点后面的单面圆锥。
                this->SetIntersectionType(IntersectionType::Ray);
                ++quantity;
                point1 = line.GetDirection();
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
        // c2 = 0, c1 != 0 （D是圆锥边界上的方向向量）
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
        // c2 = c1 = c0 = 0，圆锥包含光线V + t * D，其中V是圆锥顶点，D是线方向。
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

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_ACHIEVE_H