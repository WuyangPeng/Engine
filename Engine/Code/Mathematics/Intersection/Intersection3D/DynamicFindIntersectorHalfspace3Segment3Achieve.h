///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/04 11:41)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H

#include "DynamicFindIntersectorHalfspace3Segment3.h"
#include "FindIntersectorAxis.h"
#include "IntersectorConfiguration.h"
#include "Detail/FindIntersectorAxisImpl.h"
#include "Detail/TestIntersectorAxisImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::DynamicFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Halfspace{ halfspace }, m_Segment{ segment }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    using SegmentType = std::array<Vector3D, 2>;
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    auto cfg = FindIntersectorAxisImpl<Real>::GetConfiguration(m_Halfspace.GetNormal(), segment);
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    const TestIntersectorAxisImpl<Real> testIntersectorAxis{ m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), cfg.GetMin(), cfg.GetMax(), this->GetTMax() };
    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        // 永不相交。
        this->SetIntersectionType(IntersectionType::Empty);
        this->SetContactTime(contactTime);
        return;
    }

    if (Math::Approximate(contactTime, Math::GetValue(0)))
    {
        // 现在相交。
        this->SetIntersectionType(IntersectionType::Empty);
        this->SetContactTime(contactTime);
        return;
    }

    // 将点也及时调整到正确的位置。
    auto diff = contactTime * this->GetRhsVelocity();

    // 正极线（右）。
    if (cfg.GetMap() == VertexProjectionMap::M1_1)
    {
        m_Quantity = 1;
        m_Point0 = segment.at(cfg.GetIndex(0));
        m_Point0 += diff;
    }
    else  // cfg.mMap == VertexProjectionMap::M2
    {
        m_Quantity = 2;
        m_Point0 = segment.at(cfg.GetIndex(0));
        m_Point1 = segment.at(cfg.GetIndex(1));
        m_Point0 += diff;
        m_Point1 += diff;
    }

    this->SetIntersectionType(IntersectionType::Other);
    this->SetContactTime(contactTime);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H