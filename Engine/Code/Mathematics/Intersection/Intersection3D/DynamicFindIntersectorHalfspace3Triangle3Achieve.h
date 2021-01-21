// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/24 16:29)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H

#include "DynamicFindIntersectorHalfspace3Triangle3.h"
#include "Detail/FindIntersectorAxisImpl.h"
#include "Detail/TestIntersectorAxisImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::DynamicFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Halfspace{ halfspace }, m_Triangle{ triangle }, m_Quantity{}, m_Point0{}, m_Point1{}, m_Point2{}
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
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    auto cfg = FindIntersectorAxisImpl<Real>::GetConfiguration(m_Halfspace.GetNormal(), m_Triangle);

    const TestIntersectorAxisImpl<Real> testIntersectorAxis{ m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), cfg.GetMin(), cfg.GetMax(), this->GetTMax() };
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
        m_Quantity = 1;
        m_Point0 = m_Triangle.GetVertex(cfg.GetIndex(0)) + diff;
    }
    else if (cfg.GetMap() == VertexProjectionMap::M21)
    {
        // 线段相交。
        m_Quantity = 2;
        m_Point0 = m_Triangle.GetVertex(cfg.GetIndex(0)) + diff;
        m_Point1 = m_Triangle.GetVertex(cfg.GetIndex(1)) + diff;
    }
    else
    {
        // 面相交
        m_Quantity = 3;
        m_Point0 = m_Triangle.GetVertex(0) + diff;
        m_Point1 = m_Triangle.GetVertex(1) + diff;
        m_Point2 = m_Triangle.GetVertex(2) + diff;
    }

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
        else if (index == 2)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H