///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:25)

#ifndef MATHEMATICS_OBJECTS_3D_SEGMENT3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_SEGMENT3_DETAIL_H

#include "Segment3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT3_ACHIEVE)

    #include "Segment3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector3Tools<Real>::Approximate(lhs.GetCenterPoint(), rhs.GetCenterPoint(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent(), rhs.GetExtent(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Segment3<Real>& segment)
{
    outFile << "origin="
            << segment.GetCenterPoint()
            << ",direction="
            << segment.GetDirection()
            << ",extent="
            << segment.GetExtent()
            << ",beginPoint="
            << segment.GetBeginPoint()
            << ",endPoint="
            << segment.GetEndPoint();

    return outFile;
}
#endif  // MATHEMATICS_OBJECTS_3D_SEGMENT3_DETAIL_H
