///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/08 10:16)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_IMPL_DETAIL_H

#include "FindIntersectorTriangle3Triangle3Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::FindIntersectorTriangle3Triangle3Impl(const Triangle3& triangle0, const Triangle3& triangle1) noexcept
    : m_Triangle0{ triangle0 }, m_Triangle1{ triangle1 }, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Triangle0;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Triangle1;
}

template <typename Real>
int Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
void Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::SetPoint(const Container& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point = point;
}

template <typename Real>
void Mathematics::FindIntersectorTriangle3Triangle3Impl<Real>::AddPoint(const Vector3D& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Point.emplace_back(point);
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_IMPL_DETAIL_H