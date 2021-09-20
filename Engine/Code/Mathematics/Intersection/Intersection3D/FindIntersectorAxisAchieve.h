///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/28 17:16)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_ACHIEVE_H

#include "FindIntersectorAxis.h" 
#include "Detail/FindIntersectorAxisImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::FindIntersectorAxis<Real>::FindIntersectorAxis(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax)
    : impl{  axis, segment, triangle, velocity, tmax  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::FindIntersectorAxis<Real>::FindIntersectorAxis(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax)
    : impl{  axis, segment, box, velocity, tmax  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::FindIntersectorAxis<Real>::FindIntersectorAxis(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax)
    : impl{  axis, triangle, box, velocity, tmax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::FindIntersectorAxis<Real>::FindIntersectorAxis(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax)
    : impl{  axis, box0, box1, velocity, tmax  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::FindIntersectorAxis<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::FindIntersectorAxis<Real>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetResult();
}

template <typename Real>
Real Mathematics::FindIntersectorAxis<Real>::GetTFirst() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTFirst();
}

template <typename Real>
Real Mathematics::FindIntersectorAxis<Real>::GetTLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTLast();
}

template <typename Real>
Mathematics::ContactSide Mathematics::FindIntersectorAxis<Real>::Getside() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->Getside();
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxis<Real>::GetCfgFinal0() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCfgFinal0();
}

template <typename Real>
Mathematics::IntersectorConfiguration<Real> Mathematics::FindIntersectorAxis<Real>::GetCfgFinal1() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCfgFinal1();
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_ACHIEVE_H
