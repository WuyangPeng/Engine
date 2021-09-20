///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 16:59)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_ACHIEVE_H

#include "FindContactSet.h"
#include "Detail/FindContactSetImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(
    const SegmentType& segment,
    const Triangle3& triangle,
    ContactSide side,
    const IntersectorConfiguration& segmentCfg,
    const IntersectorConfiguration& triangleCfg,
    const Vector3D& segmentVelocity,
    const Vector3D& triangleVelocity,
    Real tFirst)
    : impl{ segment, triangle, side, segmentCfg, triangleCfg, segmentVelocity, triangleVelocity, tFirst }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(
    const SegmentType& segment,
    const Box3& box,
    ContactSide side,
    const IntersectorConfiguration& segmentCfg,
    const IntersectorConfiguration& boxCfg,
    const Vector3D& segmentVelocity,
    const Vector3D& boxVelocity,
    Real tFirst)
    : impl{ segment, box, side, segmentCfg, boxCfg, segmentVelocity, boxVelocity, tFirst }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(
    const Triangle3& triangle,
    const Box3& box,
    ContactSide side,
    const IntersectorConfiguration& triangleCfg,
    const IntersectorConfiguration& boxCfg,
    const Vector3D& triangleVelocity,
    const Vector3D& boxVelocity,
    Real tFirst)
    : impl{ triangle, box, side, triangleCfg, boxCfg, triangleVelocity, boxVelocity, tFirst }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::FindContactSet<Real>::FindContactSet(
    const Box3& box0,
    const Box3& box1,
    ContactSide side,
    const IntersectorConfiguration& box0Cfg,
    const IntersectorConfiguration& box1Cfg,
    const Vector3D& box0Velocity,
    const Vector3D& box1Velocity,
    Real tFirst)
    : impl{ box0, box1, side, box0Cfg, box1Cfg, box0Velocity, box1Velocity, tFirst }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::FindContactSet<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::FindContactSet<Real>::PointType Mathematics::FindContactSet<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoint();
}

#endif  // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_ACHIEVE_H
