///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 14:37)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_DETAIL_H

#include "Ellipsoid3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSOID3_ACHIEVE)

    #include "Ellipsoid3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ELLIPSOID3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ellipsoid3<Real>& lhs, const Ellipsoid3<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetAxis2(), rhs.GetAxis2(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent2(), rhs.GetExtent2(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ellipsoid3<Real>& ellipsoid)
{
    outFile << "center=" << ellipsoid.GetCenter() << ",axis0=" << ellipsoid.GetAxis0()
            << ",axis1=" << ellipsoid.GetAxis1() << ",axis2=" << ellipsoid.GetAxis2()
            << ",extent0=" << ellipsoid.GetExtent0() << ",extent1=" << ellipsoid.GetExtent1()
            << ",extent2=" << ellipsoid.GetExtent2();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_DETAIL_H
