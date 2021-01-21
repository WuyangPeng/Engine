///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 15:56)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H

#include "DynamicTestIntersectorTriangle3Box3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Box3<Real>::DynamicTestIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Triangle{ triangle }, m_Box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Box3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorTriangle3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Box3<Real>::Test()
{
    // 好像三角形是静止的，盒子在移动。
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    // 测试三角形法线的方向。
    using TriangleType = std::array<Vector3D, 3>;
    TriangleType edge{ m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0),
                       m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0),
                       m_Triangle.GetVertex(2) - m_Triangle.GetVertex(1) };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto crossProduct = Vector3DTools::CrossProduct(edge[0], edge[1]);
#include STSTEM_WARNING_POP

    const TestIntersectorAxis<Real> testIntersectorAxis{ crossProduct, m_Triangle, m_Box, relVelocity, this->GetTMax() };
    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 测试盒面的方向。
    for (auto i = 0; i < 3; ++i)
    {
        crossProduct = m_Box.GetAxis(i);
        const TestIntersectorAxis<Real> intersector{ crossProduct, m_Triangle, m_Box, relVelocity, this->GetTMax() };
        contactTime = intersector.GetTFirst();

        if (!intersector.GetResult())
        {
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 测试三角形箱边缘叉积的方向。
    for (auto i0 = 0; i0 < 3; ++i0)
    {
        for (auto i1 = 0; i1 < 3; ++i1)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
            crossProduct = Vector3DTools::CrossProduct(edge[i0], m_Box.GetAxis(i1));
#include STSTEM_WARNING_POP

            const TestIntersectorAxis<Real> intersector{ crossProduct, m_Triangle, m_Box, relVelocity, this->GetTMax() };
            contactTime = intersector.GetTFirst();

            if (!intersector.GetResult())
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }
    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_ACHIEVE_H