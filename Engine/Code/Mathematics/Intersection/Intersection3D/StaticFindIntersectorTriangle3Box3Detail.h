///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "IntersectorUtility3.h"
#include "StaticFindIntersectorSegment3Box3.h"
#include "StaticFindIntersectorTriangle3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Box3<Real>::StaticFindIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, triangle{ triangle }, box{ box }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Box3<Real>::Find()
{
    // 从三角形开始，将其裁剪在盒子的每个面上。

    auto container = triangle.GetVertex();

    for (auto dir = -1; dir <= 1; dir += 2)
    {
        for (auto side = 0; side < 3; ++side)
        {
            auto innerNormal = MathType::GetValue(dir) * box.GetAxis(side);
            auto constant = Vector3ToolsType::DotProduct(innerNormal, box.GetCenter()) - box.GetExtent(side);
            container = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(innerNormal, constant, container);
        }
    }

    if (!container.empty())
    {
        point = container;
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

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorTriangle3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H