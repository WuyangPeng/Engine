///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorPlane3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::StaticFindIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon)
    : ParentType{ Math::GetValue(0) <= epsilon ? epsilon : Math::GetValue(0) },
      plane{ plane },
      triangle{ triangle },
      quantity{},
      point0{},
      point1{},
      point2{}
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

    return plane;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::Find()
{
    // 计算从顶点到平面的符号距离。
    auto epsilon = this->GetEpsilon();
    auto zero = Math::GetValue(0);
    std::array<Real, 3> distance{};
    for (auto i = 0u; i < distance.size(); ++i)
    {
        distance.at(i) = plane.DistanceTo(triangle.GetVertex(i));
        if (Math::FAbs(distance.at(i)) <= epsilon)
        {
            distance.at(i) = zero;
        }
    };

    const auto vertex0 = triangle.GetVertex(0);
    const auto vertex1 = triangle.GetVertex(1);
    const auto vertex2 = triangle.GetVertex(2);

    if (zero < distance.at(0))
    {
        if (zero < distance.at(1))
        {
            if (zero < distance.at(2))
            {
                // ppp
                quantity = 0;
                this->SetIntersectionType(IntersectionType::Empty);
            }
            else if (distance.at(2) < zero)
            {
                // ppm
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(2))) * (vertex2 - vertex0);
                point1 = vertex1 + (distance.at(1) / (distance.at(1) - distance.at(2))) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // ppz
                quantity = 1;
                point0 = vertex2;
                this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else if (distance.at(1) < zero)
        {
            if (zero < distance.at(2))
            {
                // pmp
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(1))) * (vertex1 - vertex0);
                point1 = vertex1 + (distance.at(1) / (distance.at(1) - distance.at(2))) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance.at(2) < zero)
            {
                // pmm
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(1))) * (vertex1 - vertex0);
                point1 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(2))) * (vertex2 - vertex0);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pmz
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(1))) * (vertex1 - vertex0);
                point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (zero < distance.at(2))
            {
                // pzp
                quantity = 1;
                point0 = vertex1;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else if (distance.at(2) < zero)
            {
                // pzm
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(2))) * (vertex2 - vertex0);
                point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // pzz
                quantity = 2;
                point0 = vertex1;
                point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
    }
    else if (distance.at(0) < zero)
    {
        if (zero < distance.at(1))
        {
            if (zero < distance.at(2))
            {
                // mpp
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(1))) * (vertex1 - vertex0);
                point1 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(2))) * (vertex2 - vertex0);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance.at(2) < zero)
            {
                // mpm
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(1))) * (vertex1 - vertex0);
                point1 = vertex1 + (distance.at(1) / (distance.at(1) - distance.at(2))) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // mpz
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(1))) * (vertex1 - vertex0);
                point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (distance.at(1) < zero)
        {
            if (distance.at(2) > zero)
            {
                // mmp
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(2))) * (vertex2 - vertex0);
                point1 = vertex1 + (distance.at(1) / (distance.at(1) - distance.at(2))) * (vertex2 - vertex1);
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance.at(2) < zero)
            {
                // mmm
                quantity = 0;
                this->SetIntersectionType(IntersectionType::Empty);
            }
            else
            {
                // mmz
                quantity = 1;
                point0 = triangle.GetVertex(2);
                this->SetIntersectionType(IntersectionType::Point);
            }
        }
        else
        {
            if (zero < distance.at(2))
            {
                // mzp
                quantity = 2;
                point0 = vertex0 + (distance.at(0) / (distance.at(0) - distance.at(2))) * (vertex2 - vertex0);
                point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance.at(2) < zero)
            {
                // mzm
                quantity = 1;
                point0 = vertex1;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // mzz
                quantity = 2;
                point0 = vertex1;
                point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
    }
    else
    {
        if (zero < distance.at(1))
        {
            if (zero < distance.at(2))
            {
                // zpp
                quantity = 1;
                point0 = vertex0;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else if (distance.at(2) < zero)
            {
                // zpm
                quantity = 2;
                point0 = vertex1 + (distance.at(1) / (distance.at(1) - distance.at(2))) * (vertex2 - vertex1);
                point1 = vertex0;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zpz
                quantity = 2;
                point0 = vertex0;
                point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else if (distance.at(1) < zero)
        {
            if (distance.at(2) > zero)
            {
                // zmp
                quantity = 2;
                point0 = vertex1 + (distance.at(1) / (distance.at(1) - distance.at(2))) * (vertex2 - vertex1);
                point1 = vertex0;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance.at(2) < zero)
            {
                // zmm
                quantity = 1;
                point0 = vertex0;
                this->SetIntersectionType(IntersectionType::Point);
            }
            else
            {
                // zmz
                quantity = 2;
                point0 = vertex0;
                point1 = vertex2;
                this->SetIntersectionType(IntersectionType::Segment);
            }
        }
        else
        {
            if (zero < distance.at(2))
            {
                // zzp
                quantity = 2;
                point0 = vertex0;
                point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else if (distance.at(2) < zero)
            {
                // zzm
                quantity = 2;
                point0 = vertex0;
                point1 = vertex1;
                this->SetIntersectionType(IntersectionType::Segment);
            }
            else
            {
                // zzz
                quantity = 3;
                point0 = vertex0;
                point1 = vertex1;
                point2 = vertex2;
                this->SetIntersectionType(IntersectionType::Polygon);
            }
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
const Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorPlane3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
        else
            return point2;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_DETAIL_H
