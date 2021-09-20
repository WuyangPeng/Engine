///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/14 15:25)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H

#include "DynamicTestIntersectorSegment3Box3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Box3<Real>::DynamicTestIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Segment{ segment }, m_Box{ box }, m_Solid{ solid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Box3<Real>::Test()
{
    // ��ȡ�߶εĶ˵㡣
    using SegmentType = std::array<Vector3D, 2>;
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    // ��ȡ������߶εĿ��ٶȡ�
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    auto contactTime = Math::GetValue(0);

    // ���Ժз��ߡ�
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = m_Box.GetAxis(i);
        const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segment, m_Box, relVelocity, this->GetTMax() };
        contactTime = testIntersectorAxis.GetTFirst();

        if (!testIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // �����߶η���Ľ���б�Ե��
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = Vector3DTools::CrossProduct(m_Box.GetAxis(i), m_Segment.GetDirection());

        const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segment, m_Box, relVelocity, this->GetTMax() };
        contactTime = testIntersectorAxis.GetTFirst();

        if (!testIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // �����ٶȴ�Խ�С����档
    for (auto i = 0; i < 3; i++)
    {
        const auto axis = Vector3DTools::CrossProduct(relVelocity, m_Box.GetAxis(i));
        const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segment, m_Box, relVelocity, this->GetTMax() };
        contactTime = testIntersectorAxis.GetTFirst();

        if (!testIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_ACHIEVE_H