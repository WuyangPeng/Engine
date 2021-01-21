///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 12:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_IMPL_DETAIL_H

#include "StaticFindIntersectorTriangle3Box3Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::StaticFindIntersectorTriangle3Box3Impl(const Triangle3& triangle, const Box3& box) noexcept
    : m_Triangle{ triangle }, m_Box{ box }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Triangle;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Box;
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Box3Impl<Real>::SetContainer(const Container& container)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point = container;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_IMPL_DETAIL_H