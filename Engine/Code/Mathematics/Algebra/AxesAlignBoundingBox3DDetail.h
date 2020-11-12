///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:49)

// 轴对齐包围盒3D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_DETAIL_H

#include "AxesAlignBoundingBox3D.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX_3D_ACHIEVE)

    #include "AxesAlignBoundingBox3DAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX_3D_ACHIEVE)

template <typename Real>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox3D<Real>::AxesAlignBoundingBox3D(const AxesAlignBoundingBox3D<RhsType>& aabb)
    : m_MinPoint{ aabb.GetMinPoint() }, m_MaxPoint{ aabb.GetMaxPoint() }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
bool Mathematics::HasXOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs)
{
    return (lhs.GetMinPoint().GetX() <= rhs.GetMaxPoint().GetX()) &&
           (rhs.GetMinPoint().GetX() <= lhs.GetMaxPoint().GetX());
}

template <typename Real>
bool Mathematics::HasYOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs)
{
    return (lhs.GetMinPoint().GetY() <= rhs.GetMaxPoint().GetY()) &&
           (rhs.GetMinPoint().GetY() <= lhs.GetMaxPoint().GetY());
}

template <typename Real>
bool Mathematics::HasZOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs)
{
    return (lhs.GetMinPoint().GetZ() <= rhs.GetMaxPoint().GetZ()) &&
           (rhs.GetMinPoint().GetZ() <= lhs.GetMaxPoint().GetZ());
}

template <typename Real>
bool Mathematics::IsIntersection(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs)
{
    for (auto i = 0; i < Vector3D<Real>::sm_PointSize; ++i)
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
const Mathematics::AxesAlignBoundingBox3D<Real> Mathematics::FindIntersection(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs)
{
    if (!IsIntersection(lhs, rhs))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("包围盒不相交！"s));
    }

    Vector3D<Real> minPoint{};
    Vector3D<Real> maxPoint{};

    for (auto i = 0; i < Vector3D<Real>::sm_PointSize; ++i)
    {
        auto lhsMaxPoint = lhs.GetMaxPoint()[i];
        auto rhsMaxPoint = rhs.GetMaxPoint()[i];
        maxPoint[i] = std::min(lhsMaxPoint, rhsMaxPoint);

        auto lhsMinPoint = lhs.GetMinPoint()[i];
        auto rhsMinPoint = rhs.GetMinPoint()[i];
        maxPoint[i] = std::max(lhsMinPoint, rhsMinPoint);
    }

    return AxesAlignBoundingBox3D<Real>{ minPoint, maxPoint };
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_DETAIL_H