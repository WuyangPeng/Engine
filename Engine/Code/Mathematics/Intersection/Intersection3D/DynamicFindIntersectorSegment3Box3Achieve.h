///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/04 18:34)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H

#include "DynamicFindIntersectorSegment3Box3.h"
#include "FindIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Intersection/Intersection3D/FindContactSetDetail.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorConfigurationDetail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Box3<Real>::DynamicFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Segment{ segment }, m_Box{ box }, m_Solid{ solid }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Box3<Real>::Find()
{
    m_Quantity = 0;
    this->SetIntersectionType(IntersectionType::Empty);
    this->SetContactTime(Math::GetValue(0));

    using SegmentType = std::array<Vector3D, 2>;

    // 获取线段的端点。
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    // 获取相对于线段的框速度。
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    auto side = ContactSide::None;
    IntersectorConfiguration<Real> segmentContact{};
    IntersectorConfiguration<Real> boxContact{};
    auto contactTime = this->GetContactTime();
    Real tLast{};

    // 测试盒法线。
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = m_Box.GetAxis(i);

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, segment, m_Box, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        segmentContact = findIntersectorAxis.GetCfgFinal0();
        boxContact = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 测试线段方向的交叉盒边缘。
    for (auto i = 0; i < 3; i++)
    {
        const auto axis = Vector3DTools::CrossProduct(m_Box.GetAxis(i), m_Segment.GetDirection());

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, segment, m_Box, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        segmentContact = findIntersectorAxis.GetCfgFinal0();
        boxContact = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    /// 测试速度跨箱表面。
    for (auto i = 0; i < 3; i++)
    {
        const auto axis = Vector3DTools::CrossProduct(relVelocity, m_Box.GetAxis(i));

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, segment, m_Box, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        segmentContact = findIntersectorAxis.GetCfgFinal0();
        boxContact = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    if (contactTime < Math::GetValue(0) || side == ContactSide::None)
    {
        // 现在相交
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    FindContactSet<Real> findContactSet{ segment, m_Box, side, segmentContact, boxContact, this->GetLhsVelocity(), this->GetRhsVelocity(), contactTime };
    auto point = findContactSet.GetPoint();
    m_Quantity = boost::numeric_cast<int>(point.size());

    this->SetContactTime(contactTime);
    if (m_Quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
        m_Point0 = point.at(0);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Segment);
        m_Point0 = point.at(0);
        m_Point1 = point.at(1);
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H