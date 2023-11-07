///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:05)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Triangle3.h"
#include "FindIntersectorAxis.h"
#include "TestIntersectorAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::DynamicFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, halfspace{ halfspace }, triangle{ triangle }, quantity{}, point0{}, point1{}, point2{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    const auto cfg = FindIntersectorAxis<Real>::GetConfiguration(halfspace.GetNormal(), triangle);

    const TestIntersectorAxis<Real> testIntersectorAxis{ halfspace.GetNormal(), relVelocity, -Math::maxReal, halfspace.GetConstant(), cfg.GetMin(), cfg.GetMax(), this->GetTMax() };
    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        // 永不相交。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (Math::Approximate(contactTime, Math::GetValue(0)))
    {
        // 现在相交。.
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 将点也及时调整到正确的位置。
    auto diff = contactTime * this->GetRhsVelocity();

    // 正面的三角形（右）。
    if ((cfg.GetMap() == VertexProjectionMap::M12) || (cfg.GetMap() == VertexProjectionMap::M111))
    {
        // 点相交。
        quantity = 1;
        point0 = triangle.GetVertex(cfg.GetIndex(0)) + diff;
    }
    else if (cfg.GetMap() == VertexProjectionMap::M21)
    {
        // 线段相交。
        quantity = 2;
        point0 = triangle.GetVertex(cfg.GetIndex(0)) + diff;
        point1 = triangle.GetVertex(cfg.GetIndex(1)) + diff;
    }
    else
    {
        // 面相交
        quantity = 3;
        point0 = triangle.GetVertex(0) + diff;
        point1 = triangle.GetVertex(1) + diff;
        point2 = triangle.GetVertex(2) + diff;
    }

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
        else if (index == 2)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H