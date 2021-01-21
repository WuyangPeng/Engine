///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 11:06)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H

#include "DynamicTestIntersectorSegment3Triangle3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::DynamicTestIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Segment{ segment }, m_Triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::Test()
{
    // 获取该段的终点。
    using SegmentType = std::array<Vector3D, 2>;
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    // 获取三角形的边缘。
    auto edge0 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);

    // 获取相对于线段的三角形速度
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    // 测试三角形法线.
    const auto edgeNormal = Vector3DTools::CrossProduct(edge0, edge1);
    const TestIntersectorAxis<Real> intersector{ edgeNormal, segment, m_Triangle, relVelocity, this->GetTMax() };
    auto contactTime = intersector.GetTFirst();

    if (!intersector.GetResult())
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 测试线段是否平行于三角形，有效地测试： sin(Angle(NormV,DirU)) > 1 - epsilon
    auto directionU = segment[1] - segment[0];
#include STSTEM_WARNING_POP

    const auto normalU = Vector3DTools::CrossProduct(edgeNormal, directionU);
    auto directionUSqrLen = Vector3DTools::VectorMagnitudeSquared(directionU);
    auto normalUSqrLen = Vector3DTools::VectorMagnitudeSquared(normalU);
    auto edgeNormalSqrLen = Vector3DTools::VectorMagnitudeSquared(edgeNormal);
    auto oneMinusEpsilon = Math::GetValue(1) - Math::GetZeroTolerance();

    // 平行
    if (oneMinusEpsilon * edgeNormalSqrLen * directionUSqrLen < normalUSqrLen)
    {
        // 测试三角形法线横截线段方向。
        const TestIntersectorAxis<Real> normalUIntersector{ normalU, segment, m_Triangle, relVelocity, this->GetTMax() };
        contactTime = normalUIntersector.GetTFirst();

        if (!normalUIntersector.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        //  测试三角形法线横截线段边。
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3DTools::CrossProduct(edgeNormal, (m_Triangle.GetVertex(i1) - m_Triangle.GetVertex(i0)));

            const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segment, m_Triangle, relVelocity, this->GetTMax() };
            contactTime = testIntersectorAxis.GetTFirst();

            if (!testIntersectorAxis.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }
    else  // 不平行
    {
        // 测试线段方向横截三角形边。
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3DTools::CrossProduct(directionU, (m_Triangle.GetVertex(i1) - m_Triangle.GetVertex(i0)));

            const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segment, m_Triangle, relVelocity, this->GetTMax() };
            contactTime = testIntersectorAxis.GetTFirst();

            if (!testIntersectorAxis.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H