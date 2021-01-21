///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 11:01)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Sphere3<Real>::StaticFindIntersectorLine3Sphere3(const Line3& line, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Sphere{ sphere }, m_Quantity{}, m_Point0{}, m_Point1{}, m_LineParameter0{}, m_LineParameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Sphere3<Real>::Find()
{
    auto diff = m_Line.GetOrigin() - m_Sphere.GetCenter();
    auto a0 = Vector3DTools::DotProduct(diff, diff) - m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto a1 = Vector3DTools::DotProduct(m_Line.GetDirection(), diff);
    auto discr = a1 * a1 - a0;

    if (discr < Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        m_Quantity = 0;
    }
    else if (Math::GetZeroTolerance() <= discr)
    {
        auto root = Math::Sqrt(discr);
        m_LineParameter0 = -a1 - root;
        m_LineParameter1 = -a1 + root;
        m_Point0 = m_Line.GetOrigin() + m_LineParameter0 * m_Line.GetDirection();
        m_Point1 = m_Line.GetOrigin() + m_LineParameter1 * m_Line.GetDirection();
        this->SetIntersectionType(IntersectionType::Segment);
        m_Quantity = 2;
    }
    else
    {
        m_LineParameter0 = -a1;
        m_Point0 = m_Line.GetOrigin() + m_LineParameter0 * m_Line.GetDirection();
        this->SetIntersectionType(IntersectionType::Point);
        m_Quantity = 1;
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetPoint(int index) const
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

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetLineParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_LineParameter0;
        else if (index == 1)
            return m_LineParameter1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_ACHIEVE_H