///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 16:49)

#ifndef MATHEMATICS_OBJECTS2D_SEGMENT2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_SEGMENT2_DETAIL_H

#include "Segment2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT2_ACHIEVE)

    #include "Segment2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Segment2<Real>& lhs, const Segment2<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetCenterPoint(), rhs.GetCenterPoint(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent(), rhs.GetExtent(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Segment2<Real>& segment)
{
    outFile << "origin=" << segment.GetCenterPoint() << ",direction=" << segment.GetDirection()
            << ",extent=" << segment.GetExtent() << ",beginPoint=" << segment.GetBeginPoint()
            << ",endPoint=" << segment.GetEndPoint();

    return outFile;
}
#endif  // MATHEMATICS_OBJECTS2D_SEGMENT2_DETAIL_H
