///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 14:48)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H

#include "Segment3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT3_ACHIEVE)

    #include "Segment3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, const Real epsilon)
{
    return Vector3DTools<Real>::Approximate(lhs.GetCenterPoint(), rhs.GetCenterPoint(), epsilon) &&
           Vector3DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent(), rhs.GetExtent(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Segment3<Real>& segment)
{
    outFile << "origin=" << segment.GetCenterPoint() << ",direction=" << segment.GetDirection()
            << ",extent=" << segment.GetExtent() << ",beginPoint=" << segment.GetBeginPoint()
            << ",endPoint=" << segment.GetEndPoint();

    return outFile;
}
#endif  // MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H
