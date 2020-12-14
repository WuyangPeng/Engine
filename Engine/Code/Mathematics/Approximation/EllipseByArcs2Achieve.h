///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/02 17:08)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_ACHIEVE_H

#include "EllipseByArcs2.h"
#include "Detail/EllipseByArcs2ImplDetail.h"

template <typename Real>
Mathematics::EllipseByArcs2<Real>::EllipseByArcs2(Real begin, Real end, size_t numArcs)
    : m_Impl{ std::make_shared<ImplType>(begin, end, numArcs) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseByArcs2<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::EllipseByArcs2<Real>::PointsType Mathematics::EllipseByArcs2<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoints();
}

template <typename Real>
typename const Mathematics::EllipseByArcs2<Real>::Circle2Container Mathematics::EllipseByArcs2<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCircle2();
}

template <typename Real>
int Mathematics::EllipseByArcs2<Real>::getNumArcs() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->getNumArcs();
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::EllipseByArcs2<Real>::GetArc2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetArc2(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_ACHIEVE_H
