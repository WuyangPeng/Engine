///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:13)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorSegment3Sphere3.h"
#include "StaticFindIntersectorSegment3Capsule3Detail.h"
#include "StaticFindIntersectorSegment3Sphere3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::DynamicFindIntersectorSegment3Sphere3(const Segment3Type& segment, const Sphere3Type& sphere, Real tMax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, segment{ segment }, sphere{ sphere }, quantity{}, point0{}, point1{}, segmentParameter0{}, segmentParameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::Find()
{
    // 检查最初是否相交。
    StaticFindIntersectorSegment3Sphere3<Real> intersector{ segment, sphere };
    if (intersector.IsIntersection())
    {
        this->SetContactTime(MathType::GetValue(0));
        this->SetIntersectionType(IntersectionType::Other);
        if (intersector.GetQuantity() == 1)
        {
            point0 = intersector.GetPoint(0);
        }
        else if (intersector.GetQuantity() == 2)
        {
            point0 = intersector.GetPoint(0);
            point1 = intersector.GetPoint(1);
        }

        segmentParameter0 = intersector.GetSegmentParameter0();
        segmentParameter1 = intersector.GetSegmentParameter1();

        return;
    }

    /// 从球体速度中减去线段速度，以便计算基于线段的坐标系。
    /// 在该系统中，线段当然是固定的。
    /// 球体跨越一个胶囊，但是取而代之的是，我们将根据球体半径“扩大”线段，并将球体收缩到其中心。
    /// 现在的问题是检测移动中心第一次与由线段和球半径形成的胶囊相交。
    const Capsule3<Real> capsule{ segment, sphere.GetRadius() };

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relSpeed = Vector3ToolsType::GetLength(relVelocity);

    // 单位长度向量
    relVelocity.Normalize();
    const Segment3Type path{ (MathType::GetRational(1, 2)) * this->GetTMax() * relSpeed, sphere.GetCenter() + (MathType::GetRational(1, 2)) * this->GetTMax() * relSpeed * relVelocity, relVelocity };

    StaticFindIntersectorSegment3Capsule3<Real> staticFindIntersectorSegment3Capsule3{ path, capsule };
    if (!staticFindIntersectorSegment3Capsule3.IsIntersection())
    {
        this->SetContactTime(MathType::GetValue(0));
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    segmentParameter0 = staticFindIntersectorSegment3Capsule3.GetParameter0();
    segmentParameter1 = staticFindIntersectorSegment3Capsule3.GetParameter1();

    // 现在我们知道球体将与线段相交。 这可以在段端点或段内部点发生。 我们需要确定哪个。
    this->SetContactTime((staticFindIntersectorSegment3Capsule3.GetParameter0() + path.GetExtent()) / relSpeed);
    quantity = 1;
    this->SetIntersectionType(IntersectionType::Point);

    auto moveCenter = sphere.GetCenter() + this->GetContactTime() * this->GetRhsVelocity();
    auto moveOrigin = segment.GetCenterPoint() + this->GetContactTime() * this->GetLhsVelocity();
    auto origin = Vector3ToolsType::DotProduct(segment.GetDirection(), moveOrigin);
    auto negEnd = origin - segment.GetExtent();
    auto posEnd = origin + segment.GetExtent();
    auto center = Vector3ToolsType::DotProduct(segment.GetDirection(), moveCenter);

    if (center < negEnd)
    {
        // 线段终点P - e * D处的交点。
        point0 = moveOrigin - segment.GetExtent() * segment.GetDirection();
    }
    else if (center > posEnd)
    {
        // 线段终点P + e * D处的交点。
        point0 = moveOrigin + segment.GetExtent() * segment.GetDirection();
    }
    else
    {
        // 与边缘上的内部点相交。 使用沿方向轴的投影来找到那个点。
        point0 = moveOrigin + (center - origin) * segment.GetDirection();
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetPoint(int index) const
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
Real Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segmentParameter0;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segmentParameter1;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H