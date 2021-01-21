///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 18:25)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::StaticFindIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon)
    : ParentType{ Math::GetValue(0) <= epsilon ? epsilon : Math::GetValue(0) },
      m_Plane{ plane },
      m_Triangle{ triangle },
      m_Quantity{},
      m_Point0{},
      m_Point1{},
      m_Point2{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::Find()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 计算从顶点到平面的符号距离。
    auto epsilon = this->GetEpsilon();
    auto zero = Math::GetValue(0);
    std::array<Real, 3> distance{};
    for (auto i = 0u; i < distance.size(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
        distance[i] = m_Plane.DistanceTo(m_Triangle.GetVertex(i));
        if (Math::FAbs(distance[i]) <= epsilon)
        {
            distance[i] = zero;
        }
#include STSTEM_WARNING_POP
    };

    const auto vertex0 = m_Triangle.GetVertex(0);
    const auto vertex1 = m_Triangle.GetVertex(1);
    const auto vertex2 = m_Triangle.GetVertex(2);

    if (zero < distance[0])
    {
        if (zero < distance[1])
        {
            if (zero < distance[2])
            {
                // ppp
                m_Quantity = 0;
                this->SetIntersectionType(IntersectionType::Empty);
            }
            else if (distance[2] < zero)
            {
                // ppm
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[2])) * (vertex2 - vertex0);
                m_Point1 = vertex1 + (distance[1] / (distance[1] - distance[2])) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // ppz
                m_Quantity = 1;
                m_Point0 = vertex2;
                this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else if (distance[1] < zero)
        {
            if (zero < distance[2])
            {
                // pmp
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[1])) * (vertex1 - vertex0);
                m_Point1 = vertex1 + (distance[1] / (distance[1] - distance[2])) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance[2] < zero)
            {
                // pmm
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[1])) * (vertex1 - vertex0);
                m_Point1 = vertex0 + (distance[0] / (distance[0] - distance[2])) * (vertex2 - vertex0);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pmz
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[1])) * (vertex1 - vertex0);
                m_Point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (zero < distance[2])
            {
                // pzp
                m_Quantity = 1;
                m_Point0 = vertex1;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else if (distance[2] < zero)
            {
                // pzm
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[2])) * (vertex2 - vertex0);
                m_Point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pzz
                m_Quantity = 2;
                m_Point0 = vertex1;
                m_Point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
    }
    else if (distance[0] < zero)
    {
        if (zero < distance[1])
        {
            if (zero < distance[2])
            {
                // mpp
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[1])) * (vertex1 - vertex0);
                m_Point1 = vertex0 + (distance[0] / (distance[0] - distance[2])) * (vertex2 - vertex0);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance[2] < zero)
            {
                // mpm
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[1])) * (vertex1 - vertex0);
                m_Point1 = vertex1 + (distance[1] / (distance[1] - distance[2])) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // mpz
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[1])) * (vertex1 - vertex0);
                m_Point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (distance[1] < zero)
        {
            if (distance[2] > zero)
            {
                // mmp
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[2])) * (vertex2 - vertex0);
                m_Point1 = vertex1 + (distance[1] / (distance[1] - distance[2])) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance[2] < zero)
            {
                // mmm
                m_Quantity = 0;
                this->SetIntersectionType(IntersectionType::Empty);
            }
            else
            {
                // mmz
                m_Quantity = 1;
                m_Point0 = m_Triangle.GetVertex()[2];
                this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else
        {
            if (zero < distance[2])
            {
                // mzp
                m_Quantity = 2;
                m_Point0 = vertex0 + (distance[0] / (distance[0] - distance[2])) * (vertex2 - vertex0);
                m_Point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance[2] < zero)
            {
                // mzm
                m_Quantity = 1;
                m_Point0 = vertex1;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // mzz
                m_Quantity = 2;
                m_Point0 = vertex1;
                m_Point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
    }
    else
    {
        if (zero < distance[1])
        {
            if (zero < distance[2])
            {
                // zpp
                m_Quantity = 1;
                m_Point0 = vertex0;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else if (distance[2] < zero)
            {
                // zpm
                m_Quantity = 2;
                m_Point0 = vertex1 + (distance[1] / (distance[1] - distance[2])) * (vertex2 - vertex1);
                m_Point1 = vertex0;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zpz
                m_Quantity = 2;
                m_Point0 = vertex0;
                m_Point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (distance[1] < zero)
        {
            if (distance[2] > zero)
            {
                // zmp
                m_Quantity = 2;
                m_Point0 = vertex1 + (distance[1] / (distance[1] - distance[2])) * (vertex2 - vertex1);
                m_Point1 = vertex0;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance[2] < zero)
            {
                // zmm
                m_Quantity = 1;
                m_Point0 = vertex0;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // zmz
                m_Quantity = 2;
                m_Point0 = vertex0;
                m_Point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (zero < distance[2])
            {
                // zzp
                m_Quantity = 2;
                m_Point0 = vertex0;
                m_Point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance[2] < zero)
            {
                // zzm
                m_Quantity = 2;
                m_Point0 = vertex0;
                m_Point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zzz
                m_Quantity = 3;
                m_Point0 = vertex0;
                m_Point1 = vertex1;
                m_Point2 = vertex2;
                this->SetIntersectionType(IntersectionType::Polygon);
            }
        }
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
int Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
        else
            return m_Point2;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_ACHIEVE_H
