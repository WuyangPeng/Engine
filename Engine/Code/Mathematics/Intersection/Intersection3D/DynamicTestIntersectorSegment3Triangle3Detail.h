///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/01 15:48)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DynamicTestIntersectorSegment3Triangle3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::DynamicTestIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, segment{ segment }, triangle{ triangle }
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
Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::Test()
{
    // ��ȡ�öε��յ㡣
    using SegmentType = std::array<Vector3, 2>;
    SegmentType segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

    // ��ȡ�����εı�Ե��
    auto edge0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge1 = triangle.GetVertex(2) - triangle.GetVertex(0);

    // ��ȡ������߶ε��������ٶ�
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    // ���������η���.
    const auto edgeNormal = Vector3Tools::CrossProduct(edge0, edge1);
    const TestIntersectorAxis<Real> intersector{ edgeNormal, segmentType, triangle, relVelocity, this->GetTMax() };
    auto contactTime = intersector.GetTFirst();

    if (!intersector.GetResult())
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �����߶��Ƿ�ƽ���������Σ���Ч�ز��ԣ� sin(Angle(NormV,DirU)) > 1 - epsilon
    auto directionU = segmentType.at(1) - segmentType.at(0);

    const auto normalU = Vector3Tools::CrossProduct(edgeNormal, directionU);
    auto directionUSqrLen = Vector3Tools::GetLengthSquared(directionU);
    auto normalUSqrLen = Vector3Tools::GetLengthSquared(normalU);
    auto edgeNormalSqrLen = Vector3Tools::GetLengthSquared(edgeNormal);
    auto oneMinusEpsilon = Math::GetValue(1) - Math::GetZeroTolerance();

    // ƽ��
    if (oneMinusEpsilon * edgeNormalSqrLen * directionUSqrLen < normalUSqrLen)
    {
        // ���������η��ߺ���߶η���
        const TestIntersectorAxis<Real> normalUIntersector{ normalU, segmentType, triangle, relVelocity, this->GetTMax() };
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
            const auto axis = Vector3Tools::CrossProduct(edgeNormal, (triangle.GetVertex(i1) - triangle.GetVertex(i0)));

            const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, triangle, relVelocity, this->GetTMax() };
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
            const auto axis = Vector3Tools::CrossProduct(directionU, (triangle.GetVertex(i1) - triangle.GetVertex(i0)));

            const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, triangle, relVelocity, this->GetTMax() };
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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H