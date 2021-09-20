///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 11:19)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_ACHIEVE_H

#include "EllipsoidFit3.h"
#include "Detail/EllipsoidFit3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::EllipsoidFit3<Real>::EllipsoidFit3(const Points& points)
    : impl{  points  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipsoidFit3<Real>::IsValid() const noexcept
{
     
        return true;
    
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExactly();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::EllipsoidFit3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCenter();
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::EllipsoidFit3<Real>::GetRotate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRotate();
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent0();
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent1();
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>::GetExtent2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent2();
}

template <typename Real>
int Mathematics::EllipsoidFit3<Real>::GetNumPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetNumPoint();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::EllipsoidFit3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoint(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_ACHIEVE_H
