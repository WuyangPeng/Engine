///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 16:16)

#ifndef MATHEMATICS_OBJECTS2D_LINE2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_LINE2_DETAIL_H

#include "Line2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_LINE2_ACHIEVE)

    #include "Line2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_LINE2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Line2<Real>& lhs, const Line2<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetOrigin(), rhs.GetOrigin(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Line2<Real>& line)
{
    outFile << "origin=" << line.GetOrigin() << ",direction=" << line.GetDirection();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS2D_LINE2_DETAIL_H