///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 10:57)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_IMPL_DETAIL_H

#include "DynamicFindIntersectorBox3Box3Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::DynamicFindIntersectorBox3Box3Impl(const Box3& box0, const Box3& box1) noexcept
    : m_Box0{ box0 }, m_Box1{ box1 }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Box0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Box1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox3Box3Impl<Real>::SetPoint(const Container& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point = point;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_IMPL_DETAIL_H