///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 9:38)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_ACHIEVE_H

#include "Torus3Parameters.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Torus3Parameters<Real>::Torus3Parameters(Real s, Real t) noexcept
    : m_S{ s }, m_T{ t }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Torus3Parameters<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_S && m_S <= Math::GetValue(1) &&
        Math::GetValue(0) <= m_T && m_T <= Math::GetValue(1))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Torus3Parameters<Real>::GetS() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_S;
}

template <typename Real>
Real Mathematics::Torus3Parameters<Real>::GetT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_T;
}

#endif  // MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_ACHIEVE_H