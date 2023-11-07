///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:13)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "DynamicFindIntersectorSegment3Box3.h"
#include "FindIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"
#include "Mathematics/Intersection/Intersection3D/FindContactSetDetail.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorConfigurationDetail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Box3<Real>::DynamicFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tMax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, segment{ segment }, box{ box }, solid{ solid }, quantity{}, point0{}, point1{}
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
Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Box3<Real>::Find()
{
    quantity = 0;
    this->SetIntersectionType(IntersectionType::Empty);
    this->SetContactTime(Math::GetValue(0));

    using SegmentType = std::array<Vector3, 2>;

    // 获取线段的端点。
    const SegmentType segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

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
        const auto axis = box.GetAxis(i);

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, segmentType, box, relVelocity, this->GetTMax() };
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
        const auto axis = Vector3Tools::CrossProduct(box.GetAxis(i), segment.GetDirection());

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, segmentType, box, relVelocity, this->GetTMax() };
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
        const auto axis = Vector3Tools::CrossProduct(relVelocity, box.GetAxis(i));

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, segmentType, box, relVelocity, this->GetTMax() };
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

    FindContactSet<Real> findContactSet{ segmentType, box, side, segmentContact, boxContact, this->GetLhsVelocity(), this->GetRhsVelocity(), contactTime };
    auto point = findContactSet.GetPoint();
    quantity = boost::numeric_cast<int>(point.size());

    this->SetContactTime(contactTime);
    if (quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
        point0 = point.at(0);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Segment);
        point0 = point.at(0);
        point1 = point.at(1);
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorSegment3Box3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H