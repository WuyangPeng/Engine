///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/15 11:06)

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
    // ��ȡ�öε��յ㡣
    using SegmentType = std::array<Vector3D, 2>;
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    // ��ȡ�����εı�Ե��
    auto edge0 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);

    // ��ȡ������߶ε��������ٶ�
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    // ���������η���.
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

    // �����߶��Ƿ�ƽ���������Σ���Ч�ز��ԣ� sin(Angle(NormV,DirU)) > 1 - epsilon
    auto directionU = segment[1] - segment[0];
#include STSTEM_WARNING_POP

    const auto normalU = Vector3DTools::CrossProduct(edgeNormal, directionU);
    auto directionUSqrLen = Vector3DTools::VectorMagnitudeSquared(directionU);
    auto normalUSqrLen = Vector3DTools::VectorMagnitudeSquared(normalU);
    auto edgeNormalSqrLen = Vector3DTools::VectorMagnitudeSquared(edgeNormal);
    auto oneMinusEpsilon = Math::GetValue(1) - Math::GetZeroTolerance();

    // ƽ��
    if (oneMinusEpsilon * edgeNormalSqrLen * directionUSqrLen < normalUSqrLen)
    {
        // ���������η��ߺ���߶η���
        const TestIntersectorAxis<Real> normalUIntersector{ normalU, segment, m_Triangle, relVelocity, this->GetTMax() };
        contactTime = normalUIntersector.GetTFirst();

        if (!normalUIntersector.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        //  ���������η��ߺ���߶αߡ�
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
    else  // ��ƽ��
    {
        // �����߶η����������αߡ�
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