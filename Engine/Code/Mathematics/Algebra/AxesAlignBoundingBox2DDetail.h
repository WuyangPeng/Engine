///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:01)

// 轴对齐包围盒2D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_DETAIL_H

#include "AxesAlignBoundingBox2D.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX_2D_ACHIEVE)

    #include "AxesAlignBoundingBox2DAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX_2D_ACHIEVE)

template <typename Real>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox2D<Real>::AxesAlignBoundingBox2D(const AxesAlignBoundingBox2D<RhsType>& aabb)
    : m_MinPoint{ aabb.GetMinPoint() }, m_MaxPoint{ aabb.GetMaxPoint() }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
bool Mathematics::HasXOverlap(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
    return (lhs.GetMinPoint().GetX() <= rhs.GetMaxPoint().GetX()) &&
           (rhs.GetMinPoint().GetX() <= lhs.GetMaxPoint().GetX());
}

template <typename Real>
bool Mathematics::HasYOverlap(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
    return (lhs.GetMinPoint().GetY() <= rhs.GetMaxPoint().GetY()) &&
           (rhs.GetMinPoint().GetY() <= lhs.GetMaxPoint().GetY());
}

template <typename Real>
bool Mathematics::IsIntersection(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
    for (auto i = 0; i < Vector2D<Real>::sm_PointSize; ++i)
    {
        if ((lhs.GetMaxPoint()[i] < rhs.GetMinPoint()[i]) ||
            (rhs.GetMaxPoint()[i] < lhs.GetMinPoint()[i]))
        {
            return false;
        }
    }

    return true;
}

template <typename Real>
const Mathematics::AxesAlignBoundingBox2D<Real> Mathematics::FindIntersection(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
    if (!IsIntersection(lhs, rhs))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("包围盒不相交！"s));
    }

    Vector2D<Real> minPoint{};
    Vector2D<Real> maxPoint{};

    for (auto i = 0; i < Vector2D<Real>::sm_PointSize; ++i)
    {
        auto lhsMaxPoint = lhs.GetMaxPoint()[i];
        auto rhsMaxPoint = rhs.GetMaxPoint()[i];
        maxPoint[i] = std::min(lhsMaxPoint, rhsMaxPoint);

        auto lhsMinPoint = lhs.GetMinPoint()[i];
        auto rhsMinPoint = rhs.GetMinPoint()[i];
        maxPoint[i] = std::max(lhsMinPoint, rhsMinPoint);
    }

    return AxesAlignBoundingBox2D<Real>{ minPoint, maxPoint };
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_DETAIL_H