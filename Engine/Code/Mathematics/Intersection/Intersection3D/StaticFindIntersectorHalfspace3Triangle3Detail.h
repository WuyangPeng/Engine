///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/01 18:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "IntersectorUtility3Detail.h"
#include "StaticFindIntersectorHalfspace3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::StaticFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, halfspace{ halfspace }, triangle{ triangle }, quantity{}, point0{}, point1{}, point2{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::Find()
{
    // �������ο�ʼ��Ȼ����ü���ƽ���ϡ�

    auto container = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(-halfspace.GetNormal(), -halfspace.GetConstant(), triangle.GetVertex());

    quantity = boost::numeric_cast<int>(container.size());

    if (quantity == 0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else if (quantity == 1)
    {
        point0 = container.at(0);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else if (quantity == 2)
    {
        point0 = container.at(0);
        point1 = container.at(1);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else if (2 < quantity)
    {
        point0 = container.at(0);
        point1 = container.at(1);
        point2 = container.at(2);
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorHalfspace3Triangle3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H