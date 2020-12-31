///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 11:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_IMPL_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_IMPL_DETAIL_H

#include "StaticFindIntersectorEllipse2Ellipse2Impl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::StaticFindIntersectorEllipse2Ellipse2Impl(const Ellipse2& ellipse0, const Ellipse2& ellipse1) noexcept
    : m_Ellipse0{ ellipse0 }, m_Ellipse1{ ellipse1 }, m_Point{}, m_Transverse{}, m_DigitsAccuracy{ 10 } 
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::GetEllipse0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Ellipse0;
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::GetEllipse1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Ellipse1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point.at(index);
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::GetIntersectionEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Ellipse0;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::IsTransverseIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Transverse.at(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::AddIntersection(const Vector2D& point, bool transverse)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Transverse.at(m_Point.size()) = transverse;
    m_Point.emplace_back(point);    
}

template <typename Real>
int Mathematics::StaticFindIntersectorEllipse2Ellipse2Impl<Real>::GetDigitsAccuracy() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DigitsAccuracy;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_IMPL_DETAIL_H