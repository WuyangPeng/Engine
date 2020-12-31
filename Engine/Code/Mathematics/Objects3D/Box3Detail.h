///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 14:08)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_BOX3_DETAIL_H

#include "Box3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BOX3_ACHIEVE)

    #include "Box3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BOX3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Box3<Real>& lhs, const Box3<Real>& rhs, const Real epsilon)
{
    return Vector3DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector3DTools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
           Vector3DTools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
           Vector3DTools<Real>::Approximate(lhs.GetAxis2(), rhs.GetAxis2(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent2(), rhs.GetExtent2(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Box3<Real>& box)
{
    outFile << "center=" << box.GetCenter()
            << ",axis0=" << box.GetAxis0()
            << ",axis1=" << box.GetAxis1()
            << ",axis2=" << box.GetAxis2()
            << "extent0=" << box.GetExtent0()
            << "extent1=" << box.GetExtent1()
            << "extent2=" << box.GetExtent2();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS3D_BOX3_DETAIL_H
