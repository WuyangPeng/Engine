///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 11:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H

#include "IntersectorUtility3Detail.h"
#include "StaticFindIntersectorHalfspace3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::StaticFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, m_Halfspace{ halfspace }, m_Triangle{ triangle }, m_Quantity{}, m_Point0{}, m_Point1{}, m_Point2{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::Find()
{
    // 从三角形开始，然后将其裁剪在平面上。

    auto container = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(-m_Halfspace.GetNormal(), -m_Halfspace.GetConstant(), m_Triangle.GetVertex());

    m_Quantity = boost::numeric_cast<int>(container.size());

    if (m_Quantity == 0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else if (m_Quantity == 1)
    {
        m_Point0 = container.at(0);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else if (m_Quantity == 2)
    {
        m_Point0 = container.at(0);
        m_Point1 = container.at(1);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else if (2 < m_Quantity)
    {
        m_Point0 = container.at(0);
        m_Point1 = container.at(1);
        m_Point2 = container.at(2);
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H