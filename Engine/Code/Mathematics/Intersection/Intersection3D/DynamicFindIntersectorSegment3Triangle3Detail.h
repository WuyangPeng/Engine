///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:13)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DynamicFindIntersectorSegment3Triangle3.h"
#include "FindContactSetDetail.h"
#include "FindIntersectorAxisDetail.h"
#include "IntersectorConfigurationDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::DynamicFindIntersectorSegment3Triangle3(const Segment3Type& segment, const Triangle3Type& triangle, Real tmax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon },
      segment{ segment },
      triangle{ triangle },
      segmentParameter{},
      triangleBary0{},
      triangleBary1{},
      triangleBary2{},
      quantity{},
      point0{},
      point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetSegmentParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segmentParameter;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangleBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary0;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangleBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary1;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangleBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary2;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::Find()
{
    auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();

    quantity = 0;
    this->SetIntersectionType(IntersectionType::Empty);

    using SegmentType = std::array<Vector3Type, 2>;

    // ��ȡϸ�ֵĶ˵㡣
    const SegmentType segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

    // ��ȡ�����εı�Ե��
    auto edge0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge1 = triangle.GetVertex(2) - triangle.GetVertex(0);

    // ��ȡ������߶ε��������ٶȡ�
    auto relVelocity = rhsVelocity - lhsVelocity;

    this->SetContactTime(MathType::GetValue(0));

    // ���������η���
    const auto normal = Vector3ToolsType::CrossProduct(edge0, edge1);
    const FindIntersectorAxis<Real> findIntersectorAxis{ normal, segmentType, triangle, relVelocity, tMax };
    auto tLast = findIntersectorAxis.GetTLast();
    auto segmentContact = findIntersectorAxis.GetCfgFinal0();
    auto triangleContact = findIntersectorAxis.GetCfgFinal1();
    auto side = findIntersectorAxis.Getside();
    auto contactTime = findIntersectorAxis.GetTFirst();

    if (!findIntersectorAxis.GetResult())
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �����߶��Ƿ�ƽ���������Σ���Ч�ز��ԣ�sin(Angle(NormV,DirU)) > 1 - epsilon
    auto directionU = segment.GetEndPoint() - segment.GetBeginPoint();
    const auto normalU = Vector3ToolsType::CrossProduct(normal, directionU);
    auto directionSqrLength = Vector3ToolsType::GetLengthSquared(directionU);
    auto normalUSqrLength = Vector3ToolsType::GetLengthSquared(normalU);
    auto normalVSqrLength = Vector3ToolsType::GetLengthSquared(normal);
    auto oneMinusEpsilon = MathType::GetValue(1) - MathType::GetZeroTolerance();

    // ƽ��
    if (oneMinusEpsilon * normalVSqrLength * directionSqrLength < normalUSqrLength)
    {
        // ���������η��߽����߶η���
        const FindIntersectorAxis<Real> findIntersectorAxisU{ normalU, segmentType, triangle, relVelocity, tMax };
        tLast = findIntersectorAxisU.GetTLast();
        segmentContact = findIntersectorAxisU.GetCfgFinal0();
        triangleContact = findIntersectorAxisU.GetCfgFinal1();
        side = findIntersectorAxisU.Getside();
        contactTime = findIntersectorAxisU.GetTFirst();

        if (!findIntersectorAxisU.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        // ���������η��߽��������αߡ�
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3ToolsType::CrossProduct(normal, (triangle.GetVertex(i1) - triangle.GetVertex(i0)));

            const FindIntersectorAxis<Real> findTriangleIntersector{ axis, segmentType, triangle, relVelocity, tMax };
            tLast = findTriangleIntersector.GetTLast();
            segmentContact = findTriangleIntersector.GetCfgFinal0();
            triangleContact = findTriangleIntersector.GetCfgFinal1();
            side = findTriangleIntersector.Getside();
            contactTime = findTriangleIntersector.GetTFirst();

            if (!findTriangleIntersector.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }
    else
    {
        // �����߶η��򽻲������αߡ�
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3ToolsType::CrossProduct(directionU, (triangle.GetVertex(i1) - triangle.GetVertex(i0)));

            const FindIntersectorAxis<Real> findTriangleIntersector{ axis, segmentType, triangle, relVelocity, tMax };
            tLast = findTriangleIntersector.GetTLast();
            segmentContact = findTriangleIntersector.GetCfgFinal0();
            triangleContact = findTriangleIntersector.GetCfgFinal1();
            side = findTriangleIntersector.Getside();
            contactTime = findTriangleIntersector.GetTFirst();

            if (!findTriangleIntersector.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

    if (contactTime < MathType::GetValue(0))
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    FindContactSet<Real> findContactSet{ segmentType, triangle, side, segmentContact, triangleContact, lhsVelocity, rhsVelocity, contactTime };
    auto point = findContactSet.GetPoint();
    quantity = boost::numeric_cast<int>(point.size());

    this->SetContactTime(contactTime);
    if (quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
        point0 = point.at(0);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Segment);
        point0 = point.at(0);
        point1 = point.at(1);
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H