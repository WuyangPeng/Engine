///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 13:08)

#ifndef MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H

#include "Box2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BOX2_ACHIEVE)

    #include "Box2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BOX2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Box2<Real>& box)
{
    outFile << "center=" << box.GetCenter() << ",axis0=" << box.GetAxis0()
            << ",axis1=" << box.GetAxis1() << "extent0=" << box.GetExtent0()
            << "extent1=" << box.GetExtent1();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H
