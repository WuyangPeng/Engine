///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 10:45)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_RAY2_DETAIL_H

#include "Ray2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RAY2_ACHIEVE)

    #include "Ray2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RAY2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ray2<Real>& lhs, const Ray2<Real>& rhs, const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector2Tools<Real>::Approximate(lhs.GetOrigin(), rhs.GetOrigin(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ray2<Real>& ray)
{
    outFile << "origin=" << ray.GetOrigin() << ",direction=" << ray.GetDirection();

    return outFile;
}
#endif  // MATHEMATICS_OBJECTS2D_RAY2_DETAIL_H