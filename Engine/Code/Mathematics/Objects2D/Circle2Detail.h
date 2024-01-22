/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:19)

#ifndef MATHEMATICS_OBJECTS_2D_CIRCLE2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_CIRCLE2_DETAIL_H

#include "Circle2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CIRCLE2_ACHIEVE)

    #include "Circle2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CIRCLE2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector2Tools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Math<Real>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& out, const Circle2<Real>& circle2)
{
    out << "center=(" << circle2.GetCenter() << "),radius=" << circle2.GetRadius();

    return out;
}

#endif  // MATHEMATICS_OBJECTS_2D_CIRCLE2_DETAIL_H