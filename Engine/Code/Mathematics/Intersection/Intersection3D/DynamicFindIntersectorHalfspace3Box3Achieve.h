///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/31 16:40)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_ACHIEVE_H

#include "DynamicFindIntersectorHalfspace3Box3.h"
#include "Detail/DynamicFindIntersectorHalfspace3Box3ImplDetail.h"
#include "Detail/FindIntersectorAxisImplDetail.h"
#include "Detail/TestIntersectorAxisImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection3D/IntersectorUtility3Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::DynamicFindIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, impl{  halfspace, box  }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() )
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetHalfspace();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetBox();
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoint(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Box3<Real>::Find()
{
    const auto halfspace = impl->GetHalfspace();
    const auto box = impl->GetBox();

    this->SetContactTime(Math::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    auto cfg = FindIntersectorAxisImpl<Real>::GetConfiguration(halfspace.GetNormal(), box);
    const TestIntersectorAxisImpl<Real> testIntersectorAxis{ halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, halfspace.GetConstant(), cfg.GetMin(), cfg.GetMax(), this->GetTMax() };

    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        // 永不相交。
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (Math::Approximate(contactTime, Math::GetValue(0)))
    {
        // 现在相交。
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    using Container = std::vector<Vector3D>;

    Container point{};

    // 正面上的方框（右）。
    if (cfg.GetMap() == VertexProjectionMap::M1_1)
    {
        // 点相交。
        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(0), box));
    }
    else if (cfg.GetMap() == VertexProjectionMap::M2_2)
    {
        // 线段相交。
        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(0), box));
        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(1), box));
    }
    else  // cfg.mMap == VertexProjectionMap::M44
    {
        // 面相交

        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(0), box));
        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(1), box));
        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(2), box));
        point.emplace_back(IntersectorUtility3<Real>::GetPointFromIndex(cfg.GetIndex(3), box));
    }

    // 将点也及时调整到正确的位置。
    auto diff = contactTime * this->GetRhsVelocity();
    for (auto& value : point)
    {
        value += diff;
    }
    impl->SetPoint(point);
    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_ACHIEVE_H