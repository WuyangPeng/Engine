///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 23:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H

#include "StaticTestIntersectorSegment3Box3.h"
#include "StaticTestIntersectorTriangle3Box3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Box3<Real>::StaticTestIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, triangle{ triangle }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorTriangle3Box3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorTriangle3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Box3<Real>::Test()
{
    std::array<Vector3, 3> edge{ triangle.GetVertex(1) - triangle.GetVertex(0),
                                 triangle.GetVertex(2) - triangle.GetVertex(0),
                                 Vector3{} };

    auto d = Vector3Tools::CrossProduct(edge.at(0), edge.at(1));
    auto min0 = Vector3Tools::DotProduct(d, triangle.GetVertex(0));
    auto max0 = min0;
    auto result = TestIntersectorAxis<Real>::GetProjection(d, box);
    auto min1 = result.first;
    auto max1 = result.second;
    if (max1 < min0 || max0 < min1)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        d = box.GetAxis(i);
        result = TestIntersectorAxis<Real>::GetProjection(d, triangle);
        min0 = result.first;
        max0 = result.second;
        auto ddc = Vector3Tools::DotProduct(d, box.GetCenter());
        min1 = ddc - box.GetExtent(i);
        max1 = ddc + box.GetExtent(i);
        if (max1 < min0 || max0 < min1)
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    edge.at(2) = edge.at(1) - edge.at(0);
    for (int i0 = 0; i0 < 3; ++i0)
    {
        for (int i1 = 0; i1 < 3; ++i1)
        {
            d = Vector3Tools::CrossProduct(edge.at(i0), box.GetAxis(i1));
            result = TestIntersectorAxis<Real>::GetProjection(d, triangle);
            min0 = result.first;
            max0 = result.second;
            result = TestIntersectorAxis<Real>::GetProjection(d, box);
            min1 = result.first;
            max1 = result.second;
            if (max1 < min0 || max0 < min1)
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

    this->SetIntersectionType(IntersectionType::Other);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_DETAIL_H