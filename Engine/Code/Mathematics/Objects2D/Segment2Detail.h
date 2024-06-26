/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:18)

#ifndef MATHEMATICS_OBJECTS_2D_SEGMENT2_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_SEGMENT2_DETAIL_H

#include "Segment2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT2_ACHIEVE)

    #include "Segment2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_SEGMENT2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Segment2<Real>& lhs, const Segment2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector2Tools<Real>::Approximate(lhs.GetCenterPoint(), rhs.GetCenterPoint(), epsilon) &&
           Vector2Tools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon) &&
           Math<Real>::Approximate(lhs.GetExtent(), rhs.GetExtent(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Segment2<Real>& segment)
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

#endif  // MATHEMATICS_OBJECTS_2D_SEGMENT2_DETAIL_H
