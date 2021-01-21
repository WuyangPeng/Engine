///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 13:24)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_ACHIEVE_H

#include "StaticFindIntersectorLine3Torus3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h"
#include "Mathematics/Objects3D/Torus3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Torus3<Real>::StaticFindIntersectorLine3Torus3(const Line3& line, const Torus3& torus, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Torus{ torus }, m_Quantity{}, m_Point0{}, m_Point1{}, m_Point2{}, m_Point3{}
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
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Torus3<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetTorus() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Torus;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Torus3<Real>::Find()
{
    // 计算四次多项式的系数。
    auto outerRadiusSquare = m_Torus.GetOuterRadius() * m_Torus.GetOuterRadius();
    auto innerRadiusSquare = m_Torus.GetInnerRadius() * m_Torus.GetInnerRadius();
    auto directionDotDirection = Vector3DTools::DotProduct(m_Line.GetDirection(), m_Line.GetDirection());
    auto originDotDirection = Vector3DTools::DotProduct(m_Line.GetOrigin(), m_Line.GetDirection());
    auto dot = Vector3DTools::DotProduct(m_Line.GetOrigin(), m_Line.GetOrigin()) - (outerRadiusSquare + innerRadiusSquare);

    Polynomial<Real> poly{ 4 };
    auto zOrigin = m_Line.GetOrigin().GetZ();
    auto zDir = m_Line.GetDirection().GetZ();
    poly[0] = dot * dot - Math::GetValue(4) * outerRadiusSquare * (innerRadiusSquare - zOrigin * zOrigin);
    poly[1] = Math::GetValue(4) * originDotDirection * dot + Math::GetValue(8) * outerRadiusSquare * zDir * zOrigin;
    poly[2] = (Math::GetValue(2)) * directionDotDirection * dot + Math::GetValue(4) * originDotDirection * originDotDirection + Math::GetValue(4) * outerRadiusSquare * zDir * zDir;
    poly[3] = Math::GetValue(4) * directionDotDirection * originDotDirection;
    poly[4] = directionDotDirection * directionDotDirection;

    // 解决四次方程。
    PolynomialRoots<Real> proots{ Math::GetZeroTolerance() };
    if (!proots.FindBisection(poly, 6))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 获取相交点。
    for (auto begin = proots.GetBegin(); begin != proots.GetEnd(); ++begin)
    {
        auto point = m_Line.GetOrigin() + (*begin) * m_Line.GetDirection();
        if (m_Quantity == 0)
            m_Point0 = point;
        else if (m_Quantity == 1)
            m_Point1 = point;
        else if (m_Quantity == 2)
            m_Point2 = point;
        else if (m_Quantity == 3)
            m_Point3 = point;

        ++m_Quantity;
    }

    this->SetIntersectionType(0 < m_Quantity ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Torus3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
        else if (index == 2)
            return m_Point2;
        else if (index == 3)
            return m_Point3;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_ACHIEVE_H