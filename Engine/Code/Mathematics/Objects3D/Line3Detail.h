///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:10)

#ifndef MATHEMATICS_OBJECTS3D_LINE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_LINE3_DETAIL_H

#include "Line3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_LINE3_ACHIEVE)

    #include "Line3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_LINE3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, const Real epsilon)
{
    return Vector3DTools<Real>::Approximate(lhs.GetOrigin(), rhs.GetOrigin(), epsilon) &&
           Vector3DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Line3<Real>& line)
{
    outFile << "origin=" << line.GetOrigin() << ",direction=" << line.GetDirection();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS3D_LINE3_DETAIL_H
