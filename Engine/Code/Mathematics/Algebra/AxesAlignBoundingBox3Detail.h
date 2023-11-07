///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:19)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_DETAIL_H

#include "AxesAlignBoundingBox3.h"

#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX3_ACHIEVE)

    #include "AxesAlignBoundingBox3Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX3_ACHIEVE)

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox3<Real>::AxesAlignBoundingBox3(const AxesAlignBoundingBox3<RhsType>& aabb)
    : minPoint{ aabb.GetMinPoint() }, maxPoint{ aabb.GetMaxPoint() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
bool Mathematics::HasXOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs)
{
    constexpr auto pointIndex = AxesAlignBoundingBox3<Real>::PointIndex::X;

    return (lhs.GetMinPoint(pointIndex) <= rhs.GetMaxPoint(pointIndex)) &&
           (rhs.GetMinPoint(pointIndex) <= lhs.GetMaxPoint(pointIndex));
}

template <typename Real>
bool Mathematics::HasYOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs)
{
    constexpr auto pointIndex = AxesAlignBoundingBox3<Real>::PointIndex::Y;

    return (lhs.GetMinPoint(pointIndex) <= rhs.GetMaxPoint(pointIndex)) &&
           (rhs.GetMinPoint(pointIndex) <= lhs.GetMaxPoint(pointIndex));
}

template <typename Real>
bool Mathematics::HasZOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs)
{
    constexpr auto pointIndex = AxesAlignBoundingBox3<Real>::PointIndex::Z;

    return (lhs.GetMinPoint(pointIndex) <= rhs.GetMaxPoint(pointIndex)) &&
           (rhs.GetMinPoint(pointIndex) <= lhs.GetMaxPoint(pointIndex));
}

template <typename Real>
bool Mathematics::IsIntersection(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs)
{
    for (auto i = 0; i < Vector3<Real>::pointSize; ++i)
    {
        if ((lhs.GetMaxPoint(i) < rhs.GetMinPoint(i)) ||
            (rhs.GetMaxPoint(i) < lhs.GetMinPoint(i)))
        {
            return false;
        }
    }

    return true;
}

template <typename Real>
Mathematics::AxesAlignBoundingBox3<Real> Mathematics::FindIntersection(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs)
{
    Vector3<Real> minPoint{};
    Vector3<Real> maxPoint{};

    for (auto i = 0; i < Vector3<Real>::pointSize; ++i)
    {
        auto lhsMaxPoint = lhs.GetMaxPoint(i);
        auto rhsMaxPoint = rhs.GetMaxPoint(i);
        minPoint[i] = std::min(lhsMaxPoint, rhsMaxPoint);

        auto lhsMinPoint = lhs.GetMinPoint(i);
        auto rhsMinPoint = rhs.GetMinPoint(i);
        maxPoint[i] = std::max(lhsMinPoint, rhsMinPoint);
    }

    return AxesAlignBoundingBox3<Real>{ minPoint, maxPoint };
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_DETAIL_H