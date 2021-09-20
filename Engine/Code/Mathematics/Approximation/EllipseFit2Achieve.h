///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 19:05)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_ACHIEVE_H

#include "EllipseFit2.h"
#include "Detail/EllipseFit2ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::EllipseFit2<Real>::EllipseFit2(const Points& points)
    : impl{ points }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseFit2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipseFit2<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExactly();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::EllipseFit2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCenter();
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::EllipseFit2<Real>::GetRotate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRotate();
}

template <typename Real>
Real Mathematics::EllipseFit2<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent0();
}

template <typename Real>
Real Mathematics::EllipseFit2<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent1();
}

template <typename Real>
int Mathematics::EllipseFit2<Real>::GetNumPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetNumPoint();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::EllipseFit2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoint(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_ACHIEVE_H
