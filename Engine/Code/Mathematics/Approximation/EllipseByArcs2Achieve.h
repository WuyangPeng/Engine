///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 17:08)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_ACHIEVE_H

#include "EllipseByArcs2.h"
#include "Detail/EllipseByArcs2ImplDetail.h"

template <typename Real>
Mathematics::EllipseByArcs2<Real>::EllipseByArcs2(Real begin, Real end, size_t numArcs)
    : impl{ begin, end, numArcs }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseByArcs2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::EllipseByArcs2<Real>::PointsType Mathematics::EllipseByArcs2<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoints();
}

template <typename Real>
typename const Mathematics::EllipseByArcs2<Real>::Circle2Container Mathematics::EllipseByArcs2<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCircle2();
}

template <typename Real>
int Mathematics::EllipseByArcs2<Real>::getNumArcs() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->getNumArcs();
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::EllipseByArcs2<Real>::GetArc2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetArc2(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_ACHIEVE_H
