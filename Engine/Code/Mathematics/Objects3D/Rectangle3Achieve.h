///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 17:24)

#ifndef MATHEMATICS_OBJECTS3D_RECTANGLE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_RECTANGLE3_ACHIEVE_H

#include "Rectangle3.h"
#include "Detail/Rectangle3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Rectangle3<Real>::Rectangle3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, Real extent0, Real extent1, const Real epsilon)
    : impl{  center, axis0, axis1, extent0, extent1, epsilon  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Rectangle3<Real>::IsValid() const noexcept
{
  
        return true;
    
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCenter();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetAxis0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetAxis0();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetAxis1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetAxis1();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetAxis(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetAxis(index);
}

template <typename Real>
Real Mathematics::Rectangle3<Real>::GetExtent(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent(index);
}

template <typename Real>
Real Mathematics::Rectangle3<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent0();
}

template <typename Real>
Real Mathematics::Rectangle3<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetExtent1();
}

template <typename Real>
const typename Mathematics::Rectangle3<Real>::VerticesType Mathematics::Rectangle3<Real>::ComputeVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->ComputeVertices();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetPPCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPPCorner();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetPMCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPMCorner();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetMPCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMPCorner();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Rectangle3<Real>::GetMMCorner() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMMCorner();
}

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::Rectangle3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Rectangle3{ GetCenter() + t * velocity, GetAxis0(), GetAxis1(), GetExtent0(), GetExtent1(), impl->GetEpsilon() };
}

#endif  // MATHEMATICS_OBJECTS3D_RECTANGLE3_ACHIEVE_H
