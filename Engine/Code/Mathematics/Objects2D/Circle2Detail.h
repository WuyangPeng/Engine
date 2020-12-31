///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 13:40)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_DETAIL_H

#include "Circle2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CIRCLE2_ACHIEVE)

    #include "Circle2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CIRCLE2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Math<Real>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& out, const Circle2<Real>& circle2)
{
    out << "center=(" << circle2.GetCenter() << "),radius=" << circle2.GetRadius();

    return out;
}

#endif  // MATHEMATICS_OBJECTS2D_CIRCLE2_DETAIL_H