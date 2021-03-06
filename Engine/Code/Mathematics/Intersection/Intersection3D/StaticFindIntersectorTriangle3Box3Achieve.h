///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 13:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H

#include "IntersectorUtility3.h"
#include "StaticFindIntersectorSegment3Box3.h"
#include "StaticFindIntersectorTriangle3Box3.h"
#include "Detail/StaticFindIntersectorTriangle3Box3ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Box3<Real>::StaticFindIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(triangle, box) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetBox();
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Box3<Real>::Find()
{
    using Container = std::vector<Vector3D>;

    // 从三角形开始，将其裁剪在盒子的每个面上。
    auto triangle = GetTriangle();
    auto box = GetBox();
    auto container = triangle.GetVertex();

    for (auto dir = -1; dir <= 1; dir += 2)
    {
        for (auto side = 0; side < 3; ++side)
        {
            auto innerNormal = Math::GetValue(dir) * box.GetAxis(side);
            auto constant = Vector3DTools::DotProduct(innerNormal, box.GetCenter()) - box.GetExtent(side);
            container = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(innerNormal, constant, container);
        }
    }

    if (!container.empty())
    {
        m_Impl->SetContainer(container);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H