///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H

#include "StaticFindIntersectorSegment3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::StaticFindIntersectorSegment3Ellipsoid3(const Segment3Type& segment, const Ellipsoid3Type& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, ellipsoid{ ellipsoid }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::Find()
{
    /// ������(X - K)^T * M * (X - K)-1 = 0 ��������X = P + t * D��
    /// ���߷��̴������򷽳��Ի�ö��η���
    /// Q(t) = a2 * t^2 + 2 * a1 * t + a0 = 0
    /// ����a2 = D^T * M * D, a1 = D^T * M * (P - K)��a0 = (P - K)^T * M * (P - K) - 1��
    const auto matrix = ellipsoid.GetMatrix();

    auto diff = segment.GetCenterPoint() - ellipsoid.GetCenter();
    const auto matrixDirection = matrix * segment.GetDirection();
    const auto matrixDiff = matrix * diff;
    auto a2 = Vector3ToolsType::DotProduct(segment.GetDirection(), matrixDirection);
    auto a1 = Vector3ToolsType::DotProduct(segment.GetDirection(), matrixDiff);
    auto a0 = Vector3ToolsType::DotProduct(diff, matrixDiff) - MathType::GetValue(1);

    // ��� Q(t)����t >= 0��ʵ���������ཻ��
    auto discr = a1 * a1 - a0 * a2;

    if (discr < MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        quantity = 0;
    }
    else if (MathType::GetZeroTolerance() < discr)
    {
        auto root = MathType::Sqrt(discr);
        auto inv = (MathType::GetValue(1)) / a2;
        auto t0 = (-a1 - root) * inv;
        auto t1 = (-a1 + root) * inv;

        // ���ԣ�t0 < t1��Ϊa2 > 0
        StaticFindIntersector1<Real> intr{ t0, t1, -segment.GetExtent(), segment.GetExtent() };

        quantity = intr.GetNumIntersections();
        if (quantity == 2)
        {
            this->SetIntersectionType(IntersectionType::Segment);
            point0 = segment.GetCenterPoint() + intr.GetIntersection(0) * segment.GetDirection();
            point1 = segment.GetCenterPoint() + intr.GetIntersection(1) * segment.GetDirection();
        }
        else if (quantity == 1)
        {
            this->SetIntersectionType(IntersectionType::Point);
            point0 = segment.GetCenterPoint() + intr.GetIntersection(0) * segment.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
    else
    {
        auto t0 = -a1 / a2;
        if (MathType::FAbs(t0) <= segment.GetExtent())
        {
            this->SetIntersectionType(IntersectionType::Point);
            quantity = 1;
            point0 = segment.GetCenterPoint() + t0 * segment.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
            quantity = 0;
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_DETAIL_H