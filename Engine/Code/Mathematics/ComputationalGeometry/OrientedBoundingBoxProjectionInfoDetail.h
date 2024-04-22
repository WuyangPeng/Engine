/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/08 14:45)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_PROJECTION_INFO_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_PROJECTION_INFO_DETAIL_H

#include "OrientedBoundingBoxProjectionInfo.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::OrientedBoundingBoxProjectionInfo<Real>::OrientedBoundingBoxProjectionInfo() noexcept
    : pointIndex{}, projection{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::OrientedBoundingBoxProjectionInfo<Real>::OrientedBoundingBoxProjectionInfo(int pointIndex, Real projection) noexcept
    : pointIndex{ pointIndex }, projection{ projection }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::OrientedBoundingBoxProjectionInfo<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxProjectionInfo<Real>::GetPointIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return pointIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::OrientedBoundingBoxProjectionInfo<Real>::GetProjection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return projection;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxProjectionInfo<Real>::SetPointIndex(int aPointIndex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    pointIndex = aPointIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxProjectionInfo<Real>::SetProjection(Real aProjection) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    projection = aProjection;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const OrientedBoundingBoxProjectionInfo<Real>& lhs, const OrientedBoundingBoxProjectionInfo<Real>& rhs) noexcept
{
    return lhs.GetProjection() < rhs.GetProjection();
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_PROJECTION_INFO_DETAIL_H
