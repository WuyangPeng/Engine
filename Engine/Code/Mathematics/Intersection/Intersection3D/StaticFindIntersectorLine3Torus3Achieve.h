///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_ACHIEVE_H

#include "StaticFindIntersectorLine3Torus3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h"
#include "Mathematics/Objects3D/Torus3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Torus3<Real>::StaticFindIntersectorLine3Torus3(const Line3& line, const Torus3& torus, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, torus{ torus }, quantity{}, point0{}, point1{}, point2{}, point3{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Torus3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Torus3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetTorus() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return torus;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Torus3<Real>::Find()
{
    // 计算四次多项式的系数。
    auto outerRadiusSquare = torus.GetOuterRadius() * torus.GetOuterRadius();
    auto innerRadiusSquare = torus.GetInnerRadius() * torus.GetInnerRadius();
    auto directionDotDirection = Vector3ToolsType::DotProduct(line.GetDirection(), line.GetDirection());
    auto originDotDirection = Vector3ToolsType::DotProduct(line.GetOrigin(), line.GetDirection());
    auto dot = Vector3ToolsType::DotProduct(line.GetOrigin(), line.GetOrigin()) - (outerRadiusSquare + innerRadiusSquare);

    Polynomial<Real> poly{ 4 };
    auto zOrigin = line.GetOrigin().GetZ();
    auto zDir = line.GetDirection().GetZ();
    poly[0] = dot * dot - MathType::GetValue(4) * outerRadiusSquare * (innerRadiusSquare - zOrigin * zOrigin);
    poly[1] = MathType::GetValue(4) * originDotDirection * dot + MathType::GetValue(8) * outerRadiusSquare * zDir * zOrigin;
    poly[2] = (MathType::GetValue(2)) * directionDotDirection * dot + MathType::GetValue(4) * originDotDirection * originDotDirection + MathType::GetValue(4) * outerRadiusSquare * zDir * zDir;
    poly[3] = MathType::GetValue(4) * directionDotDirection * originDotDirection;
    poly[4] = directionDotDirection * directionDotDirection;

    // 解决四次方程。
    PolynomialRoots<Real> proots{ MathType::GetZeroTolerance() };
    if (!proots.FindBisection(poly, 6))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 获取相交点。
    for (auto begin = proots.GetBegin(); begin != proots.GetEnd(); ++begin)
    {
        auto point = line.GetOrigin() + (*begin) * line.GetDirection();
        if (quantity == 0)
            point0 = point;
        else if (quantity == 1)
            point1 = point;
        else if (quantity == 2)
            point2 = point;
        else if (quantity == 3)
            point3 = point;

        ++quantity;
    }

    this->SetIntersectionType(0 < quantity ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
        else if (index == 2)
            return point2;
        else if (index == 3)
            return point3;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s))
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_ACHIEVE_H