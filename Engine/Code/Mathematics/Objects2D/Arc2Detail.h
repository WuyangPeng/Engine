///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 11:22)

#ifndef MATHEMATICS_OBJECTS2D_ARC2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ARC2_DETAIL_H

#include "Arc2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ARC2_ACHIEVE)

    #include "Arc2Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_ARC2_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, const Real epsilon)
{
    return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
           Math<Real>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetEnd0(), rhs.GetEnd0(), epsilon) &&
           Vector2DTools<Real>::Approximate(lhs.GetEnd1(), rhs.GetEnd1(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& out, const Arc2<Real>& arc2)
{
    out << "center=(" << arc2.GetCenter() << "),radius=" << arc2.GetRadius()
        << ",firstEnd=(" << arc2.GetEnd0() << "),secondEnd=("
        << arc2.GetEnd1() << ")";

    return out;
}

#endif  // MATHEMATICS_OBJECTS2D_ARC2_DETAIL_H
