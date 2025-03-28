///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:04)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Box3.h"
#include "FindIntersectorAxisDetail.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorUtility3Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::DynamicFindIntersectorHalfspace3Box3(const Plane3Type& halfSpace, const Box3Type& box, Real tMax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, halfSpace{ halfSpace }, box{ box }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfSpace;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::Find()
{
    this->SetContactTime(MathType::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    const auto cfg = FindIntersectorAxis<Real>::GetConfiguration(halfSpace.GetNormal(), box);
    const TestIntersectorAxis<Real> testIntersectorAxis{ halfSpace.GetNormal(), relVelocity, -MathType::maxReal, halfSpace.GetConstant(), cfg.GetMin(), cfg.GetMax(), this->GetTMax() };

    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        // 永不相交。
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (MathType::Approximate(contactTime, MathType::GetValue(0)))
    {
        // 现在相交。
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    Container container{};

    // 正面上的方框（右）。
    if (cfg.GetMap() == VertexProjectionMap::M1_1)
    {
        // 点相交。
        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(0), box));
    }
    else if (cfg.GetMap() == VertexProjectionMap::M2_2)
    {
        // 线段相交。
        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(0), box));
        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(1), box));
    }
    else  // cfg.mMap == VertexProjectionMap::M44
    {
        // 面相交

        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(0), box));
        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(1), box));
        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(2), box));
        container.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(3), box));
    }

    // 将点也及时调整到正确的位置。
    auto diff = contactTime * this->GetRhsVelocity();
    for (auto& value : container)
    {
        value += diff;
    }

    point = container;
    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H