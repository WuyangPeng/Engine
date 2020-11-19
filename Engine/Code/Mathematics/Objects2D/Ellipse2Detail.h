///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 12:54)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_DETAIL_H

#include "Ellipse2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSE2_ACHIEVE)

    #include "Ellipse2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSE2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ellipse2<Real>& ellipse)
{
    outFile << "center=" << ellipse.GetCenter() << ",axis0=" << ellipse.GetAxis0()
            << ",axis1=" << ellipse.GetAxis1() << "extent0=" << ellipse.GetExtent0()
            << "extent1=" << ellipse.GetExtent1();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_DETAIL_H
