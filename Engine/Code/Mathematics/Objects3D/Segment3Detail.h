///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 14:55)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H

#include "Segment3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT3_ACHIEVE)

    #include "Segment3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
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
#endif  // MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H
