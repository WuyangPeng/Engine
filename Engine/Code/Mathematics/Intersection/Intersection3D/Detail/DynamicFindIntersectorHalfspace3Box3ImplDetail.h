///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/31 16:28)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_IMPL_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Box3Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::DynamicFindIntersectorHalfspace3Box3Impl(const Plane3& halfspace, const Box3& box) noexcept
    : m_Halfspace{ halfspace }, m_Box{ box }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Box;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Box3Impl<Real>::SetPoint(const Container& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point = point;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_IMPL_DETAIL_H