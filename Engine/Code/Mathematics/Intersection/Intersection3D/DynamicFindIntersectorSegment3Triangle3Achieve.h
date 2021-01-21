///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 16:52)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H

#include "DynamicFindIntersectorSegment3Triangle3.h"
#include "FindContactSetDetail.h"
#include "FindIntersectorAxisDetail.h"
#include "IntersectorConfigurationDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::DynamicFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon },
      m_Segment{ segment },
      m_Triangle{ triangle },
      m_SegmentParameter{},
      m_TriangleBary0{},
      m_TriangleBary1{},
      m_TriangleBary2{},
      m_Quantity{},
      m_Point0{},
      m_Point1{}
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
const Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetSegmentParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangleBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary0;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangleBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary1;
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetTriangleBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary2;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::Find()
{
    auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();

    m_Quantity = 0;
    this->SetIntersectionType(IntersectionType::Empty);

    using SegmentType = std::array<Vector3D, 2>;

    // 获取细分的端点。
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    // 获取三角形的边缘。
    auto edge0 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);

    // 获取相对于线段的三角形速度。
    auto relVelocity = rhsVelocity - lhsVelocity;

    this->SetContactTime(Math::GetValue(0));

    // 测试三角形法线
    const auto normal = Vector3DTools::CrossProduct(edge0, edge1);
    FindIntersectorAxis<Real> findIntersectorAxis{ normal, segment, m_Triangle, relVelocity, tMax };
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

    // 测试线段是否平行于三角形，有效地测试：sin(Angle(NormV,DirU)) > 1 - epsilon
    auto directionU = m_Segment.GetEndPoint() - m_Segment.GetBeginPoint();
    const auto normalU = Vector3DTools::CrossProduct(normal, directionU);
    auto directionSqrLength = Vector3DTools::VectorMagnitudeSquared(directionU);
    auto normalUSqrLength = Vector3DTools::VectorMagnitudeSquared(normalU);
    auto normalVSqrLength = Vector3DTools::VectorMagnitudeSquared(normal);
    auto oneMinusEpsilon = Math::GetValue(1) - Math::GetZeroTolerance();

    // 平行
    if (oneMinusEpsilon * normalVSqrLength * directionSqrLength < normalUSqrLength)
    {
        // 查找三角形法线交叉线段方向。
        FindIntersectorAxis<Real> findIntersectorAxisU{ normalU, segment, m_Triangle, relVelocity, tMax };
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

        // 查找三角形法线交叉三角形边。
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3DTools::CrossProduct(normal, (m_Triangle.GetVertex(i1) - m_Triangle.GetVertex(i0)));

            FindIntersectorAxis<Real> findTriangleIntersector{ axis, segment, m_Triangle, relVelocity, tMax };
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
        // 查找线段方向交叉三角形边。
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3DTools::CrossProduct(directionU, (m_Triangle.GetVertex(i1) - m_Triangle.GetVertex(i0)));

            FindIntersectorAxis<Real> findTriangleIntersector{ axis, segment, m_Triangle, relVelocity, tMax };
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

    if (contactTime < Math::GetValue(0))
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    FindContactSet<Real> findContactSet{ segment, m_Triangle, side, segmentContact, triangleContact, lhsVelocity, rhsVelocity, contactTime };
    auto point = findContactSet.GetPoint();
    m_Quantity = boost::numeric_cast<int>(point.size());

    this->SetContactTime(contactTime);
    if (m_Quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
        m_Point0 = point.at(0);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Segment);
        m_Point0 = point.at(0);
        m_Point1 = point.at(1);
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSegment3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H