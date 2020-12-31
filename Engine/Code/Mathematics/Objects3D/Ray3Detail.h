///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:24)

#ifndef MATHEMATICS_OBJECTS3D_RAY3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_RAY3_DETAIL_H

#include "Ray3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RAY3_ACHIEVE)

    #include "Ray3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RAY3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ray3<Real>& lhs, const Ray3<Real>& rhs, const Real epsilon)
{
    return Vector3DTools<Real>::Approximate(lhs.GetOrigin(), rhs.GetOrigin(), epsilon) &&
           Vector3DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ray3<Real>& ray)
{
    outFile << "origin=" << ray.GetOrigin() << ",direction=" << ray.GetDirection();

    return outFile;
}
#endif  // MATHEMATICS_OBJECTS3D_RAY3_DETAIL_H