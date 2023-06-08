///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:48)

#ifndef MATHEMATICS_OBJECTS_3D_CIRCLE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_CIRCLE3_DETAIL_H

#include "Circle3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CIRCLE3_ACHIEVE)

    #include "Circle3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CIRCLE3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Circle3<Real>& lhs, const Circle3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector3Tools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetDirection0(), rhs.GetDirection0(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetDirection1(), rhs.GetDirection1(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetNormal(), rhs.GetNormal(), epsilon) &&
           Math<Real>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Circle3<Real>& circle)
{
    outFile << "center="
            << circle.GetCenter()
            << ",direction0="
            << circle.GetDirection0()
            << ",direction1="
            << circle.GetDirection1()
            << ",normal="
            << circle.GetNormal()
            << "radius="
            << circle.GetRadius();

    return outFile;
}
#endif  // MATHEMATICS_OBJECTS_3D_CIRCLE3_DETAIL_H
