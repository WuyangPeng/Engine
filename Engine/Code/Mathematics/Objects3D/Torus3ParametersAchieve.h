///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 16:46)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_ACHIEVE_H

#include "Torus3Parameters.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Torus3Parameters<Real>::Torus3Parameters(Real s, Real t) noexcept
    : s{ s }, t{ t }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Torus3Parameters<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= s &&
        s <= Math::GetValue(1) &&
        Math::GetValue(0) <= t &&
        t <= Math::GetValue(1))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Torus3Parameters<Real>::GetS() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return s;
}

template <typename Real>
Real Mathematics::Torus3Parameters<Real>::GetT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return t;
}

#endif  // MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_ACHIEVE_H