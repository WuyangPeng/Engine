///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Sphere3<Real>::StaticFindIntersectorLine3Sphere3(const Line3& line, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, sphere{ sphere }, quantity{}, point0{}, point1{}, lineParameter0{}, lineParameter1{}
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
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Sphere3<Real>::Find()
{
    auto diff = line.GetOrigin() - sphere.GetCenter();
    auto a0 = Vector3Tools::DotProduct(diff, diff) - sphere.GetRadius() * sphere.GetRadius();
    auto a1 = Vector3Tools::DotProduct(line.GetDirection(), diff);
    auto discr = a1 * a1 - a0;

    if (discr < Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        quantity = 0;
    }
    else if (Math::GetZeroTolerance() <= discr)
    {
        auto root = Math::Sqrt(discr);
        lineParameter0 = -a1 - root;
        lineParameter1 = -a1 + root;
        point0 = line.GetOrigin() + lineParameter0 * line.GetDirection();
        point1 = line.GetOrigin() + lineParameter1 * line.GetDirection();
        this->SetIntersectionType(IntersectionType::Segment);
        quantity = 2;
    }
    else
    {
        lineParameter0 = -a1;
        point0 = line.GetOrigin() + lineParameter0 * line.GetDirection();
        this->SetIntersectionType(IntersectionType::Point);
        quantity = 1;
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetPoint(int index) const
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

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Sphere3<Real>::GetLineParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return lineParameter0;
        else if (index == 1)
            return lineParameter1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_ACHIEVE_H